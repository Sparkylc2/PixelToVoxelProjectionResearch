//
// Created by Lukas Campbell on 23/06/2025.
//

#pragma once
#include "headers.h"

bool init_glfw(GLFWwindow*& window, int width, int height);
unsigned int create_texture(int width, int height);
void update_texture(unsigned int textureID, const cv::Mat& frame);
void render_texture(unsigned int textureID);