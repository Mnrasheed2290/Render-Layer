#ifndef V1_H
#define V1_H

#include <opencv2/opencv.hpp>
#include <iostream>

namespace Approach::Render {

 class V1 {
 public:
  cv::Mat process(const cv::Mat& image) {
   cv::Mat processed;
   // Example processing (modify as needed)
   image.copyTo(processed);
   std::cout << "Processing in V1" << std::endl;
   return processed;
  }
 };

} // namespace Approach::Render

#endif // V1_H
