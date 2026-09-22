#include <iostream>
using namespace std;
class clsAddress
{
private:
	string _AddressLine1;
	string _AddressLine2;
	string _POBox;
	string _ZipCode;
public:
		
	void SetAddressLine1(string AddressLine1)
	{
		_AddressLine1 = AddressLine1;
	}
	string AddressLine1()
	{
		return _AddressLine1;
	}
	void SetAddressLine2(string AddressLine2)
	{
		_AddressLine2 = AddressLine2;
	}
	string AddressLine2()
	{
		return _AddressLine2;
	}

	clsAddress(string AddressLine1,string AddressLine2,string POBox,string ZipCode) {
		_AddressLine1 = AddressLine1;
		_AddressLine2 = AddressLine2;
		_POBox = POBox;
		_ZipCode = ZipCode;
	}
	clsAddress(clsAddress &oldobj) {
		_AddressLine1 = oldobj.AddressLine1();
		_AddressLine2 = oldobj.AddressLine2();
	}

};
int main(){



	return 0;
}
