#ifndef V4_H
#define V4_H

#include <opencv2/opencv.hpp>
#include <iostream>

namespace Approach::Render {

 class V4 {
 public:
  void process(cv::Mat &image) {
   // Morphological transformations (e.g., dilation)
   cv::Mat morph;
   cv::dilate(image, morph, cv::Mat(), cv::Point(-1, -1), 2);
   image = morph;
   std::cout << "Processing in V4 (Morphological Transformations)" << std::endl;
  }

  bool needsFurtherProcessing(const cv::Mat &image) {
   // Check some criteria to decide if further processing is needed
   // For example, we might check the number of non-zero pixels in the image
   int nonZeroCount = cv::countNonZero(image);
   return nonZeroCount < image.total() * 0.1; // if less than 10% of the image is non-zero, we need more processing
  }
 };

} // namespace Approach::Render

#endif // V4_H
