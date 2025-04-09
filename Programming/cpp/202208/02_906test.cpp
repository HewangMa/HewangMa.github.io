#include <iostream>
#include <assert.h>
// #include<iostream.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
namespace virt
{
	class Aa
	{
	public:
		virtual void fb(int a = 0)
		{
			cout << "fb of one!\n";
		}
		void fa()
		{
			cout << "fa of one!\n";
		}
	};
	class Bb : public Aa
	{
	public:
		/*virtual void fb(int a = 0) {
			cout << "fb of two!\n";
		}*/
	};
	class Cc : public Bb
	{
	public:
		virtual void fb(int a = 0)
		{
			cout << "fb of three!\n";
		}
		void fc()
		{
			cout << "fc of three!\n";
		}
	};
	class String
	{
		char *st;

	public:
		String();
		String(const char *);
		~String();
		void show() { cout << st; };
		String operator+(String &);
		int operator==(String &);
	};
	String::~String()
	{
		// if (st)delete[]st;
	}
	String::String() { st = (char *)("\0"); }
	String::String(const char *s)
	{
		// cout << "doing!\n";
		// cout << strlen(s) << endl;
		st = new char[1];
		// cout << "setting done!\n";
		strcpy_s(st, strlen(s) + 1, s);
		// cout << "done!\n";
	}
	int String::operator==(String &tar)
	{
		return strcmp(st, tar.st) == 0;
	}
	class Complex
	{
		double real;
		double imag;

	public:
		Complex()
		{
			real = 0;
			imag = 0;
		}
		Complex(double r, double i) : real(r), imag(i)
		{
		}
		Complex operator+(Complex &c2);
		void Display();
	};
	Complex Complex::operator+(Complex &c2)
	{
		Complex c;
		c.real = real + c2.real;
		c.imag = imag + c2.imag;
		return c;
	}
	void Complex::Display()
	{
		cout << "(" << real << "," << imag << "i)" << endl; // ע�������ʽ����
	}
	class CTest
	{
		int x, y;

	public:
		CTest(int n1, int n2)
		{
			x = n1;
			y = n2;
		}
		CTest operator++(int);
		void print()
		{
			cout << "x= " << x << " y= " << y << endl;
		}
	};
	CTest CTest::operator++(int)
	{
		CTest temp = *this;
		x++;
		y++;
		return temp;
	}
	class List
	{
		int size;
		double *list;

	public:
		List(int = 1, double = 0.0);
		List(const List &ls);
		~List() { delete[] list; };
		List &operator=(const List &);
		// friend operator= (const List&);//operator=�����ǳ�Ա����
		friend ostream &operator<<(ostream &, List &);
		friend istream &operator>>(istream &, List &);
	};
	List::List(int sz, double t)
	{
		size = sz;
		list = new double[size];
		for (int i = 0; i < size; i++)
			list[i] = t;
	}
	List::List(const List &ls)
	{
		if (&ls != this && list != NULL)
		{
			delete[] list;
			size = ls.size;
			list = new double[size];
			for (int i = 0; i < size; i++)
				list[i] = ls.list[i];
		}
	}
	List &List::operator=(const List &v)
	{
		if (&v != this)
		{
			delete[] list;
			size = v.size;
			list = new double[size];
			for (int i = 0; i < size; i++)
				list[i] = v.list[i];
		}
		return *this;
	}
	ostream &operator<<(ostream &os, List &v)
	{
		int i;
		for (i = 0; i < v.size; i++)
		{
			os << v.list[i] << ',';
			if ((i + 1) % 8 == 0)
				os << '\n';
		}
		return os;
	}
	istream &operator>>(istream &is, List &v)
	{
		int i;
		for (i = 0; i < v.size; i++)
		{
			cout << i << ":";
			is >> v.list[i];
		}
		return is;
	}

