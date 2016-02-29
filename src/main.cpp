
#include "Audio/audio.hpp"

#include <GLFW/glfw3.h>

#include <memory>
#include <iostream>


int main() {
  if (!glfwInit()) return 0;

  auto window = glfwCreateWindow(640, 480, "media", nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  // Sound ---
  Audio audio;
  Media media("../../assets/sound.wav");
  media.setVolume(1.)
    ->enableLoop()
    ->play();
  // --- Sound

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.3, 0.3, 0.3, 0.3);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}