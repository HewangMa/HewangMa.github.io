#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<numeric>
#include<iterator>
#include"BinaryTree.h"
using namespace std;

template<class T>
inline string toString(const T&a) {
	ostringstream os;
	os<<a;
	return os.str();
}
template<class T>
inline T fromString(string s) {
	istringstream is(s);
	T res;
	is >> res;
	return res;
}

//template<typename T> //再确认怎么回事

namespace PrimePair {
	//一个用于存放质数的list
	class Node {
	public:
		Node() :link(NULL) {};
		Node(int a) :val(a), link(NULL) {};
		int val;
		Node* link;
	};
	class PrimeList {
	private:
		Node* head;
		Node* tail;
	public:
		Node* getHead() {
			return head;
		}
		Node* getTail() {
			return tail;
		}
		//int count = 0;
		PrimeList() {
			head = new Node;
			tail = head;
			head->link = tail;
		}
		PrimeList(Node& x) {
			head = &x;
			tail = head;
			head->link = NULL;
			//count++;
		}
		void add(Node* x) {
			tail->link = x;
			tail = x;
			assert(!tail->link);
			//tail->link = NULL;
			//count++;
		}
		//void show() {
		//	//int a = 0;
		//	Node* p = head;
		//	while (p != NULL) {
		//		//if (a % 10 == 0) {
		//		cout << p->val << " ";
		//		//a = 0;
		//	//}
		//		p = p->link;
		//		//a++;
		//	}
		//	cout << endl;
		//}
		friend bool PrimeInsert(int, PrimeList&);
		friend bool Prime(unsigned long long, PrimeList&);
		//friend FivePrime;
		//friend bool Trunc(int, PrimeList&);
		/*bool Exist(int a) {
			Node* p = head;
			while (p != NULL) {
				if (p->val == a)return 1;
				if (p->val > a) return 0;
				else p = p->link;
			}
			return 0;
		}*/
	};
	bool PrimeInsert(int a, PrimeList& x) {
		Node* p = x.head;
		while (1) {
			if (p->val * p->val > a) {
				x.add(new Node(a));
				return true;
			}
			if (a % p->val == 0) {
				return false;
			}
			else p = p->link;
		}
	}
	bool Prime(unsigned long long a, PrimeList& L) {
		Node* p = L.head;
		while (1) {
			if (p->val * p->val > a) return true;
			if (a % p->val == 0) return false;
			p = p->link;
		}
	}
	//建立一个最简单的链表
	struct ListNode {
		int val;
		ListNode* link;
		ListNode() {
			val = -1;
			link = NULL;
		}
		ListNode(int s) {
			val = s;
			link = NULL;
		}
	};
	//删繁就简的Mlist
	class Mlist {
	public:
		//简单的默认构造
		Mlist() {
			head = new ListNode;
			head->val = -1;
			head->link = NULL;
		}
		Mlist(int s) {
			head = new ListNode;
			head->val = s;
			head->link = NULL;
			tail = head;
			//cout << "successfully constructed\n";
		}
		ListNode* head = NULL;
		ListNode* tail = NULL;
		//长度
		int len() {
			ListNode* h = head;
			int i = 0;
			while (h != NULL) {
				i++;
				h = h->link;
			}
			return i;
		}
		//增加节点
		void add(int u) {
			ListNode x(u);
			tail->link = &x;
			tail = &x;
			//cout << "successfully added\n";
		}
		//累计
		unsigned long long accum() {
			//最大表示10^19;
			unsigned long long s = 0;
			ListNode* p = head;
			while (p != NULL) {
				s += p->val;
				//s = s % INT_MAX;
				p = p->link;
			}
			return s;
		}
		void output() {
			ofstream ofs;
			ofs.open("Prime.txt");
			if (!ofs.is_open())cout << "fail to open the file!\n";
			ofs.clear();
			int i = 0;
			ListNode* p = head;
			while (p != NULL) {
				ofs << p->val << ' ';
				i++;
				if (i > 30) {
					ofs << "\n";
					i = 0;
				}
				p = p->link;
			}
		}
		/*void check() {
			ListNode* p = head;
			while (p != NULL) {
				if (!prime(p->val))cout << "error!\n";
				p = p->link;
			}
		}*/
		void show() {
			ListNode* p = head;
			while (p != NULL) {
				cout << p->val << endl;
				p = p->link;
			}
			cout << len() << endl;
		}
	};
}
void test31() {
	using namespace PrimePair;
	Node x(2);
	PrimeList L(x);
	int i = 2;
	while (i++ < 673)PrimeInsert(i, L);
	//L.show();
	//Node* p = L.getTail();
	//cout << "p->val: "<<p->val << endl;
	int arr[4] = { 3,7,109,673 };
	vector<int> sf(arr,arr+4);
	string s[5];
	for (int i = 0;i < 4;i++)s[i] = toString<int>(sf[i]);
	//copy(s, s + 4, ostream_iterator<string>(cout, " "));
	//cout << endl;

	//vector<int>::iterator it = sf.begin();

	int ti = 675;
	string tiString;
	int j = 0;
	while (1) {
		while (!PrimeInsert(ti, L))ti+=2;
		//cout << ti << endl;system("pause");
		//assert(Prime(ti, L));
		tiString = toString<int>(ti);
		//if (ti == 3944767)cout << "!" << endl;
		//cout << "ti: " << ti << endl;
		for (j = 0;j < 4;j++) {
			unsigned long long x1 = fromString<unsigned long long>(tiString+s[j]),
				x2 = fromString<unsigned long long>(s[j]+tiString);
			//system("pause");
			if (Prime(x1, L) && Prime(x2, L)) {
				//assert(Prime(x1, L)&&Prime(x2,L));
				//if(*it==673)cout << "x2: " << x2 << endl;
				if(s[j]=="109")
				cout << "x1: " << x1 << "  x2: " << x2 << "   ti: " << ti << "   s[j]: " << s[j] << '\n';
				continue;
			}
			else break;
		}
		if (j==4) {
			sf.push_back(ti);
			break;
		}
		else ti+=2;
		//if (Prime(ti,L)) {
		//	//L.show();
		//	cout << ti << " " << ti + 2 << endl;
		//	system("pause");
		//}
	}
	int sum=accumulate(sf.begin(), sf.end(), 0);
	copy(sf.begin(), sf.end(), ostream_iterator<int>(cout, " "));
	cout << "\nsum = " << sum << endl;
}
bool PrimeQ(unsigned long long a) {
	//if (a % 2 == 0) return false;
	int i = 3;
	int s = sqrt(a);
	while (i <= s) {
		if (a % i == 0) {
			cout << i << " " << a / i << endl;
			return false;
		}
		else i += 2;
	}
	return true;
}
void test01() {
	string s = "65";
	int a = fromString<int>(s);
	cout << a << endl;
	cout << INT_MAX << endl;
	cout << "673107427511: " << PrimeQ(673107427511);

	int arr[5] = { 3,7,109,673,107427511 };
	//copy(arr,arr+5,ostream_iterator<int>)
}
namespace class906 {