	template <typename T>
	class seqlist
	{
		T *elements;
		// ���˳���������
		int Maxsize;
		// ������������
		int last;
		// �Ѵ��������λ��
	public:
		seqlist(int ms = 18);
		~seqlist() { delete[] elements; } // ���ܻ����
		T &operator[](int);
		// �����±������[]������elements[i]������ʡ��
		int Josephus(int, int);
	};
	template <typename T>
	seqlist<T>::seqlist(int ms)
	{
		last = -1;
		Maxsize = ms;
		elements = new T[Maxsize];
		assert(elements != NULL); // ���ԣ�����ɹ�
	}
	template <typename T>
	int seqlist<T>::Josephus(int a, int m)
	{
		// a��������,m�����յ�
		int i, j, k, l;
		for (i = 0; i < a; i++)
		{
			elements[i] = 1;
			// Ԫ�ظ���ֵ,1 ��ʾ��λ�����к���
			last++;
		}
		cout << "last: " << last << endl;
		i = -1, j = 0, k = last;
		while (k != 0)
		{
			while (j < m)
			{
				i = (i + 1) % (last + 1);
				// ��1��ģ
				if (elements[i])
					j++;
				// ��λ�����к��Ӳż���
			}
			elements[i] = 0;
			// Ԫ��Ϊ0��ʾ�ú��ӳ���
			j = 0;
			k--;
			// ������
			for (l = 0; l <= last; l++)
				cout << elements[l] << ' ';
			cout << endl;
		}
		for (i = 0; i <= last; i++)
		{
			if (elements[i] == 1)
				break;
		}
		return i;
	}
	// template <typename T, int size>
	/*void Orderedlist<T, size>::Sort() {
		int i, j, k;
		T temp;
		for (i = 0;i < last;i++) {
			k = i;
			temp = slist[i];
			for (j = i;j <= last;j++)
				if (slist[j] < temp) {
					k = j;
					temp = slist[j];
				}
			if (k != i) {
				temp = slist[i];
				slist[i] = slist[k];
				slist[k] = temp;
			}
		}
	}*/
	template <typename T>
	T add(T a, T b) { return a + b; }
}
void test09()
{
	using namespace virt;
	cout << add<char>('a', 2) << endl;	// c
	cout << add<int>(3.5, 2.9) << endl; // 5
	cout << add(1.1, 2.1) << endl;		// 3.2
}
void test01()
{
	using namespace virt;
	Aa a;
	Bb b;
	Cc c;
	Aa *p;
	p = &c;
	p->fb(); //"fb of one!"
}
void test02()
{
	using namespace virt;
	String yourname((char *)("Luo"));
	String myname((char *)("Luo"));
	cout << (myname == yourname) << endl;
}
void test03()
{
	char s1[] = "asdg";
	char sEnd[] = "\0";
	cout << s1 << endl;
	cout << strlen(s1) << endl;
	char *s2 = new char[1];
	strcpy_s(s2, strlen(s1) + 1, s1);
	cout << s2 << endl;
	cout << strlen(s2) << endl;
}
int test04()
{
	using namespace virt;
	Complex c1(3, 4), c2(5, -10), c3;
	c1.Display(); //(3,4i)
	c3 = c1 + c2;
	cout << "c1+c2=";
	c3.Display(); //(8,-6i)
	return 0;
}
int test05()
{
	using namespace virt;
	CTest d1(2, 3);
	d1.print();
	//++d1;
	d1.print();
	return 0;
}
void test06()
{
	int *a = new int[34];
	for (int i = 0; i < 34; i++)
		a[i] = i;
	for (int i = 0; i < 34; i++)
		cout << a[i] << " ";
}
void test07()
{
	using namespace virt;
	List a(4), b(4);
	cout << "input List b:\n";
	cin >> b;
	cout << "b:" << b << endl;
	a = b;
	cout << "a:" << a << endl;
}
int test08()
{
	using namespace virt;
	seqlist<int> seq;
	int a, m;
	cout << "��������������ͱ���ֹͣ����" << endl;
	cin >> a >> m;
	cout << "������±�Ϊ��" << seq.Josephus(a, m) << endl;
	return 0;
}
template <class T>
T func(T x, T y)
{
	return x * x + y * y;
}
void test10()
{
	// cout << func(3, 5.5) << endl;
	cout << func<int>(3, 5.5) << endl;
}
int main()
{
	test08();
	return 0;
}