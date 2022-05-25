/*
** EPITECH PROJECT, 2020
** test_main.cpp
** File description:
** test_main.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Debug.hpp>

int main()
{
    std::string path = "./build";
    std::string name = "Test";


    try
    {
        Polymorph::Engine e = Polymorph::Engine(path, name);
        e.loadGraphicalAPI("./lib/libarcade_sfml.so");
        //e.loadScriptingAPI(path + "/" +name + ".so");
        e.loadEngine();
        e.run();
    }
    catch (ConfigurationException &e)
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