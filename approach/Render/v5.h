#ifndef V5_H
#define V5_H

#include <opencv2/opencv.hpp>
#include <iostream>

namespace Approach::Render {

 class V5 {
 public:
  void process(cv::Mat &image) {
   // Contour detection
   std::vector<std::vector<cv::Point>> contours;
   cv::findContours(image, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
   cv::Mat contourImage = cv::Mat::zeros(image.size(), CV_8UC3);
   cv::drawContours(contourImage, contours, -1, cv::Scalar(255, 0, 0), 2);
   image = contourImage;
   std::cout << "Processing in V5 (Contour Detection)" << std::endl;
  }

  bool needsFurtherProcessing(const cv::Mat &image) {
   // Check some criteria to decide if further processing is needed
   // For example, we might check the number of contours detected
   std::vector<std::vector<cv::Point>> contours;
   cv::findContours(image, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
   return contours.size() < 1; // if no contours are detected, we need more processing
  }
 };

} // namespace Approach::Render

#endif // V5_H
