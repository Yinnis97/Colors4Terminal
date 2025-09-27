#pragma once
#include "iostream"
#include "sstream"
#include "Windows.h"


namespace CFT
{
	// Struct color to make things easier.
	typedef struct Color
	{
		int r;
		int g;
		int b;
	};

	// Constexpr for color codes that get used a lot.
	constexpr const char* Default_Color_Code	=	"\033[0m";
	constexpr const char* Error_Color_Code		=	"\033[31m";
	constexpr const char* Warning_Color_Code	=	"\033[38;2;255;160;0m";
	constexpr const char* Blinking_Code			=	"\033[5m";
	constexpr const char* CrossedOut_Code		=	"\033[9m";
	constexpr const char* BellNoise_Code		=	"\a";

	// **************************
	// ******* FUNCTIONS ********
	// **************************


	// Needs to be called at the start.
	// This makes sure the Virtual Terminal is Enabled.

	void EnableVirtualTerminal() 
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD dwMode = 0;
		GetConsoleMode(hOut, &dwMode);
		SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
	}

	bool SupportsANSI() 
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hOut == INVALID_HANDLE_VALUE) return false;

		DWORD dwMode = 0;
		if (!GetConsoleMode(hOut, &dwMode)) return false;

		return (dwMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING);
	}

	// Show Error message by default :
	// Example : Error : "message".
	// Where "Error : " is red and "message" is default color.
	// 
	// Parameters :
	// Input 1 (const char*)	: The Error message.
	// Input 2 (bool)			: Turn message in same color as Error color.
	// Input 3 (bool)			: Makes a sound as well as a msg.
	// Input 4 (bool)			: Turn blinking on or off.
	// Output (void)			: No return value.

	void ErrorMessage(const char* msg, bool C_msg = 0, bool b_noise = 0, bool blink = 0)
	{
		std::cout << Error_Color_Code
			<< (blink ? Blinking_Code : "")
			<< "Error : "
			<< (C_msg ? Error_Color_Code : Default_Color_Code)
			<< msg
			<< (b_noise ? BellNoise_Code : "")
			<< Default_Color_Code 
			<< std::endl;
	}


	// Show Warning message by default :
	// Example : Warning : "message".
	// Where Warning is red and message is default color.
	// 
	// Parameters :
	// Input 1 (const char*)	: The Warning message.
	// Input 2 (bool)			: Turn message in same color as Warning color.
	// Input 3 (bool)			: Turn blinking on or off.
	// Output (void)			: No return value.

	void WarningMessage(const char* msg, bool C_msg = 0, bool blink = 0)
	{ 
		std::cout << Warning_Color_Code 
			<< (blink ? Blinking_Code : "") 
			<< "Warning : "
			<< (C_msg ? Warning_Color_Code : Default_Color_Code) 
			<< msg 
			<< Default_Color_Code 
			<< std::endl;
	}


	// Show a message in specific rgb colors.
	// Default all values are set to 0.
	// 
	// Parameters :
	// Input 1 (const char*)	: The message.
	// Input 2 (int)			: The value for R (red).
	// Input 3 (int)			: The value for G (Green).
	// Input 4 (int)			: The value for B (Blue).

	void ColorRGBMessage(const char* msg, int r = 0, int g = 0, int b = 0)
	{
		std::stringstream rgb_ss;
		rgb_ss << "\033[38;2;" << r << ";" << g << ";" << b << "m";

		std::cout << rgb_ss.str() 
			<< msg 
			<< Default_Color_Code 
			<< std::endl;
	}


	// Shows the message and background in specific rgb colors.
	// 
	// Parameters :
	// Input 1 (const char*)	: The message.
	// Input 2 (Color*)			: The rgb values for the background.
	// Input 3 (Color*)			: The rgb values for the text.

	void ColorAll(const char* msg, Color* bg, Color* text)
	{
		std::stringstream text_ss;
		std::stringstream bg_ss;
		text_ss << "\033[38;2;" << text->r << ";" << text->g << ";" << text->b << "m";
		bg_ss << "\033[48;2;" << bg->r << ";" << bg->g << ";" << bg->b << "m";

		std::cout << text_ss.str() 
			<< bg_ss.str()
			<< msg
			<< Default_Color_Code
			<< std::endl;
	}



	// Instead of printing messages directly, we can return the correct string for any color.
	// This allows you to create custom combinations by chainning multiple string together.
	// 
	// Example :
	// std::cout << ColorToTextString(&color) << ColorToBackgroundString(&color)
	//			 << "This will change both the text and background color" 
	//			 << Default_Color_Code << std::endl;
	// 
	// Important :
	// Always use Default_Color_Code at the end to reset everything.


	// Parameters : 
	// Input 1 (Color*)			: The rgb values for the string.
	// Output 1 (std::string)	: The string for the text color values from input 1.
	
	std::string ColorToTextString(Color* color)
	{
		std::stringstream rgb_ss;
		rgb_ss << "\033[38;2;" << color->r << ";" << color->g << ";" << color->b << "m";

		return rgb_ss.str();
	}


	// Parameters : 
	// Input 1 (Color*)			: The rgb values for the string.
	// Output 1 (std::string)	: The string for the background color values from input 1.

	std::string ColorToBackgroundString(Color* color)
	{
		std::stringstream rgb_ss;
		rgb_ss << "\033[48;2;" << color->r << ";" << color->g << ";" << color->b << "m";

		return rgb_ss.str();
	}


}