#ifndef V5_H
#define V5_H

#include <opencv2/opencv.hpp>
#include <iostream>

namespace Approach::Render {

 class V5 {
 public:
  cv::Mat process(const cv::Mat& image) {
   cv::Mat edges;
   cv::Canny(image, edges, 100, 200);
   std::cout << "Processing in V5 (Canny Edge Detection)" << std::endl;
   return edges;
  }
 };

} // namespace Approach::Render

#endif // V5_H
