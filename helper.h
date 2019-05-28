#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

struct PointData { 
    float cornerResponse;
    Point point;
};

struct CornerResponse { 
    bool operator()(PointData const &left, PointData const &right) { 
        return left.cornerResponse > right.cornerResponse;
    }
};

struct Derivatives {
	Mat Ix;
	Mat Iy;
	Mat Ixy;
};

class Helper {
public:
	static void DisplayImage(Mat& img, string title);
	static void DisplayMat(Mat& img);
	static void DisplayPointVector(vector<Point> vp);

	static Mat MarkInImage(Mat& img, vector<PointData> points, int radius);
};