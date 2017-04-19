//
// Created by Prince Chawla on 4/5/17.
//

#ifndef ADVDBTEST_TESTBULKLOAD_H
#define ADVDBTEST_TESTBULKLOAD_H

#include "../QuadTreeLib.h"
#include "../QPoint.h"
#include "../prQuadTree.h"
#include "../prQuadNode.h"
#include "../QBoundingBox.h"

using namespace std;

prQuadTree* bulkLoadPrQuadTree(std::string inputFilePath ){

    vector<QPoint*> pointsToLoad;
    QBoundingBox* qBb;
    float height, width;
    float originX, originY = 0.0;

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
            pointsToLoad.push_back( new QPoint(vect.at(0),vect.at(1),i));
//            prQt->insert(temp);

        }
        qBb = QBoundingBox::getQBoundingBoxCooridinates(pointsToLoad);
        height = qBb->getHeight();
        width = qBb->getWidth();

        i++;
    }

    prQuadTree* prQt = new prQuadTree(qBb);

    for(int i=0;i<pointsToLoad.size();i++) {
        prQt->insert(pointsToLoad[i]);
    }

    fileToLoad.close();

    return prQt;
}


prQuadTree* testBulkLoadPrQuadTree() {

    cout << "\n\n\n Bulkloading Of Points - Started" << endl;
    std:: string fileToLoadPath;
//    fileToLoadPath = "/Users/ravichandran/Documents/Misc/Docs/ASU_Subjects/Spring_17/ADVDB/Project/Code/advances-quadtree/new/advdbSpatialTest/Test/point.csv";
//    fileToLoadPath = "/Users/princechawla/advances-quadtree/new/advdbSpatialTest/Test/point.csv";
    fileToLoadPath = "G:/Sahil/MS in US/ASU/ASU SEM 2/AdbDB/Project-04-15-2017/advances-quadtree/new/advdbSpatialTest/Test/point.csv";

    prQuadTree* temp = bulkLoadPrQuadTree(fileToLoadPath);
    cout << "\n\n\n Bulkloading Of Points - Ended" << endl;
    return temp;
}


#endif //ADVDBTEST_TESTBULKLOAD_H
