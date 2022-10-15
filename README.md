# PolymorphEngine

PolymorphEngine is a beautiful game engine that allows great modularity and all the advantages of an ECS.\
With this engine you don't need to bother, you have access to an application/game that allows you to do the most complicated configuration actions, but all simply and quickly!\
But for this readme, let's consider that the interface doesn't exist to explain how things actually work under the hood.

## ⚙ How does it work?
PolymorphEngine works with scripts, "pieces" of code that are executed during the execution of the program.\
Each script must be as specialized and stable as possible, in order to eventually build more complex objects.\
These objects are **entities**, these last ones have their own execution of the scripts which are allotted to them, giving them a great autonomy while being able to take references with other entity and script if necessary.\
These **entities can become prefabs** if necessary, a representation of the entity that can be easily instantiated several times, while maintaining the advantages of independence allowed by an entity.\
Well, they are beautiful our entities but we could make something of it that would be good.\
This is where the **scene** comes into play, the scene allows you to contain your entities, each "screen" of your application/game will probably be a different scene (e.g. Main Menu, Game, Settings, etc...). 

## 🔨 How to use ?

### 🔧​ Setup

First things first, the `main.cpp`!\
To instantiate the engine you need to reproduce this:
```cpp
#include <iostream>
#include "Core/Engine.hpp"
#include "Exceptions/ConfigurationException.hpp"
#include "Anywhere/ScriptFactory.hpp"

int main() {

#ifdef _WIN32
    std::string path = R"(.\PROJECT_NAME\Game\Assets)";
    std::string name = "PROJECT_NAME";
#else
    std::string path = "./Game/Assets";
    std::string name = "PROJECT_NAME";
#endif

    try
    {
        Polymorph::Engine e = Polymorph::Engine(path, name);

    /*
        This exemple use Raylib as GraphicalAPI, but you are free to implement
        your any other API or even better, write your own !
    */
#ifdef _WIN32
        e.loadGraphicalAPI(".\\raymodules.dll");
#else
        e.loadGraphicalAPI("./raymodules.so");
#endif
        e.loadScriptingAPI(std::make_unique<YourNameSpace::ScriptFactory>());
        e.loadEngine();
        return e.run() != 0 ? 84 : 0;
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
```

This is the basic logic of the engine, as you can see we instantiate the engine and load the graphical API, but you may have noticed that we also load the `YourNameSpace::ScriptFactory`, this Factory is the one that will contain all our initializer.\
But it's your scripts that you're going to initialize, isn't it? So... you have to create your ScriptFactory !

Here is how to create the ScriptFactory:

`ScriptFactory.hpp`
```cpp
#pragma once

#include "Polymorph/Factory.hpp"
#include "Polymorph/Components.hpp"
#include "Polymorph/Core.hpp"

//@Future Initalizers

//@Future Scripts

namespace YourNameSpace
{
    class ScriptFactory : public IScriptFactory
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            ~ScriptFactory() override = default;


//////////////////////--------------------------/////////////////////////

            //Builder template : {"${SCRIPT_NAME}", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new ${SCRIPT_NAME}Initializer(data, entity));}},

///////////////////////////// PROPERTIES ////////////////////////////////
        private:
            using FactoryLambda = std::function<Initializer (Config::XmlComponent &data, GameObject entity)>;
            using F = auto (Config::XmlComponent &data, GameObject entity) -> Initializer;
            static const inline std::map<std::string, FactoryLambda>
                _buildables =
                {

                };
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            Initializer create(std::string &type, Config::XmlComponent &data,
                               GameObject entity) override;
//////////////////////--------------------------/////////////////////////

    };
}
```

And then `ScriptFactory.cpp`:
```cpp
#include "ScriptFactory.hpp"

Polymorph::Initializer YourNameSpace::ScriptFactory::create(std::string &type, Config::XmlComponent &data,
                                 GameObject entity)
{
    return _buildables.at(type)(data, entity);
}

```

🎉 Tadaa ! You are ready! Yes, it's hard to believe, but you already have a working engine!

