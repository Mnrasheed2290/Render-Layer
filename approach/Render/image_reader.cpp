#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
 if (argc < 2) {
  std::cerr << "Usage: " << argv[0] << " <Image_Path>" << std::endl;
  return -1;
 }

 std::string imagePath = argv[1];
 cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);

 if (image.empty()) {
  std::cerr << "Could not open or find the image: " << imagePath << std::endl;
  return -1;
 }

 // Display the image
 cv::imshow("Cat Eating Ice Cream", image);
 cv::waitKey(0);  // Wait for a keystroke in the window

 return 0;
}
