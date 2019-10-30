//
//  main.cpp
//  Lists
//
//  Created by Spencer on 1/30/19.
//  Copyright © 2019 Spencer. All rights reserved.
//


#include <iostream>

#define LISTSIZE 10

using namespace std;

typedef struct{
    float x;
    float y;
    float z;
    bool viz;
    int num;
}Point3D;

class Point3DList{
    Point3D pointArr[10];
    size_t curSize = 0;

public:
    void Insert(Point3D point, size_t pos);
    
    Point3D Retrieve(size_t pos);
    
    size_t Length(); // return number of items in list
    void Print();
};

void Point3DList::Print(){
for(int i=0; i<curSize; i++){
    cout << "(x:" << pointArr[i].x
        << ", y:" << pointArr[i].y
        << ", z:" << pointArr[i].z
        << ", viz:" << pointArr[i].viz
        << ", num:" << pointArr[i].num
        << ")" << endl;
    }
}
    
void Point3DList::Insert(Point3D point, size_t pos){
    
    if (pos >= curSize && pos < LISTSIZE){ // no longer a hack?
        pointArr[curSize].x = point.x;
        pointArr[curSize].y = point.y;
        pointArr[curSize].z = point.z;
        pointArr[curSize].viz = point.viz;
        pointArr[curSize].num = point.num;
        curSize++;
    }
    else if (pos < curSize && curSize < LISTSIZE){
        // overwrite but not increment curSize
        for(size_t i = curSize; i < pos; i--){
            pointArr[i] = pointArr[i - 1]; // dangerous shallow copy
        }
        pointArr[pos] = point;
        curSize++;
    }
    else{
        
        // what to do when the array is full???
        
    }
    
}

size_t Point3DList::Length(){
    return curSize;
}

int main(int argc, const char * argv[]) {
    Point3DList myList;
    Point3D p1;
    p1.x = 33;
    p1.y = 44;
    p1.z = 55;
    p1.viz = true;
    p1.num = 42;
    
    myList.Insert(p1, 8);
    myList.Insert(p1, 8);
    myList.Insert(p1, 8);
    myList.Insert(p1, 8);
    
    myList.Print(); //print the list
    
    p1.x = 99;
    p1.y = 132;
    p1.z = 165;
    myList.Insert(p1, 0);
    
    //myList.Retrieve(0);
    
    //myList.Print();
    
    cout << "List Length: " << myList.Length() << endl;
    return 0;
    
    // (x: , y: , z: ,viz: , num: )

}