### ⚗️​ Your first Script !

Now... The scripts ! Scripts need 2 things : an initilizer which derives from "AComponentInitializer" and the actual script that derives from `Polymorph::Component`.

Here is an example of an initializer:

`YourAwesomeInitializer.hpp`
```cpp
#pragma once

#include <Polymorph/Components.hpp>
#include <Polymorph/Types.hpp>
#include <Polymorph/Factory.hpp>

namespace YourNameSpace
{

   /*
       Try to respect that type if you can :>
       YourScriptName
         |
         |---> Initializer : YourScriptNameInitializer
         |
         ---> Script : YourScriptNameScript

   */

    class YourAwesomeScript;

    class YourAwesomeInitializer
            : public AComponentInitializer<YourAwesomeScript>
    {
///////////////////////////////// Constructors /////////////////////////////////

        public:
            YourAwesomeInitializer(Config::XmlComponent &data,
                                            GameObject entity);

///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////

        public:
            void build() final;

            void reference() final;
///////////////////////////--------------------------///////////////////////////
    };
}
```

`YourAwesomeInitializer.cpp`
```cpp
#include "Polymorph/Factory.hpp"
#include "Polymorph/Core.hpp"
#include "Polymorph/Types.hpp"
#include "Polymorph/Components.hpp"
#include "ScriptFactory.hpp"

namespace YourNameSpace
{
    YourAwesomeInitializer::YourAwesomeInitializer(Config::XmlComponent &data,
                                                   GameObject entity)
            : AComponentInitializer("YourAwesome", data, entity)
    {}

    // Called at Script creation to set properties from configuration
    // use:  data.setProperty(yourScriptPropertyName, component->yourProperty)
    // optionnaly had a severity as third parameter to log when not found 
    // (Logger::severity, throw's when Logger::MAJOR)
    void YourAwesomeInitializer::build()
    {
    }

    // Called after all components/scripts have been built
    void YourAwesomeInitializer::reference()
    {
        
    }
}
```

Now we want to implement the actual script `YourAwesomeScript.hpp`
```cpp
#pragma once

#include <Polymorph/Components.hpp>
#include <Polymorph/Types.hpp>

namespace YourNameSpace
{
    class YourAwesomeScript;

    using YourAwesome = safe_ptr<YourAwesomeScript>;
    using YourAwesomeBase = std::shared_ptr<YourAwesomeScript>;

    class YourAwesomeScript : public Component
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            explicit YourAwesomeScript(GameObject gameObject);

            //////////////////////--------------------------/////////////////////////

            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void start() override;

            void update() override;

        private:

            //////////////////////--------------------------/////////////////////////

    };
}
```

And of course the `YourAwesomeScript.cpp`
```cpp
#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>
#include "YourAwesomeScript.hpp"

namespace YourNameSpace
{
    YourAwesomeScript::YourAwesomeScript(GameObject gameObject)
            : Component("YourAwesome", gameObject)
    {}

    // Called only once when the Script is enabled the first time
    void YourAwesomeScript::start()
    {
        
    }

    // Called every frame by the engine
    void YourAwesomeScript::update()
    {

    }

}
```


**But wait**, it's dangerous to go it alone, you need to add your initializer to the list of engine initializers, add this to your `ScriptFactory.hpp` :

```cpp
{"YourScriptName", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new YourScriptNameInitializer(data, entity));}}
```

That will give us:
`ScriptFactory.hpp`
```cpp
[...]

//@Initalizers
#include "YourScriptNameInitializer.hpp"

//@Scripts
#include "YourScriptNameScript.hpp"

namespace YourNameSpace
{
    class ScriptFactory : public IScriptFactory
    {

            [...]

///////////////////////////// PROPERTIES ////////////////////////////////
        private:
            [...]
            static const inline std::map<std::string, FactoryLambda>
                _buildables =
                {
                    {"YourScriptName", [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new YourScriptNameInitializer(data, entity));}}
                };
            [...]
//////////////////////--------------------------/////////////////////////

            [...]
}
```

