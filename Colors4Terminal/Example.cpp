
#include <iostream>
#include "Colors4Terminal.h"

int main()
{
	CFT::EnableVirtualTerminal();

	CFT::ErrorMessage("Message");
	CFT::ErrorMessage("Message in red", 1, 0, 0);
	CFT::ErrorMessage("Error is blinking", 0, 0, 1);
	CFT::ErrorMessage("Error makes a bell sound", 0, 1, 0);

	CFT::WarningMessage("Message");
	CFT::WarningMessage("Message in orange", 1, 0);
	CFT::WarningMessage("Warning is blinking", 0, 1);

	CFT::ColorRGBMessage("RGB", 0, 50, 150);

	CFT::Color color_background{ 40,150,0 };
	CFT::Color color_text{ 100,0,250 };
	CFT::ColorAll("Color All : text and background", &color_background, &color_text);


	// Returning strings

	std::cout << CFT::ColorToTextString(&color_text) << "Example Text" << CFT::ANSI_CODE::DefaultColor << std::endl;
	std::cout << CFT::ColorToBackgroundString(&color_text) << "Example Background" << CFT::ANSI_CODE::DefaultColor << std::endl;

	
	std::cout << CFT::ANSI_CODE::Underline << "underline" << CFT::ANSI_CODE::DefaultColor << std::endl;
	std::cout << CFT::ANSI_CODE::Italic << "italic" << CFT::ANSI_CODE::DefaultColor << std::endl;
	std::cout << CFT::ANSI_CODE::CrossedOut << "crossed out" << CFT::ANSI_CODE::DefaultColor << std::endl;

	return 0;
}


