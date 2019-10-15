#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat colorImage = imread("D:\\Downloads\\Bandar.jpg");
	int i, j, k, m = 0, n = 0, s = 0;
	//mat variable for grey image
	Mat greyImage(colorImage.rows, colorImage.cols, CV_8UC1);
	Mat greyImage1(colorImage.rows, 2*colorImage.cols-1, CV_8UC1);
	Mat new2( colorImage.rows, 2 * colorImage.cols, CV_8UC1);
	Mat new1(2 * colorImage.rows, 2 * colorImage.cols, CV_8UC1);
	Mat new3(2 * colorImage.rows, 2 * colorImage.cols, CV_8UC1);
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
	int a, x = 0, y = 0;
	for (i = 0; i < greyImage.rows; i++)
	{
		for (j = 0; j < greyImage.cols; j++)
		{
			for (k = 0; k < 2; k++)
			{

				greyImage1.at<uchar>(x, y) = greyImage.at<uchar>(i, j);
				y++;
			}
		}
		x++;
		y = 0;
	}

	x = 0, y = 0;
	for (int i = 0; i < greyImage.rows; i++)
	{
		for (int k = 0; k < 2*greyImage.cols-1; k++)
		{
			
				if (k % 2 == 0)
				{
					
					new2.at<uchar>(m, n) = greyImage1.at<uchar>(i, k);
					
				}
				else
				{
					s = greyImage1.at<uchar>(i, k - 1) + greyImage1.at<uchar>(i, k + 1);
					new2.at<uchar>(m, n) = s / 2;
				}
				y++;
				n++;
			}
			m++;
			n = 0;
		}
	m = 0; n = 0;
	for (int i = 0; i < 2*greyImage.cols; i++)
	{
		for (int j = 0; j < greyImage.rows; j++)
		{
			for (k = 0; k < 2; k++)
			{
				new1.at<uchar>(m, n) = new2.at<uchar>(j, i);
				m++;
			}
		}
		 n++;
		m = 0;
	}
	x = 0; y = 0; m = 0; n = 0;
	for (int i = 0; i < 2*greyImage.rows - 1; i++)
	{
		for (int k = 0; k < 2 * greyImage.cols - 1; k++)
		{
			if (i % 2 == 0)
			{
				new3.at<uchar>(m, n) = new1.at<uchar>(i, k);

			}
			else
			{
				s = new1.at<uchar>(i - 1, k) + new1.at<uchar>(i + 1, k);
				new3.at<uchar>(m, n) = s / 2;
			}
			//x++;
			n++;
		}
		m++;
		n = 0;
	}

	//imshow("<window name>", <image variable>);
	imshow("1", greyImage);
	imshow("2", new3);
	waitKey(0);


	return 0;
}
