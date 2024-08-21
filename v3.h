//
// Created by maria on 8/21/2024.
//

#ifndef V3_H
#define V3_H

#endif //V3_H#ifndef V3_H
#define V3_H

#include <opencv2/opencv.hpp>
#include <iostream>

namespace Approach::Render {

 class V3 {
 public:
  void process(cv::Mat &image) {
   // Thresholding
   cv::Mat thresholded;
   cv::threshold(image, thresholded, 128, 255, cv::THRESH_BINARY);
   image = thresholded;
   std::cout << "Processing in V3 (Thresholding)" << std::endl;
  }
 };

} // namespace Approach::Render

#endif // V3_H

