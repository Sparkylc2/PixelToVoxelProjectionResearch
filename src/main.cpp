

#include "headers.h"

int main() {
    cv::VideoCapture cap;
    if (!init_camera(cap)) {
        std::cerr << "failed to open webcam.\n";
        return -1;
    }

    int width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));

    GLFWwindow* window;
    if (!init_glfw(window, width, height)) {
        std::cerr << "failed to initialize glfw/iopengl.\n";
        return -1;
    }

    GLuint texture = create_texture(width, height);

    cv::Mat prev_f = cv::Mat::zeros(height, width, CV_8UC1);
    cv::Mat curr_f;

    while (!glfwWindowShouldClose(window)) {
        if (get_frame(cap, curr_f)) {
            cv::cvtColor(curr_f, curr_f, cv::COLOR_BGR2GRAY); // convert to grayscale

            process_image_to_gray(curr_f);
            cv::Mat d_f = process_motion(prev_f, curr_f);
            cv::cvtColor(d_f, d_f, cv::COLOR_GRAY2RGB);


            update_texture(texture, d_f);
            render_texture(texture);

            prev_f = curr_f;
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    cap.release();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}