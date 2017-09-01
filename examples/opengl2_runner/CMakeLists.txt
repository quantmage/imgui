cmake_minimum_required (VERSION 3.2)
set (CMAKE_CXX_STANDARD 11)

# GLFW can be automatically compiled via hunter (https://github.com/ruslo/hunter)
# if the option HUNTER_ENABLED is set (cmake .. -DHUNTER_ENABLED=ON)
option(HUNTER_ENABLED "Use hunter for auto install/compil of GLFW" OFF)
if(HUNTER_ENABLED)
  include("cmake/HunterGate.cmake")
  HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.90.tar.gz"
    SHA1 "9ff7d2f4aa456588236d2816e9edb945a2469e16"
  )
endif()

project(imgui_runners)

add_subdirectory(imgui_runner_opengl2)
add_subdirectory(imgui_runner_opengl2_example)
