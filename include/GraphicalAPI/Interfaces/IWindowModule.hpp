/*
** EPITECH PROJECT, 2020
** IWindowModule
** File description:
** header for IWindowModule.cpp
*/

#pragma once

#include <string>

namespace Polymorph
{
	class IWindowModule
	{
		public:
			virtual ~IWindowModule() = default;

			virtual void close() = 0;
			virtual bool isOpen() = 0;
			virtual bool isFullscreen() = 0;
			virtual void setFullscreen(bool fullscreen) = 0;
			virtual void setTitle(const std::string &title) = 0;
            virtual void setLogLevel(int level) = 0;
	};

}