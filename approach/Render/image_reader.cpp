#include <opencv2/opencv.hpp>
#include "v1.h"
#include "v2.h"
#include "v3.h"
#include "v4.h"
#include "v5.h"
#include <iostream>
#include "tinyfiledialogs.h"

int main() {
 // Open a file dialog to select an image
 const char* filename = tinyfd_openFileDialog(
     "Select an image file",
     "C:\Users\maria\Desktop"
     1,  // Only allow one file to be selected
     nullptr,  // No filter
     nullptr,  // No filter description
     0  // No default path
 );

 if (!filename) {
  std::cerr << "Error: No file selected!" << std::endl;
  return -1;
 }

 // Load the selected image
 cv::Mat image = cv::imread(filename);
 if (image.empty()) {
  std::cerr << "Error: Image not found or cannot be opened!" << std::endl;
  return -1;
 }

 // Initialize processing layers
 Approach::Render::V1 v1;
 Approach::Render::V2 v2;
 Approach::Render::V3 v3;
 Approach::Render::V4 v4;
 Approach::Render::V5 v5;

 // Process the image through layers
 cv::Mat processedImage = v1.process(image);
 processedImage = v2.process(processedImage);
 processedImage = v3.process(processedImage);
 processedImage = v4.process(processedImage);
 processedImage = v5.process(processedImage);

 // Display the final processed image
 cv::imshow("Processed Image", processedImage);
 cv::waitKey(0);

 return 0;
}
