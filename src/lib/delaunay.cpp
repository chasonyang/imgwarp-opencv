/*
 *  delaunay.cpp
 *  aamlib-opencv
 *
 *  Created by Chen Xing on 10-2-12.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "delaunay.h"
using cv::Point2i;

bool operator<(const Triangle &t1, const Triangle &t2) {
    for (int i = 0; i < 3; i++) {
        if ((t1.v[i].x < t2.v[i].x) ||
            (t1.v[i].x == t2.v[i].x && t1.v[i].y < t2.v[i].y))
            return true;
        else if (t1.v[i].x > t2.v[i].x)
            return false;
        else if (t1.v[i].x == t2.v[i].x && t1.v[i].y > t2.v[i].y)
            return false;
    }
    return false;
}

bool operator<(const TriangleInID &a, const TriangleInID &b) {
    return (a.v[0] < b.v[0]) || (a.v[0] == b.v[0] && a.v[1] < b.v[1]) ||
           (a.v[0] == b.v[0] && a.v[1] == b.v[1] && a.v[2] < b.v[2]);
}


