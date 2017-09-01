cmake_minimum_required (VERSION 3.2)
set (CMAKE_CXX_STANDARD 11)
project(imgui_runner_opengl2_example)

add_executable(imgui_runner_opengl2_example runner_opengl2_example.cpp)
target_link_libraries(imgui_runner_opengl2_example imgui_runner_opengl2)

install(TARGETS imgui_runner_opengl2_example
DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)
