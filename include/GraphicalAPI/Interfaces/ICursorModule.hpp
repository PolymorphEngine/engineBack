/*
** EPITECH PROJECT, 2020
** ICursorModule
** File description:
** header for ICursorModule.cpp
*/

#pragma once

namespace Polymorph
{
	class ICursorModule
	{
		public:
			virtual ~ICursorModule() = default;

			virtual bool isOnScreen() = 0;
			virtual int getMouseX() = 0;
			virtual int getMouseY() = 0;
	};

}