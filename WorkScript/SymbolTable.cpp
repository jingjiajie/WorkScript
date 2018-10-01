#include "stdafx.h"
#include "SymbolTable.h"

using namespace std;

size_t SymbolTable::getTotalSymbolCount(BLOCK_ID block) const
{
	auto it = this->blockInfos.find(block);
	return it->second.getTotalSymbolCount();
}

void SymbolTable::print() const
{
	wprintf(L"块号\t符号名\t域号\t偏移\n");
	wstring lineHead;
	for (auto itBlock = this->blockInfos.begin(); itBlock != this->blockInfos.end(); ++itBlock) {
		auto blockInfos = itBlock->second.getSymbolInfos();
		for (auto itVar = blockInfos.begin(); itVar != blockInfos.end(); ++itVar) {
			if (itVar->second.hasPublicDomainOffset()) {
				wprintf(L"%llu\t%ls\tPUBLIC\t%llu\n", itBlock->first, itVar->first.c_str(), itVar->second.getPublicDomainOffset());
			}
			auto domainSymbolInfos = itVar->second.getPrivateDomainInfos();
			for (auto itDomain = domainSymbolInfos.begin(); itDomain != domainSymbolInfos.end(); ++itDomain) {
				wprintf(L"%llu\t%ls\tPRIV(%llu)\t%llu\n", itBlock->first, itVar->first.c_str(), itDomain->first, itDomain->second.getOffset());
			}

		}
	}
}

SymbolTable::SymbolTable()
{
}


SymbolTable::~SymbolTable()
{
}

bool SymbolTable::getLocalSymbolOffset(BLOCK_ID block, DOMAIN_ID domain, const wchar_t * varName, BLOCK_ID *outBlockID, size_t *outOffset)
{
	auto it = this->blockInfos.find(block);
	if (it == this->blockInfos.end())return false;
	auto blockInfos = it->second;
	*outBlockID = blockInfos.getBlockID();
	return blockInfos.getLocalSymbolOffset(domain, varName, outOffset);
}

bool SymbolTable::getBaseSymbolOffset(BLOCK_ID block, DOMAIN_ID domain, const wchar_t * varName, BLOCK_ID *outBlockID, size_t * outOffset)
{
	auto baseBlock = this->blockInfos[block].getBaseBlock();
	if (baseBlock == nullptr)return false;
	auto curBlock = baseBlock;
	while (curBlock) {
		if (curBlock->getLocalSymbolOffset(domain, varName, outOffset)) {
			*outBlockID = curBlock->getBlockID();
			return true;
		}
		curBlock = curBlock->getBaseBlock();
	}
	return false;
}

bool SymbolTable::getSymbolOffset(BLOCK_ID block, DOMAIN_ID domain, const wchar_t * varName, BLOCK_ID *outBlockID, size_t * outOffset)
{
	if (this->getLocalSymbolOffset(block, domain, varName, outBlockID, outOffset)) {
		return true;
	}
	else {
		return this->getBaseSymbolOffset(block, domain, varName, outBlockID, outOffset);
	}
}

void SymbolTable::setSymbolInfo(BLOCK_ID block, DOMAIN_ID domain, DomainAccess access, const wchar_t * varName, bool strictLocal)
{
	if (!strictLocal) {
		size_t tmp;
		//如果父级已经定义了相同的符号，则不在当前级别重复定义
		if (this->getBaseSymbolOffset(block, domain, varName, &tmp, &tmp)) {
			return;
		}
	}
	this->blockInfos[block].setSymbolInfo(domain, access, varName,strictLocal);
	//清除所有子块的相同符号
	for (auto it = this->blockInfos.begin(); it != this->blockInfos.end(); ++it) {
		auto &blockSymbolInfo = it->second;
		if (blockSymbolInfo.isSubBlockOf(&this->blockInfos[block])) {
			if(access == DomainAccess::PUBLIC) blockSymbolInfo.removeNonStrictLocalSymbols(varName);
			else blockSymbolInfo.removeNonStrictPrivateLocalSymbol(varName, domain);
		}
	}
}

void SymbolTable::setBaseBlock(BLOCK_ID curBlock, BLOCK_ID baseBlock)
{
	this->blockInfos[curBlock].setBaseBlock(&this->blockInfos[curBlock]);
}

BLOCK_ID SymbolTable::newBlock(BLOCK_ID baseBlock)
{
	BLOCK_ID newID = this->blockCount;
	++this->blockCount;
	this->blockInfos[newID].setBlockID(newID);
	this->blockInfos[newID].setBaseBlock(&this->blockInfos[baseBlock]);
	return newID;
}

BLOCK_ID SymbolTable::newBlock()
{
	BLOCK_ID newID = this->blockCount;
	++this->blockCount;
	this->blockInfos[newID].setBlockID(newID);
	return newID;
}

std::unordered_map<std::wstring, SymbolInfo> BlockInfo::getSymbolInfos() const
{
	return this->symbolInfos;
}

bool BlockInfo::getLocalSymbolOffset(DOMAIN_ID domain, const wchar_t * varName, size_t *outOffset)
{
	auto &info = this->symbolInfos[varName];
	//首先在私有域中查找符号，如果有则优先私有
	if (info.getPrivateDomainOffset(domain, outOffset)) {
		return true;
	}
	else {
		if (info.hasPublicDomainOffset()) {
			*outOffset = info.getPublicDomainOffset();
			return true;
		}
		else {
			return false;
		}
	}
}

