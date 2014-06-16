#ifndef MAIN_H
#define MAIN_H

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <cstdio>
#include "Quaternion.hpp"
using namespace cv;

void blockAssign ( cv::Mat dst, cv::Mat block, cv::Point tl );
void ARC_compare ( cv::Mat cmat, char *fn, double thresh=0 );
void hexToVec ( const char *fn, vector<double>& vec );
void loadData(vector<double>& pibHist, vector<double>& ppbHist, vector<double>& refFlag, vector<double>& renewHist);
void loadData(vector<double>& aHist, vector<double>& altHist, vector<double>& dtHist, vector<double>& qbwHist, vector<double>& wHist);
void copyMat(Mat& src, Mat& dst);
void reshapeMat(vector<double> src, Mat& dst);
void reshapeMat3D(vector<double> src, Mat& dst);
void euler2Quaternion(Mat src, Mat& dst);
void jacobianH(Mat mu, Quaternion qbw, Mat xb0w, Mat qb0w, int i, Mat& Hb, Mat& Hi, int k);
void motionModel(Mat mu, Quaternion qbw, cv::Vec3d a, cv::Vec3d w, Mat pibHat, int nf, double dt, Mat& f, Mat& F);
void measurementModel(int k, int nf, double alt, Mat pibHist, Mat pib0, 
        Mat ppbHist, Mat mu, Quaternion qbw, Mat xb0wHat, Mat xbb0Hat, Mat qb0w,
        vector<Matx33d> Rb2b0, Mat refFlag, int flagMeas, Mat& meas, Mat& hmu,
        Mat& H, Mat& pibHat, Mat& xiwHat);
vector<int> findIndex(const Mat& src, double val);

#endif
