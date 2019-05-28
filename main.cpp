#include "helper.h"
#include "harris.h"

// Specifies the sensitivity factor of the Harris algorithm (0 < k < 0.25)
float k = 0.25;
// Size of the box filter that is applied to the integral images
int boxFilterSize = 3;
// dimension of the maxima suppression box around a maxima
int maximaSuppressionDimension = 10;

// dimension of the objects showing a maxima in the image
int markDimension = 5;

// constant for the slider-value division
float divisionConstant = 1000000;

//Global variables
int slider_valueMaxsp = 10;
int slider_valueMeanfilter = 2;
int slider_valuePercentage = 1;
float percentage = 50;
bool gauss = true;

void doHarris(Mat &image) {
    // compute harris
    Harris harris = Harris(image, k, boxFilterSize, gauss);

    // get vector of points wanted
    vector<PointData> resPts = harris.GetMaximaPoints(percentage, boxFilterSize, maximaSuppressionDimension);
    // cout << resPts.size() << " Points" << endl;

    Mat _img = Helper::MarkInImage(image, resPts, markDimension);
    imshow("Floor Detection", _img);
}

//-----------------------------------------------------------------------------------------------
int main(int argc, char** argv) {
    // read image from file + error handling
    Mat img;

    if (argc == 1) {
        cout << "No image provided! Usage: ./floordetection [path to image]" << endl << "Using default image: haus.jpg" << endl;

        img = imread("haus.jpg");
    } else {
        img = imread(argv[1]);
    }

    // create UI and show the image
    namedWindow("Floor Detection", 1);

    // Display image
    imshow("Floor Detection", img);

    // Do Harris
    doHarris(img);

    waitKey(0);

    return 0;

}
