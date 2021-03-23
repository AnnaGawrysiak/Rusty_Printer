#pragma once
#include <string>

class Printer
{
public:
	virtual ~Printer() = default;

	virtual std::string Print() const;
};

