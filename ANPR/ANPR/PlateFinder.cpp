#include "PlateFinder.h"


PlateFinder::PlateFinder()
{
	S1 = cvCreateStructuringElementEx(3, 1, 1, 0, CV_SHAPE_RECT, NULL);
	S2 = cvCreateStructuringElementEx(6, 1, 3, 0, CV_SHAPE_RECT, NULL);
	Plate = NULL;
}

PlateFinder::~PlateFinder()
{
	if (Plate)
	{
		S1 = NULL;
		S2 = NULL;
		Plate = NULL;
	}
}

void PlateFinder::ImageRestoration(IplImage* src)
{
	int w = src->width;
	int h = src->height;

	IplImage* mImg = cvCreateImage(cvSize(w / 2, h / 2), IPL_DEPTH_8U, 1);		// Anh su dung cho bien doi hinh thai hoc
	IplImage* src_pyrdown = cvCreateImage(cvSize(w / 2, h / 2), IPL_DEPTH_8U, 1);
	IplImage* tmp = cvCreateImage(cvSize(w / 2, h / 2), IPL_DEPTH_8U, 1);
	IplImage* thresholed = cvCreateImage(cvSize(w / 2, h / 2), IPL_DEPTH_8U, 1);	// Anh nhi phan 
	IplImage* mini_thresh = cvCreateImage(cvSize(w / 2, h / 2), IPL_DEPTH_8U, 1);
	IplImage* dst = cvCreateImage(cvSize(w / 2, h / 2), IPL_DEPTH_8U, 1);			// Anh da lam ro vung bien so

	cvPyrDown(src, src_pyrdown);

	cvMorphologyEx(src_pyrdown, mImg, tmp, S2, CV_MOP_BLACKHAT);
	cvNormalize(mImg, mImg, 0, 255, CV_MINMAX);

	// Nhi phan hoa anh mImg
	cvThreshold(mImg, thresholed, (int)10 * cvAvg(mImg).val[0], 255, CV_THRESH_BINARY);
	cvZero(dst);
	cvCopy(thresholed, mini_thresh);

	// Su dung hinh chu nhat co size = 8x16 truot tren toan bo anh

	int cnt;
	int nonZero1, nonZero2, nonZero3, nonZero4;
	CvRect rect;

	for (int i = 0; i < mini_thresh->width - 32; i += 4)
	{
		for (int j = 0; j < mini_thresh->height - 16; j += 4)
		{
			rect = cvRect(i, j, 16, 8);
			cvSetImageROI(mini_thresh, rect);	//ROI = Region of Interest
			nonZero1 = cvCountNonZero(mini_thresh);
			cvResetImageROI(mini_thresh);

			rect = cvRect(i + 16, j, 16, 8);
			cvSetImageROI(mini_thresh, rect);	
			nonZero2 = cvCountNonZero(mini_thresh);
			cvResetImageROI(mini_thresh);

			rect = cvRect(i, j + 8, 16, 8);
			cvSetImageROI(mini_thresh, rect);	
			nonZero3 = cvCountNonZero(mini_thresh);
			cvResetImageROI(mini_thresh);

			rect = cvRect(i + 16, j + 8, 16, 8);
			cvSetImageROI(mini_thresh, rect);	
			nonZero4 = cvCountNonZero(mini_thresh);
			cvResetImageROI(mini_thresh);

			cnt = 0;
			if (nonZero1 > 15) { cnt++; }
			if (nonZero2 > 15) { cnt++; }
			if (nonZero3 > 15) { cnt++; }
			if (nonZero4 > 15) { cnt++; }

			if (cnt > 2)
			{
				rect = cvRect(i, j, 32, 16);
				cvSetImageROI(dst, rect);
				cvSetImageROI(mini_thresh, rect);
				cvCopy(mini_thresh, dst);
				cvResetImageROI(dst);
				cvResetImageROI(mini_thresh);
			}
		}
	}

	IplImage* dst_clone = cvCloneImage(dst);

	cvDilate(dst, dst, NULL, 2);
	cvErode(dst, dst, NULL, 2);
	cvDilate(dst, dst, S1, 9);
	cvErode(dst, dst, S1, 10);
	cvDilate(dst, dst);

	//cvShowImage("Source" , src);
	//cvShowImage("mImg", mImg);
	//cvShowImage("mini_thresh", mini_thresh);
	//cvShowImage("dst_clone", dst_clone);
	//cvShowImage("dst", dst);

	cvPyrUp(dst, src);

	cvReleaseImage(&mini_thresh);
	cvReleaseImage(&mImg);
	cvReleaseImage(&tmp);
	cvReleaseImage(&dst);
	cvReleaseImage(&src_pyrdown);
	cvReleaseImage(&thresholed);
	cvReleaseImage(&dst_clone);
}

