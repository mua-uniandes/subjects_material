//
//  Line.cpp
//  Geometry
//
//  Created by NicolasCardozo on 6/9/19.
//  Copyright © 2019 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>
#include "../Point.cpp"
#include "Vector.cpp"

#define EPS 1e-9

using namespace std;

struct line {
    double a, b, c;
};

void line(point p1, point p2, line &l) {
    if(fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    } else {
        l.a = -(p1.y - p2.y)/(p1.x - p2.x);
        l.b = 1.0;
        l.c = -(l.a*p1.x) - p1.y;
    }
}

bool parallelP(struct line l1, struct line l2) {
    return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
}

bool intersection(struct line l1, struct line l2, point &p) {
    if(parallelP(l1, l2))
        return false;
    p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.a - l1.a*l2.b);
    if(fabs(l1.b) > EPS)
        p.y = -(l1.a*p.x + l1.c);
    else
        p.y = -(l2.a*p.x + l2.c);
    return true;
}

double distanceToLine(point p, point s1, point s2, point &c) {
    vector2D s1p = toVector2D(s1, p);
    vector2D s2p = toVector2D(s2, p);
    vector2D s1s2 = toVector2D(s1, s2);
    double u = crossProduct(s1p, s2p) / s1s2.getMagnitude();
    c = translate(s1, scale(s1s2, u));
    return u;
}
