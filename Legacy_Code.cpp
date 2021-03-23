// Legacy_Code.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "Printer.h"
#include "RustyPrinter.h"

class Adapter : public Printer
{
	RustyPrinter* rust;

public:

	Adapter(RustyPrinter* rusty)
	{
		rust = rusty;
	}

	std::string Print() const override
	{
		std::string text = rust->OldStylePrint();

		std::reverse(text.begin(), text.end()); // reverse nic nie zwraca

		return text;
	}

};

void ClientCode(const Printer *target)
{
	std::cout << target->Print() << std::endl;
}

int main()
{
	Printer* ClassicPrinter = new Printer;
	ClientCode(ClassicPrinter);

	RustyPrinter* OldPrinter = new RustyPrinter;

	Adapter* transformer = new Adapter(OldPrinter);

	ClientCode(transformer);

	delete ClassicPrinter;
	delete OldPrinter;

	return 0;
}
