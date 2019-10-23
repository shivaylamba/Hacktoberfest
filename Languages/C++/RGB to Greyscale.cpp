#include<pencv2/opencv.hpp>     //including opencv library
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
    //initializing the variables to use
    //threshold is for setting threshold value
    int Rhist[256],Ghist[256],Bhist[256],Greyhist[256],threshold;

    //initialising the image matrices
    Mat RGBimage=("Cat.jpg");
    Mat Greyimage(RGBimage.rows,RGBimage.cols,CV_8UC1);
    Mat BinaryTimage(RGBimage.rows,RGBimage.cols,CV_8UC1);

    //converting RGB image to Grey image
    for(int i=0;i<RGBimage.rows;++i)
    {
        for(int j=0;j<RGBimage.cols;++j)
        {
            Greyimage.at<uchar>(i,j)=(RGBimage.at<Vec3b>(i,j)[0]+RGBimage.at<Vec3b>(i,j)[1]+RGBimage.at<Vec3b>(i,j)[2])/3;
        }
    }

    //Nullifying the histogram values
    for(int i=0;i<256;++i)
    {
        Rhist[i]=0;
        Ghist[i]=0;
        Bhist[i]=0;
        Greyhist[i]=0;
    }

    //Calculating histogram values for RGB and Grey image
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

    //Printing histogram values for RGB image
    for(int i=0;i<256;++i)
    {
        cout<<"Rhist["<<i<<"]= "<<Rhist[i]<<"\tGhist["<<i<<"]= "<<Ghist[i]<<"\tBhist["<<i<<"]= "<<Bhist[i]<<endl;
    }

    //Printing histogarm values for Grey image
    for(int i=0;i<256;++i)
    {
        cout<<"Greyhist["<<i<<"]= "<<Greyhist[i]<<endl;
    }

    cout<<endl<<"Enter threshold value for binary thresholding the grey image : ";
    cin>>threshold;

    //Binary thresholding with "threshold" as the thresholding value
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

    //Displaying the images
    imshow("RGB Image",RGBimage);
    imshow("Grey Image",Greyimage);
    imshow("Binary Thresholded",BinaryTimage);

    //To make the images to be display indefinitely
    waitKey(0);

    return(0);
}