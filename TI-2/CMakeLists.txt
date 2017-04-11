cmake_minimum_required(VERSION 3.5)
project(TI-2)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE ti-2_SOURCES "src/*.cpp")
file(GLOB_RECURSE ti-2_HEADERS "src/*.h")

set (ti-2_INCLUDE_DIRS "")
foreach (_headerFile ${ti-2_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND ti-2_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES ti-2_INCLUDE_DIRS)

add_executable (${PROJECT_NAME} ${ti-2_SOURCES})

INCLUDE("build_glm.cmake")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

include_directories(${ti-2_INCLUDE_DIRS})
