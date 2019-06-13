//
//  Polygon.cpp
//  Geometry
//
//  Created by NicolasCardozo on 6/12/19.
//  Copyright © 2019 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>
#include "../Point.cpp"
#include "../1D/Vector.cpp"

using namespace std;

vector<point> P;

double area(const vector<point> &P) {
    double res = 0.0, x1, y1, x2, y2;
    for(int i=0; i<P.size()-1; i++) {
        x1 = P[i].x;
        y1 = P[i].y;
        x2 = P[i+1].x;
        y2 = P[i+1].y;
        res += x1*y2 - x2*y1;
    }
    return fabs(res)/2.0;
}

bool ccw(point p1, point p2, point p3) {
    vector2D v1 = toVector2D(p1, p2);
    vector2D v2 = toVector2D(p2, p3);
    return crossProduct(v1, v2) >= 0;
}

bool convexP(const vector<point> &P) {
    int size = (int)P.size();
    if(size <= 3)
        return false;
    bool isLeft = ccw(P[0], P[1], P[2]);
    for(int i=1; i< size -1; i++) {
        if(ccw(P[i], P[i+1], P[(i+2) == size ? 1 : i+2]) != isLeft)
            return false;
    }
    return true;
}

//crossing point algorithm
int inPolygon(point p, point* v, int n) {
    int cn = 0;
    
    for (int i=0; i<n; i++) {    // edge from V[i]  to V[i+1]
        if (((v[i].y <= p.y) && (v[i+1].y > p.y))     //upward crossing
            || ((v[i].y > p.y) && (v[i+1].y <=  p.y))) { // a downward crossing
            // compute  the actual edge-ray intersect x-coordinate
            float vt = (float)(p.y  - v[i].y) / (v[i+1].y - v[i].y);
            if (p.x <  v[i].x + vt * (v[i+1].x - v[i].x)) // P.x < intersect
                ++cn;   // a valid crossing of y=P.y right of P.x
        }
    }
    return (cn&1);    // 0 if even (out), and 1 if  odd (in)
    
}

