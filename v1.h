#ifndef V1_H
#define V1_H

#include <opencv2/opencv.hpp>
#include <iostream>

namespace Approach::Render {

 class V1 {
 public:
  void process(cv::Mat &image) {
   // Edge detection
   cv::Mat edges;
   cv::Canny(image, edges, 100, 200);
   image = edges;
   std::cout << "Processing in V1 (Edge Detection)" << std::endl;
  }
 };

} // namespace Approach::Render

#endif // V1_H
