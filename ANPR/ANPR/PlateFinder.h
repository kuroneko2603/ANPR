#pragma once
#include <opencv/cv.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/ml/ml.hpp>
#include <iostream>
#include<sstream>
#include "Function.h"

const int MIN_CONTOUR_AREA = 100; //dien tich du kien cua anh moi ky tu
const int RESIZED_IMAGE_WIDTH = 20;
const int RESIZED_IMAGE_HEIGHT = 30;

class ContourWithData {
public:
	std::vector<cv::Point> ptContour;           // contour
	cv::Rect boundingRect;                      // bounding rect for contour
	float fltArea;                              // area of contour

	bool checkIfContourIsValid() {                              // obviously in a production grade program
		if (fltArea < MIN_CONTOUR_AREA) return false;           // we would have a much more robust function for 
		return true;                                            // identifying if a contour is valid !!
	}

	static bool sortByBoundingRectXPosition(const ContourWithData& cwdLeft, const ContourWithData& cwdRight) {      // this function allows us to sort
		return(cwdLeft.boundingRect.x < cwdRight.boundingRect.x);                                                   // the contours from left to right
	}

};

class PlateFinder
{
private:
	IplConvKernel *S1;
	IplConvKernel *S2;
	IplImage* Plate;
	Function f;
public:
	PlateFinder();
	~PlateFinder();
	void ImageRestoration(IplImage* src);//anh src phai la anh xam
	IplImage* FindPlate(IplImage* src, IplImage *& plate, IplImage *&charImg, std::string &strResult); // tim anh co the la bien so
	int CountCharacter(IplImage* plate , IplImage * &charImg);
	std::string CharRegconition(IplImage *CharImg);
};

