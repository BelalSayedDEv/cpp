
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

string printfirstletter(string name) {

    bool isfirstletter = true;

	for (int i = 0; i < name.length(); i++)
	{
		if (name[i]!= ' ' && isfirstletter)
		{
			name[i] = toupper(name[i]) ;
		}

		isfirstletter = (name[i] == ' ') ? true : false;
	}

	return name;
}
int main()
{
	string name;
	name = readstring();
	name = printfirstletter(name);
	cout << name << endl;
}

