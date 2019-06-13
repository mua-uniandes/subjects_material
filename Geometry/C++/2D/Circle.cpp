//
//  Circle.cpp
//  Geometry
//
//  Created by NicolasCardozo on 6/11/19.
//  Copyright © 2019 NicolasCardozo. All rights reserved.
//

#include <bits/stdc++.h>
#include "../Point.cpp"

using namespace std;

int insideCircle(point c, int radius, point p) {
    int dx = p.x - c.x;
    int dy = p.y - c.y;
    int dist = dx*dx + dy*dy;
    int rad = radius*radius;
    if(dist == rad) {
        return 1;
    } else if(dist < rad)
        return 0;
    else
        return 2;
}
