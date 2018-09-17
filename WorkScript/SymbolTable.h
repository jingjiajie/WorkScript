#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include "CompileDomain.h"

typedef size_t BLOCK_ID;

class PrivateDomainInfo {
public:
	size_t getOffset()const;
	void setOffset(size_t offset);
	bool isStrictLocal()const;
	void setStrictLocal(bool strictLocal);
private:
	size_t offset;
	bool strictLocal = false;
};

class PublicDomainInfo {
public:
	size_t getOffset()const;
	void setOffset(size_t offset);
	bool isStrictLocal()const;
	void setStrictLocal(bool strictLocal);

	void addDeclareDomain(DOMAIN_ID domain);
	bool containsDeclareDomain(DOMAIN_ID domain)const;
private:
	size_t offset;
	bool strictLocal = false;
	std::vector<DOMAIN_ID> declareDomains;
};

class SymbolInfo {
public:
	SymbolInfo();
	bool getPrivateDomainOffset(DOMAIN_ID domain, size_t *outOffset)const;
	std::unordered_map<DOMAIN_ID, PrivateDomainInfo> getPrivateDomainInfos() const;
	void setPrivateDomainInfo(DOMAIN_ID domain, size_t offset, bool strictLocal);
	void removeNonStrictLocalPrivateDomainInfo(DOMAIN_ID domain);
	void removeNonStrictLocalPrivateDomainInfos();
	void setPublicDomainInfo(size_t offset, DOMAIN_ID declareDomain, bool strictLocal);
	size_t getPublicDomainOffset()const;
	bool isPublicDomainStrictLocal() const;
	bool hasPublicDomainOffset() const;
private:
	std::unordered_map<DOMAIN_ID, PrivateDomainInfo> privateDomainInfos;
	PublicDomainInfo publicDomainInfo;
	bool hasPublic = false;
};

class BlockInfo {
public:
	std::unordered_map<std::wstring, SymbolInfo> getSymbolInfos() const;
	bool getLocalSymbolOffset(DOMAIN_ID domain, const wchar_t *varName, size_t *outOffset);
	void setSymbolInfo(DOMAIN_ID domain, DomainAccess access, const wchar_t *varName, bool strictLocal = false);
	void removeNonStrictLocalSymbols(const wchar_t *varName);
	void removeNonStrictPrivateLocalSymbol(const wchar_t *varName, DOMAIN_ID domain);

	size_t getTotalSymbolCount()const;

	void setBaseBlock(BlockInfo *base);
	BlockInfo *getBaseBlock()const;

	BLOCK_ID getBlockID() const;
	void setBlockID(BLOCK_ID id);

	bool isSubBlockOf(BlockInfo *block)const;
private:
	void pushAvailableOffset(size_t offset);
	size_t getNextOffset();

	std::unordered_map<std::wstring, SymbolInfo> symbolInfos;
	size_t totalSymbolCount = 0;
	std::stack<size_t> availableOffsets;

	BlockInfo *baseBlock;
	BLOCK_ID id;
};

class SymbolTable
{
public:
	SymbolTable();
	~SymbolTable();

	bool getLocalSymbolOffset(BLOCK_ID block, DOMAIN_ID domain, const wchar_t *varName, BLOCK_ID *outBlockID,size_t *outOffset);
	bool getBaseSymbolOffset(BLOCK_ID block, DOMAIN_ID domain, const wchar_t *varName,BLOCK_ID *outBlockID, size_t *outOffset);
	bool getSymbolOffset(BLOCK_ID block, DOMAIN_ID domain, const wchar_t *varName, BLOCK_ID *outBlockID, size_t *outOffset);

	void setSymbolInfo(BLOCK_ID block, DOMAIN_ID domain, DomainAccess access, const wchar_t *varName, bool strictLocal = false);
	void setBaseBlock(BLOCK_ID curBlock, BLOCK_ID baseBlock);
	BLOCK_ID newBlock(BLOCK_ID baseBlock);
	BLOCK_ID newBlock();

	size_t getTotalSymbolCount(BLOCK_ID block)const;

	void print() const;
private:
	std::unordered_map<BLOCK_ID,BlockInfo> blockInfos;
	size_t blockCount = 0;
};