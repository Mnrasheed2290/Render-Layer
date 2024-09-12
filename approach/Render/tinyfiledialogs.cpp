#include <opencv2/opencv.hpp>
#include <iostream>
#include "tinyfiledialogs.h"  // Include tinyfiledialogs header

int main() {
 // Open file dialog
 const char* file = tinyfd_openFileDialog(
     "Select an image",
     "",  // Default path (can be left empty)
     0, nullptr, nullptr, 0
 );

 if (!file) {
  std::cerr << "No file selected!" << std::endl;
  return -1;
 }

 std::string imagePath = file;
 cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);

 if (image.empty()) {
  std::cerr << "Could not open or find the image: " << imagePath << std::endl;
  return -1;
 }

 // Display the image
 cv::imshow("Selected Image", image);
 cv::waitKey(0);  // Wait for a keystroke in the window

 return 0;
}
