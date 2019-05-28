#pragma once

#include "helper.h"

class Harris {
public:
    Harris(Mat img, float k, int filterRange, bool gauss);
	vector<PointData> GetMaximaPoints(float percentage, int filterRange, int suppressionRadius);

private:
	Mat ConvertRgbToGrayscale(Mat& img);
	Derivatives ComputeDerivatives(Mat& greyscaleImg);	
	Derivatives ApplyMeanToDerivatives(Derivatives& dMats, int filterRange);
	Derivatives ApplyGaussToDerivatives(Derivatives& dMats, int filterRange);
	Mat ComputeHarrisResponses(float k, Derivatives& intMats);

	Mat ComputeIntegralImg(Mat& img);
	Mat MeanFilter(Mat& intImg, int range);
	Mat GaussFilter(Mat& img, int range);

private:
	Mat harrisResponses;
};