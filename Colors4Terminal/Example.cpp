
#include <iostream>
#include "Colors4Terminal.h"

int main()
{
	TCYK::EnableVirtualTerminal();

	TCYK::ErrorMessage("Message");
	TCYK::ErrorMessage("Message in red", 1, 0);
	TCYK::ErrorMessage("Error is blinking", 0, 1);

	TCYK::WarningMessage("Message");
	TCYK::WarningMessage("Message in orange", 1, 0);
	TCYK::WarningMessage("Warning is blinking", 0, 1);

	TCYK::ColorRGBMessage("RGB", 0, 50, 150);

	std::cin.get();

	return 0;
}


