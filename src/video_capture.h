//
// Created by Lukas Campbell on 23/06/2025.
//

#pragma once
#include "headers.h"

bool init_camera(cv::VideoCapture& cap, int width = 640, int height = 480);
bool get_frame(cv::VideoCapture& cap, cv::Mat& frame);