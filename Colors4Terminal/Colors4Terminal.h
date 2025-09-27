#pragma once
#include "iostream"
#include "Windows.h"

namespace TCYK
{
	constexpr const char* Default_Color		=	"\033[0m";
	constexpr const char* Red_Color			=	"\033[31m";
	constexpr const char* Green_Color		=	"\033[32m";
	constexpr const char* Yellow_Color		=	"\033[33m";
	constexpr const char* Blue_Color		=	"\033[34m";

	
	//	Needs to be called at the start,
	//	to make sure virtual terminal is enabled.
	
	void EnableVirtualTerminal() 
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD dwMode = 0;
		GetConsoleMode(hOut, &dwMode);
		SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
	}

	std::string blinking(bool blink)
	{
		return blink ? "\033[5m" : "";
	}

	void ErrorMessage(const char* msg, bool blink = 0)
	{
		std::cout << Red_Color << blinking(blink) << msg << Default_Color << std::endl;
	}


}