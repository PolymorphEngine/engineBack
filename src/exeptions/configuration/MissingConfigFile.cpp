/*
** EPITECH PROJECT, 2020
** MissingConfigFile.cpp
** File description:
** header for MissingConfigFile.c
*/

#include "Engine/Exceptions/configuration/MissingConfigFile.hpp"

MissingConfigFile::MissingConfigFile(std::string fileName) : ConfigurationException("Missing file :"+fileName, Logger::MAJOR)
{}
