#include "Function.h"

Function::Function()
{
}

void Function::FindCharacter(std::vector<IplImage*>* LstChar, IplImage* plate)
{
	std::vector<CvRect> rect;
	IplImage* resizeImg, * binaryImg, * cloneImg;
	if (!plate)
	{
		return;
	}
	resizeImg = cvCreateImage(cvSize(408, 70), IPL_DEPTH_8U, 3);
	binaryImg = cvCreateImage(cvSize(408, 70), IPL_DEPTH_8U, 1);

	cvResize(plate, resizeImg);
	cvCvtColor(resizeImg, binaryImg, CV_RGB2GRAY);
	cvAdaptiveThreshold(binaryImg, binaryImg, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 13, 2);

	cloneImg = cvCloneImage(resizeImg);

	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* contours = cvCreateSeq(CV_SEQ_ELTYPE_POINT, sizeof(CvSeq), sizeof(CvPoint), storage);
	cvFindContours(binaryImg, storage, &contours);

	double ratio, ratioWhite;
	int s, white;

	while (contours) {
		CvRect r = cvBoundingRect(contours, 0);

		ratio = (double)r.width / r.height;
		s = r.width * r.height;

		cvSetImageROI(binaryImg, r);
		white = cvCountNonZero(binaryImg);
		cvResetImageROI(binaryImg);
		ratioWhite = (double)white / s;

		if (ratio > 0.3 && ratio < 1.1 &&
			s > 375 && r.width > 15 && r.width < 50 &&
			r.height > 20 && r.height < 65 &&
			ratioWhite > 0.3 && ratioWhite < 0.75 && r.x > 2)
		{
			cvRectangle(cloneImg, cvPoint(r.x, r.y), cvPoint(r.x + r.width, r.y + r.height), cvScalar(255, 0, 0), 2);

			rect.push_back(r);
		}

		contours = contours->h_next;
	}

	// sap xep
	for (int i = 0; i < rect.size() - 1; i++)
	{
		for (int j = i + 1; j < rect.size(); j++)
		{
			if (rect[i].x > rect[j].x)
			{
				CvRect sw;
				sw = rect[i];
				rect[i] = rect[j];
				rect[j] = sw;
			}
		}
	}

	// cat ky tu
	IplImage* charImg;
	IplImage* saveImg;
	//cv::Mat m;
	for (int i = 0; i < rect.size(); i++)
	{
		charImg = cvCreateImage(cvSize(rect[i].width, rect[i].height), IPL_DEPTH_8U, 3);
		cvSetImageROI(resizeImg, rect[i]);
		cvCopy(resizeImg, charImg, NULL);
		cvResetImageROI(resizeImg);
		saveImg = cvCreateImage(cvSize(rect[i].width, rect[i].height), IPL_DEPTH_8U, 1);
		cvCvtColor(charImg, saveImg, CV_RGB2GRAY);
		cvAdaptiveThreshold(saveImg, saveImg, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 13, 2);
		LstChar->push_back(saveImg);
		char sname[10];
		//sprintf(sname, "Data %d.jpg", i+1);
		//cvShowImage(sname, saveImg);
		//cvSaveImage("Data\1.jpg", plate);
	}
}
