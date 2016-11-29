cmake_minimum_required(VERSION 2.8)
project(arandoc)

# ============================================= OPTIONS
option(BUILD_GTK_EDITOR "Build also the GTK editor" ON)
option(BUILD_TESTING "Build unit tests" ON)

# ======================================== DEPENDENCIES
find_package(PkgConfig REQUIRED)

# GTK (if editor building is active)
if(BUILD_GTK_EDITOR)
  pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
  include_directories(${GTK3_INCLUDE_DIRS})
  link_directories(${GTK3_LIBRARY_DIRS})
  add_definitions(${GTK3_CFLAGS_OTHER})
endif()

# GLIB (if testing building is active)
if(BUILD_TESTING)
  pkg_check_modules(GLIB2 REQUIRED glib-2.0)
  include_directories(${GLIB2_INCLUDE_DIRS})
  link_directories(${GLIB2_LIBRARY_DIRS})
  add_definitions(${GLIB2_CFLAGS_OTHER})
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# ===================================================================== LIBRARY

set(LIB_HDRS
  version.h macros.h    arandoc.h   crossref.h listitem.h equationinline.h
  list.h    paragraph.h text.h      block.h    document.h  equation.h
  container.h figure.h  link.h      subfigure.h)
set(LIB_SRCS arandoc.c)

foreach(LIB_HDR ${LIB_HDRS})
  list(APPEND LIB_HDRS_ABS ${CMAKE_CURRENT_SOURCE_DIR}/include/ad/core/${LIB_HDR})
endforeach()
list(APPEND LIB_HDRS_ABS ${CMAKE_CURRENT_SOURCE_DIR}/include/ad/core.h)
foreach(LIB_SRC ${LIB_SRCS})
  list(APPEND LIB_SRCS_ABS ${CMAKE_CURRENT_SOURCE_DIR}/src/core/${LIB_SRC})
endforeach()


add_library(arandoc SHARED ${LIB_SRCS_ABS} ${LIB_HDRS_ABS})

# ====================================================================== EDITOR

add_executable(arandoc-gtk ${CMAKE_CURRENT_SOURCE_DIR}/src/editor_gtk/main.c)
target_link_libraries(arandoc-gtk ${GTK3_LIBRARIES} arandoc)

# ====================================================================== PARSER

add_executable(arandoc-cmd ${CMAKE_CURRENT_SOURCE_DIR}/src/cmd/main.c)
target_link_libraries(arandoc-cmd arandoc)
set_target_properties(arandoc-cmd PROPERTIES OUTPUT_NAME arandoc)

# ======================================================================= TESTS

add_executable(test_arandoc ${CMAKE_CURRENT_SOURCE_DIR}/test/core/arandoc.c)
target_link_libraries(test_arandoc ${GLIB2_LIBRARIES} arandoc)
