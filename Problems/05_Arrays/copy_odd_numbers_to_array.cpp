#include<iostream>
#include <time.h>
#include<stdlib.h>

using namespace std;

int readlength(){
    int number ;
    cout << "enter length of array" << endl;
    cin >> number;
    return number;
}


bool isodd(int number){
    if(number %2 !=0){
    return true;
    }
    return false;
}
int randnumber(int from,int to){
    int number = rand()%(to-from+1)+from;
    return number;
}
void fillarray(int arr[],int &arraylength){

    for(int i =0 ; i < arraylength;i++){
        
        arr[i]= randnumber(1,100);
    }
}
void fillcopyarray(int arr1[],int arr2[],int arraylength,int &arraylength2){
    
    for(int i =0;i<arraylength;i++){
        if(isodd(arr1[i]))
        {
        arr2[arraylength2] =arr1[i];
        arraylength2++;
        }
    }
}

void printfillarray(int arr[],int &arraylength){
    for(int i =0 ; i < arraylength;i++){
        
       cout << arr[i]<<" ";
    }
}


int main()
{
   srand((unsigned)time(NULL));
   
    int arr1[100],arr2[100], arraylength, arraylength2 = 0;
    arraylength=readlength();
    fillarray(arr1, arraylength);
    cout << "Array 1 Element : " << endl;
    printfillarray(arr1, arraylength);
    
    cout << "\n\nArray 2 (odd numbers) Element : " << endl;
    fillcopyarray(arr1,arr2, arraylength, arraylength2);
    printfillarray(arr2, arraylength2);
    return 0;
}