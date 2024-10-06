cmake_minimum_required(VERSION 3.28)
project(TSP_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(TSP_1 Source/Class/main.cpp
        Source/Class/NearestNeighbour.cpp
        Source/Headers/NearestNeighbour.h
        Source/Class/BruteForce.cpp
        Source/Headers/BruteForce.h
        Source/Class/Random.cpp
        Source/Headers/Random.h
        Source/Class/Run.cpp
        Source/Headers/Run.h
        Source/Libraries/iniParser/INIReader.cpp
        Source/Libraries/iniParser/INIReader.h
        Source/Libraries/iniParser/ini.cpp
        Source/Libraries/iniParser/ini.h
        Source/Headers/Structures.h
        Source/Headers/TimeCounter.h)
