#include "KeyPoll.h"
#include "Utility.h"
#include "filesystem.h"
#include <stdio.h>
#include <string.h>

void KeyPoll::setSensitivity(int _value)
{
	switch (_value)
	{
		case 0:
			sensitivity = 28000;
			break;
		case 1:
			sensitivity = 16000;
			break;
		case 2:
			sensitivity = 8000;
			break;
		case 3:
			sensitivity = 4000;
			break;
		case 4:
			sensitivity = 2000;
			break;
	}

}

KeyPoll::KeyPoll()
{
	xVel = 0;
	yVel = 0;
	setSensitivity(2);

	quitProgram = 0;
	textentrymode=true;
	keybuffer="";
	leftbutton=0; rightbutton=0; middlebutton=0;
	mx=0; my=0;
	resetWindow = 0;
	toggleFullscreen = false;
	pressedbackspace = false;

	useFullscreenSpaces = false;
}

void KeyPoll::enabletextentry()
{
	keybuffer = "";
	textentrymode = true;
	SDL_StartTextInput();
}

void KeyPoll::disabletextentry()
{
	textentrymode = false;
	SDL_StopTextInput();
}

void KeyPoll::Poll()
{
	SDL_Event evt;
	while (SDL_PollEvent(&evt))
	{
		//fs::slog("Event: " + vvvvvv::Utility::toString(evt.type) + "\n");

		/* Controller Input */

		//DPAD Events?
		if (evt.type == 1538)
		{
			//buttonmap[(SDL_GameControllerButton) evt.cbutton.button] = true;
		}
		//Button Down
		else if (evt.type == 1539)
		{
			buttonmap[(SDL_GameControllerButton) evt.cbutton.button] = true;
		}
		//Button Up
		else if (evt.type == 1540)
		{
			buttonmap[(SDL_GameControllerButton) evt.cbutton.button] = false;
		}
		//Joystick
		else if (evt.type == 1536)
		{
			if (evt.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX)
			{
				if (	evt.caxis.value > -sensitivity &&
					evt.caxis.value < sensitivity	)
				{
					xVel = 0;
				}
				else
				{
					xVel = (evt.caxis.value > 0) ? 1 : -1;
				}
			}
			if (evt.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY)
			{
				if (	evt.caxis.value > -sensitivity &&
					evt.caxis.value < sensitivity	)
				{
					yVel = 0;
				}
				else
				{
					yVel = (evt.caxis.value > 0) ? 1 : -1;
				}
			}
		}
		else if (evt.type == SDL_CONTROLLERDEVICEADDED)
		{
			SDL_GameController *toOpen = SDL_GameControllerOpen(evt.cdevice.which);

			//fs::slog("Opened SDL_GameController ID #" + evt.cdevice.which + SDL_GameControllerName(toOpen) + "\n");

			controllers[SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(toOpen))] = toOpen;
		}
		else if (evt.type == SDL_CONTROLLERDEVICEREMOVED)
		{
			SDL_GameController *toClose = controllers[evt.cdevice.which];
			controllers.erase(evt.cdevice.which);

			//fs::slog("Closing " + SDL_GameControllerName(toClose) + "\n");

			SDL_GameControllerClose(toClose);
		}

		/* Quit Event (we never use this on the xbox) */
		else if (evt.type == SDL_QUIT)
		{
			quitProgram = true;
		}
	}
}

bool KeyPoll::isDown(SDL_Keycode key)
{
	return keymap[key];
}

bool KeyPoll::isUp(SDL_Keycode key)
{
	return !keymap[key];
}

bool KeyPoll::isDown(std::vector<SDL_GameControllerButton> buttons)
{
	for (size_t i = 0; i < buttons.size(); i += 1)
	{
		if (buttonmap[buttons[i]])
		{
			return true;
		}
	}
	return false;
}

bool KeyPoll::isDown(SDL_GameControllerButton button)
{
	return buttonmap[button];
}

bool KeyPoll::controllerButtonDown()
{
	for (
		SDL_GameControllerButton button = SDL_CONTROLLER_BUTTON_A;
		button < SDL_CONTROLLER_BUTTON_DPAD_UP;
		button = (SDL_GameControllerButton) (button + 1)
	) {
		if (isDown(button))
		{
			return true;
		}
	}
	return false;
}

bool KeyPoll::controllerWantsLeft(bool includeVert)
{
	return (	buttonmap[SDL_CONTROLLER_BUTTON_DPAD_LEFT] ||
			xVel < 0 ||
			(	includeVert &&
				(	buttonmap[SDL_CONTROLLER_BUTTON_DPAD_UP] ||
					yVel < 0	)	)	);
}

bool KeyPoll::controllerWantsRight(bool includeVert)
{
	return (	buttonmap[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] ||
			xVel > 0 ||
			(	includeVert &&
				(	buttonmap[SDL_CONTROLLER_BUTTON_DPAD_DOWN] ||
					yVel > 0	)	)	);
}
