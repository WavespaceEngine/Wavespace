cmake_minimum_required(VERSION 3.0.0)
project(Wavespace VERSION 0.1.0)

set(SRC_FOLDER src)
set(INCLUDE_FOLDER include)
set(THIRDPARTY_FOLDER thirdparty)

set(OpenGL_GL_Preference GLVND)
find_package(OpenGL REQUIRED)

set(BUILD_SHARED_LIBS OFF)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)
set(GLFW_VULKAN_STATIC OFF)
add_subdirectory(${THIRDPARTY_FOLDER}/glfw)

add_executable(Wavespace
    ${SRC_FOLDER}/glad.c
    ${SRC_FOLDER}/main.cpp
    ${SRC_FOLDER}/VBO.cpp)

target_include_directories(Wavespace PUBLIC ${INCLUDE_FOLDER})

target_link_libraries(Wavespace OpenGL::GL)
target_link_libraries(Wavespace glfw)