IplImage* PlateFinder::FindPlate(IplImage* src, IplImage*& plate, IplImage*& charImg, std::string& strResult)
{
	strResult = "";
	std::vector<IplImage*> LstChar;
	IplImage* contourImg = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);// anh goc la anh mau
	IplImage* grayImg = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);//chuyen anh goc sang gray image

	cvCvtColor(src, grayImg, CV_RGB2GRAY);

	IplImage* cloneImg = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 3);
	cloneImg = cvCloneImage(src);

	cvCopy(grayImg, contourImg);
	cvNormalize(contourImg, contourImg, 0, 255, CV_MINMAX);
	ImageRestoration(contourImg);

	IplImage* rectImg = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 3);
	cvMerge(contourImg, contourImg, contourImg, NULL, rectImg);

	//tim contour 
	CvMemStorage* storagePlate = cvCreateMemStorage(0);
	CvSeq* contours = cvCreateSeq(CV_SEQ_ELTYPE_POINT, sizeof(CvSeq), sizeof(CvPoint), storagePlate);
	cvFindContours(contourImg, storagePlate, &contours, sizeof(CvContour), CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));

	//cvShowImage("contour", contourImg);

	int left, top, right, bottom, width, height, S, r1;
	int count;
	double r2;

	CvRect rectPlate;

	//mang luu cac anh co kha nang la bien so
	IplImage** plateArr = new IplImage * [5];
	int j = 0;
	for (int i = 0; i < 5; i++)
	{
		plateArr[i] = NULL;
	}
	while (contours)
	{
		count = contours->total;
		CvPoint* pointArr = new CvPoint[count];
		cvCvtSeqToArray(contours, pointArr, CV_WHOLE_SEQ);
		for (int i = 0; i < count; i++)
		{
			if (i == 0)
			{
				left = right = pointArr[0].x;
				top = bottom = pointArr[0].y;
			}
			if (pointArr[i].x > right)
				right = pointArr[i].x;
			else
				if (pointArr[i].x < left)
					left = pointArr[i].x;

			if (pointArr[i].y > bottom)
				bottom = pointArr[i].y;
			else
				if (pointArr[i].y < top)
					top = pointArr[i].y;
		}
		width = right - left;
		height = bottom - top;
		S = width * height;
		cvRectangle(rectImg, cvPoint(left, top), cvPoint(right, bottom), cvScalar(0, 255, 0));
		//loai bo bot theo ty le so voi anh goc
		if (S != 0)
		{
			r1 = (contourImg->width * contourImg->height / S);
			r2 = (double)(width / height);
		}
		else {
			r1 = 0;
			r2 = 0;
		}

		if (r1 > 30 && r1 < 270)
		{
			cvRectangle(rectImg, cvPoint(left, top), cvPoint(right, bottom), cvScalar(255, 0, 0));
			if (r2 > 2.6 && r2 < 7)
			{
				cvRectangle(rectImg, cvPoint(left, top), cvPoint(right, bottom), cvScalar(0, 255, 0));
				if (width > 80 && width < 600 && height>25 && height < 150)
				{
					rectPlate = cvRect(left, top, width, height);
					cvRectangle(cloneImg, cvPoint(rectPlate.x, rectPlate.y),
						cvPoint(rectPlate.x + rectPlate.width, rectPlate.y + rectPlate.height), cvScalar(0, 0, 255), 3);
					//cat bien so
					plate = cvCreateImage(cvSize(rectPlate.width, rectPlate.height), IPL_DEPTH_8U, 3);
					cvSetImageROI(src, rectPlate);
					cvCopy(src, plate, NULL);
					cvResetImageROI(src);
					//luu bien so vao mang
					int total = CountCharacter(plate, charImg);//dem sl ky tu trong bien so tim dc 
					if (total >= 5)
					{
						plateArr[j] = cvCloneImage(plate);
						j++;
					}

				}
			}
		}
		delete[]pointArr;
		contours = contours->h_next;
	}
	//dem so ky tu trong plate de tim ra platearr co kha nang cao nhat la bien so
	//cvShowImage("charimg", charImg);
	int tmp = 0;
	if (plateArr[0])
	{
		int w = plateArr[0]->width;
		for (int i = 1; i < 4; i++) {
			if (plateArr[i] && plateArr[i]->width < w)
				tmp = i;
		}
		plateArr[tmp];
	}
	plate = plateArr[tmp];
	f.FindCharacter(&LstChar, plate);
	for (int i = 0; i < LstChar.size(); i++)
	{
		char sname[10];
		sprintf(sname, "Data %d.jpg", i + 1);
		strResult += CharRegconition(LstChar.at(i));
		//cvShowImage(sname, LstChar.at(i));
	}
	//cvShowImage("plateImg", plate);
	//cvShowImage("Img", cloneImg);
	//cvShowImage("rectImg", rectImg);
	cvReleaseImage(&contourImg);
	cvReleaseImage(&rectImg);
	//cvReleaseImage(&plate);
	return plate;
}

