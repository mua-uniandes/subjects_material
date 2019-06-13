//
//  Triangle.cpp
//  Geometry
//
//  Created by NicolasCardozo on 12/06/2019.
//  Copyright © 2019 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>
#include "../Point.cpp"
#include "../1D/Line.cpp"
#include "../1D/Vector.cpp"

using namespace std;

double perimeter(point p1, point p2, point p3) {
    return toVector2D(p1,p2)+ toVector2D(p2,p3)+ toVector2D(p3,p1);
}


double area(point p1, point p2, point p3) {
    double a = toVector2D(p1,p2);
    double b = toVector2D(p2,p3);
    double c = toVector2D(p3,p1);
    double s = 0.5*perimeter(p1, p2, p3);
    
    return sqrt(s*(s - a)*(s-b)*(s-c));
}

int inscribedCirc(point p1, point p2, point p3, point &c, double &r) {
    r = 2*area(p1,p2,p3)/perimeter(p1,p2,p3);
    if(fabs(r) < EPS)
        return 0;
    struct line l1, l2;
    double ratio = toVector2D(p1, p2).getMagnitude()/toVector2D(p1, p3).getMagnitude();
    point p = translate(p2, scale(toVector2D(p2,p3), ratio / (1+ratio)));
    line(p1, p, l1);
    
    ratio = toVector2D(p2,p1).getMagnitude() / toVector2D(p2, p3).getMagnitude();
    p = translate(p1, sclae(toVector2D(p1,p3), ratio / (1+ratio)));
    line(p2, p, l2);
    intersection(l1, l2, c);
    return 1;
}

bool triangleP(point p1, point p2, point p3) {
    double a = toVector2D(p1, p2).getMagnitude();
    double b = toVector2D(p2, p3).getMagnitude();
    double c = toVector2D(p3, p1).getMagnitude();
    return (a + b > c) && (b + c > a) && (a + c > b);
}

