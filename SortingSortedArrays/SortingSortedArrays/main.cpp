//
//  main.cpp
//  SortingSortedArrays
//
//  Created by Spencer on 4/12/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

bool sortCheck(int array1[], int array2[], int array_size){
    std::sort(array2, array2 + array_size);
    bool equal = true;
    for (int i=0; i<array_size; i++){
        if (array1[i] != array2[i]){
            equal = false;
            break;
        }
        else{
            continue;
        }
    }
    return equal;
}


void swap(int *temp1, int *temp2)
{
    int temp = *temp1;
    *temp1 = *temp2;
    *temp2 = temp;
}


void bubbleSort(int myArray[], int size)
{
    for (int i = 0; i < size-1; i++)
        
        for (int j = 0; j < size-i-1; j++)
            if (myArray[j] > myArray[j+1])
                swap(&myArray[j], &myArray[j+1]);
}


void selectionSort(int myArray[], int size){
    for (int i = 0; i < size-1; i++)
    {
        int min  = i;
        for (int j = i+1; j < size; j++)
            if (myArray[j] < myArray[min])
                min = j;
        swap(&myArray[min], &myArray[i]);
    }
}


void insertionSort(int myArray[], int size){
    int j;
    for (int i = 1; i < size; i++) {
        int key = myArray[i];
        j = i - 1;
        
        while ((j >= 0) && (myArray[j] > key)) {
            myArray[j + 1] = myArray[j];
            j = j - 1;
        }
        myArray[j + 1] = key;
    }
}


void merge(int *myArray, int left, int mid, int right)
{
    int i, j, k;
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int *leftArr = new int[size1];
    int *rightArr = new int[size2];
    
    for (i = 0; i < size1; i++)
        leftArr[i] = myArray[left + i];
    for (j = 0; j < size2; j++)
        rightArr[j] = myArray[mid + 1+ j];
    
    i = 0;
    j = 0;
    k = left;
    while (i < size1 && j < size2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            myArray[k] = leftArr[i];
            i++;
        }
        else
        {
            myArray[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < size1)
    {
        myArray[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        myArray[k] = rightArr[j];
        j++;
        k++;
    }
    delete [] leftArr;
    delete [] rightArr;
}


void mergeSort(int *myArray, int left, int right)
{
    if (left < right)
    {
        int mid = (left + (right-1)) / 2;
        mergeSort(myArray, mid+1, right);
        mergeSort(myArray, left, mid);
        merge(myArray, left, mid, right);
    }
}


int partition (int myArray[], int low, int high)
{
    int pivot = myArray[high];
    int i = (low - 1);
    
    for (int j = low; j <= high- 1; j++)
    {
        if (myArray[j] <= pivot)
        {
            i++;
            swap(&myArray[i], &myArray[j]);
        }
    }
    swap(&myArray[i + 1], &myArray[high]);
    return (i + 1);
}


void quickSort(int *myArray, int low, int high)
{
    if (low < high)
    {
        int pi = partition(myArray, low, high);
        quickSort(myArray, low, pi - 1);
        quickSort(myArray, pi + 1, high);
    }
}


void heapify(int myArray[], int size, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (l < size && myArray[l] > myArray[largest])
        largest = l;
    
    if (r < size && myArray[r] > myArray[largest])
        largest = r;
    
    if (largest != i)
    {
        swap(&myArray[i], &myArray[largest]);
        heapify(myArray, size, largest);
    }
}

void heapSort(int myArray[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(myArray, size, i);

    for (int i=size-1; i>=0; i--)
    {
        swap(&myArray[0], &myArray[i]);
        heapify(myArray, i, 0);
    }
}

int shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            
            arr[j] = temp;
        }
    }
    return 0;
}

//---------------------------------------------------------//
//--------------------- Main Function ---------------------//
//---------------------------------------------------------//


