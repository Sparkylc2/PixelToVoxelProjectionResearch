//
// Created by Lukas Campbell on 23/06/2025.
//

#include "video_capture.h"

bool init_camera(cv::VideoCapture& cap, int width, int height) {
    cap.open(0);
    if (!cap.isOpened()) return false;

    cap.set(cv::CAP_PROP_FRAME_WIDTH, width);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, height);
    return true;
}

bool get_frame(cv::VideoCapture& cap, cv::Mat& frame) {
    cap >> frame;
    return !frame.empty();
}
