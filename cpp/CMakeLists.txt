cmake_minimum_required(VERSION 3.3)
project(pattern_design)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp

        simple_factory/Product.hpp
        simple_factory/Factory.hpp

        singleton/Singleton.cpp
        singleton/Singleton.hpp

        factory_method/Product.hpp
        factory_method/Factory.hpp

        abstract_factory/Product.hpp
        abstract_factory/Factory.hpp

        builder/Actor.hpp
        builder/ActorContoller.hpp
        builder/Builder.hpp

        facade/Facade.hpp

        prototype/Prototype.cpp
        prototype/Prototype.hpp

        proxy/Proxy.hpp

        adapter/Adapter.hpp

        decorator/Docorator.hpp

        bridge/Bridge.hpp

        composite/Composite.hpp

        strategy/Strategy.hpp

        template/Template.hpp

        test/test.hpp
        test/test_simple_factory.cpp
        test/test_singleton.cpp
        test/test_factory_method.cpp
        test/test_abstract_factory.cpp
        test/test_builder.cpp
        test/test_facade.cpp
        test/test_prototype.cpp
        test/test_proxy.cpp
        test/test_adapter.cpp
        test/test_decorator.cpp
        test/test_bridge.cpp
        test/test_composite.cpp
        test/test_flyweight.cpp
        test/test_strategy.cpp
        test/test_template.cpp
        test/test_template.cpp)

add_executable(pattern_design ${SOURCE_FILES})