int PlateFinder::CountCharacter(IplImage* plate, IplImage*& charImg)
{
	int i = 0;
	IplImage* resizePlate, * binImg;
	resizePlate = cvCreateImage(cvSize(400, 70), IPL_DEPTH_8U, 3);
	binImg = cvCreateImage(cvSize(400, 70), IPL_DEPTH_8U, 1);
	cvResize(plate, resizePlate);
	cvCvtColor(resizePlate, binImg, CV_RGB2GRAY);
	cvAdaptiveThreshold(binImg, binImg, 255, CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 13, 2);
	//cvShowImage("bin img", binImg);
	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* contours = cvCreateSeq(CV_SEQ_ELTYPE_POINT, sizeof(CvSeq), sizeof(CvPoint), storage);
	cvFindContours(binImg, storage, &contours);

	while (contours) {
		CvRect rect = cvBoundingRect(contours);
		if (rect.width > 15 && rect.width < 50 && rect.height >40 && rect.height < 65 && rect.width * rect.height>1000)
		{
			cvRectangle(resizePlate, cvPoint(rect.x, rect.y), cvPoint(rect.x + rect.width, rect.y + rect.height), cvScalar(255, 0, 0), 2);//ve hcn vao anh
			i++;
		}
		contours = contours->h_next;
	}
	if (i >= 5)
	{
		charImg = resizePlate;
	}
	return i;
}

