# cmake_minimum_required(VERSION <specify CMake version here>)
project(DataStructs)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataStructs
        DataStructs/DataStructs.cpp
        DataStructs/FListIterator.cpp
        DataStructs/FListIterator.h
        DataStructs/ForwardIterator.h
        DataStructs/ForwardIterator_type.cpp
        DataStructs/ForwardIterator_type.h
        DataStructs/Iterator_base.cpp
        DataStructs/Iterator_base.h
        DataStructs/IteratorAlgorithms.h
        DataStructs/ListNodes.h
        DataStructs/stdafx.cpp
        DataStructs/stdafx.h
        DataStructs/targetver.h
        DataStructs/TemplateMagic.h
        DataStructs/Traits.h)
