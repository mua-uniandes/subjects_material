//
//  Vector.cpp
//  Geometry
//
//  Created by NicolasCardozo on 10/06/2019.
//  Copyright © 2019 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>
#include "../Point.cpp"

#define DEG_to_RAD(angle) ((angle) * M_PI / 180.0)

using namespace std;

struct vector2D {
    int x, y;
    double magnitude;
    
    vector2D() {x = y = magnitude = 0;}
    vector2D(int _x, int _y) : x(_x), y(_y), magnitude(sqrt(x*x + y*y)){}
    vector2D(int _x1, int _x2, int _y1, int _y2) : x(_y1 - _x1), y(_y2 - _x2){ magnitude = sqrt(x*x + y*y);}
    
    double getMagnitude() {
        magnitude = sqrt(x*x + y*y);
        return magnitude;
    }
};

vector2D scale(vector2D v, int s) {
    return vector2D(v.x*s, v.y*s);
}

vector2D toVector2D(point a, point b) {
    return vector2D(b.x - a.x, b.y - a.y);
}

double dotProduct(vector2D v1, vector2D v2) {
    return v1.x*v2.x + v1.y*v2.y;
}

double dotProduct(vector2D v1, vector2D other, double theta) {
    return v1.magnitude*other.magnitude*cos(DEG_to_RAD(theta));
}

double crossProduct(vector2D v1, vector2D v2) {
    return v1.x*v2.x - v1.y*v2.y;
}

double crossProduct(vector2D v1, vector2D v2, double theta) {
    return v1.getMagnitude()
}

point translate(point p, vector2D v) {
    return point(p.x + v.x, p.y + v.y);
}
