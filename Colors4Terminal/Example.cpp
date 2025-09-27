
#include <iostream>
#include "Colors4Terminal.h"

int main()
{
	CFT::EnableVirtualTerminal();

	CFT::ErrorMessage("Message");
	CFT::ErrorMessage("Message in red", 1, 0);
	CFT::ErrorMessage("Error is blinking", 0, 1);

	CFT::WarningMessage("Message");
	CFT::WarningMessage("Message in orange", 1, 0);
	CFT::WarningMessage("Warning is blinking", 0, 1);

	CFT::ColorRGBMessage("RGB", 0, 50, 150);

	std::cin.get();

	return 0;
}