void BlockInfo::setSymbolInfo(DOMAIN_ID domain, DomainAccess access, const wchar_t * varName, bool strictLocal)
{
	//public符号，如果已经在相同域的公有或私有部分声明，则不重复添加
	if(access == DomainAccess::PUBLIC){
		auto &infos = this->symbolInfos[varName];
		infos.setPublicDomainInfo(this->getNextOffset(), domain, strictLocal);
	} //否则是增加private符号，如果已经在相同域的公有或私有部分声明，则不重复添加
	else {
		auto &info = this->symbolInfos[varName];
		info.setPrivateDomainInfo(domain, this->getNextOffset(),strictLocal);
	}
}

void BlockInfo::removeNonStrictLocalSymbols(const wchar_t * varName)
{
	auto it = this->symbolInfos.find(varName);
	if (it == this->symbolInfos.end())return;
	auto &symbolInfo = it->second;
	if (symbolInfo.hasPublicDomainOffset() && !symbolInfo.isPublicDomainStrictLocal()) {
		this->symbolInfos.erase(it);
	}
	else {
		symbolInfo.removeNonStrictLocalPrivateDomainInfos();
	}
}

void BlockInfo::removeNonStrictPrivateLocalSymbol(const wchar_t * varName, DOMAIN_ID domain)
{
	this->symbolInfos[varName].removeNonStrictLocalPrivateDomainInfo(domain);
}

size_t BlockInfo::getTotalSymbolCount() const
{
	return this->totalSymbolCount;
}

void BlockInfo::setBaseBlock(BlockInfo * base)
{
	this->baseBlock = base;
}

BlockInfo * BlockInfo::getBaseBlock() const
{
	return this->baseBlock;
}

BLOCK_ID BlockInfo::getBlockID() const
{
	return this->id;
}

void BlockInfo::setBlockID(BLOCK_ID id)
{
	this->id = id;
}

bool BlockInfo::isSubBlockOf(BlockInfo * block) const
{
	if (this->baseBlock == nullptr)return false;
	else if (this->baseBlock == block)return true;
	else return this->baseBlock->isSubBlockOf(block);
}

void BlockInfo::pushAvailableOffset(size_t offset)
{
	this->availableOffsets.push(offset);
}

size_t BlockInfo::getNextOffset()
{
	if (!this->availableOffsets.empty()) {
		size_t result = this->availableOffsets.top();
		this->availableOffsets.pop();
		return result;
	}
	else {
		return this->totalSymbolCount++;
	}
}

SymbolInfo::SymbolInfo()
{
}

void SymbolInfo::setPublicDomainInfo(size_t offset, DOMAIN_ID declareDomain, bool strictLocal)
{
	//如果已经在私有域中声明过，则不再声明
	if (this->privateDomainInfos.find(declareDomain) != this->privateDomainInfos.end())return;
	this->hasPublic = true;
	this->publicDomainInfo.setStrictLocal(strictLocal);
	this->publicDomainInfo.setOffset(offset);
	this->publicDomainInfo.addDeclareDomain(declareDomain);
}

size_t SymbolInfo::getPublicDomainOffset() const
{
	return this->publicDomainInfo.getOffset();
}

bool SymbolInfo::isPublicDomainStrictLocal() const
{
	return this->publicDomainInfo.isStrictLocal();
}

bool SymbolInfo::hasPublicDomainOffset() const
{
	return this->hasPublic;
}

bool SymbolInfo::getPrivateDomainOffset(DOMAIN_ID domain, size_t *outOffset) const
{
	auto it = this->privateDomainInfos.find(domain);
	if (it == this->privateDomainInfos.end()) {
		return false;
	}
	auto &info = it->second;
	*outOffset = info.getOffset();
	return true;
}

std::unordered_map<DOMAIN_ID, PrivateDomainInfo> SymbolInfo::getPrivateDomainInfos() const
{
	return this->privateDomainInfos;
}

void SymbolInfo::setPrivateDomainInfo(DOMAIN_ID domain, size_t offset,bool strictLocal)
{
	//如果已经在该域的公有部分声明过，则不要再声明。
	if (this->hasPublic && this->publicDomainInfo.containsDeclareDomain(domain))return;
	this->privateDomainInfos[domain].setOffset(offset);
	this->privateDomainInfos[domain].setStrictLocal(strictLocal);
}

void SymbolInfo::removeNonStrictLocalPrivateDomainInfo(DOMAIN_ID domain)
{
	if (this->privateDomainInfos[domain].isStrictLocal())return;
	else this->privateDomainInfos.erase(domain);
}

void SymbolInfo::removeNonStrictLocalPrivateDomainInfos()
{
	for (auto it = this->privateDomainInfos.begin(); it != this->privateDomainInfos.end();) {
		if (!it->second.isStrictLocal()) {
			this->privateDomainInfos.erase(it++);
		}
		else {
			++it;
		}
	}
}

size_t PrivateDomainInfo::getOffset() const
{
	return this->offset;
}

void PrivateDomainInfo::setOffset(size_t offset)
{
	this->offset = offset;
}

bool PrivateDomainInfo::isStrictLocal() const
{
	return this->strictLocal;
}

void PrivateDomainInfo::setStrictLocal(bool strictLocal)
{
	this->strictLocal = strictLocal;
}

size_t PublicDomainInfo::getOffset() const
{
	return this->offset;
}

void PublicDomainInfo::setOffset(size_t offset)
{
	this->offset = offset;
}

bool PublicDomainInfo::isStrictLocal() const
{
	return this->strictLocal;
}

void PublicDomainInfo::setStrictLocal(bool strictLocal)
{
	this->strictLocal = strictLocal;
}

void PublicDomainInfo::addDeclareDomain(DOMAIN_ID domain)
{
	if (!this->containsDeclareDomain(domain)) {
		this->declareDomains.push_back(domain);
	}
}

bool PublicDomainInfo::containsDeclareDomain(DOMAIN_ID domain) const
{
	return find(this->declareDomains.begin(), this->declareDomains.end(), domain) != this->declareDomains.end();
}
