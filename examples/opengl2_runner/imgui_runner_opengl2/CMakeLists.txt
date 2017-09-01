cmake_minimum_required (VERSION 3.2)
set (CMAKE_CXX_STANDARD 11)
project(imgui_runner_opengl2)

add_library(imgui_runner_opengl2 
  ${CMAKE_CURRENT_LIST_DIR}/../../../imgui.cpp
  ${CMAKE_CURRENT_LIST_DIR}/../../../imgui.h
  ${CMAKE_CURRENT_LIST_DIR}/../../../imgui_draw.cpp
  ${CMAKE_CURRENT_LIST_DIR}/../../../imgui_internal.h
  ${CMAKE_CURRENT_LIST_DIR}/../../../imconfig.h
  ${CMAKE_CURRENT_LIST_DIR}/../../../imgui_demo.cpp
  ${CMAKE_CURRENT_LIST_DIR}/../../opengl2_example/imgui_impl_glfw.cpp
  ${CMAKE_CURRENT_LIST_DIR}/../../opengl2_example/imgui_impl_glfw.h
  imgui_gl2_runner.h
  imgui_gl2_runner.cpp
)
target_include_directories(imgui_runner_opengl2 
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../../.. .
  PRIVATE 
  ${CMAKE_CURRENT_LIST_DIR}/../../opengl2_example/
)

# OpenGL dependency via find_package
find_package(OpenGL REQUIRED)
target_include_directories(imgui_runner_opengl2 PRIVATE ${OPENGL_INCLUDE_DIR})
target_link_libraries(imgui_runner_opengl2 PUBLIC ${OPENGL_LIBRARIES} )

#
# GLFW dependency
#

# GLFW can be automatically compiled via hunter (https://github.com/ruslo/hunter)
if (HUNTER_ENABLED)
  hunter_add_package(glfw)
  find_package(glfw3)
  target_link_libraries(imgui_runner_opengl2 PUBLIC glfw )
else(HUNTER_ENABLED)
  # glfw dependency for windows : via precompiled library
  if (MSVC)
    target_include_directories(imgui_runner_opengl2
      PRIVATE 
        ${CMAKE_CURRENT_LIST_DIR}/../../libs/glfw/include
        ${CMAKE_CURRENT_LIST_DIR}/../../libs/gl3w 
    )
    if(${CMAKE_SIZEOF_VOID_P} EQUAL 8)
      target_link_libraries(imgui_runner_opengl2 PUBLIC 
        ${CMAKE_CURRENT_LIST_DIR}/../../libs/glfw/lib-vc2010-64/glfw3.lib)
    elseif(${CMAKE_SIZEOF_VOID_P} EQUAL 4)
      target_link_libraries(imgui_runner_opengl2 PUBLIC 
        ${CMAKE_CURRENT_LIST_DIR}/../../libs/glfw/lib-vc2010-32/glfw3.lib)
    endif()
  endif()

  # glfw dependency for linux and osx
  # for osx : install glfw via homebrew : 
  #     brew install glfw3
  # for ubuntu :see for example https://github.com/glfw/glfw/issues/808
  if(UNIX OR APPLE)
    find_package(glfw3 REQUIRED)
    target_link_libraries(imgui_runner_opengl2 PUBLIC glfw )
  endif()
endif(HUNTER_ENABLED)






