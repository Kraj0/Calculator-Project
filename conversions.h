#pragma once
#include "pch.h"
#include <string>
#define _AFXDLL

class Conversions
{
public:
	std::string binary2decimal(const std::string& bin);
	std::string oct2decimal(const std::string& oct);
	std::string hex2decimal(const std::string& hex);

	std::string decimal2binary(const std::string& dec);
	std::string decimal2oct(const std::string& dec);
	std::string decimal2hex(const std::string& dec);
};