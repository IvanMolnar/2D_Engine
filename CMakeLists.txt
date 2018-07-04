cmake_minimum_required(VERSION 3.12)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release;" CACHE STRING "" FORCE)

project(2D_Engine
    LANGUAGES CXX
    VERSION 0.1
)

set(AllFiles ${CMAKE_CURRENT_SOURCE_DIR}/src/2D_Engine.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/2D_Engine.h 
${CMAKE_CURRENT_SOURCE_DIR}/src/dllmain.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/InputInterface.h
${CMAKE_CURRENT_SOURCE_DIR}/src/MyObjectDisplayData.h ${CMAKE_CURRENT_SOURCE_DIR}/src/Render.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/Render.h ${CMAKE_CURRENT_SOURCE_DIR}/src/stdafx.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/stdafx.h 
${CMAKE_CURRENT_SOURCE_DIR}/src/targetver.h)


source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${AllFiles})


add_library(2D_Engine MODULE 
    ${AllFiles}
)

include_directories(2D_Engine ${CMAKE_CURRENT_SOURCE_DIR}/src)

if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(LibPathSDL "${CMAKE_CURRENT_SOURCE_DIR}/src/Libraries/SDL/lib/x64")
    set(LibPathSDL_Image "${CMAKE_CURRENT_SOURCE_DIR}/src/Libraries/SDL_Image/lib/x64")
else()
    set(LibPathSDL "${CMAKE_CURRENT_SOURCE_DIR}/src/Libraries/SDL/lib/x86")
    set(LibPathSDL_Image "${CMAKE_CURRENT_SOURCE_DIR}/src/Libraries/SDL_Image/lib/x86")
endif()

target_link_libraries(2D_Engine debug ${LibPathSDL}/SDL2.lib)
target_link_libraries(2D_Engine debug ${LibPathSDL_Image}/SDL2_image.lib)

target_link_libraries(2D_Engine optimized ${LibPathSDL}/SDL2.lib)
target_link_libraries(2D_Engine optimized ${LibPathSDL_Image}/SDL2_image.lib)

set(Install_Dir ${CMAKE_CURRENT_SOURCE_DIR}/Bin)

set_target_properties( 2D_Engine PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${Install_Dir})
set_target_properties( 2D_Engine PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${Install_Dir})

target_compile_features(2D_Engine PUBLIC cxx_std_17)

ADD_CUSTOM_COMMAND(
    TARGET 2D_Engine
    POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy
${LibPathSDL}/SDL2.dll
${Install_Dir}
${LibPathSDL_Image}/libjpeg-9.dll
${Install_Dir}
${LibPathSDL_Image}/libpng16-16.dll
${Install_Dir}
${LibPathSDL_Image}/libtiff-5.dll
${Install_Dir}
${LibPathSDL_Image}/libwebp-7.dll
${Install_Dir}
${LibPathSDL_Image}/SDL2_image.dll
${Install_Dir}
${LibPathSDL_Image}/zlib1.dll
${Install_Dir}
)