#pragma once
#include <unordered_map>
#include <string>

typedef size_t DOMAIN_ID;

enum class DomainAccess : unsigned char {
	PUBLIC, PRIVATE
};