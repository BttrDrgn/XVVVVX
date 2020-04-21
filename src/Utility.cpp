#include "Utility.h"
#include "filesystem.h"

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

namespace vvvvvv
{

	/*stoi or to_string doesn't exist pre C++11 (Xbox requires VC++ 6.0 or  Visual Studio 2003 to which I assume-
																						-uses C++98 or around there)*/
	int Utility::toInt(std::string string)
	{ 
		int retval = atoi(string.c_str());
		return retval;
	}

	std::string Utility::toString(int number)
	{
		char buffer [32];
		itoa(number, buffer, 10);
		std::string retval = Utility::charToString(buffer);
		return retval;
	}

	std::string Utility::charToString(char* a) 
	{ 
		int size = strlen(a);
		int i; 
		std::string s = ""; 
		for (i = 0; i < size; i++) { 
			s = s + a[i]; 
		} 
		return s; 
	} 

	std::string Utility::toString(SDL_GameControllerButton button)
	{
		switch (button)
		{
			case SDL_CONTROLLER_BUTTON_A:
				return "A";

			case SDL_CONTROLLER_BUTTON_B:
				return "B";
			
			case SDL_CONTROLLER_BUTTON_X:
				return "X";
			
			case SDL_CONTROLLER_BUTTON_Y:
				return "Y";

			case SDL_CONTROLLER_BUTTON_BACK:
				return "BACK";

			case SDL_CONTROLLER_BUTTON_GUIDE:
				return "GUIDE";

			case SDL_CONTROLLER_BUTTON_START:
				return "START";

			case SDL_CONTROLLER_BUTTON_LEFTSTICK:
				return "LS";

			case SDL_CONTROLLER_BUTTON_RIGHTSTICK:
				return "RS";

			case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
				return "WHITE";

			case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
				return "BLACK";

			default:
				fs::log("Unhandled button!");
				return NULL;
		}
	}

	std::string Utility::toString(std::vector<SDL_GameControllerButton> buttons)
	{
		std::string retval = "";
		for (size_t i = 0; i < buttons.size(); i += 1)
		{
			retval += toString(buttons[i]);
			if ((i + 1) < buttons.size())
			{
				retval += ",";
			}
		}
		return retval;
	}

	std::vector<std::string> Utility::split(const std::string &string, char delimiter)
	{
		std::vector<std::string> elems;
		std::stringstream ss(string);
		std::string item;

		while(std::getline(ss, item, delimiter))
		{
			elems.push_back(item);
		}

		return elems;
	}

	std::string Utility::twoDigits(int number)
	{
		if (number < 10)
		{
			return "0" + toString(number);
		}
		else if (number >= 100)
		{
			return "??";
		}

		return toString(number);
	}

	std::string Utility::timeString(int frames)
	{
		int remainder = frames % 30;
		int seconds = (frames - remainder) / 30;
		
		if (seconds < 60)
		{
			return toString(seconds) + ":" + twoDigits(remainder * 100 / 30);
		}

		int minutes = (seconds - seconds % 60) / 60;
		seconds = seconds % 60;
		return toString(minutes) + ":" + twoDigits(seconds) + ":" + twoDigits(remainder * 100 / 30);
	}

	std::string Utility::toWord(int number)
	{
		const int maxnum = 50;
		std::string words[] = {
			"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
			"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
			"Seventeen", "Eighteen", "Nineteen", "Twenty", "Twenty One", "Twenty Two",
			"Twenty Three", "Twenty Four", "Twenty Five", "Twenty Six", "Twenty Seven",
			"Twenty Eight", "Twenty Nine", "Thirty", "Thirty One", "Thirty Two",
			"Thirty Three", "Thirty Four", "Thirty Five", "Thirty Six", "Thirty Seven",
			"Thirty Eight", "Thirty Nine", "Forty Zero", "Forty One", "Forty Two",
			"Forty Three", "Forty Four", "Forty Five", "Forty Six", "Forty Seven",
			"Forty Eight", "Forty Nine", "Fifty"
		};

		if (number <= maxnum) {
			return words[number];
		}

		return "Lots";
	}

	bool Utility::intersects(SDL_Rect rect1, SDL_Rect rect2)
	{
		//Calculate the sides of rect 1
		int left1 = rect1.x;
		int right1 = rect1.x + rect1.w;
		int top1 = rect1.y;
		int bottom1 = rect1.y + rect1.h;

		//Calculate the sides of rect B
		int left2 = rect2.x;
		int right2 = rect2.x + rect2.w;
		int top2 = rect2.y;
		int bottom2 = rect2.y + rect2.h;

		return (bottom1 > top2 && top1 < bottom2 && right1 > left2 && left1 < right2);
	}

	void Utility::updateGlow()
	{
		slowSine++;
		if (slowSine >= 64) {
			slowSine = 0;
		}

		if (glowDir == 0) {
			glow += 2;
			if (glow >= 62) {
				glowDir = 1;
			}
		}
		else
		{
			glow -= 2;
			if (glow < 2) {
				glowDir = 0;
			}
		}
	}

	int Utility::glow = 0;
	int Utility::slowSine = 0;
	int Utility::glowDir = 0;
}
