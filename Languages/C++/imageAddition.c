#include<iostream>
#include<opencv2/opencv.hpp>

//code to check the resolution of the custom input video and resise it


using namespace std;
using namespace cv;

int main()
{

	Mat colorImage = imread("C:\\New folder\\3.jpg");
	Mat colorImage2 = imread("C:\\New folder\\4.jpg");
	Mat nframe_1(colorImage.rows, colorImage.cols, CV_8UC1);
	Mat nframe_2(colorImage.rows, colorImage.cols, CV_8UC1);

	for (int i = 0; i < colorImage.rows; i++)
	{
		for (int j = 0; j < colorImage.cols; j++)
		{
			int B = colorImage.at<Vec3b>(i, j)[0];
			int G = colorImage.at<Vec3b>(i, j)[1];
			int R = colorImage.at<Vec3b>(i, j)[2];

			//conversion from RGB to grey
			nframe_1.at<uchar>(i, j) = (B + G + R) / 3;
		}
	}

	for (int i = 0; i < colorImage.rows; i++)
	{
		for (int j = 0; j < colorImage.cols; j++)
		{
			int B = colorImage2.at<Vec3b>(i, j)[0];
			int G = colorImage2.at<Vec3b>(i, j)[1];
			int R = colorImage2.at<Vec3b>(i, j)[2];

			//conversion from RGB to grey
			nframe_2.at<uchar>(i, j) = (B + G + R) / 3;
		}
	}




	while (1) {
		
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
				//int c = (a > b) ? a - b : b - a;
				addImage.at<uchar>(i, j) = a+b;
			}
		}
		
		
		//video_add.write(addImage);
		imshow("frame", addImage);
		if (waitKey(30) >= 0)
			break;

	}


	//printf("width1:%d\nwidth2:%d\nheight1:%d\nheight2:%d\n",width1,width2,height1,height2);
	return 0;
}