#ifndef V3_H
#define V3_H

#include <opencv2/opencv.hpp>
#include <iostream>

namespace Approach::Render {

 class V3 {
 public:
  cv::Mat process(const cv::Mat& image) {
   cv::Mat thresholded;
   cv::threshold(image, thresholded, 128, 255, cv::THRESH_BINARY);
   std::cout << "Processing in V3 (Thresholding)" << std::endl;
   return thresholded;
  }
 };

} // namespace Approach::Render

#endif // V3_H
