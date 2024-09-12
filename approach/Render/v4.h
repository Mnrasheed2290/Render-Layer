#ifndef V4_H
#define V4_H

#include <opencv2/opencv.hpp>
#include <iostream>

namespace Approach::Render {

 class V4 {
 public:
  cv::Mat process(const cv::Mat& image) {
   cv::Mat processed;
   cv::GaussianBlur(image, processed, cv::Size(5, 5), 0);
   std::cout << "Processing in V4 (Gaussian Blur)" << std::endl;
   return processed;
  }
 };

} // namespace Approach::Render

#endif // V4_H
