#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<opencv2/opencv.hpp>
extern int width;


using namespace std;
using namespace cv;

int main()
{
	Mat colorImage = imread("C:\\Users\\Srinath\\Desktop\\img2.jpg");

	//mat variable for grey image
	Mat greyImage(colorImage.rows, colorImage.cols, CV_8UC1);

	//accessing image pixels when image in RGB format
	for (int i = 0; i < colorImage.rows; i++)
	{
		for (int j = 0; j < colorImage.cols; j++)
		{
			int B = colorImage.at<Vec3b>(i, j)[0];
			int G = colorImage.at<Vec3b>(i, j)[1];
			int R = colorImage.at<Vec3b>(i, j)[2];

			//conversion from RGB to grey
			greyImage.at<uchar>(i, j) = (B + G + R) / 3;
		}
	}

	Mat colImage(colorImage.rows, (colorImage.cols * 2), CV_8UC1);

	int x = 0, y = 0;
	for (int i = 0; i < colorImage.rows; i++)
	{
		for (int j = 0; j < colorImage.cols; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				colImage.at<uchar>(x, y) = greyImage.at<uchar>(i, j);
				y++;

			}

		}
	}
}