	class example {
		int i;
	public:
		example(int n) {
			i = n;
			cout << "Constructing\n";
		}
		example(const example& x) {
			i = x.i;
			cout << "Copying!\n";
		}
		~example() {
			cout << "Destructing\n";
		}
		int get_i() { return i; }
	};
	int sqr_it(example o) {
		return o.get_i() * o.get_i();
	}

	class A {
		float x, y;
	public:
		A() { x = 0; y = 0; cout << "调用无参数的构造函数\n"; }

		A(float a) { x = a; y = 0; cout << "调用一个参数的构造函数\n"; }

		A(float a, float b) { x = a; y = b; cout << "调用两个参数的构造函数\n"; }

		A(A& a) { x = a.x;y = a.y;cout << "调用拷贝构造函数\n"; }

		void Print() { cout << x << '\t' << y << endl; }
	};
	void f() {
		A a0;
		a0 = 2 + 3;//拷贝 a0(A(5));
		a0.Print();
	}
	//A a1(7.0, 3.0);

	/*class Printer{
		int PrintValue;
		int PrintPages();
	public:
		void Printer(int value);
		int PrintDocuments();
		~Printer();
		~Printer(int value);
	};*/
	//成员函数在类外的定义在此处未具体写出。（略） 

	class Base {
		int v;
	public:
		Base(int value = 8) {
			cout << "Constructor" << endl;
			v = value;
		}
		Base(const Base& b);
		void Disp() { cout << "v=" << v << endl; }
		friend Base& add(const Base& b1, const Base& b2, Base& b3);
	};
	Base::Base(const Base& b) {
		cout << "Copy Constructor" << endl;
		v = b.v;
	}
	Base& add(const Base& b1, const Base& b2, Base& b3) {
		b3.v = b1.v + b2.v;
		return b3;
	}

