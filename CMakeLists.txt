cmake_minimum_required(VERSION 3.30)
# Comment out if not on Windows
IF (WIN32)
    set(VCPKG_TARGET_TRIPLET "x64-mingw-static" CACHE STRING "VCPKG Triplet")
    add_compile_definitions(SFML_STATIC)
ENDIF ()
if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
endif()

project(assignment_3_1)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(assignment_3_1 main.cpp
        main.cpp
        ball.cpp
        ball.h
        paddle.cpp
        paddle.h
        enemy.cpp
        enemy.h
)
if(MINGW)
    target_link_options(assignment_3_1 PRIVATE -static-libstdc++ -static-libgcc)
endif()

target_compile_features(assignment_3_1 PRIVATE cxx_std_17)
target_link_libraries(assignment_3_1 PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio)