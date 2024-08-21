#ifndef V2_H
#define V2_H

#include <opencv2/opencv.hpp>
#include <iostream>

namespace Approach::Render {

 class V2 {
 public:
  void process(cv::Mat &image) {
   // Gaussian blur
   cv::Mat blurred;
   cv::GaussianBlur(image, blurred, cv::Size(5, 5), 1.5);
   image = blurred;
   std::cout << "Processing in V2 (Gaussian Blur)" << std::endl;
  }
 };

} // namespace Approach::Render

#endif // V2_H