	class Add {
		int n;
	public:
		Add(int i) { n = i; }
		Add(const Add& x) { n = x.n;cout << "Copying!\n"; }
		void operator++() { n += 5; }
		void operator++(int) { n += 2; } //后++
		void show() { cout << n << '\t'; }
	};

	class Point {
		//Point类定义 
	private:
		int X, Y;
	public:
		Point(int xx = 0, int yy = 0) {
			X = xx;
			Y = yy;
			cout << "Point构造函数被调用" << endl;
		}
		Point(Point& p);
		int GetX() { return X; }
		int GetY() { return Y; }
	};
	Point::Point(Point& p) {
		//复制构造函数的定义 
		X = p.X;
		Y = p.Y;
		cout << "Point复制构造函数被调用" << endl;
	}
	class Line {
		//Line类的定义 
	private:
		//私有数据成员 
		Point p1, p2;
		//成员对象 
		double len;
		//线段长度 
	public:
		//外部接口 
		Line(Point xp1, Point xp2);
		Line(Line& L);
		double GetLen() { return len; }
	};
	Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2) {
		cout << "Line构造函数被调用" << endl;
		double x = double(p1.GetX() - p2.GetX());
		double y = double(p1.GetY() - p2.GetY());
		len = sqrt(x * x + y * y);
	} //提示：注意两个类的构造函数被调用的时机，以及实参与形参的关系 

	class Fruit {
	private:
		double* price;
	public:
		Fruit(double p[]) :price(p) {};
	};
}
void test02() {
	char str[] = "string";
	str[0] = 0;
	str[1] = '\0';
	str[2] = '0';
	cout << sizeof(str) << " " << strlen(str) << endl;
}
void test03() {
	using namespace class906;
	example x(10);
	cout << x.get_i() << endl;
	cout << sqr_it(x) << endl;
}
void test04() {
	using namespace class906;//调用两个参数的构造函数
	f();//调用无参数的构造函数
	//调用一个参数的构造函数
	//调用拷贝构造函数
	//5  0
	//A a2(a1);//调用拷贝构造函数
}
void test05() {
	using namespace class906;
	Base b1(Base(3)); //copy???
	Base b2(3);
	Base b3, b4;
	b4 = add(b1, b2, b3); //return时 copy//????为什么不调用copy？？？？
	b3.Disp();
}
void test06() {
	using namespace class906;
	Add A(5), B(5);
	++A;
	B++;
	A.show(); B.show();
	Add C(A), D(A);
	++C;
	D++;
	C.show(); D.show();
	cout << endl;

	//	10  7   15   12
}
//void test05() {
//	using namespace class906;
//	Printer HP, Canon(4);
//	Canon.PrintPages();
//}
void test07() {
	using namespace class906;
	Point myp1(1, 1), myp2(4, 5);//Point构造函数被调用//Point构造函数被调用
	//定义Point类的对象 
	Line line0(myp1, myp2);//Point复制构造函数被调用//Point复制构造函数被调用//Line构造函数被调用
	//定义Line类的对象 
	cout << "The length of the line0 is:";//The length of the line0 is:5
	cout << line0.GetLen() << endl;
}
void test08() {
	int a = 9;
	double b = 1.8;
	a += b;
	cout << a << endl;
}
void test09() {

	BinTreeNode<int>* p1 = new BinTreeNode<int>(4);
	BinTreeNode<int>* p2 = new BinTreeNode<int>(5);
	BinTreeNode<int>* p3 = new BinTreeNode<int>(6);
	BinTreeNode<int>* p4 = new BinTreeNode<int>(2);
	BinaryTree<int> tr(p1);
	tr.Insert(tr.getRoot(), p2, 1);
	tr.Insert(tr.getRoot(), p3, 2);

	BinaryTree<int> tr2(tr);
	tr2.Insert(tr2.getRoot()->leftChild, p4, 1);

	cout << "good job! all done! but now tring to destroy! \n";
}
int main() {
	test09();
	return 0;
}