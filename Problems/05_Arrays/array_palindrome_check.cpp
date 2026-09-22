#include<iostream>
#include<string>
using namespace std;


int readnumber(){
    int number;
    cout << "please enter a number" << endl;
    cin>>number;
    return number;
    
}
void addnumberinarray(int number,int arr[],int &arraylength){
    arraylength++;
    arr[arraylength-1]=number;
}

void readarray(int arr[],int &arraylength){
    bool addmore;
    do{
    addnumberinarray(readnumber(),arr, arraylength);
    cout << "add more number press (1) or get out press(0) " << endl;
    cin>>addmore;
    }while(addmore);
}

void printarray(int arr[],int arraylength){
    cout << "Array Element :" << endl;
    for(int i = 0;i<arraylength;i++){
        cout << arr[i]<< " ";
    
    }
    cout << endl;
}
void reversearray(int arr2[],int arr1[],int arraylength){
    for(int i = 0;i<arraylength;i++){
        arr2[i]=arr1[arraylength-i-1];
    }
}

bool checkpalindrome(int arr2[],int arr1[],int arraylength){
    
    for(int i = 0;i<arraylength;i++){
        if(arr2[i]!=arr1[i]){
        return false;
        }
    }
    return true;
}


int main()
{
    int arr1[100],arr2[100], arraylength;
    readarray(arr1, arraylength);
    printarray(arr1, arraylength);
    reversearray(arr2,arr1, arraylength);
    if(checkpalindrome(arr2,arr1,arraylength)==true){
        cout << "\nyes,your array is palindrome" << endl;
    }else{
        cout << "\nNo,your array is not plainrom" << endl;
    }
    printarray(arr2, arraylength);
    
    
    return 0;
}