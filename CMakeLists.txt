cmake_minimum_required(VERSION 3.26)
project(DMS_Practice1_)

set(CMAKE_CXX_STANDARD 17)

add_executable(DMS_Practice1_ main.cpp
        SingleLinkedList/SinglyLinkedList.cpp
        SingleLinkedList/SinglyLinkedList.h
        HashMap/hashMap.cpp
        HashMap/hashMap.h
        DoubleLinkedList/DblLnkdList.cpp
        DoubleLinkedList/DblLnkdList.h
        Set/Set.cpp
        Set/Set.h
        Dao.cpp
        Dao.h
)
