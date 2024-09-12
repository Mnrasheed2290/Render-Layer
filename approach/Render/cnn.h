#ifndef CNN_H
#define CNN_H

#include <opencv2/dnn.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

class CNN {
private:
    cv::dnn::Net net; // The loaded CNN model

public:
    // Load the pre-trained CNN model
    void loadModel(const std::string &modelPath) {
        try {
            net = cv::dnn::readNetFromONNX(modelPath); // Assuming an ONNX model for portability
            std::cout << "Model loaded successfully from: " << modelPath << std::endl;
        } catch (cv::Exception &e) {
            std::cerr << "Error loading the model: " << e.what() << std::endl;
        }
    }

    // Preprocess the image before passing it to the CNN
    cv::Mat preprocessImage(const cv::Mat &image) {
        // Resize the image to the input size required by the model
        cv::Mat resized;
        cv::resize(image, resized, cv::Size(224, 224)); // Assuming the model takes 224x224 images

        // Convert the image to float and normalize to [0, 1] range
        cv::Mat inputBlob = cv::dnn::blobFromImage(resized, 1.0 / 255.0, cv::Size(224, 224), cv::Scalar(0, 0, 0), true, false);

        return inputBlob;
    }

    // Run the CNN model on the preprocessed image and get the classification result
    std::string classify(const cv::Mat &image) {
        // Preprocess the image
        cv::Mat inputBlob = preprocessImage(image);

        // Set the input to the network
        net.setInput(inputBlob);

        // Run forward pass to get predictions
        cv::Mat result = net.forward();

        // Find the class with the highest confidence
        double maxVal;
        cv::Point maxLoc;
        cv::minMaxLoc(result, 0, &maxVal, 0, &maxLoc);

        int classId = maxLoc.x; // Get the index of the class with the highest score

        // Map the classId to the corresponding label (you'll need a labels file for this)
        return getClassLabel(classId);
    }

    // You can implement this function to map the class index to an actual class name
    std::string getClassLabel(int classId) {
        // For now, let's return a placeholder; you'll need to map this to real class names
        // You could load these labels from a file or use a hardcoded list
        switch (classId) {
            case 0: return "Cat";
            case 1: return "Dog";
            case 2: return "Car";
            // Add more cases for your classes
            default: return "Unknown";
        }
    }
};

#endif // CNN_H
