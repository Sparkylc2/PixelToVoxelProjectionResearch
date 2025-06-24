//
// Created by Lukas Campbell on 23/06/2025.
//
#include "voxel_projection.h"






void process_image_to_gray(cv::Mat& f) {
    // uchar* pixel_data_ptr = f.data;
    //
    // for (size_t i = 0; i < f.rows * f.cols; ++i) {
    //     uchar p = pixel_data_ptr[i]; // get curr pixel value (0-255)
    //     p += NOISE_DIST(GEN); // add noise
    //     if (p < 0.0f) p = 0.0f; // clamp to [0, 255]
    //     if (p > 255.0f) p = 255.0f; // clamp to [0, 255]
    //     pixel_data_ptr[i] = p; // store back to pixel data
    //     // compiler will strip away the extra var creation (p) since we'll be using -O4
    // }
    //
    // // cv::cvtColor(f, f, cv::COLOR_GRAY2RGB);
}



cv::Mat process_motion(const cv::Mat &prev_f, const cv::Mat &curr_f) {
    cv::Mat d_f = { curr_f.rows, curr_f.cols, CV_8UC1, cv::Scalar(255)};

    // using d_f might pull the data into the cpu cache earlier so possibly faster
    for (size_t i = 0; i < d_f.rows * d_f.cols; ++i) {
        if (std::fabs(curr_f.data[i] - prev_f.data[i]) < PIXEL_DIFF_THRESHOLD) continue;
        d_f.data[i] = 0; // mark as changed
    }

    return d_f;
}
