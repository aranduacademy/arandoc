cmake_minimum_required(VERSION 2.8)
project(arandoc)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


set(LIB_HDR ${CMAKE_CURRENT_SOURCE_DIR}/include/arandoc/arandoc.h)
set(LIB_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/arandoc/arandoc.c)

add_library(arandoc SHARED ${LIB_SRC} ${LIB_HDR})

add_executable(arandoc-gtk ${CMAKE_CURRENT_SOURCE_DIR}/src/editor_gtk/main.c)
target_link_libraries(arandoc-gtk ${GTK3_LIBRARIES})
