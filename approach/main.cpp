#include "derivednode.h"
#include "Render/v1.h"
#include "v2.h"
#include "Render/v3.h"
#include "Render/v4.h"
#include "Render/v5.h"
#include "cnn.h"
#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
 // Initialize your derived node (if needed)
 MyNamespace::DerivedNode node;
 node.someMethod(); // Call the method to check if it works

 // Load an image
 cv::Mat image = cv::imread("C:/Users/maria/OneDrive/Desktop/download.jpg");
 if (image.empty()) {
  std::cerr << "Could not open or find the image" << std::endl;
  return -1;
 }

 // Processing stages
 Approach::Render::V1 v1;
 v1.process(image);

 Approach::Render::V2 v2;
 v2.process(image);

 Approach::Render::V3 v3;
 v3.process(image);

 Approach::Render::V4 v4;
 Approach::Render::V5 v5;

 // Feedback loop for V4 and V5
 bool needsProcessing = true;
 int maxIterations = 10; // Limit to avoid infinite loops
 int iteration = 0;

 while (needsProcessing && iteration < maxIterations) {
  v4.process(image);
  needsProcessing = v4.needsFurtherProcessing(image);

  if (!needsProcessing) {
   v5.process(image);
   needsProcessing = v5.needsFurtherProcessing(image);
  }

  iteration++;
 }

 // Display final processed image
 cv::imshow("Final Processed Image", image);
 cv::waitKey(0);

 // CNN for classification
 CNN cnn;
 cnn.loadModel("path/to/your/model"); // Update this path
 std::string result = cnn.classify(image);

 std::cout << "Classification result: " << result << std::endl;

 return 0;
}