int main(int argc, const char * argv[]) {
    int elements = 17;
    int arraySize[] = {128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608};
    
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<float> time_span = (duration<float>)0;
    
    
//ARRAYS TO STORE TIME VALUES FOR CSV FILE
    float standardTime[elements];
    float bubbleTime[elements];
    float insertionTime[elements];
    float selectionTime[elements];
    float mergeTime[elements];
    float quickTime[elements];
    float heapTime[elements];
    float shellTime[elements];

    
//FOR-LOOP TO CREATE & SORT ARRAYS OF DIFFERENT SIZES -- CHECKS AT 10 MINUTES
//STD SORT
    for(int a = 0; a < elements; a++)
    {
        int array_size = arraySize[a];
        int * originalArray;
        originalArray = new int [array_size];
        for(int i = 0; i < array_size; i++){
            originalArray[i] = rand() % 1000; //range is 0-999
        }
        t1 = high_resolution_clock::now();
        std::sort(originalArray, originalArray + array_size);
        t2 = high_resolution_clock::now();
        duration<float> time_span = duration_cast<duration<float>>(t2 - t1);
        standardTime[a] = time_span.count();
        if(time_span < (duration<float>)100){
            delete [] originalArray;
            continue;
        }
        else{
            for(int i = a+1; i < elements; i++)
            {
                standardTime[i] = 0;
            }
            delete [] originalArray;
            break;
        }
    }
    
//BUBBLE SORT
    time_span = (duration<float>)0.0;
    for(int a = 0; a < elements; a++)
    {
        int array_size = arraySize[a];
        int * originalArray;
        originalArray = new int [array_size];
        for(int i = 0; i < array_size; i++){
            originalArray[i] = rand() % 1000; //range is 0-999
        }
        std::sort(originalArray, originalArray + array_size);
        t1 = high_resolution_clock::now();
        bubbleSort(originalArray, array_size);
        t2 = high_resolution_clock::now();
        time_span = duration_cast<duration<float>>(t2 - t1);
        bubbleTime[a] = time_span.count();
        
        if(time_span < (duration<float>)200){

            delete [] originalArray;
            continue;
        }
        else{
            for(int i = a+1; i < elements; i++)
            {
                bubbleTime[i] = 0;
            }
            delete [] originalArray;
            break;
        }
        
    }
    
//INSERTION SORT
    time_span = (duration<float>)0.0;
    for(int a = 0; a < elements; a++)
    {
        int array_size = arraySize[a];
        int * originalArray;
        originalArray = new int [array_size];
        for(int i = 0; i < array_size; i++){
            originalArray[i] = rand() % 1000; //range is 0-999
        }
        std::sort(originalArray, originalArray + array_size);
        t1 = high_resolution_clock::now();
        insertionSort(originalArray, array_size);
        t2 = high_resolution_clock::now();
        time_span = duration_cast<duration<float>>(t2 - t1);
        insertionTime[a] = time_span.count();
        if(time_span < (duration<float>)130){
            delete [] originalArray;
            continue;
        }
        else{
            for(int i = a+1; i < elements; i++)
            {
                insertionTime[i] = 0;
            }
            delete [] originalArray;
            break;
        }
    }
    
//SELECTION SORT
    time_span = (duration<float>)0.0;
    for(int a = 0; a < elements; a++)
    {
        int array_size = arraySize[a];
        int * originalArray;
        originalArray = new int [array_size];
        for(int i = 0; i < array_size; i++){
            originalArray[i] = rand() % 1000; //range is 0-999
        }
        std::sort(originalArray, originalArray + array_size);
        t1 = high_resolution_clock::now();
        selectionSort(originalArray, array_size);
        t2 = high_resolution_clock::now();
        time_span = duration_cast<duration<float>>(t2 - t1);
        selectionTime[a] = time_span.count();
        if(time_span < (duration<float>)225){
            
            delete [] originalArray;
            continue;
        }
        else{
            for(int i = a+1; i < elements; i++)
            {
                selectionTime[i] = 0;
            }
            delete [] originalArray;
            break;
        }
        
    }
    
//MERGE SORT
    time_span = (duration<float>)0.0;
    for(int a = 0; a < elements; a++)
    {
        int array_size = arraySize[a];
        int *originalArray;
        originalArray = new int [array_size];
        for(int i = 0; i < array_size; i++){
            originalArray[i] = rand() % 1000; //range is 0-999
        }
        std::sort(originalArray, originalArray + array_size);
        t1 = high_resolution_clock::now();
        mergeSort(originalArray, 0, array_size - 1);
        t2 = high_resolution_clock::now();
        duration<float> time_span = duration_cast<duration<float>>(t2 - t1);
        mergeTime[a] = time_span.count();
        if(time_span < (duration<float>)300){
            
            delete [] originalArray;
            continue;
        }
        else{
            for(int i = a+1; i < elements; i++)
            {
                mergeTime[i] = 0;
            }
            delete [] originalArray;
            break;
        }
    }

//QUICK SORT
    time_span = (duration<float>)0.0;
    for(int a = 0; a < elements; a++)
    {
        int array_size = arraySize[a];
        int * originalArray;
        originalArray = new int [array_size];
        for(int i = 0; i < array_size; i++){
            originalArray[i] = rand() % 1000; //range is 0-999
        }
        std::sort(originalArray, originalArray + array_size);
        t1 = high_resolution_clock::now();
        quickSort(originalArray, 0, array_size - 1);
        t2 = high_resolution_clock::now();
        time_span = duration_cast<duration<float>>(t2 - t1);
        quickTime[a] = time_span.count();
        if(time_span < (duration<float>)40){
            delete [] originalArray;
            continue;
        }
        else{
            for(int i = a+1; i < elements; i++)
            {
                quickTime[i] = 0;
            }
            delete [] originalArray;
            break;
        }
    }
    
//HEAP SORT
    time_span = (duration<float>)0.0;
    for(int a = 0; a < elements; a++)
    {
        int array_size = arraySize[a];
        int * originalArray;
        originalArray = new int [array_size];
        for(int i = 0; i < array_size; i++){
            originalArray[i] = rand() % 1000; //range is 0-999
        }
        std::sort(originalArray, originalArray + array_size);
        t1 = high_resolution_clock::now();
        heapSort(originalArray, array_size);
        t2 = high_resolution_clock::now();
        time_span = duration_cast<duration<float>>(t2 - t1);
        heapTime[a] = time_span.count();
        if(time_span < (duration<float>)200){
            delete [] originalArray;
            continue;
        }
        else{
            for(int i = a+1; i < elements; i++)
            {
                heapTime[i] = 0;
            }
            delete [] originalArray;
            break;
        }
    }
    
//SHELL SORT
    time_span = (duration<float>)0.0;
    for(int a = 0; a < elements; a++)
    {
        int array_size = arraySize[a];
        int * originalArray;
        originalArray = new int [array_size];
        for(int i = 0; i < array_size; i++){
            originalArray[i] = rand() % 1000; //range is 0-999
        }
        std::sort(originalArray, originalArray + array_size);
        t1 = high_resolution_clock::now();
        shellSort(originalArray, array_size);
        t2 = high_resolution_clock::now();
        time_span = duration_cast<duration<float>>(t2 - t1);
        shellTime[a] = time_span.count();
        if(time_span < (duration<float>)200){
            delete [] originalArray;
            continue;
        }
        else{
            for(int i = a+1; i < elements; i++)
            {
                shellTime[i] = 0;
            }
            delete [] originalArray;
            break;
        }
    }
    
//WRITE RESULTS TO CSV FILE
    ofstream myfile;
    myfile.open("myoutput.csv");
    myfile << fixed;
    myfile << "Elements: ,";
    for(int i = 0; i < elements; i++){
        myfile << arraySize[i] << ", ";
    }
    myfile << endl;
    
    myfile << "Standard Sort: ,";
    for(int i = 0; i < elements; i++){
        if(standardTime[i] == 0)
            myfile << "inf" << ", ";
        else
            myfile << standardTime[i] << ", ";    }
    myfile << endl;
    
    myfile << "Bubble Sort: ,";
    for(int i = 0; i < elements; i++){
        if(bubbleTime[i] == 0)
            myfile << "inf" << ", ";
        else
            myfile << bubbleTime[i] << ", ";    }
    myfile << endl;
    
    myfile << "Insertion Sort: ,";
    for(int i = 0; i < elements; i++){
        if(insertionTime[i] == 0)
            myfile << "inf" << ", ";
        else
            myfile << insertionTime[i] << ", ";    }
    myfile << endl;
    
    myfile << "Selection Sort: ,";
    for(int i = 0; i < elements; i++){
        if(selectionTime[i] == 0)
            myfile << "inf" << ", ";
        else
            myfile << selectionTime[i] << ", ";    }
    myfile << endl;
    
    myfile << "Merge Sort: ,";
    for(int i = 0; i < elements; i++){
        if(mergeTime[i] == 0)
            myfile << "inf" << ", ";
        else
            myfile << mergeTime[i] << ", ";    }
    myfile << endl;
    
    myfile << "Quick Sort: ,";
    for(int i = 0; i < elements; i++){
        if(quickTime[i] == 0)
            myfile << "inf" << ", ";
        else
            myfile << quickTime[i] << ", ";    }
    myfile << endl;
    
    myfile << "Heap Sort: ,";
    for(int i = 0; i < elements; i++){
        if(heapTime[i] == 0)
            myfile << "inf" << ", ";
        else
            myfile << heapTime[i] << ", ";    }
    myfile << endl;
    
    myfile << "Shell Sort: ,";
    for(int i = 0; i < elements; i++){
        if(shellTime[i] == 0)
            myfile << "inf" << ", ";
        else
            myfile << shellTime[i] << ", ";    }
    myfile << endl;
    
    myfile.close();
    
    
//END PROGRAM
    return 0;
}


