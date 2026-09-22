
#include <iostream>

using namespace std;

class clsCluclatuer
{
private:
	int result = 0;
	int lasnumber = 0;
	string process = "none";

public:
	int Clear() {

		return result = 0;
		int lasnumber = 0;
		string process = "none";
	}
	void add(int pnumber) {
		result += pnumber;
		lasnumber = pnumber;
		process = "adding";
	}

	void subtract(int pnumber) {
		result -= pnumber;
		lasnumber = pnumber;
		process = "subtracting";
	}

	void multiplay(int pnumber) {
		result *= pnumber;
		lasnumber = pnumber;
		process = "muliplication";
	}
	void divide(int pnumber) {
		if (pnumber == 0) {
			pnumber = 1;
		}
		result /= pnumber;
		lasnumber = pnumber;
		process = "dividation";
	}
	void PrintResult() {
		
		cout << "number after " << process << " " << lasnumber << " is : " << result << endl;
	}

};


int main()
{
	clsCluclatuer cluclatur;
	cluclatur.Clear();
	cluclatur.add(10);
	cluclatur.PrintResult();
	cluclatur.add(100);
	cluclatur.PrintResult();
	cluclatur.multiplay(2);
	cluclatur.PrintResult();

}

