#ifndef V2_H
#define V2_H

#include <opencv2/opencv.hpp>
#include <iostream>

namespace Approach::Render {

 class V2 {
 public:
  cv::Mat process(const cv::Mat& image) {
   cv::Mat processed;
   // Example processing (modify as needed)
   cv::GaussianBlur(image, processed, cv::Size(5, 5), 0);
   std::cout << "Processing in V2 (Gaussian Blur)" << std::endl;
   return processed;
  }
 };

} // namespace Approach::Render

#endif // V2_H
