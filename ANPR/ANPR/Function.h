#pragma once
#include <opencv/cv.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/ml/ml.hpp>
#include <iostream>
class Function
{
public:
	Function();
	void FindCharacter( std::vector<IplImage*> *LstChar ,IplImage* plate);
};

