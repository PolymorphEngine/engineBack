/*
** EPITECH PROJECT, 2020
** ScriptingApi.hpp
** File description:
** header for ScriptingApi.c
*/


#pragma once

#include "Utilities/safe_ptr.hpp"
#include "ScriptingAPI/IScriptFactory.hpp"
#include "Core/Component/initializer/AComponentInitializer.hpp"
#include "ISerializableObjectFactory.hpp"
#include "ASerializableObject.hpp"
#include "Node.hpp"
#include "Debug/Log/Logger.hpp"
#include "Debug/Exceptions/ExceptionLogger.hpp"


namespace polymorph::engine
{
    namespace Config
    {
        class XmlComponent;
    }

    class IScriptFactory;

    class IComponentInitializer;

    class Entity;

    class ScriptingApi
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            explicit ScriptingApi(std::unique_ptr<IScriptFactory> factory);
            ScriptingApi() = default;
            ScriptingApi(ScriptingApi &&c) noexcept: _scriptFactory(std::move(c._scriptFactory)), _objectFactory(std::move(c._objectFactory)) {};
            ScriptingApi(ScriptingApi &c): _scriptFactory(std::move(c._scriptFactory)), _objectFactory(std::move(c._objectFactory)) {};

            ~ScriptingApi();
            
            ScriptingApi &operator=(ScriptingApi &&other) noexcept
            {
                this->_scriptFactory = std::move(other._scriptFactory);
                return *this;
            }


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            using Initializer = std::shared_ptr<IComponentInitializer>;

        private:
            std::unique_ptr<IScriptFactory> _scriptFactory;
            std::unique_ptr<ISerializableObjectFactory> _objectFactory;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void setSerializableObjectFactory(std::unique_ptr<ISerializableObjectFactory> factory);
            
            Initializer
            create(std::string &type, Config::XmlComponent &data,
                   safe_ptr<Entity> entity);


            
            std::shared_ptr<ASerializableObject> createSerializableObject(std::string type, std::shared_ptr<myxmlpp::Node> &data, engine::Config::XmlComponent &manager);
            


        private:

    };
}




#define PSERIALIZABLE(name) \
class Serializable##name; \
using name = std::shared_ptr<Serializable##name>;\
class Serializable##name : public polymorph::engine::ASerializableObject\

#define PSERIALIZABLE_CTOR(name) \
    public:\
        explicit Serializable##name(): polymorph::engine::ASerializableObject(#name) {};\
        ~Serializable##name() override = default;\

#define PSERIALIZABLE_IMPL(ns, name) \
class name##Impl : public ns::Serializable##name\

#define PSERIALIZABLE_IMPL_CTOR(name) \
    public:\
        explicit name##Impl(std::shared_ptr<myxmlpp::Node> &data, \
        engine::Config::XmlComponent &manager);\
        ~name##Impl() override = default;\



#define COMPONENT(name) \
class name##Component; \
using name = polymorph::engine::safe_ptr<name##Component>;\
class name##Component : public polymorph::engine::Component\

#define COMPONENT_CTOR(name) \
    public:\
        explicit name##Component(engine::GameObject gameObject) : polymorph::engine::Component(#name, std::move(gameObject)){};\
        virtual ~name##Component() = default;\


#define COMPONENT_IMPL(ns, name)\
class name##Impl : public ns::name##Component\

#define COMPONENT_IMPL_CTOR(name) \
    public:\
        explicit name##Impl(engine::GameObject gameObject);\
        ~name##Impl() override = default;\




#define ACOMPONENT(name) \
class A##name##Component; \
using name = polymorph::engine::safe_ptr<A##name##Component>;\
class A##name##Component : public polymorph::engine::Component\

#define ACOMPONENT_CTOR(name) \
    public:\
        explicit name##Component(std::string type, engine::GameObject gameObject) : polymorph::engine::Component(std::move(type), std::move(gameObject)){};\
        virtual ~name##Component() = default;\


#define COMPONENT_FROMA(ns, name, a) \
class name##Component; \
using name = polymorph::engine::safe_ptr<name##Component>;\
class name##Component : public ns::A##a##Component\

