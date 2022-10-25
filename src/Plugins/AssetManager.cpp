/*
** EPITECH PROJECT, 2020
** AssetManager.cpp
** File description:
** header for AssetManager.c
*/

#include <filesystem>
#include "Plugins/AssetManager.hpp"

std::string AssetManager::tryResolve(const std::string &resource)
{
    for (auto &folder: _assetsFolders) {
        std::string path = folder + "/" + resource;
        if (std::filesystem::exists(path))
            return path;
    }
    return "";
}

void AssetManager::addPath(const std::string &path)
{
    _assetsFolders.push_back(path);
}
