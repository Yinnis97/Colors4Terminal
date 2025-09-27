
#include <iostream>
#include "Colors4Terminal.h"

int main()
{
	TCYK::EnableVirtualTerminal();

	TCYK::ErrorMessage("Error message");
	TCYK::ErrorMessage("Error message", 1, 0);
	TCYK::ErrorMessage("Error message", 0, 1);

	TCYK::WarningMessage("Warning message");
	TCYK::WarningMessage("Warning message", 1, 0);
	TCYK::WarningMessage("Warning message", 0, 1);

	TCYK::ColorRGBMessage("RGB", 0, 50, 150);

	std::cin.get();

	return 0;
}


