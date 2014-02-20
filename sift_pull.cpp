#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/legacy/legacy.hpp>
#include <opencv2/features2d/features2d.hpp>
#include "opencv2/core/core.hpp"
#include <stdio.h>
#include <vector>

int main(int argc, char *argv[]) {

    cv::Mat colorImg1 = cv::imread("../picts/non1.png");
    cv::Mat colorImg2 = cv::imread("../picts/non2.jpg");
    if(colorImg1.empty() || colorImg2.empty()){
        std::cout << "No Image" << std::endl;
        return -1;
    }

    cv::Mat grayImg1, grayImg2;
    cv::cvtColor(colorImg1, grayImg1, CV_BGR2GRAY);
    cv::normalize(grayImg1, grayImg1, 0, 255, cv::NORM_MINMAX);
    cv::cvtColor(colorImg2, grayImg2, CV_BGR2GRAY);
    cv::normalize(grayImg2, grayImg2, 0, 255, cv::NORM_MINMAX);

    cv::SiftFeatureDetector detector;
    cv::SiftDescriptorExtractor extractor;

    std::vector<cv::KeyPoint> keypoints1;
    detector.detect(grayImg1, keypoints1);
    std::vector<cv::KeyPoint> keypoints2;
    detector.detect(grayImg2, keypoints2);

    cv::Mat descriptors1;    
    extractor.compute(grayImg1, keypoints1, descriptors1);    
    cv::Mat descriptors2;    
    extractor.compute(grayImg2, keypoints2, descriptors2);  
   
    std::cout << keypoints1.size() << std::endl;
   return 0;

}
