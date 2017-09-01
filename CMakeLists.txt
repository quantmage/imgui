cmake_minimum_required(VERSION 3.2)

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

project(imgui)

include("cmake/ucm.cmake")
option(IMGUI_STATIC_RUNTIME "Force static runtime" OFF)
option(IMGUI_DYNAMIC_RUNTIME "Force dynamic runtime" OFF)
if(IMGUI_STATIC_RUNTIME)
  ucm_set_runtime(STATIC)
endif()
if(IMGUI_DYNAMIC_RUNTIME)
  ucm_set_runtime(DYNAMIC)
endif()


# examples/opengl2_runner is a ready to use runner for imgui, using the opengl2 backend.
# It will automatically link to imgui & glfw 
# Typical usage : 
# cmake ../imgui -DHUNTER_ENABLED=ON -DIMGUI_BUILD_OPENGL2_RUNNER=ON
option(IMGUI_BUILD_OPENGL2_RUNNER OFF)
if (IMGUI_BUILD_OPENGL2_RUNNER)
  add_subdirectory(examples/opengl2_runner)
endif()

option(IMGUI_BUILD_VULKAN_EXAMPLE OFF)
if (IMGUI_BUILD_VULKAN_EXAMPLE)
  add_subdirectory(examples/vulkan_example)
endif()
