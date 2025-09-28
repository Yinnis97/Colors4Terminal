#pragma once
#include "iostream"
#include "sstream"
#ifdef _WIN32
#include "Windows.h"
#endif

namespace CFT
{
	typedef struct Color
	{
		int r;
		int g;
		int b;
	};
	
	namespace STYLE
	{
		constexpr const char* BLINK				 = "\033[5m";
		constexpr const char* CROSSED			 = "\033[9m";
		constexpr const char* ITALIC			 = "\033[3m";
		constexpr const char* UNDERLINE			 = "\033[4m";
		constexpr const char* BOLD				 = "\033[1m";
		constexpr const char* BELLNOISE			 = "\a";
	}

#ifdef _WIN32
	namespace STYLE_W
	{
		constexpr LPCWSTR BLINK					 = L"\033[5m";
		constexpr LPCWSTR CROSSED				 = L"\033[9m";
		constexpr LPCWSTR ITALIC				 = L"\033[3m";
		constexpr LPCWSTR UNDERLINE				 = L"\033[4m";
		constexpr LPCWSTR BOLD					 = L"\033[1m";
		constexpr LPCWSTR BELLNOISE				 = L"\a";
	}
#endif

	namespace COLOR
	{
		constexpr const char* DEFAULT			 = "\033[0m";
		constexpr const char* RED				 = "\033[38;2;255;0;0m";
		constexpr const char* ORANGE			 = "\033[38;2;255;150;0m";
		constexpr const char* BLUE				 = "\033[38;2;5;80;150m";
		constexpr const char* GREEN				 = "\033[38;2;0;255;0m";
		constexpr const char* YELLOW			 = "\033[38;2;255;255;0m";
		constexpr const char* PURPLE			 = "\033[38;2;75;0;150m";
	}

#ifdef _WIN32
	namespace COLOR_W
	{
		constexpr LPCWSTR DEFAULT				 = L"\033[0m";
		constexpr LPCWSTR RED					 = L"\033[38;2;255;0;0m";
		constexpr LPCWSTR ORANGE				 = L"\033[38;2;255;150;0m";
		constexpr LPCWSTR BLUE					 = L"\033[38;2;5;80;150m";
		constexpr LPCWSTR GREEN					 = L"\033[38;2;0;255;0m";
		constexpr LPCWSTR YELLOW				 = L"\033[38;2;255;255;0m";
		constexpr LPCWSTR PURPLE				 = L"\033[38;2;75;0;150m";
	}
#endif



	// **************************
	// ******* FUNCTIONS ********
	// **************************

	/********************************************************************************************/
	// Needs to be called at the start.
	// This makes sure the Virtual Terminal is Enabled.

	void EnableVirtualTerminal() 
	{
#ifdef _WIN32
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD dwMode = 0;
		GetConsoleMode(hOut, &dwMode);
		SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
	}

	bool SupportsANSI() 
	{
#ifdef _WIN32
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hOut == INVALID_HANDLE_VALUE) return false;

		DWORD dwMode = 0;
		if (!GetConsoleMode(hOut, &dwMode)) return false;

		return (dwMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#else
		return true;
#endif
	}


	/********************************************************************************************/
	// Show Error message by default :
	// Example : Error : "message".
	// Where "Error : " is red and "message" is default color.
	
	// Parameters :
	// Input 1 (const char*)	: The Error message.
	// Input 2 (bool)			: Turn message in same color as Error color.
	// Input 3 (bool)			: Makes a sound as well as a msg.
	// Input 4 (bool)			: Turn blinking on or off.
	// Output (void)			: No return value.
	void ErrorMessage(const char* msg, bool C_msg = 0, bool b_noise = 0, bool blink = 0)
	{
		std::cout << COLOR::RED
			<< (blink ? STYLE::BLINK : "")
			<< "Error : "
			<< (C_msg ? COLOR::RED : COLOR::DEFAULT)
			<< msg
			<< (b_noise ? STYLE::BELLNOISE : "")
			<< COLOR::DEFAULT
			<< std::endl;
	}

#ifdef _WIN32
	// Parameters :
	// Input 1 (LPCWSTR)		: The Error message. (UTF-16)
	// Input 2 (bool)			: Turn message in same color as Error color.
	// Input 3 (bool)			: Makes a sound as well as a msg.
	// Input 4 (bool)			: Turn blinking on or off.
	// Output (void)			: No return value.
	void ErrorMessage(LPCWSTR  msg, bool C_msg = 0, bool b_noise = 0, bool blink = 0)
	{
		std::wcout << COLOR_W::RED
			<< (blink ? STYLE_W::BLINK : L"")
			<< L"Error : "
			<< (C_msg ? COLOR_W::RED : COLOR_W::DEFAULT)
			<< msg
			<< (b_noise ? STYLE_W::BELLNOISE : L"")
			<< COLOR_W::DEFAULT
			<< std::endl;
	}
#endif

