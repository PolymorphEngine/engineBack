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
        if (std::filesystem::exists(path) && !std::filesystem::is_directory(path))
            return path;
    }
    return "";
}

void AssetManager::addPath(const std::string &path)
{
    std::string p;
    if (path[path.size() - 1] == '/')
        p = path.substr(0, path.size() - 1);
    else
        p = path;
    while(p.find("//") != std::string::npos)
        p.replace(p.find("//"), 2, "/");
    _assetsFolders.push_back(p);
}
