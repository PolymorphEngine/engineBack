/*
** EPITECH PROJECT, 2020
** test_main.cpp
** File description:
** test_main.cpp
*/

#include <polymorph/Core.hpp>
#include <polymorph/Debug.hpp>

int main()
{
    std::string workDir = "./build";
    std::string pluginDir = "./Plugins";
    std::string name = "Test";


    try
    {
        polymorph::engine::Engine e = polymorph::engine::Engine(name, workDir, pluginDir);
        //e.loadScriptingAPI(path + "/" +name + ".so");
        e.loadEngine();
        e.run();
    }
    catch (polymorph::engine::ConfigurationException &e)
    {
        e.what();
        return 84;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}