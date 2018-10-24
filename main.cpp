// Author:       Mariana Acosta
// Assignment:       project 6
// File:       Sorring
// Instructor:       Reza Sanati
// Class:       CSIS 2420  Section: 001
// Date Written:   June 6, 2018
// Description: get 3 file inputs and sort the files using different methods. Record the time it takes to sort each method and output a table with the files and the time they took to sort 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

// Function Name:    insertionSort
// Purpose:       sort the file using isertion sort type
// Parameters:     int data[], int n
// Returns:      none (void)
// Pre-conditions:   inside the loop if data at i is less than val then swap
// Post-conditions:none
void insertionSort(int data[], int n){
    for (int i = 0; i < n; i++){
        int idx = i;
        int val = data[idx];
        int j;
        for(j = i; j < n; j++){
            if (data[j] < val){
                val = data[j];
                idx = j;
            }
        }
        
        int temp = data[i];
        data[i] = data[idx];
        data[idx] = temp;
        
        //swap(data[j], data[i]);
    }
}

// Function Name:    shellSort
// Purpose:       sort the file using shell sort type
// Parameters:     int data[], int n
// Returns:      none (void)
// Pre-conditions:   none
// Post-conditions:none
void shellSort(int data[], int n){
    for (int gap = n/2; gap > 0; gap/= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = data[i];
            for (int j = i; j >= gap && data[j - gap] > temp; j -= gap) {
                data[j] = data[j - gap];
                data[j] = temp;
            }
        }
    }
}

