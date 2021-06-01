cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 OLD)
cmake_policy(SET CMP0081 OLD)
cmake_policy(SET CMP0048 OLD)

project(chess_for_dummies)

ADD_SUBDIRECTORY(googletest)
SET(CMAKE_CXX_STANDARD 11)


SET(SOURCE_DIR "./source")

if (WIN32)
    SET(SFML_INCLUDE_DIR "./SFML-2.5.1/include")
    SET(SFML_LIBRARY_DIR "./SFML-2.5.1/lib")
    include_directories(SFML_INCLUDE_DIR)
    link_directories(SFML_LIBRARY_DIR)
endif()

if (APPLE)
    include_directories("/usr/local/include")
    link_directories("/usr/local/lib")
endif()

if(UNIX)
    find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
endif()

FILE(GLOB sources ${SOURCE_DIR}/*.h ${SOURCE_DIR}/*.hpp ${SOURCE_DIR}/*.c ${SOURCE_DIR}/*.cpp)

ADD_EXECUTABLE(main ${sources} main.cpp)
ADD_EXECUTABLE(unit_test
    ${sources}
    test/unit_test.cpp
)

TARGET_LINK_LIBRARIES (main sfml-graphics sfml-window sfml-system)
TARGET_LINK_LIBRARIES(unit_test gtest sfml-graphics sfml-window sfml-system)
TARGET_COMPILE_DEFINITIONS(unit_test PRIVATE gtest_disable_pthreads=ON)