#define COMPONENT_FROMA_CTOR(ns, name, a) \
    public:\
        explicit name##Component(engine::GameObject gameObject) : ns::A##a##Component(#name, std::move(gameObject)){};\
        virtual ~name##Component() = default;\


#define MAKE_INITIALIZER(ns, name)\
namespace ns\
{\
    class name##Initializer\
    : public polymorph::engine::AComponentInitializer<ns::name##Impl>\
    {\
        public:\
            name##Initializer(polymorph::engine::Config::XmlComponent &data,\
                                   polymorph::engine::GameObject entity) : AComponentInitializer(#name, data, std::move(entity)){}\
        public:\
            void build() final;\
            void reference() final;\
    };\
}\



#define MAKE_BUILD_LINE(d) \
data.setProperty(#d, component->d);\

#define MAKE_INIT_BUILD(ns, name, ...) \
void ns::name##Initializer::build()\
{                                      \
    FOR_EACH(MAKE_BUILD_LINE, __VA_ARGS__)\
}                                      \

#define MAKE_INIT_REF(ns, name, ...) \
void ns::name##Initializer::reference()\
{                                      \
    FOR_EACH(MAKE_BUILD_LINE, __VA_ARGS__)\
}

#define MAKE_INIT_REF_(ns, name) \
void ns::name##Initializer::reference()\
{                                      \
}

#define FACTORY_BEGIN() \
namespace polymorph::engine\
{\
using Initializer = std::shared_ptr<IComponentInitializer>;\
class ScriptFactory : public IScriptFactory\
{\
    public:\
        ~ScriptFactory() override = default;\
    private:\
        using GameObject = polymorph::engine::safe_ptr<polymorph::engine::Entity>;\
        using FactoryLambda = std::function<Initializer (Config::XmlComponent &data, GameObject entity)>;\
        template<typename T>\
        static inline FactoryLambda _make()\
        {\
            return [](Config::XmlComponent &data, GameObject entity) -> Initializer{ return Initializer(new T(data, entity));};\
        }\
        const std::map<const std::string, FactoryLambda> _buildables =            \

#define FACTORY_END();\
    public:\
        Initializer create(std::string &type, Config::XmlComponent &data,\
                           GameObject entity) override;\
        bool hasType(std::string &type) final;\
\
};\
}

#define OBJECT_FACTORY_BEGIN() \
namespace polymorph::engine\
{\
class ObjectFactory : public ISerializableObjectFactory\
{\
    public:\
        ~ObjectFactory() override = default;\
        std::shared_ptr<ASerializableObject>\
        createS(std::string type, std::shared_ptr<myxmlpp::Node> &data,\
                Config::XmlComponent &manager) override;\
        bool hasType(std::string &type) override;\
        std::unordered_map<std::string, FactoryLambdaS> _factoriesS = \

#define OBJECT_FACTORY_END()\
        ;\
};\
}

#define MAKE_COMPONENT(ns, S) {#S, _make<ns::S##Initializer>()},
#define MAKE_SERIALIZABLE(ns, S) {#S, _make<ns::S##Impl>()},



// Make a FOREACH macro
#define FE_0()
#define FE_1(WHAT, X) WHAT(X)
#define FE_2(WHAT, X, ...) WHAT(X)FE_1(WHAT, __VA_ARGS__)
#define FE_3(WHAT, X, ...) WHAT(X)FE_2(WHAT, __VA_ARGS__)
#define FE_4 (WHAT, X, ...) WHAT(X)FE_3(WHAT, __VA_ARGS)
#define FE_5 (WHAT, X, ...) WHAT(X)FE_4(WHAT, __VA_ARGS)
#define FE_6 (WHAT, X, ...) WHAT(X)FE_5(WHAT, __VA_ARGS)
#define FE_7 (WHAT, X, ...) WHAT(X)FE_6(WHAT, __VA_ARGS)
#define FE_8 (WHAT, X, ...) WHAT(X)FE_7(WHAT, __VA_ARGS)
#define FE_9 (WHAT, X, ...) WHAT(X)FE_8(WHAT, __VA_ARGS)
#define FE_10 (WHAT, X, ...) WHAT(X)FE_9(WHAT, __VA_ARGS)
#define FE_11 (WHAT, X, ...) WHAT(X)FE_10(WHAT, __VA_ARGS)
#define FE_12 (WHAT, X, ...) WHAT(X)FE_11(WHAT, __VA_ARGS)
#define FE_13 (WHAT, X, ...) WHAT(X)FE_12(WHAT, __VA_ARGS)
#define FE_14 (WHAT, X, ...) WHAT(X)FE_13(WHAT, __VA_ARGS)
#define FE_15 (WHAT, X, ...) WHAT(X)FE_14(WHAT, __VA_ARGS)
#define FE_16 (WHAT, X, ...) WHAT(X)FE_15(WHAT, __VA_ARGS)
#define FE_17 (WHAT, X, ...) WHAT(X)FE_16(WHAT, __VA_ARGS)
#define FE_18 (WHAT, X, ...) WHAT(X)FE_17(WHAT, __VA_ARGS)
#define FE_19 (WHAT, X, ...) WHAT(X)FE_18(WHAT, __VA_ARGS)
#define FE_20 (WHAT, X, ...) WHAT(X)FE_19(WHAT, __VA_ARGS)
#define FE_21 (WHAT, X, ...) WHAT(X)FE_20(WHAT, __VA_ARGS)
#define FE_22 (WHAT, X, ...) WHAT(X)FE_21(WHAT, __VA_ARGS)
#define FE_23 (WHAT, X, ...) WHAT(X)FE_22(WHAT, __VA_ARGS)
#define FE_24 (WHAT, X, ...) WHAT(X)FE_23(WHAT, __VA_ARGS)
#define FE_25 (WHAT, X, ...) WHAT(X)FE_24(WHAT, __VA_ARGS)
#define FE_26 (WHAT, X, ...) WHAT(X)FE_25(WHAT, __VA_ARGS)
#define FE_27 (WHAT, X, ...) WHAT(X)FE_26(WHAT, __VA_ARGS)
#define FE_28 (WHAT, X, ...) WHAT(X)FE_27(WHAT, __VA_ARGS)
#define FE_29 (WHAT, X, ...) WHAT(X)FE_28(WHAT, __VA_ARGS)
#define FE_30 (WHAT, X, ...) WHAT(X)FE_29(WHAT, __VA_ARGS)
#define FE_31 (WHAT, X, ...) WHAT(X)FE_30(WHAT, __VA_ARGS)
#define FE_32 (WHAT, X, ...) WHAT(X)FE_31(WHAT, __VA_ARGS)
#define FE_33 (WHAT, X, ...) WHAT(X)FE_32(WHAT, __VA_ARGS)
#define FE_34 (WHAT, X, ...) WHAT(X)FE_33(WHAT, __VA_ARGS)
#define FE_35 (WHAT, X, ...) WHAT(X)FE_34(WHAT, __VA_ARGS)
#define FE_36 (WHAT, X, ...) WHAT(X)FE_35(WHAT, __VA_ARGS)
#define FE_37 (WHAT, X, ...) WHAT(X)FE_36(WHAT, __VA_ARGS)
#define FE_38 (WHAT, X, ...) WHAT(X)FE_37(WHAT, __VA_ARGS)
#define FE_39 (WHAT, X, ...) WHAT(X)FE_38(WHAT, __VA_ARGS)
#define FE_40 (WHAT, X, ...) WHAT(X)FE_39(WHAT, __VA_ARGS)
#define FE_41 (WHAT, X, ...) WHAT(X)FE_40(WHAT, __VA_ARGS)
#define FE_42 (WHAT, X, ...) WHAT(X)FE_41(WHAT, __VA_ARGS)
#define FE_43 (WHAT, X, ...) WHAT(X)FE_42(WHAT, __VA_ARGS)
#define FE_44 (WHAT, X, ...) WHAT(X)FE_43(WHAT, __VA_ARGS)
#define FE_45 (WHAT, X, ...) WHAT(X)FE_44(WHAT, __VA_ARGS)
#define FE_46 (WHAT, X, ...) WHAT(X)FE_45(WHAT, __VA_ARGS)
#define FE_47 (WHAT, X, ...) WHAT(X)FE_46(WHAT, __VA_ARGS)
#define FE_48 (WHAT, X, ...) WHAT(X)FE_47(WHAT, __VA_ARGS)
#define FE_49 (WHAT, X, ...) WHAT(X)FE_48(WHAT, __VA_ARGS)
#define FE_50 (WHAT, X, ...) WHAT(X)FE_49(WHAT, __VA_ARGS)
#define FE_51 (WHAT, X, ...) WHAT(X)FE_50(WHAT, __VA_ARGS)
#define FE_52 (WHAT, X, ...) WHAT(X)FE_51(WHAT, __VA_ARGS)
#define FE_53 (WHAT, X, ...) WHAT(X)FE_52(WHAT, __VA_ARGS)
#define FE_54 (WHAT, X, ...) WHAT(X)FE_53(WHAT, __VA_ARGS)
#define FE_55 (WHAT, X, ...) WHAT(X)FE_54(WHAT, __VA_ARGS)
#define FE_56 (WHAT, X, ...) WHAT(X)FE_55(WHAT, __VA_ARGS)
#define FE_57 (WHAT, X, ...) WHAT(X)FE_56(WHAT, __VA_ARGS)
#define FE_58 (WHAT, X, ...) WHAT(X)FE_57(WHAT, __VA_ARGS)
#define FE_59 (WHAT, X, ...) WHAT(X)FE_58(WHAT, __VA_ARGS)
#define FE_60 (WHAT, X, ...) WHAT(X)FE_59(WHAT, __VA_ARGS)
#define FE_61 (WHAT, X, ...) WHAT(X)FE_60(WHAT, __VA_ARGS)
#define FE_62 (WHAT, X, ...) WHAT(X)FE_61(WHAT, __VA_ARGS)
#define FE_63 (WHAT, X, ...) WHAT(X)FE_62(WHAT, __VA_ARGS)
#define FE_64 (WHAT, X, ...) WHAT(X)FE_63(WHAT, __VA_ARGS)
#define FE_65 (WHAT, X, ...) WHAT(X)FE_64(WHAT, __VA_ARGS)
#define FE_66 (WHAT, X, ...) WHAT(X)FE_65(WHAT, __VA_ARGS)
#define FE_67 (WHAT, X, ...) WHAT(X)FE_66(WHAT, __VA_ARGS)
#define FE_68 (WHAT, X, ...) WHAT(X)FE_67(WHAT, __VA_ARGS)
#define FE_69 (WHAT, X, ...) WHAT(X)FE_68(WHAT, __VA_ARGS)
#define FE_70 (WHAT, X, ...) WHAT(X)FE_69(WHAT, __VA_ARGS)
#define FE_71 (WHAT, X, ...) WHAT(X)FE_70(WHAT, __VA_ARGS)
#define FE_72 (WHAT, X, ...) WHAT(X)FE_71(WHAT, __VA_ARGS)
#define FE_73 (WHAT, X, ...) WHAT(X)FE_72(WHAT, __VA_ARGS)
#define FE_74 (WHAT, X, ...) WHAT(X)FE_73(WHAT, __VA_ARGS)
#define FE_75 (WHAT, X, ...) WHAT(X)FE_74(WHAT, __VA_ARGS)
#define FE_76 (WHAT, X, ...) WHAT(X)FE_75(WHAT, __VA_ARGS)
#define FE_77 (WHAT, X, ...) WHAT(X)FE_76(WHAT, __VA_ARGS)
#define FE_78 (WHAT, X, ...) WHAT(X)FE_77(WHAT, __VA_ARGS)
#define FE_79 (WHAT, X, ...) WHAT(X)FE_78(WHAT, __VA_ARGS)
#define FE_80 (WHAT, X, ...) WHAT(X)FE_79(WHAT, __VA_ARGS)
#define FE_81 (WHAT, X, ...) WHAT(X)FE_80(WHAT, __VA_ARGS)
#define FE_82 (WHAT, X, ...) WHAT(X)FE_81(WHAT, __VA_ARGS)
#define FE_83 (WHAT, X, ...) WHAT(X)FE_82(WHAT, __VA_ARGS)
#define FE_84 (WHAT, X, ...) WHAT(X)FE_83(WHAT, __VA_ARGS)
#define FE_85 (WHAT, X, ...) WHAT(X)FE_84(WHAT, __VA_ARGS)
#define FE_86 (WHAT, X, ...) WHAT(X)FE_85(WHAT, __VA_ARGS)
#define FE_87 (WHAT, X, ...) WHAT(X)FE_86(WHAT, __VA_ARGS)
#define FE_88 (WHAT, X, ...) WHAT(X)FE_87(WHAT, __VA_ARGS)
#define FE_89 (WHAT, X, ...) WHAT(X)FE_88(WHAT, __VA_ARGS)
#define FE_90 (WHAT, X, ...) WHAT(X)FE_89(WHAT, __VA_ARGS)
#define FE_91 (WHAT, X, ...) WHAT(X)FE_90(WHAT, __VA_ARGS)
#define FE_92 (WHAT, X, ...) WHAT(X)FE_91(WHAT, __VA_ARGS)
#define FE_93 (WHAT, X, ...) WHAT(X)FE_92(WHAT, __VA_ARGS)
#define FE_94 (WHAT, X, ...) WHAT(X)FE_93(WHAT, __VA_ARGS)
#define FE_95 (WHAT, X, ...) WHAT(X)FE_94(WHAT, __VA_ARGS)
#define FE_96 (WHAT, X, ...) WHAT(X)FE_95(WHAT, __VA_ARGS)
#define FE_97 (WHAT, X, ...) WHAT(X)FE_96(WHAT, __VA_ARGS)
#define FE_98 (WHAT, X, ...) WHAT(X)FE_97(WHAT, __VA_ARGS)
#define FE_99 (WHAT, X, ...) WHAT(X)FE_98(WHAT, __VA_ARGS)


//... repeat as needed

#define GET_MACRO(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32,_33,_34,_35,_36,_37,_38,_39,_40,_41,_42,_43,_44,_45,_46,_47,_48,_49,_50,_51,_52,_53,_54,_55,_56,_57,_58,_59,_60,_61,_62,_63,_64,_65,_66,_67,_68,_69,_70,_71,_72,_73,_74,_75,_76,_77,_78,_79,_80,_81,_82,_83,_84,_85,_86,_87,_88,_89,_90,_91,_92,_93,_94,_95,_96,_97,_98,_99,NAME, ...) NAME
#define FOR_EACH(action,...) GET_MACRO(_0,__VA_ARGS__, FE_99, FE_98, FE_97, FE_96, FE_95, FE_94, FE_93, FE_92, FE_91, FE_90, FE_89, FE_88, FE_87, FE_86, FE_85, FE_84, FE_83, FE_82, FE_81, FE_80, FE_79, FE_78, FE_77, FE_76, FE_75, FE_74, FE_73, FE_72, FE_71, FE_70, FE_69, FE_68, FE_67, FE_66, FE_65, FE_64, FE_63, FE_62, FE_61, FE_60, FE_59, FE_58, FE_57, FE_56, FE_55, FE_54, FE_53, FE_52, FE_51, FE_50, FE_49, FE_48, FE_47, FE_46, FE_45, FE_44, FE_43, FE_42, FE_41, FE_40, FE_39, FE_38, FE_37, FE_36, FE_35, FE_34, FE_33, FE_32, FE_31, FE_30, FE_29, FE_28, FE_27, FE_26, FE_25, FE_24, FE_23, FE_22, FE_21, FE_20, FE_19, FE_18, FE_17, FE_16, FE_15, FE_14, FE_13, FE_12, FE_11, FE_10, FE_9, FE_8, FE_7, FE_6, FE_5, FE_4, FE_3, FE_2, FE_1, FE_0)(action, __VA_ARGS__)

