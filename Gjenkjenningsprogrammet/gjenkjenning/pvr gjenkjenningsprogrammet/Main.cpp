#include <iostream>
#include<string>
#include <vector>
#include<opencv2/opencv.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/core.hpp"
#include <float.h>
#include "mottaPartA.h"
#include"mottaPartB.h"
#include"send.h";
#include "zbar.h";
#include<list>
#include<fstream>
int mottaPA();
int mottaPB();

string readAndDecodeBarcode(Mat& frame);
int sende();


using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;
using namespace zbar;

int main(int argc, char* argv[]) {
	// These function must connects to  buttons in User Interface.
	// When user press a button one of the functions calls

	//mottaPA();      // -- This function calls when the user press the button to take picture for recognation
	mottaPB();		 // -- This one calls when the user wants to compare one image with other images. The user can press this button again if the image didnt get match.
	
	sende();		//-- This function calls when the user wants to read barcode and take pictures
	return 0;
}


// The mottaPA() function is create to capture video frame from the webcamera and blurring the image.
// This function showing the frame on the screen and saving the image in a folder with PATH (Check getfullPATH() function in mottaPartA.cpp)
// If the camera is not open or the PORT is not defined correct it will cast and error message.
// The number (1) is defined for camera wich is conneted through USB.
// When the user press close button on the screen the program will close.

int  mottaPA() {
	mottaPartA mpa;

	VideoCapture capture(1);
	if (!capture.isOpened()) {
		cout << " Fant ingen frame, sjekk om webkamera er koblet" << endl;
		return false;
	}
	else {
		while (true)
		{
			Mat frame, blur;

			capture >> frame;
			GaussianBlur(frame, blur, Size(5, 5), 0);
			imshow("Webkamera blurred", blur);
			//			ESC erstattes med en knap
			if (waitKey(30) == 27) { // esc							
				imwrite(mpa.getfullPATH(), blur);
				cout << mpa.getimageName() << " ble lagret" << endl;
			}
			// erstattes med en knap
			if (waitKey(50) == 113) { // q
				break;
			}
		}
	}
	return 0;
}


//The function mottaPB is to compare images and show the results to screen and printing out the match percent. 
int mottaPB() {
	mottaPartB mpb;

	mpb.detector->detectAndCompute(mpb.getImage(), noArray(), mpb.keypoint_1, mpb.descriptor_1);										// Detecting keypoints_1 and computes the descriptor_1
	mpb.detector->detectAndCompute(mpb.getImages(), noArray(), mpb.keypoint_2, mpb.descriptor_2);										// Detecting keypoints_2 and computes the descriptor_2

	
	mpb.matcher->knnMatch(mpb.descriptor_1, mpb.descriptor_2, mpb.k_nearest_neighbor_matches, 2);										//  Matching descriptor and finding the best K match


	for (size_t i = 0; i < mpb.k_nearest_neighbor_matches.size(); i++)																	// Filter matches. Basically this loop filtering the matches and
	{
		if (mpb.k_nearest_neighbor_matches[i][0].distance < mpb.ratio_threshhold * mpb.k_nearest_neighbor_matches[i][1].distance)
		{
			mpb.good_match_points.push_back(mpb.k_nearest_neighbor_matches[i][0]);
		}
	}
																																		// Printing out the match percent
	int num_keypoints= 0;																									
	if (mpb.keypoint_1.size() > mpb.keypoint_2.size()) {

		num_keypoints = mpb.keypoint_1.size();
	}
	else {
		num_keypoints = mpb.keypoint_2.size();
	}
	int per = mpb.good_match_points.size() * 100 / num_keypoints;
	cout << "Match percent " << per << endl;
	cout << "Image name " << mpb.getImageName() << endl;
																																							
	drawMatches(mpb.getImage(), mpb.keypoint_1, mpb.getImages(), mpb.keypoint_2, mpb.good_match_points, mpb.draw_matches, Scalar::all(-1),	//-- Drawing matches, but not single keypoints
		Scalar::all(-1), std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	//-- Show  matches
	imwrite("C:\\OpenCV_DIR\\Gjenkjenning_PVR\\gjenkjenning\\result\\result.jpg", mpb.draw_matches);

	imshow("Results", mpb.draw_matches);
	waitKey();
	return 0;

}




// This function is create to decode barcode.
// In this function I use classes from ZBar Library and from OpenCV
// This fucntion is called by the sende() function.

string readAndDecodeBarcode(Mat &frame ) {
	zbarBarcode decodeBarcode;

	ImageScanner s;																					// ImageScanner is a class of Zbar using this to scan the image
	s.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);													// Enabling for barcode 
	Mat gray;
	cvtColor(frame, gray, COLOR_BGR2GRAY);															// We have to convert the frame into gray other ways it the program cant decode the barcode
	Image img(frame.cols, frame.rows, "Y800", (uchar*)gray.data, frame.cols * frame.rows);			// Using Image class from Zbar to get data from cols and rows.

	int x = s.scan(img);																			// Scanning and returning data
	string barcodeData; 
	
	for (Image::SymbolIterator i = img.symbol_begin(); i != img.symbol_end(); ++i) {				// This loops itererets over the barcode data and get type and data
		
		decodeBarcode.barcodeType = i->get_type_name();
		decodeBarcode.barcodeData = i->get_data();

		
		cout << "Data : " << decodeBarcode.barcodeData << endl;
		//cout << "Type : " << decode.barcodeType  << endl;

		barcodeData = decodeBarcode.barcodeData;
	}
	return barcodeData;

}
// This function reads frame from kamera and takes pictures and reads the barcode. When the barcode is readed it will be stored temporary in a text file.
// When the picture is taken it will get the barcode data as its name. The file text file is overwriting.
// In this function I'm using basic method to open, save and read to and from file.
int sende() {


	send send;
	string EAN;
	string LINE;
	string FILEPATH = "C:\\OpenCV_DIR\\Gjenkjenning_PVR\\gjenkjenning\\EAN\\ean.txt";
	VideoCapture capture(1);
	if (!capture.isOpened()) {
		cout << " Fant ingen frame, sjekk om webkamera er koblet" << endl;
		return false;
	}
	else {
		while (true)
		{
			Mat frame, blur;
			
			capture >> frame;
			
			GaussianBlur(frame, blur, Size(5, 5), 0);
			EAN = readAndDecodeBarcode(frame);

			if (EAN.empty()) {
				cout << "Empty EAN" << endl;
			}
			else {
				ofstream EAN_FILE (FILEPATH);

				if (EAN_FILE.is_open()) {
					EAN_FILE << EAN << endl;
					EAN_FILE.close();
				}
				else {
					cout << "EAN filen er utilgjengelig for å skrive barkoden";
				}
			}
			ifstream EAN_FILE (FILEPATH);
			string BARCODE = LINE;
			if (EAN_FILE.is_open()) {
				getline(EAN_FILE, LINE);
				EAN_FILE.close();
			}

			imshow("Webkamera blurred", blur);
			string fullPath = send.getFolderPath() +BARCODE + send.getimageExtension();

			//			ESC erstattes med en knap
			if (waitKey(30) == 27) { // esc
				imwrite(fullPath, blur);
				cout <<  fullPath<< " ble lagret" << endl;
			}
			// erstattes med en knap
			if (waitKey(50) == 113) { // q
				break;
			}
		}
	}
	return 0;
}