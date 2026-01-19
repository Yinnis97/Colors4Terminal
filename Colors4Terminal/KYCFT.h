#pragma once
#include "iostream"
#include "sstream"
#ifdef _WIN32
#include "Windows.h"
#endif

namespace CFT
{
	namespace STYLE
	{
		constexpr const char* BLINK = "\033[5m";
		constexpr const char* CROSSED = "\033[9m";
		constexpr const char* ITALIC = "\033[3m";
		constexpr const char* UNDERLINE = "\033[4m";
		constexpr const char* BOLD = "\033[1m";
		constexpr const char* BELLNOISE = "\a";
	}

	namespace COLOR
	{
		constexpr const char* DEFAULT = "\033[0m";
		constexpr const char* RED = "\033[38;2;255;0;0m";
		constexpr const char* ORANGE = "\033[38;2;255;150;0m";
		constexpr const char* BLUE = "\033[38;2;5;80;150m";
		constexpr const char* GREEN = "\033[38;2;0;255;0m";
		constexpr const char* YELLOW = "\033[38;2;255;255;0m";
		constexpr const char* PURPLE = "\033[38;2;75;0;150m";
	}

	/********************************************************************************************/
	// Can be called at the start.
	// This makes sure the Virtual Terminal is Enabled.

	inline void EnableVirtualTerminal()
	{
#ifdef _WIN32
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD dwMode = 0;
		GetConsoleMode(hOut, &dwMode);
		SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
	}

	inline bool SupportsANSI()
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
	// Helper function to return only the file name not the entire path.
	namespace impl
	{
		inline const char* _GetFileName(const char* path)
		{
			const char* file = path;
			while (*path)
			{
				if (*path++ == '/' || *(path - 1) == '\\')
				{
					file = path;
				}
			}
			return file;
		}
	}

	/********************************************************************************************/
	// Show Error message by default :
	// Example : Error : "message".
	// Where "Error : " is red and "message" is default color.

	// Parameters :
	// Input 1 (const char*)	: The Error message.
	inline void _ErrorMessage(const char* msg, const char* file, int line)
	{
		std::cout << COLOR::RED
			<< "Error [" << impl::_GetFileName(file) << ":" << line << "] : "
			<< COLOR::DEFAULT
			<< msg
			<< std::endl;
	}
#define ErrorMessage(msg) _ErrorMessage(msg, __FILE__, __LINE__)

	/********************************************************************************************/
	// Show Warning message by default :
	// Example : Warning : "message".
	// Where Warning is red and message is default color.

	// Parameters :
	// Input 1 (const char*)	: The Warning message.
	inline void _WarningMessage(const char* msg, const char* file, int line)
	{
		std::cout << COLOR::ORANGE
			<< "Warning [" << impl::_GetFileName(file) << ":" << line << "] : "
			<< COLOR::DEFAULT
			<< msg
			<< std::endl;
	}
#define WarningMessage(msg) _WarningMessage(msg, __FILE__, __LINE__)

	/********************************************************************************************/
	// Show Warning message by default :
	// Example : Warning : "message".
	// Where Warning is red and message is default color.

	// Parameters :
	// Input 1 (const char*)	: The Debug message.
	inline void _DebugMessage(const char* msg,const char* file, int line)
	{
		std::cout << COLOR::BLUE
			<< "Debug [" << impl::_GetFileName(file) << ":" << line << "] : "
			<< COLOR::DEFAULT
			<< msg
			<< std::endl;
	}
#define DebugMessage(msg) _DebugMessage(msg, __FILE__, __LINE__)

	/********************************************************************************************/
	// Show a message in specific rgb colors.
	// Default all values are set to 0.

	// Parameters :
	// Input 1 (const char*)	: The message.
	// Input 2 (Const char*)	: The color.
	inline void _ColorMessage(const char* msg, const char* COLOR)
	{
		std::cout << COLOR
			<< msg
			<< COLOR::DEFAULT
			<< std::endl;
	}
#define ColorMessage(msg,color) _ColorMessage(msg,color)

} // End namespace CFT