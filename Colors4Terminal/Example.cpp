
#include <iostream>
#include "Colors4Terminal.h"

int main()
{
	CFT::EnableVirtualTerminal();
	std::cout << "Does my terimnal support Ansi ? " << (CFT::SupportsANSI() ? "Yes! " : "Nope! ") << std::endl;

	// Error messages
	CFT::ErrorMessage("Message");
	CFT::ErrorMessage("Message in red", 1, 0, 0);
	CFT::ErrorMessage("Error is blinking", 0, 0, 1);
	//CFT::ErrorMessage("Error makes a bell sound", 0, 1, 0);

	// Warning Messages
	CFT::WarningMessage("Message");
	CFT::WarningMessage("Message in orange", 1, 0);
	CFT::WarningMessage("Warning is blinking", 0, 1);

	// Color the message
	CFT::Color c{ 5,80,150 };
	CFT::ColorMessage("RGB using r,g,b values", 5, 80, 150);
	CFT::ColorMessage("RGB using struct", c);
	CFT::ColorMessage("RGB using defined colors", CFT::COLOR::BLUE);

	// Color the text and background.
	CFT::Color cc{ 0,255,0 };
	CFT::ColorAll("Color everything using structs", c, cc);
	CFT::ColorAll("Color everything using defined colors", CFT::COLOR::RED, CFT::COLOR::GREEN);

	// Generate your own color.
	CFT::Color ccc{ 255,0,25 };
	std::cout << CFT::GenerateColorText(ccc) << "Text color using Color struct as input" << CFT::COLOR::DEFAULT << std::endl;
	std::cout << CFT::GenerateColorText(255, 0, 25) << "Text color using r, g, and b values as input" << CFT::COLOR::DEFAULT << std::endl;

	std::cout << CFT::GenerateColorBackground(ccc) << "Background color using Color struct as input" << CFT::COLOR::DEFAULT << std::endl;
	std::cout << CFT::GenerateColorBackground(255, 0, 25) << "Background color using r,g and b values as input" << CFT::COLOR::DEFAULT << std::endl;
	
	// Make your own combination.
	std::cout << CFT::STYLE::UNDERLINE	<< "underline"		<< CFT::COLOR::DEFAULT << std::endl;
	std::cout << CFT::STYLE::ITALIC		<< "italic"			<< CFT::COLOR::DEFAULT << std::endl;
	std::cout << CFT::STYLE::CROSSED	<< "crossed out"	<< CFT::COLOR::DEFAULT << std::endl;
	std::cout << CFT::STYLE::BOLD		<< "bold"			<< CFT::COLOR::DEFAULT << std::endl;

	std::cout << CFT::COLOR::BLUE		<< "Blue"			<< CFT::COLOR::DEFAULT << std::endl;
	std::cout << CFT::COLOR::GREEN		<< "Green"			<< CFT::COLOR::DEFAULT << std::endl;
	std::cout << CFT::COLOR::RED		<< "Red"			<< CFT::COLOR::DEFAULT << std::endl;
	std::cout << CFT::COLOR::ORANGE		<< "Orange"			<< CFT::COLOR::DEFAULT << std::endl;
	std::cout << CFT::COLOR::YELLOW		<< "Yellow"			<< CFT::COLOR::DEFAULT << std::endl;
	std::cout << CFT::COLOR::PURPLE		<< "Purple"			<< CFT::COLOR::DEFAULT << std::endl;

	return 0;
}


