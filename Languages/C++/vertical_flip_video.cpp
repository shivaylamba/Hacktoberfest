#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
	VideoCapture cap(0);	//open the default camera
	if (!cap.isOpened()) {
		printf("error while reading from camera\n");
		return -1;
	}

	//Mat edges;
	//namedWindow("edges", 1);

	int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

	//debugging code, ignore
	printf("frame width= %d \nframe height= %d\n", frame_width, frame_height);

	VideoWriter video_orig("original.avi", CV_FOURCC('M', 'J', 'P', 'G'), 30, Size(frame_width, frame_height), false);
	VideoWriter video_trans("vflip.avi", CV_FOURCC('M', 'J', 'P', 'G'), 30, Size(frame_width, frame_height), false);

	while (1) {
		Mat frame;
		cap >> frame;	//get a new frame from the camera
		if (frame.empty())
			break;
		cvtColor(frame, frame, COLOR_BGR2GRAY);
		//GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
		//Canny(edges, edges, 0, 30, 3);
		Mat vflip(frame.rows, frame.cols, CV_8UC1);
		int i, j;
		for (i = 0; i < frame.rows; i++)
			for (j = 0; j < frame.cols; j++)
				vflip.at<uchar>(i, j) = frame.at<uchar>(i, frame.cols - j);

		imshow("frame", frame);
		imshow("vflip", vflip);
		video_orig.write(frame);
		video_trans.write(vflip);
		if (waitKey(30) >= 0)
			break;
	}
	return 0;
}

