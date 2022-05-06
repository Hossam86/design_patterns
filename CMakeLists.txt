cmake_minimum_required(VERSION 3.20)
project(design_patterns C CXX)

set (CMAKE_CXX_STANDARD 20)
# Creational Patterns
# add_executable(Builder Creational_Builder.cpp)
add_executable(Factory Creational/Factory.cpp)
# add_executable(Abstract Creational_Abstract.cpp)
add_executable(Prototype Creational/Prototype.cpp)
add_executable(Singleton Creational/Singleton.cpp)
# Structural Patterns
#add_executable(Adaptor Structrual_Adaptor.cpp)
add_subdirectory(Structural/Bridge)
add_executable(Decorator Structural/Decorator.cpp)
add_executable(Proxy Structural/Proxy/smart_pointers.cpp)
