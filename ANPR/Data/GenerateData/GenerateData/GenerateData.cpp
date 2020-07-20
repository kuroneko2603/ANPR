#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/ml/ml.hpp>
#include<iostream>
#include<vector>

const int MIN_CONTOUR_AREA = 100;

const int RESIZED_IMAGE_WIDTH = 20;
const int RESIZED_IMAGE_HEIGHT = 30;

int main() {

    cv::Mat imgTrainingNumbers;         // input image
    cv::Mat imgGrayscale;               // 
    cv::Mat imgBlurred;                 //
    cv::Mat imgThresh;                  //
    cv::Mat imgThreshCopy;              //

    std::vector<std::vector<cv::Point> > ptContours;        
    std::vector<cv::Vec4i> v4iHierarchy;                    

    cv::Mat matClassificationInts;      

                                    
    cv::Mat matTrainingImagesAsFlattenedFloats;

    std::vector<int> intValidChars = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z' };

    imgTrainingNumbers = cv::imread("training_chars.png");          // doc anh du lieu train

    if (imgTrainingNumbers.empty()) {                               
        std::cout << "error: image not read from file\n\n";         
        return(0);                                                  
    }

    cv::cvtColor(imgTrainingNumbers, imgGrayscale, CV_BGR2GRAY);        // chuyen anh sang anh xam

    cv::GaussianBlur(imgGrayscale,              // input image
        imgBlurred,                             // output image
        cv::Size(5, 5),                         // lam min anh
        0);                                    

                                              
    cv::adaptiveThreshold(imgBlurred,           // input image
        imgThresh,                              // output image
        255,                                    
        cv::ADAPTIVE_THRESH_GAUSSIAN_C,         // gaussian giup cai thien do chinh xac
        cv::THRESH_BINARY_INV,                  
        11,                                     
        2);                                     

    cv::imshow("imgThresh", imgThresh);         //HT choi choi :v

    imgThreshCopy = imgThresh.clone();          //copy lai ban goc vi qua trinh tim contour se thay doi anh goc

    cv::findContours(imgThreshCopy,             // input image
        ptContours,                             // output contours
        v4iHierarchy,                          
        cv::RETR_EXTERNAL,                     
        cv::CHAIN_APPROX_SIMPLE);              

    for (int i = 0; i < ptContours.size(); i++) {                           
        if (cv::contourArea(ptContours[i]) > MIN_CONTOUR_AREA) {                // if contour thoa dkien define 
            cv::Rect boundingRect = cv::boundingRect(ptContours[i]);                // lay bien

            cv::rectangle(imgTrainingNumbers, boundingRect, cv::Scalar(0, 0, 255), 2);      // ve duong bao xung quanh

            cv::Mat matROI = imgThresh(boundingRect);           // ROI ne

            cv::Mat matROIResized;
            cv::resize(matROI, matROIResized, cv::Size(RESIZED_IMAGE_WIDTH, RESIZED_IMAGE_HEIGHT));   

            cv::imshow("matROI", matROI);                               // hien thi ky tu de nhan dien

            int intChar = cv::waitKey(0);           // nahp ket qua 

            if (intChar == 27) {        // neu nhan esc 
                return(0);             
            }
            else if (std::find(intValidChars.begin(), intValidChars.end(), intChar) != intValidChars.end()) {    //neu ky tu nam trong mang cho phep

                matClassificationInts.push_back(intChar);       //bo kq vao mang

                cv::Mat matImageFloat;                         
                matROIResized.convertTo(matImageFloat, CV_32FC1);       

                cv::Mat matImageFlattenedFloat = matImageFloat.reshape(1, 1);       // flatten

                matTrainingImagesAsFlattenedFloats.push_back(matImageFlattenedFloat);      
                                                                                           
            }  
        }   
    }  

    std::cout << "training complete\n\n";


    cv::FileStorage fsClassifications("classifications.xml", cv::FileStorage::WRITE);           // mo file de ghi kq nek 

    if (fsClassifications.isOpened() == false) {                                                        
        std::cout << "error, unable to open training classifications file, exiting program\n\n";      
        return(0);                                                                                     
    }

    fsClassifications << "classifications" << matClassificationInts;        // ghi ket qua
    fsClassifications.release();                                            


    cv::FileStorage fsTrainingImages("images.xml", cv::FileStorage::WRITE);         //luu lai anh train

    if (fsTrainingImages.isOpened() == false) {                                                 
        std::cout << "error, unable to open training images file, exiting program\n\n";         
        return(0);                                                                            
    }

    fsTrainingImages << "images" << matTrainingImagesAsFlattenedFloats;         
    fsTrainingImages.release();                                                 
	system("pause");
    return(0);
}