cmake_minimum_required(VERSION 3.12)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release;" CACHE STRING "" FORCE)

project(2D_Engine
    LANGUAGES CXX
    VERSION 0.1
)

set(AllFiles ${CMAKE_CURRENT_SOURCE_DIR}/2D_Engine.cpp ${CMAKE_CURRENT_SOURCE_DIR}/2D_Engine.h 
${CMAKE_CURRENT_SOURCE_DIR}/dllmain.cpp ${CMAKE_CURRENT_SOURCE_DIR}/InputInterface.h
${CMAKE_CURRENT_SOURCE_DIR}/MyObjectDisplayData.h ${CMAKE_CURRENT_SOURCE_DIR}/Render.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Render.h ${CMAKE_CURRENT_SOURCE_DIR}/stdafx.cpp ${CMAKE_CURRENT_SOURCE_DIR}/stdafx.h 
${CMAKE_CURRENT_SOURCE_DIR}/targetver.h)


source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${AllFiles})


add_library(2D_Engine
    ${AllFiles}
)

include_directories(2D_Engine ${PROJECT_SOURCE_DIR}/src)
include_directories(/src)

if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(LibPath "/src/Libraries/SDL/lib/x64")
else ()
    set(LibPath "/src/Libraries/SDL/lib/x86")
endif ()

include_directories(2D_Engine ${PROJECT_SOURCE_DIR}${LibPath})


target_compile_features(2D_Engine PUBLIC cxx_std_17)


