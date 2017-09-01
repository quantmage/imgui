#include <string>
#include <functional>
#include "imgui.h"

namespace imgui_gl2_runner
{
  void imgui_gl2_runner_example();

  typedef void(*error_callback_function)(int, const char*);
  typedef std::function<void(void)> main_loop_body_function;

  inline void error_callback_stderr(int error, const char* description)
  {
    fprintf(stderr, "Error %d: %s\n", error, description);
  }


  struct imgui_params
  {
    int win_width = 800;
    int win_height = 600;
    std::string win_title = "Imgui - Title";
    ImVec4 clear_color = ImColor(114, 144, 154);
  };

  void run(
    main_loop_body_function _main_loop_body_function, 
    const imgui_params & params, 
    error_callback_function error_callback = error_callback_stderr
  );

}