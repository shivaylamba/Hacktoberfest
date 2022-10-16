#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {



	VideoCapture cap(0);
	Mat img;

	while (true) {

		cap.read(img);
		imshow("Image", img);
		waitKey(1);


	}



	return 0;


}