std::string PlateFinder::CharRegconition(IplImage* CharImg)
{
	std::vector<ContourWithData> allContoursWithData;           
	std::vector<ContourWithData> validContoursWithData;
	cv::Mat matClassificationInts;      // mang anh luu du lieu mau

	cv::FileStorage fsClassifications("classifications.xml", cv::FileStorage::READ);        // mo file du lieu training

	if (fsClassifications.isOpened() == false) {                                                   
		std::cout << "error, unable to open training classifications file, exiting program\n\n";    
		return(0);                                                                            
	}

	fsClassifications["classifications"] >> matClassificationInts;      // doc train img vao mang anh
	fsClassifications.release();                                        																	

	cv::Mat matTrainingImagesAsFlattenedFloats;         

	cv::FileStorage fsTrainingImages("images.xml", cv::FileStorage::READ);          // mo file anh dung de train

	if (fsTrainingImages.isOpened() == false) {                                               
		std::cout << "error, unable to open training images file, exiting program\n\n";        
		return "a";                                                                            
	}

	fsTrainingImages["images"] >> matTrainingImagesAsFlattenedFloats;          
	fsTrainingImages.release();                          

																				// train thui

	cv::Ptr<cv::ml::KNearest>  kNearest(cv::ml::KNearest::create());            // instantiate KNN 

																				
																				
	kNearest->train(matTrainingImagesAsFlattenedFloats, cv::ml::ROW_SAMPLE, matClassificationInts);

	cv::Mat matTestingNumbers = cv::cvarrToMat(CharImg);
	cv::Mat matGrayscale;           
	cv::Mat matBlurred;             
	cv::Mat matThresh;            
	cv::Mat matThreshCopy;         
	cv::adaptiveThreshold(matTestingNumbers,                           // input img
		matThresh,                            // output img
		255,                                 
		cv::ADAPTIVE_THRESH_GAUSSIAN_C,       // lam min
		cv::THRESH_BINARY_INV,                // chuyen sang trang den
		11,                                 
		2);                                   
	//cv::imshow("matThresh", matThresh);
	matThreshCopy = matThresh.clone();              // luu lai anh goc vi khi tim contour se lm thay doi anh goc

	std::vector<std::vector<cv::Point> > ptContours;        // vector contour
	std::vector<cv::Vec4i> v4iHierarchy;                   

	cv::findContours(matThreshCopy,            
		ptContours,                            
		v4iHierarchy,                          
		cv::RETR_EXTERNAL,                     
		cv::CHAIN_APPROX_SIMPLE);              

	for (int i = 0; i < ptContours.size(); i++) {               
		ContourWithData contourWithData;                                                   
		contourWithData.ptContour = ptContours[i];                                         
		contourWithData.boundingRect = cv::boundingRect(contourWithData.ptContour);         // lay bien cua contour
		contourWithData.fltArea = cv::contourArea(contourWithData.ptContour);               // tim contour area
		allContoursWithData.push_back(contourWithData);                                     
	}

	for (int i = 0; i < allContoursWithData.size(); i++) {                      
		if (allContoursWithData[i].checkIfContourIsValid()) {                   // kiem tra dien tich co phu hop hay ko
			validContoursWithData.push_back(allContoursWithData[i]);            
		}
	}
	//// sort contour
	std::sort(validContoursWithData.begin(), validContoursWithData.end(), ContourWithData::sortByBoundingRectXPosition);

	std::string strFinalString;         // ket qua

	for (int i = 0; i < validContoursWithData.size(); i++) 
	{            
																
		cv::rectangle(matTestingNumbers,                           
			validContoursWithData[i].boundingRect,       
			cv::Scalar(0, 255, 0),                       
			2);                                           

		cv::Mat matROI = matThresh(validContoursWithData[i].boundingRect);         

		cv::Mat matROIResized;
		cv::resize(matROI, matROIResized, cv::Size(RESIZED_IMAGE_WIDTH, RESIZED_IMAGE_HEIGHT));  

		cv::Mat matROIFloat;
		matROIResized.convertTo(matROIFloat, CV_32FC1);           

		cv::Mat matROIFlattenedFloat = matROIFloat.reshape(1, 1);

		cv::Mat matCurrentChar(0, 0, CV_32F);

		kNearest->findNearest(matROIFlattenedFloat, 1, matCurrentChar);    

		float fltCurrentChar = (float)matCurrentChar.at<float>(0, 0);

		strFinalString = strFinalString + char(int(fltCurrentChar));     
	}
	return strFinalString;
}

