// states class header
#ifndef STATES_H
#define STATES_H
#include <map>
#include "Quaternion.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <iostream>
#include "feature.h"
#include "Sensors.hpp"
#include "imagesensor.hpp"
using namespace cv;

class States{

    public:
        Vec3d X;
        Vec3d V;
        std::vector<Feature> features;
        std::map<int,Feature> feats;
        Vec3d b;
        int nf;
        int rows;

        // constructor
        States();
        ~States();
        States(Vec3d pos, Vec3d vel, std::vector<Feature> feat, Vec3d bias, int n);

        // accessor
        Vec3d getX();
        Vec3d getV();
        std::vector<Feature> getFeatures();
        Feature getFeature(int i);
        Vec3d getb();

        // mutator
        void update_features( ImageSensor imgsense, Sensors sense );
        void setX(Vec3d pos);
        void setV(Vec3d vel);
        void setFeature(int i, Feature f);
        void addFeature(Feature f);
        void setb(Vec3d bias);
        void add(States a);
        States dynamics( Sensors s );
};

#endif
