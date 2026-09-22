#include <iostream>

using namespace std;

void makeadress()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << "   " << i;
    }
    cout << endl
         << "------------------------------------------" << endl;
}

void makebody()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << " " << i << ".    "
             << "|";
        for (int j = 1; j <= 10; j++)
        {
            cout << j * i << "   ";
        }

        cout << endl;
    }
}

int main()
{
    makeadress();
    makebody();
}
