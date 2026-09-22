#include<iostream>
#include<iomanip>

using namespace std;

void readnumber (int arr[10][10]) {

    for(int i=0; i<10; i++)
    {
        for(int j = 0; j<10; j++)
        {
            arr[i][j]=(i+1)*(j+1);
        }
    }

}
void printnumber(int arr[10][10]) {

    for(int i=0; i < 10; i++)
    {
        for(int j =0; j < 10; j++)
        {
            printf("   %02d",arr[i][j]);
        }
        cout << " " << endl;

    }
}

int main()
{
    int arr[10][10];
    readnumber(arr);
    printnumber(arr);
    return 0;
}