// Function Name:    partition
// Purpose:       takes the last elemnt and changes it to its correct position by swaping the elemntes 
// Parameters:     int data[], int n
// Returns:      i +1
// Pre-conditions:   none
// Post-conditions:none
int partition (int data[], int low, int high)
{
    int change = data[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++){
      // If current element is smaller than or equal to change increase and swap
        if (data[j] <= change) {
            i++; 
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[high]);
    return (i + 1);
}

// Function Name:    quickSort
// Purpose:       sort the file using shell sort type
// Parameters:     int data[], int low, int hight
// Returns:      none (void)
// Pre-conditions:   if low lower than high
// Post-conditions:none
void quickSort(int data[], int low, int high) {
    if (low < high)
    {
        int p;
        p = partition(data, low, high);
        quickSort(data, low, p - 1);
        quickSort(data, p + 1, high);
    }
}

int main() {
    //cout << 8;
    string filename1;
    string filename2;
    string filename3;
    ifstream file1;
    ifstream file2;
    ifstream file3;
    int i, j, k;
    int *a1, *a2, *a3;
    int temp;
    int n; //= myArray.size();
    // int myArray[n];
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    //cout << 7;
    
    cout << "Mariana Acosta Zermeno" << endl;
    cout << "CS2420 Section 1" << endl;
    cout << "Program 5: Sorting" << endl;
    
    //ask for files 
    cout << "Enter the first file name you would like to use:" << endl;
    getline(cin, filename1);
    cout << "Enter the second file name you would like to use:" << endl;
    getline(cin, filename2);
    cout << "Enter the third file name you would like to use:" << endl;
    getline(cin, filename3);
    
    //build table headers
    cout << "\t " << "\t" << "\t" << "NUMBER" "\tELAPSED" "\tELAPSED"  << "\t" << "\tSORTED" << endl;
    cout << "SORT " << "\t" << "\tFILE#" <<  "\tITEMS"  "\tCLOCK"  <<"\tTIME" "\t" << "\tFILENAME" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    
    //open files
    file1.open(filename1);
    file2.open(filename2);
    file3.open(filename3);
    //cout << 6;
    assert(file1.is_open());
    assert(file2.is_open());
    assert(file3.is_open());
    
    //push data from files to data 
    int data;
    while (file1 >> data)
    {
        v1.push_back(data);
    }
    while (file2 >> data)
    {
        v2.push_back(data);
    }
    while (file3 >> data)
    {
        v3.push_back(data);
    }
    //cout << v1.size();
    
    
     //FILE 1
    //loop throught the files and build vectors
    a1= new int[v1.size()];
    for (int i=0; i<v1.size(); i++){
        a1[i]=v1[i];
    }
    
    a2= new int[v2.size()];
    for (int i=0; i<v2.size(); i++){
        a2[i]=v2[i];
    }
    a3= new int[v3.size()];
    for (int i=0; i<v3.size(); i++){
        a3[i]=v3[i];
    }
    
    int cStart = clock(); //start time
    auto start = chrono::high_resolution_clock::now(); //start clock
    insertionSort(a1, v1.size()); //call insertionSort
    auto end = chrono::high_resolution_clock::now(); //end time
    int cEnd = clock(); // end clock
    int cDiff = cEnd - cStart; //find difference of time 
    auto diff = chrono::duration_cast < chrono::nanoseconds >(end-start).count(); //fin difference of clock
    //cout info
    cout << "Insertion \t1" << "\t" << v1.size() << "\t" << cDiff << "\t" << (diff*0.00001)<< "\t" << "\t" << filename1 << endl;
    
    //same for the rest the only thing changes is the file and the function called
    cStart = clock();
    start = chrono::high_resolution_clock::now();
    shellSort(a1, v1.size()); 
    cEnd = clock();
    end = chrono::high_resolution_clock::now();
    diff = chrono::duration_cast < chrono::nanoseconds >(end-start).count();
    cDiff = cEnd - cStart;
    cout << "Shellsort \t2" << "\t" << v1.size() << "\t" << cDiff << "\t" << diff *0.00001 << "\t" << "\t" << filename1 << endl;

    cStart = clock();
    start = chrono::high_resolution_clock::now();
    quickSort(a1, 0, n-1);
    end = chrono::high_resolution_clock::now();
    cEnd = clock();
    diff = chrono::duration_cast < chrono::nanoseconds >(end-start).count();
    cDiff = cEnd - cStart;
    //cout << 1;
    cout << "QuickSort \t1" << "\t" << v1.size() << "\t" << cDiff << "\t" << diff *0.00001 << "\t" << "\t" << filename1 << endl;
    cout << endl;
    
    //FILE 2
    for (int i=0; i<v1.size(); i++){
        a1[i]=v1[i];
    }
    
    for (int i=0; i<v2.size(); i++){
        a2[i]=v2[i];
    }
    
    for (int i=0; i<v3.size(); i++){
        a3[i]=v3[i];
    }
    cStart = clock();
    start = chrono::high_resolution_clock::now();
    insertionSort(a2, v2.size());
    cEnd = clock();
    end = chrono::high_resolution_clock::now();
    diff = chrono::duration_cast < chrono::nanoseconds >(end-start).count();
    cDiff = cEnd - cStart;
    cout << "Insertion \t2" << "\t" << v2.size() << "\t" << cDiff << "\t" << diff*0.00001 << "\t"  << "\t" << filename2 << endl;
    
    cStart = clock();
    start = chrono::high_resolution_clock::now();
    shellSort(a2, v2.size());
    cEnd = clock();
    end = chrono::high_resolution_clock::now();
    diff = chrono::duration_cast < chrono::nanoseconds >(end-start).count();
    cDiff = cEnd - cStart;
    cout << "ShellSort \t2" << "\t" << v2.size() << "\t" << cDiff << "\t" << diff*0.00001 << "\t" << "\t" << filename2 << endl;
    
    cStart = clock();
    start = chrono::high_resolution_clock::now();
    quickSort(a2, 0, n-1);
    cEnd = clock();
    end = chrono::high_resolution_clock::now();
    diff = chrono::duration_cast < chrono::nanoseconds >(end-start).count();
    cDiff = cEnd - cStart;
    cout << "QuickSort \t2" << "\t" << v2.size() << "\t" << cDiff << "\t" << diff *0.00001<< "\t" << "\t"<< filename2 << endl;
    cout << endl;
    //FILE 3
    //cin.get();
    for (int i=0; i<v1.size(); i++){
        //cout << i;
        // cin.get();
        a1[i]=v1[i];
    }
    //return 0;
    for (int i=0; i<v2.size(); i++){
        a2[i]=v2[i];
    }
    
    for (int i=0; i<v3.size(); i++){
        a3[i]=v3[i];
    }
    
    cStart = clock();
    start = chrono::high_resolution_clock::now();
    insertionSort(a3, v3.size());
    cEnd = clock();
    end = chrono::high_resolution_clock::now();
    diff = chrono::duration_cast < chrono::nanoseconds >(end-start).count();
    cDiff = cEnd - cStart;
    cout << "Insertion\t3" << "\t" << v3.size() << "\t" << cDiff  << "\t"  << diff*0.00001 << "\t"<<  "\t" << filename3 << endl;
    
    cStart = clock();
    start = chrono::high_resolution_clock::now();
    shellSort(a3, v3.size());
    cEnd = clock();
    end = chrono::high_resolution_clock::now();
    diff = chrono::duration_cast < chrono::nanoseconds >(end-start).count();
    cDiff = cEnd - cStart;
    cout << "ShellSort\t3" << "\t" << v3.size() << "\t" << cDiff << "\t" << diff*0.00001 << "\t" << "\t"<< filename3 << endl;
    
    
    cStart = clock();
    start = chrono::high_resolution_clock::now();
    quickSort(a3, 0, n-1);
    cEnd = clock();
    end = chrono::high_resolution_clock::now();
    diff = chrono::duration_cast < chrono::nanoseconds >(end-start).count();
    cDiff = cEnd - cStart;
    cout << "QuickSort\t3" << "\t" << v3.size() << "\t" << cDiff << "\t" << diff*0.00001 << "\t" << "\t"<< filename3 << endl;
    

    //delete arrays
    delete[] a1;
    delete[] a2;
    delete[] a3;
    
   
    

    
    
    
   
    
    
    
    
}
