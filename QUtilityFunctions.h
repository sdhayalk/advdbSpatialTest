//
// Created by ravichandran on 19/03/17.
//

#ifndef ADVDBTEST_UTILITYFUNCTIONS_H
#define ADVDBTEST_UTILITYFUNCTIONS_H

#include "QuadTreeLib.h"
#include "QPoint.h"
#include "QBoundingBox.h"

using namespace std;

void printQPointVectors(vector<QPoint> qPoints)
{
    for(int i=0;i< qPoints.size();i++) {
        qPoints[i].print();
    }
}

void printQBoundingBoxVectors(vector<QBoundingBox> qbbs)
{
    for(int i=0;i< qbbs.size();i++) {
        qbbs[i].print();
    }
}


#endif //ADVDBTEST_UTILITYFUNCTIONS_H