	/********************************************************************************************/
	// Show Warning message by default :
	// Example : Warning : "message".
	// Where Warning is red and message is default color.
	
	// Parameters :
	// Input 1 (const char*)	: The Warning message.
	// Input 2 (bool)			: Turn message in same color as Warning color.
	// Input 3 (bool)			: Turn blinking on or off.
	// Output (void)			: No return value.
	void WarningMessage(const char* msg, bool C_msg = 0, bool blink = 0)
	{ 
		std::cout << COLOR::ORANGE
			<< (blink ? STYLE::BLINK : "")
			<< "Warning : "
			<< (C_msg ? COLOR::ORANGE : COLOR::DEFAULT)
			<< msg 
			<< COLOR::DEFAULT
			<< std::endl;
	}

#ifdef _WIN32
	// Parameters :
	// Input 1 (LPCWSTR)		: The Warning message. (UTF-16)
	// Input 2 (bool)			: Turn message in same color as Warning color.
	// Input 3 (bool)			: Turn blinking on or off.
	// Output (void)			: No return value.
	void WarningMessage(LPCWSTR msg, bool C_msg = 0, bool blink = 0)
	{
		std::wcout << COLOR_W::ORANGE
			<< (blink ? STYLE_W::BLINK : L"")
			<< L"Warning : "
			<< (C_msg ? COLOR_W::ORANGE : COLOR_W::DEFAULT)
			<< msg
			<< COLOR_W::DEFAULT
			<< std::endl;
	}
#endif

	/********************************************************************************************/
	// Show a message in specific rgb colors.
	// Default all values are set to 0.
	
	// Parameters :
	// Input 1 (const char*)	: The message.
	// Input 2 (Color&)			: The color struct.
	void ColorMessage(const char* msg, Color& color)
	{
		std::stringstream rgb_ss;
		rgb_ss << "\033[38;2;" << color.r << ";" << color.g << ";" << color.b << "m";

		std::cout << rgb_ss.str()
			<< msg
			<< COLOR::DEFAULT
			<< std::endl;
	}

	// Parameters :
	// Input 1 (const char*)	: The message.
	// Input 2 (Const char*)	: The color.
	void ColorMessage(const char* msg, const char* COLOR)
	{
		std::cout << COLOR
			<< msg
			<< COLOR::DEFAULT
			<< std::endl;
	}

#ifdef _WIN32
	// Parameters :
	// Input 1 (LPCWSTR)		: The message.
	// Input 2 (Color&)			: The color struct.
	void ColorMessage(LPCWSTR msg, Color& color)
	{
		std::wcout << L"\033[38;2;"
			<< color.r << L";" << color.g << L";" << color.b << L"m"
			<< msg
			<< COLOR_W::DEFAULT
			<< std::endl;
	}

	// Parameters :
	// Input 1 (LPCWSTR)		: The message. (UTF-16)
	// Input 2 (LPCWSTR)		: The color.
	void ColorMessage(LPCWSTR msg, LPCWSTR COLOR)
	{
		std::wcout << COLOR
			<< msg
			<< COLOR_W::DEFAULT
			<< std::endl;
	}
#endif

	/********************************************************************************************/
	// Instead of printing messages directly, we can return the correct string for any color.
	// This allows you to create custom combinations by chainning multiple strings together.
	// 
	// Example :
	// std::cout << ColorToTextString(&color) << ColorToBackgroundString(&color)
	//			 << "This will change both the text and background color" 
	//			 << Default_Color_Code << std::endl;
	// 
	// Important :
	// Always use Default_Color_Code at the end to reset everything.
	
	// Parameters : 
	// Input 1 (Color* || int,int,int)		: The rgb values for the string.
	// Output 1 (std::string)				: The string for the text color values from input 1.
	std::string GenerateColorText(Color& color)
	{
		std::stringstream rgb_ss;
		rgb_ss << "\033[38;2;" << color.r << ";" << color.g << ";" << color.b << "m";

		return rgb_ss.str();
	}


	/********************************************************************************************/
	// Parameters : 
	// Input 1 (Color*)							: The rgb values for the string.
	// Output 1 (std::string)					: The string for the background color values from input 1.
	std::string GenerateColorBackground(Color& color)
	{
		std::stringstream rgb_ss;
		rgb_ss << "\033[48;2;" << color.r << ";" << color.g << ";" << color.b << "m";

		return rgb_ss.str();
	}


	/********************************************************************************************/
}