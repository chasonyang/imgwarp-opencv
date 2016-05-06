/*
 *  delaunay.h
 *  aamlib-opencv
 *
 *  Created by Chen Xing on 10-2-12.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#include "qglobal.h"
#include "opencv/cv.h"
#ifdef Q_OS_ANDROID
#include "opencv2/legacy/legacy.hpp"
#else
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#endif
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
using cv::Point_;
using cv::Mat_;
using std::vector;
using std::set;
using std::map;
using std::sort;
using cv::Subdiv2D;
class Delaunay;

struct Triangle {
    Point_<int> v[3];
};

struct TriangleInID {
    int v[3];
};

//! Find the Delaunay division for given points(Return in int coordinates).
template <class T>
vector<Triangle> delaunayDiv(const vector<Point_<T> > &vP, cv::Rect boundRect) {
    Subdiv2D *subdiv;
    subdiv=new Subdiv2D(boundRect);
    for(auto p:vP)
        subdiv->insert(p);
    vector < cv::Vec6f> tris;
    subdiv->getTriangleList(tris);
    vector<Triangle> ans;
    for(auto t:tris){
        Triangle triT;
        for(int j=0;j<3;j++)
            triT.v[j]=cvPoint(cvRound(t[2*j]), cvRound(t[2*j+1]));
        ans.push_back(triT);
    }
    return ans;
}

template <class T>
struct PointLess {
    bool operator()(const Point_<T> &pa, const Point_<T> &pb) const {
        return (pa.x < pb.x) || (pa.x == pb.x && pa.y < pb.y);
    }
};

template <typename T>
void labelMatByTriInID(const vector<Point_<T> > &vP,
                       vector<TriangleInID> &triList, Mat_<int> &mapMat,
                       cv::Size labelSize) {
    mapMat.create(labelSize);
    mapMat.setTo(triList.size());

    vector<TriangleInID>::iterator it;
    Point_<T> v[3];
    for (it = triList.begin(); it != triList.end(); it++) {
        // Not interested in points outside the region.
        v[0] = vP[it->v[0]];
        v[1] = vP[it->v[1]];
        v[2] = vP[it->v[2]];

        cv::fillConvexPoly(mapMat, v, 3, it - triList.begin());
    }
}
