cmake_minimum_required(VERSION 3.6)
project(DSA_4MAP)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp Map/Elem.h Map/Elem.cpp Exception/Exception.cpp Exception/Exception.h HashMap/HashMap.cpp HashMap/HashMap.h Tests/TestHashMap.cpp Tests/TestHashMap.h Map/Map.h Map/Map.cpp HashMap/HashMapIterator.cpp HashMap/HashMapIterator.h Map/MapIterator.cpp Map/MapIterator.h Tests/TestMap.cpp Tests/TestMap.h)
#set(SOURCE_FILES main.cpp Map/Map.cpp Map/Map.h Map/Elem.cpp Map/Elem.h  Map/MapIterator.cpp Map/MapIterator.h Exception/Exception.cpp Exception/Exception.h HashMap/HashMap.cpp HashMap/HashMap.h Tests/TestHashMap.cpp Tests/TestHashMap.h)

add_executable(DSA_4MAP ${SOURCE_FILES})