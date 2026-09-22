
#include <iostream>
#include<string>
#include<cctype>



using namespace std;


string readstring() {
	string name;
	cout << "enter your name : " << endl;
	getline(cin, name);
	return name;

}
void printfirstletter(string name) {
	
	bool isfisrtletter = true;
	for (int i = 0; i < name.length(); i++)
	{
		
		if (name[i] != ' ' && isfisrtletter) {
			cout <<name[i]<<" ";
		}
		isfisrtletter = (name[i] == ' ' ? true : false);
	}
}

int main()
{
	string name;
	name = readstring();
	printfirstletter(name);

}

