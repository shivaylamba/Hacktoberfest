#include<pencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
    int Rhist[256],Ghist[256],Bhist[256],Greyhist[256],threshold;

    Mat RGBimage=("Cat.jpg");
    Mat Greyimage(RGBimage.rows,RGBimage.cols,CV_8UC1);
    Mat BinaryTimage(RGBimage.rows,RGBimage.cols,CV_8UC1);

    for(int i=0;i<RGBimage.rows;++i)
    {
        for(int j=0;j<RGBimage.cols;++j)
        {
            Greyimage.at<uchar>(i,j)=(RGBimage.at<Vec3b>(i,j)[0]+RGBimage.at<Vec3b>(i,j)[1]+RGBimage.at<Vec3b>(i,j)[2])/3;
        }
    }

    for(int i=0;i<256;++i)
    {
        Rhist[i]=0;
        Ghist[i]=0;
        Bhist[i]=0;
        Greyhist[i]=0;
    }

    for(int i=0;i<RGBimage.rows;++i)
    {
        for(int j=0;i<RGBimage.cols;++j)
        {
            ++Rhist[RGBimage.at<Vec3b>(i,j)[0]];
            ++Ghist[RGBimage.at<Vec3b>(i,j)[2]];
            ++Bhist[RGBimage.at<Vec3b>(i,j)[2]];
            ++Greyhist[Greyimage.at<uchar>(i,j)];
        }
    }

    for(int i=0;i<256;++i)
    {
        cout<<"Rhist["<<i<<"]= "<<Rhist[i]<<"\tGhist["<<i<<"]= "<<Ghist[i]<<"\tBhist["<<i<<"]= "<<Bhist[i]<<endl;
    }

    for(int i=0;i<256;++i)
    {
        cout<<"Greyhist["<<i<<"]= "<<Greyhist[i]<<endl;
    }

    cout<<endl<<"Enter threshold value for binary thresholding the grey image : ";
    cin>>threshold;

    for(int i=0;i<Greyimage.rows;++i)
    {
        for(int j=0;i<Greyimage.cols;++j)
        {
            a=Greyimage.at<uchar>(i,j);
            if(a>threshold)
            {
                BinaryTimage.at<uchar>(i,j)=255;
            }
            else
            {
                BinaryTimage.at<uchar>(i,j)=0;
            }
        }
    }

    imshow("RGB Image",RGBimage);
    imshow("Grey Image",Greyimage);
    imshow("Binary Thresholded",BinaryTimage);

    waitKey(0);

    return(0);
}