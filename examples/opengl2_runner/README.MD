# imgui opengl2_runner

A quick start example for impatient people.


## imgui_runner_opengl2
 imgui_runner_opengl2 is a library that includes:
  * imgui 
  * the opengl2 backend : it links automatically with opengl and glfw
  * imgui_gl2_runner.h : helper function in order to launch an imgui window with your gui code.

If you link your project via cmake with imgui_runner_opengl2, it will automatically be linked with imgui, opengl and glfw.

`imgui_gl2_runner.h` provides a utility function in order to quickly launch imgui with opengl2/glfw.
The usage is summarized below:
````cpp
#include "imgui.h"
#include "imgui_gl2_runner.h"

void sample_main_loop_body()
{
  if (ImGui::Button("Hello")) 
    std::cout << "Hello";
  // etc.
}

int main()
{
  imgui_gl2_runner::imgui_params params;
  params.win_width = 1280;
  params.win_height = 720;
  params.win_title = "Hello";
  imgui_gl2_runner::run(sample_main_loop_body, params);
  return 0;
}
````


## runner_opengl2_example
runner_opengl2_example is an example : it links with imgui_runner_opengl2, and thus will automatically be linked with imgui, opengl and glfw.


