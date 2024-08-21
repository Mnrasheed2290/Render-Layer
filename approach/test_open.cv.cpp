#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
 std::cout << "Testing OpenCV Installation" << std::endl;

 // Create a simple black image
 cv::Mat image = cv::Mat::zeros(300, 300, CV_8UC3);

 // Draw a white diagonal line
 cv::line(image, cv::Point(0, 0), cv::Point(300, 300), cv::Scalar(255, 255, 255), 5);

 // Display the image
 cv::imshow("Test Image", image);
 cv::waitKey(0);

 std::cout << "OpenCV is working correctly!" << std::endl;
 return 0;
}
