//
// Created by Lukas Campbell on 23/06/2025.
//

#pragma once
#include "headers.h"


static std::random_device RD;
static std::mt19937 GEN(RD());
static std::uniform_real_distribution NOISE_DIST(-1.0f, 1.0f);
constexpr static float PIXEL_DIFF_THRESHOLD = 2.0f;


void process_image_to_gray(cv::Mat& f);
cv::Mat process_motion(const cv::Mat& prev_f, const cv::Mat& curr_f);

