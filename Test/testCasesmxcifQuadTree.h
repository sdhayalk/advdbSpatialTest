//
// Created by ravichandran on 19/03/17.
//

#ifndef ADVDBTEST_TESTCASESMXCIFQUADTREE_H
#define ADVDBTEST_TESTCASESMXCIFQUADTREE_H

#include "../QUtilityFunctions.h"
#include "../mxcifQuadNode.h"
#include "../mxcifQuadTree.h"

using namespace std;


void testmxcifQuadNode()
{
    cout<<"\n\n mxcifQuadNode Testing - Started"<<endl;

    cout<<"\n\n mxcifQuadNode Test Case 1"<<endl;
    mxcifQuadNode *mxcifQuadNode1= new mxcifQuadNode();
    mxcifQuadNode1->print();

    cout<<"\n\n mxcifQuadNode Test Case 2"<<endl;
    QBoundingBox *tqbb1 = new QBoundingBox(0,0,100,100);
    mxcifQuadNode *mxcifQuadNode2= new mxcifQuadNode(*tqbb1);
    mxcifQuadNode2->print();

    cout<<"\n\n mxcifQuadNode Testing - Ended"<<endl;

}

void printmxcifQuadTreeRange(mxcifQuadTree *mxcifQT,float x, float y, float width, float height)
{
    vector<QBoundingBox> vQBoundingBox = mxcifQT->queryRange(x,y,width,height);
    printQBoundingBoxVectors(vQBoundingBox);

}


vector<QBoundingBox*> rectanglesTestCase1(){

    vector<QBoundingBox*> vQBoundingBox;

    vQBoundingBox.push_back(QBoundingBox::createRectangle(3,6,8,36,1));
    vQBoundingBox.push_back(QBoundingBox::createRectangle(25,34,34,38,2));
    vQBoundingBox.push_back(QBoundingBox::createRectangle(33,21,37,36,3));
    vQBoundingBox.push_back(QBoundingBox::createRectangle(21,23,38,27,4));
    vQBoundingBox.push_back(QBoundingBox::createRectangle(6,3,26,8,5));
    vQBoundingBox.push_back(QBoundingBox::createRectangle(31,15,35,19,6));
    vQBoundingBox.push_back(QBoundingBox::createRectangle(23,25,26,36,7));
    vQBoundingBox.push_back(QBoundingBox::createRectangle(27,14.5,33.5,20.5,8));
    vQBoundingBox.push_back(QBoundingBox::createRectangle(16,3.5,22,7.5,9));


    return vQBoundingBox;

}

void mxcifQuadTreeTestCase1()
{
    cout<<"\n\nmxcifQuadTree Test Case 1"<<endl;

    vector<QBoundingBox*> testQBoundingBoxes = rectanglesTestCase1();
    QBoundingBox *QBB = QBoundingBox::getQBoundingBoxCooridinates(testQBoundingBoxes);
    mxcifQuadTree *mxcifQT = new mxcifQuadTree(QBB);

    for(int i=0;i<testQBoundingBoxes.size();i++) {
        mxcifQT->insert(testQBoundingBoxes[i]);
    }
    mxcifQT->print();
    cout<<"\n\n\n\n\n"<<endl;
    cout<<"\n\nmxcifQuadTree 1 - Query Range 1"<<endl;
    printmxcifQuadTreeRange(mxcifQT,0,0,10,10);

    /**
     * CONCLUSION: Works fine
     */
}


void testmxcifQuadTree()
{
    cout<<"\n\n mxcifQuadTree Testing - Started"<<endl;

    mxcifQuadTreeTestCase1();

    cout<<"\n\n mxcifQuadTree Testing - Ended"<<endl;

}


#endif //ADVDBTEST_TESTCASESMXCIFQUADTREE_H
