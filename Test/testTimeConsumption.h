//
// Created by SAHIL on 18-04-2017.
//

#ifndef ADVDBTEST_TESTTIMECONSUMPTION_H
#define ADVDBTEST_TESTTIMECONSUMPTION_H

#include "../QuadTreeLib.h"
#include "../QPoint.h"
#include "../prQuadTree.h"
#include "../prQuadNode.h"
#include "../QBoundingBox.h"
#include "testBulkLoad.h"
#include <intrin.h>

using namespace std;

vector<QPoint*> populateAllPoints(std::string inputFilePath ){

    vector<QPoint*> pointsToSearch;
    ifstream fileToLoad (inputFilePath);
    string line;
    float val = 0.0;
    int i = 0;
    cout<< fileToLoad.is_open()<<endl;

    if ( fileToLoad.is_open() ) {
        while (getline(fileToLoad, line)) {
            stringstream ss(line);
            QPoint* temp = new QPoint();
            vector<float> vect;
            while (ss >> val) {
                vect.push_back(val);
                if (ss.peek() == ',')
                    ss.ignore();
            }
            temp->set(vect.at(0),vect.at(1),i);
            pointsToSearch.push_back( new QPoint(vect.at(0),vect.at(1),i));
//            prQt->insert(temp);
        }
        i++;
    }

    fileToLoad.close();
    return pointsToSearch;
}


void testTimeConsumption() {
    cout << "\n\n\n Loading points for testing time consumption - Started" << endl;
    std:: string fileToLoadPath;
    fileToLoadPath = "G:/Sahil/MS in US/ASU/ASU SEM 2/AdbDB/Project-04-15-2017/advances-quadtree/new/advdbSpatialTest/Test/point.csv";
    vector<QPoint*> pointsToSearch = populateAllPoints(fileToLoadPath);
    prQuadTree* prQt = testBulkLoadPrQuadTree();

    vector<QPoint> vQPoint;
    uint64_t startTimeTemp, startTime, endTime;
    long counter=0;

    //start testing:
    startTimeTemp = __rdtsc();
    for(int i=0;i<pointsToSearch.size();i++) {
//        cout<<pointsToSearch[i]->getX()<<" "<<pointsToSearch[i]->getY()<<endl;

        startTime = __rdtsc();
        vQPoint = prQt->queryRange(pointsToSearch[i]->getX()-0.0001, pointsToSearch[i]->getY()-0.0001, 0.0002, 0.0002);
        endTime = __rdtsc();
        cout << endTime-startTime << endl;
//        printQPointVectors(vQPoint);
//        cout<<endl;
        counter++;
    }
    cout << "total time: " << endTime-startTimeTemp << endl;
    cout<<counter;
    //end testing

}

#endif //ADVDBTEST_TESTTIMECONSUMPTION_H
