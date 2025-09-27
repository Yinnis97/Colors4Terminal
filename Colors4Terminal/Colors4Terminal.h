#pragma once
#include "iostream"
#include "sstream"
#include "Windows.h"


namespace CFT
{
	constexpr const char* Default_Color_Code	=	"\033[0m";
	constexpr const char* Error_Color_Code		=	"\033[31m";
	constexpr const char* Warning_Color_Code	=	"\033[38;2;255;160;0m";
	constexpr const char* Blinking_Code			=	"\033[5m";

	//	Needs to be called at the start.
	//	This makes sure the Virtual Terminal is Enabled.
	void EnableVirtualTerminal() 
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD dwMode = 0;
		GetConsoleMode(hOut, &dwMode);
		SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
	}


	// Show Error message by default :
	// Example : Error : "message".
	// Where "Error : " is red and "message" is default color.
	// 
	// Parameters :
	// Input 1 (const char*)	: The Error message.
	// Input 2 (bool)			: turn message in same color as Error color.
	// Input 3 (bool)			: turn blinking on or off.
	// Output (void)			: No return value.
	void ErrorMessage(const char* msg, bool C_msg = 0, bool blink = 0)
	{
		std::cout << Error_Color_Code 
			<< (blink ? Blinking_Code : "") 
			<< "Error : "
			<< (C_msg ? Error_Color_Code : Default_Color_Code) 
			<< msg 
			<< Default_Color_Code 
			<< std::endl;
	}


	// Show Warning message by default :
	// Example : Warning : "message".
	// Where Warning is red and message is default color.
	// 
	// Parameters :
	// Input 1 (const char*)	: The Warning message.
	// Input 2 (bool)			: turn message in same color as Warning color.
	// Input 3 (bool)			: turn blinking on or off.
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


}