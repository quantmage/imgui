// ImGui - standalone example application for Glfw + OpenGL 2, using fixed pipeline
// If you are new to ImGui, see examples/README.txt and documentation at the top of imgui.cpp.

#include <imgui.h>
#include "imgui_impl_glfw.h"
#include <stdio.h>
#include "../libs/glfw/include/GLFW/glfw3.h"
#include "imgui_gl2_runner.h"

namespace imgui_gl2_runner
{
  void run(
    main_loop_body_function _main_loop_body_function, 
    const imgui_params & params, 
    error_callback_function error_callback)
  {
    // Setup window
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
      throw std::runtime_error("imgui_gl2_runner::run -> glfwInit() failed");
    GLFWwindow* window = glfwCreateWindow(params.win_width, params.win_height, params.win_title.c_str(), NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup ImGui binding
    ImGui_ImplGlfw_Init(window, true);

    // Load Fonts
    // (there is a default font, this is only if you want to change it. see extra_fonts/README.txt for more details)
    //ImGuiIO& io = ImGui::GetIO();
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../extra_fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../extra_fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../extra_fonts/ProggyClean.ttf", 13.0f);
    //io.Fonts->AddFontFromFileTTF("../../extra_fonts/ProggyTiny.ttf", 10.0f);
    //io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
      glfwPollEvents();
      ImGui_ImplGlfw_NewFrame();

      _main_loop_body_function();

      // Rendering
      int display_w, display_h;
      glfwGetFramebufferSize(window, &display_w, &display_h);
      glViewport(0, 0, display_w, display_h);
      glClearColor(params.clear_color.x, params.clear_color.y, params.clear_color.z, params.clear_color.w);
      glClear(GL_COLOR_BUFFER_BIT);
      //glUseProgram(0); // You may want this if using this code in an OpenGL 3+ context where shaders may be bound
      ImGui::Render();
      glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplGlfw_Shutdown();
    glfwTerminate();
  }
}
