cmake_minimum_required(VERSION 2.8.11)
project( libxml2 )

include_directories( "src/include")

file( GLOB SRC src/*.c src/*.h)
#file( GLOB API_HEADERS src/include/libxml/*.h )

if(WIN32)
    add_definitions(-DUNICODE)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-DLIBXML_STATIC)
    add_definitions(-DNOLIBTOOL)
    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   /wd4244 /wd4267 /wd4996 /wd4018")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4244 /wd4267 /wd4996 /wd4018")
else()
    if(BUILD_SHARED_LIBS)
        add_definitions(-fPIC)
    endif()
    if(APPLE)
        set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS}  -Wno-unused-const-variable")
    else()
        set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS}  -Wno-unused-but-set-variable")
    endif()
    if(NOT ANDROID)
        set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wno-unused-private-field")
        set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wno-shorten-64-to-32")
    endif()
    set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS}  -Wno-unused-function")
    set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS}  -Wno-enum-compare")
    set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS}  -Wno-pointer-sign")
endif()

if(MINGW OR UNIX)
  set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS}  -Wno-attributes")
endif()

add_library( libxml2 OBJECT ${SRC} )
set_target_properties(libxml2 PROPERTIES FOLDER "3rdparty")
#set_target_properties(libxml2 PROPERTIES PUBLIC_HEADER "${API_HEADERS}")
