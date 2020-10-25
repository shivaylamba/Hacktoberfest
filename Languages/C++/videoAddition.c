#include<iostream>
#include<opencv2/opencv.hpp>

//code to check the resolution of the custom input video and resise it


using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap_1("C:\\New folder\\sanskari.mp4");
	VideoCapture cap_2("C:\\New folder\\bridge.mp4");
	if (!cap_1.isOpened() || !cap_2.isOpened()) {
		printf("error while reading\n");
	}

	int frame_width = cap_1.get(CV_CAP_PROP_FRAME_WIDTH);
	int frame_height = cap_1.get(CV_CAP_PROP_FRAME_HEIGHT);
	int frame_width2 = cap_2.get(CV_CAP_PROP_FRAME_WIDTH);
	int frame_height2 = cap_2.get(CV_CAP_PROP_FRAME_HEIGHT);


	printf("width1:%d\nwidth2:%d\nheight1:%d\nheight2:%d\n", frame_width, frame_width2, frame_height, frame_height2);
	
	
	/*Mat f1, f2;
	cap_1 >> f1;
	cap_2 >> f2;
	*/


	VideoWriter video_add("C:\\New folder\\vadd.mp4", CV_FOURCC('M', 'P', '4', '2'), 30, Size(frame_width/2, frame_height/2), false);

	while (1) {
		Mat frame_1,frame_2;
		cap_1 >> frame_1;
		cap_2 >> frame_2;
		if (frame_1.empty() || frame_2.empty())
			break;
		cvtColor(frame_1, frame_1, COLOR_BGR2GRAY);
		cvtColor(frame_2, frame_2, COLOR_BGR2GRAY);

		Mat nframe_1,nframe_2;
		resize(frame_1, nframe_1, cvSize(0, 0), 0.5, 0.5);
		resize(frame_2, nframe_2, cvSize(0, 0), 0.5, 0.5);

		int width1, width2, height1, height2;

		width1 = nframe_1.cols;
		width2 = nframe_2.cols;
		height1 = nframe_1.rows;
		height2 = nframe_2.rows;

		
		
		int width = (width1 > width2) ? width1 : width2;
		int height = (height1 > height2) ? height1 : height2;

		Mat addImage(height, width, CV_8UC1);

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				int a = (j > width1 || i > height1) ? 0 : nframe_1.at<uchar>(i,j);
				int b = (j > width2 || i > height2) ? 0 : nframe_2.at<uchar>(i,j);
				//addImage.at<uchar>(i, j) = nframe_1.at<uchar>(i,j) + nframe_2.at<uchar>(i,j);
				addImage.at<uchar>(i, j) = a + b;
			}
		}
		
		
		video_add.write(addImage);
		//imshow("frame", addImage);
		if (waitKey(30) >= 0)
			break;

	}
	//printf("width1:%d\nwidth2:%d\nheight1:%d\nheight2:%d\n",width1,width2,height1,height2);

	return 0;
}