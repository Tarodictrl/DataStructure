cmake_minimum_required(VERSION 3.0.0)
project(SD VERSION 0.1.0)
include_directories(Model)
include_directories(Stack)
include_directories(Services)

set(VALIDATOR Services/Validator.cpp Services/Validator.h)
set(NODE Model/Node/Node.h)
set(HASHTABLE Model/HashTable/HashTable.h Model/HashTable/HashTable.cpp)
set(DICTIONARY Model/Dictionary/Dictionary.h Model/Dictionary/Dictionary.cpp)

add_executable(Lab4 main.cpp ${VALIDATOR} ${NODE} ${HASHTABLE} ${DICTIONARY})

set(CMAKE_CXX_STANDARD 17)

