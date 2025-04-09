#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
class ex
{
public:
	int a;
	int *p;
	ex(int a = 0) : a(a)
	{
		p = new int(a);
		cout << "constructing " << a << endl;
	}
	~ex() { cout << "deconstructing " << a << endl; }
};
void test01()
{
	ex x4(4);
	ex *p5 = new ex(5);
	cout << "\n\ntest01 done\n\n";
}
void test02()
{
	cout << 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 << endl;
	cout << sin(30) << endl;
	int a = 90, b = 9;
	cout << "!b: " << !b;
	if (a = !b)
		cout << "a!=b!" << endl;

	a = 100;
	cout << "\n\n16: " << hex << a << endl;
	cout << "8: " << oct << a << endl;
	cout << "10: " << dec << a << endl;
}
void test03()
{
	string s = "0123456=31";
	int pos = s.find('=');
	cout << "pos: " << pos << endl;
}
int main()
{
	test03();
	return 0;
}