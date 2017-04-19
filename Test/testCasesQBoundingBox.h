//
// Created by ravichandran on 18/03/17.
//

#ifndef ADVDBTEST_TESTCASESQBOUNDINGBOX_H
#define ADVDBTEST_TESTCASESQBOUNDINGBOX_H

#include "../QuadTreeLib.h"
#include "../QBoundingBox.h"

using namespace std;

void qBoundingBoxTestCase1()
{
    cout<<"\nQBoundingBox 1"<<endl;
    QBoundingBox *tqbb1 = new QBoundingBox(100,100);
    tqbb1->print();
    tqbb1->set(200,100);
    tqbb1->print();
    tqbb1->set(10,10,200,100);
    tqbb1->print();

}

void qBoundingBoxTestCase2()
{
    cout<<"\nQBoundingBox 2"<<endl;
    QBoundingBox *tqbb2 = new QBoundingBox(0,0,100,100);
    tqbb2->print();
    tqbb2->set(50,50);
    tqbb2->print();
    tqbb2->set(10,10,100,100);
    tqbb2->print();

}


void qBoundingBoxTestCase3()
{
    cout<<"\nQBoundingBox 3"<<endl;
    float minX = 50;
    float minY = 50;
    float maxX = 100;
    float maxY = 100;
    QBoundingBox *tqbb3 = new QBoundingBox(minX,minY,maxX,maxY,24);
    tqbb3->print();

}




void testCreateQBoundingBox()
{
    cout<<"\n\n Create QBoundingBox Testing - Started"<<endl;

    qBoundingBoxTestCase1();
    qBoundingBoxTestCase2();
    qBoundingBoxTestCase3();

    cout<<"\n\n Create QBoundingBox Testing - Started"<<endl;

}

vector<QPoint*> pointsTestCaseQBoundingBox1(){

    vector<QPoint*> vQPoint;

    vQPoint.push_back(new QPoint(-20,-10,5));
    vQPoint.push_back(new QPoint(5,5,6));
    vQPoint.push_back(new QPoint(6,-26,7));
    vQPoint.push_back(new QPoint(10,-10,10));
    vQPoint.push_back(new QPoint(-5,-10,11));
    vQPoint.push_back(new QPoint(-5,11,11));

    return vQPoint;

}

void pointsGetQBoundingBoxTestCase1()
{
    cout<<"\nPoints Test Case 1"<<endl;
    vector<QPoint*> testQPoints = pointsTestCaseQBoundingBox1();
    QBoundingBox *QBB = QBoundingBox::getQBoundingBoxCooridinates(testQPoints);
    QBB->print();

}

vector<QBoundingBox*> rectanglesTestCaseQBoundingBox1(){

    vector<QBoundingBox*> vQBoundingBox;

    vQBoundingBox.push_back(QBoundingBox::createRectangle(3,6,8,36));
    vQBoundingBox.push_back(QBoundingBox::createRectangle(25,34,34,38));
    vQBoundingBox.push_back(QBoundingBox::createRectangle(33,21,37,36));
    vQBoundingBox.push_back(QBoundingBox::createRectangle(21,23,38,27));
    vQBoundingBox.push_back(QBoundingBox::createRectangle(6,3,26,8));
    vQBoundingBox.push_back(QBoundingBox::createRectangle(31,15,35,19));
    vQBoundingBox.push_back(QBoundingBox::createRectangle(23,25,26,36));
    vQBoundingBox.push_back(QBoundingBox::createRectangle(27,14.5,33.5,20.5));
    vQBoundingBox.push_back(QBoundingBox::createRectangle(16,3.5,22,7.5));


    return vQBoundingBox;

}

void rectanglesGetQBoundingBoxTestCase1()
{
    cout<<"\nRectangles Test Case 1"<<endl;
    vector<QBoundingBox*> testQBoundingBoxes = rectanglesTestCaseQBoundingBox1();
    QBoundingBox *QBB = QBoundingBox::getQBoundingBoxCooridinates(testQBoundingBoxes);
    QBB->print();

}

void testGetBoundingBoxCoordinates()
{
    cout<<"\n\n Get BoundingBox Co-ordinates Points - Testing - Started"<<endl;

    pointsGetQBoundingBoxTestCase1();
    rectanglesGetQBoundingBoxTestCase1();

    cout<<"\n\n Get BoundingBox Co-ordinates Points - Testing - Ended"<<endl;
}

void testQBoundingBox()
{
    cout<<"\n\n QBoundingBox Testing - Started"<<endl;

    testCreateQBoundingBox();
    testGetBoundingBoxCoordinates();


    cout<<"\n\n QBoundingBox Testing - Ended"<<endl;

}


#endif //ADVDBTEST_TESTCASESQBOUNDINGBOX_H