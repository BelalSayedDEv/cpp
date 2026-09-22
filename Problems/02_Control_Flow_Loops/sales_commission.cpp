
#include <iostream>
using namespace std;

int readtotalsales() {
    int total;
    cout << "please enter tour total sales" << endl;
    cin >> total;
    return total;
}
float getthecommations(int total) {
    if (total > 1000000) {
        return 0.01;
    }else if(total>=500000 &&  total<=1000000) {
        return 0.02;
    }
    else if (total >= 100000 && total <= 500000) {
        return 0.03;
    }
    else if (total >= 50000 && total <= 100000) {
        return 0.05;
    }
    else {
        return 0;
    }
}

void printresult(int total) {
    cout << "the commations is : " << getthecommations(total) * total << endl;
}


int main()
{
    printresult(readtotalsales());
}


