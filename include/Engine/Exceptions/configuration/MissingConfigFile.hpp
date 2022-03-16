/*
** EPITECH PROJECT, 2020
** MissingConfigFile.hpp
** File description:
** header for MissingConfigFile.c
*/

#ifndef ENGINE_MISSINGCONFIGFILE_HPP
#define ENGINE_MISSINGCONFIGFILE_HPP


#include "ConfigurationException.hpp"

class MissingConfigFile : public ConfigurationException
{
///////////////////////////////// Constructors /////////////////////////////////

    public:
        explicit MissingConfigFile(std::string fileName);

///////////////////////////--------------------------///////////////////////////

};


#endif //ENGINE_MISSINGCONFIGFILE_HPP
