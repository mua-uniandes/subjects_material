//
//  Point.cpp
//  Geometry
//
//  Created by NicolasCardozo on 6/9/19.
//  Copyright © 2019 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>

#define EPS 1e-9
#define DEG_to_RAD(angle) ((angle) * M_PI / 180.0)

using namespace std;

struct point {
    int x, y;
    point() {x = y= 0;}
    point(int _x, int _y) : x(_x), y(_y){}
    
    int distance(point other) {
        return hypot(x - other.x, y - other.y);
    }
    
    bool operator <(point other) const {
        if(fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
    
    point rotate(double theta) {
        double rad = DEG_to_RAD(theta);
        return point(x*cos(rad) - y*sin(rad), x*sin(rad) - y*cos(rad));
    }
    
    bool operator ==(point other) const {
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }
};
