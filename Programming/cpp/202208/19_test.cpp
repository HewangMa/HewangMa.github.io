#include <iostream>
// #include<string.h>
#include <iomanip>
#include <string>
#include <complex>
using namespace std;

namespace SRC1
{
	class CA123
	{
	public:
		CA123(int x = 0) { cout << "constructing!" << endl; };
	};
	class TestBa
	{
	public:
		static int num;
		int b;
		TestBa(int a = 0) : b(a){};
		TestBa operator+(int a)
		{
			this->b += a;
			return *this;
		}
	};
	int TestBa::num = 0;
	class TestPr : public TestBa
	{
	public:
		int p;
		TestPr(int a = 0) : p(a){};
	};
	class Array
	{
		int *list;
		int last;
		int maxsize;

	public:
		Array(int n = 20);
		~Array()
		{
			if (list)
				delete[] list;
		}
		void print();
		void set(int, int);
		void insert(int);
	};
	Array::Array(int n)
	{
		maxsize = n;
		last = -1;
		list = new int[n];
	}
	void Array::print()
	{
		if (last == -1)
			cout << "empty list!" << endl;
		else
		{
			for (int i = 0; i <= last; i++)
				cout << list[i] << "  ";
			cout << endl;
		}
	}
	void Array::set(int i, int key)
	{
		if (i < 0 || i > last)
			cout << "illegal subscript!" << endl;
		else
			list[i] = key;
	}
	void Array::insert(int key)
	{
		if (last == -1)
		{
			last++;
			list[last] = key;
		}
		else if (last == maxsize - 1)
			cout << "list full!" << endl;
		else
		{
			int i = 0;
			for (i = last; i >= 0 && list[i] > key; i--)
				list[i + 1] = list[i];
			list[i + 1] = key;
			last++;
		}
	}
	int In(int *a, int x)
	{
		while (*a)
			if (*(a++) == x)
				return 0;
		return 1;
	}
}
namespace TestP1
{

	void test01()
	{
		char p[] = "Hello";
		char *s = p; // ��vs����������char*
		// char* s = *p;
		s = s + 2;
		cout << s << endl;
	}
	// ��Ĺ�����ڴ��������
	void test02()
	{
		using namespace SRC1;
		CA123 a(4), b[3], *c[2]; // ����c��û�з����ڴ棡
	}
	// ���ָ�븳ֵ����
	void test03()
	{
		using namespace SRC1;
		TestBa ba, *p1;
		TestPr son, *p2;
		p1 = &son;
		p2 = static_cast<TestPr *>(&ba);
		// p2 = &ba; ����ʹ����ʾת�� ���ǲ���ֱ�Ӹ�ֵ
		// son = ba;
		ba = son;
	}
	// �����Щ�������Լ̳�
	void test04()
	{
		using namespace SRC1;
		TestBa ba, *p1;
		TestPr son, *p2;
		ba = ba + 4;
		// son = son + 3;
	}
	// strcmp
	void test05()
	{
		char s1[] = "DeG";
		char s2[] = "dEg";
		cout << (int)'d' << " " << (int)'D' << endl;
		cout << strcmp(s1, s2) << endl; // s1<s2 ���-1
		cout << setprecision(3) << 65163.561321 << endl;
	}
	void test06()
	{
		using namespace SRC1;
		int a[9] = {1, 2, 4, 5, 7, 8, 10, 11, 0};
		int b[5] = {2, 3, 7, 9, 0};
		int c[9] = {0}, *p1 = a, *p2 = c;
		while (*p1)
		{
			if (In(b, *p1))
				*p2++ = *p1;
			p1++;
		}
		p2 = c;
		while (*p2)
			cout << *p2++ << '\t';
		cout << '\n';
	}
	void test07()
	{
		int a = 790;
		string s = to_string(a);
		cout << "s: " << s << endl;
		string x = "213";
		int b = stoi(x);
		cout << "b+5: " << b + 5 << endl;
	}
	void test08()
	{
		string s = "5+6i";
		int a1 = s.find('+');
		int a2 = s.find('i');
		complex<int> a(stoi(s.substr(0, a1)), stoi(s.substr(a1 + 1, a1 + a2 + 1)));
		complex<int> b();
		cout << a << endl;
		cout << b << endl;
	}
}
int main()
{
	using namespace TestP1;
	test08();

	cout << "\n\nwork done!\n\n";
	return 0;
}