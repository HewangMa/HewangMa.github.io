#include<iostream>
#include<sstream>
#include<string>
#include<list>
#include<ostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<stdio.h>
#include<fstream>
#include<assert.h>
//#include<heap.h>//未定义文件
//#include<UFSets.h>
using namespace std;

//使用字符串流将数字转化为字符串
template<class T>
inline string toString(const T& x) {
	ostringstream ost;
	ost << x;//这才是字符流
	//要分清<<的方向：
	// 这里要把x的东西读入ostringstream 因此用ost << x;
	// 实际上箭头表示数据流向
	//ofstream ofs >> t;//ofstream是文件流！
	return ost.str();
}
void test01() {
	string s = "I am a string!";
	int i = 90;
	//ofstream if = toString(i).str;
	string s1 = toString(i);//可以缺省默认类型
	cout << s1 << endl;
}
//使用字符串流将字符串转化为数字
template<class T>
inline T fromString(const string& x) {
	T res;
	istringstream ist(x);
	ist>>res;
	return res;
}
void test02() {
	string s = "2947";
	int res = fromString<int>(s);
	//这里需要指定类型因为T在返回值的位置上
	//，无法根据参数类型自动判断。
	cout << res << endl;
}

//引用与指针的关系？再确认
void test03() {
	int a = 9;
	int& b = a;//创建一个整形的引用，b与a是同样的东西
	//可以直接输出b；
	cout << b << endl;
	int* p = &b;
	cout << *p << endl;
}

//确认指针常量和常量指针的关系
void test04() {
	int a = 90;
	const int* p = &a;//要把“int*”理解为一种全新的类型
	//*p = 89;
	//p被称作常量指针，其指向的量是常量，不能改变
	int b = 79;
	int* const p2 = &a;
	//p2 = &b;
	//p2被称作指针常量，其名称的作用可以参考“整形常量”
	//表示这个指针不能改变。
	cout << *p2 << endl;
}

//以下内容是小灶，关于如何高效输出n以内的质数
namespace classtest {
	void test05(int n) {
		list<int> m;
		m.push_back(2);
		for (int i = 3;i <= n;i += 2) {
			list<int>::iterator it = m.begin();
			while (it != m.end()) {
				//cout << "i: " << i << " ";
				if ((*it) * (*it) > i) {
					m.push_back(i);
					break;//昨天就是这一句忘了加 导致程序计算完不能正常结束
				}
				if (i % (*it) == 0) {
					//cout << i << " ";
					break;
				}
				else it++;
			}
		}
		copy(m.begin(), m.end(), ostream_iterator<int>(cout, " "));
	}
	//一个简单的程序
	//面向对象 类
	class Person {
	private://属性
		int id;//223;
		string name;//Peter 字符串
	public://行为
		Person() {};
		//获取id号
		int get_id() { return id; }
		//获取姓名
		string get_name() { return name; }

		//构造一个人
		Person(int a, string b) :id(a), name(b) {}

		inline void show() {
			cout << "id: " << id << "\tname: " << name << endl;
		}

		//bool 布尔类型
		bool is_friend(Person& x) {
			if (abs(id - x.id) < 2)return true;
			else return false;
		}
	};
}
void test07() {
	using namespace classtest;
	Person x(10023, "Peter");
	Person y(10024, "Simpson");
	x.show();
	y.show();
	if (x.is_friend(y)) 
		cout << x.get_name() << " and " << y.get_name()
		<< " are friends!" << endl;
	else
		cout<< x.get_name() << " and " << y.get_name()
		<< " are not friends!" << endl;
}

//函数对象与stl算法的关系
template<class T>
T prod(T a, T b) {
	return a * b;
}
template<class T>
T gsy(T a, T b) {
	T ta = a;
	T tb = b;
	a = max(ta, tb);
	b = min(ta, tb);
	while (b > 0) {
		if (a % b == 0) return b;
		else {
			cout << "a: " << a << " b: " << b << endl;
			T t = b;
			b = a % b;
			a = t;
		}
	}
}
void test06() {
	int ivector[4] = { 4,8,16,24 };
	vector<int> s(ivector, ivector + sizeof(ivector) / sizeof(int));
	sort(s.begin(), s.end());
	int x = s.back();
	int a = accumulate(s.begin(), s.end(), x, gsy<int>);
	cout << a << endl;
}

//克鲁斯卡尔算法的实现
//先定义边的结构
template<class T,class E>
struct MSTEdgeNode {
	int tail, head;
	E key;
	MSTEdgeNode() :tail(-1), head(-1), key(0) {}
	bool operator<=(MSTEdgeNode<T, E>& R) {
		return key <= R.key;
	}
	bool operator>(MSTEdgeNode<T, E>& R) {
		return key > R.key;
	}
};
template<class T,class E>
class MinSpanTree {
protected:
	//内涵一个边值数组,在构造函数中创建
	MSTEdgeNode<T, E>* edgeV;
	int maxSize, n;
public:
	MinSpanTree(int sz):maxSize(sz),n(0) {
		edgeV = new MSTEdgeNode<T, E>[sz];
	}
	int Insert(MSTEdgeNode<T,E>& item);
};
//再实现克鲁斯卡尔算法（使用stl中的堆和并查集）
//暂时实现不了 因为需要重写数据结构
void Kruskal() {

}

void print(int s) {
	cout << s << " ";
}
void test08() {
	int ivector[8] = { 5,2,52,56,3,85,78,21 };
	vector<int> v(ivector, ivector + 8);
	make_heap(v.begin(), v.end(), greater<int>());
	//sort_heap(v.begin(), v.end());
	for_each(v.begin(), v.end(), print);
}

//以下内容是906练习题
const int M = 4;
const int N = 5;
void come(int d[][N], int m) {
	for (int i = 1; i <= M - 2; i++)//1 2 3错！ 是1 2
		cout << d[i][i] << endl;
}
void test09(){
	int a[4][5], * p;
	int i, j, k = 1;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			a[i][j] = k++;
	/*
	{1,2,3,4,5
	6,7,8,9,10
	11,12,13,14,15
	16,17,18,19,20}
	*/

	come(a, M);

	/*
	7
	13
	19//错
	*/

	p = a[0];
	cout << *p << endl; //1
	p = a[1];
	cout << *p << endl;//6

	cout << *(p += N) << endl;//11
}
void test10() {
	//int(*ptr)[3];//这个到底是什么？
	//ptr = q;

	//int* l = p + q;
	//if (qp)cout << "l" << endl;
	//int b[3];
	//ptr = b;
	//int 
	//ptr = p;
	//cout << ( * ptr)[1] << endl;

	int* p = new int[9]();//动态分配一个数组，并用（）全部初始化为0
	for_each(p, p+9, print);
	delete[]p;
	cout << endl;

	//成句辨析
	char s[] = "246", * ptr = s;
	cout << s << endl;
	cout << (char)(*(ptr + 1) + 1) << '\n';
	cout << *(ptr + 1) << endl;
	cout << (char)(53) << endl;


	cout << "直接把字符+1： " << '0' + 1 << endl;

	//char* name;
	//name = &"southeast";
	//cout << char(name[1] + 3) << '\n'; //‘0’+3//‘r’
	//cout << char(*name + 3) << '\n'; //先取了第一个字符，然后往后挪三个 stuvw//v
	//cout << *(name + 3) << '\n'; //t
	//cout << name[4] << '\n';//h

}

void ft(int* s, int n1, int n2) {
	int t;
	while (n1 < n2) {
		t = *(s + n1);
		*(s + n1) = *(s + n2);
		*(s + n2) = t;
		n1++;
		n2--;
	}
}
void test11() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int i, * pi = a;
	ft(pi, 0, 3);
	for_each(pi, pi + 10, print);cout << endl;
	//4 3 2 1 5 6 7 8 9 0
	cout << "*p : " << *pi << endl;
	ft(pi + 3, 1, 6);
	for_each(pi, pi + 10, print);cout << endl;

	int k[3][3], * pk[2];

	//pk = k;//y
	//pk[0] = &k[1][2];//x
	//pk = k[0];//x
	//pk[1] = k;//x

	int ai[10] = { 1,5,6,4,2,74,7,2,4,2 };
	int * p, *s;
	for (p = ai, s = ai;p - ai < 10;p++)
		if (*p > *s) s = p;
	printf("index= %d\n", s - ai);
	printf("max= %d\n",*s);
}

float f1(float n){
	return n * n;
}
float f2(float n){
	return 2 * n;
}
void test12(){
	float (*p1)(float), (*p2)(float), (*t)(float), y1, y2;
	p1 = f1; p2 = f2;
	y1 = p2(p1(2.0));//y1=p2(4.0)=8.0;
	t = p1; p1 = p2; p2 = t;
	y2 = p2(p1(2.0));//y2=p2(4.0)=16.0
	printf("%3.0f, %3.0f\n", y1, y2);//8,16
}

void f(int* q){
	int i = 0;
	for (;i < 5;i++)//i=0,1,2,3,4
		(*q)++;//(*q)+=5;
}
void test13(){
	int a[5] = { 1,2,3,4,5 }, i;
	f(a);//把第一个数+5
	for (i = 0;i < 5;i++)
		printf("%d,", a[i]);//6,2,3,4,5,
}

void swap(int* a, int* b){
	int* t;
	t = a;a = b;b = t;
}//不能交换实参
void swap2(int* a, int* b) {
	int* t = a;
	a = b;b = t;
}//不能交换实参
void swap3(int* a, int* b) {
	int t = *a; *a = *b; *b = t;
}//通过* 解引用的方式改变了实参
void test14(){
	int i = 3, j = 5, * p = &i, * q = &j;

	swap(p, q);
	cout << "result of swap():   i: " << i
		<< " j: " << j << endl;

	swap2(p,q);
	cout << "result of swap2():   i: " << i
		<< " j: " << j << endl;

	swap3(p, q);
	cout << "result of swap3():   i: " << i
		<< " j: " << j << endl;
}
void fun(char* c){
	while (*c)	{
		if (*c >= 'a' && *c <= 'z')
			*c = *c - ('a' - 'A');
		c++;
	}
}
void test15(){
	char s[81];
	cin >> s;
	fun(s);
	puts(s);
}

//期末题中的代码 我觉得不那么优美
class CPc {
private:
	int  Id;                //产品编号
	double   Price;         //价格
	int   Amount;           //数量
	int   mon;              //进货日期月号
	int   day;              //进货日期日号
public:
	CPc(int a, double b, int c, int d, int e) {
		Id = a; Price = b; Amount = c;
		if (d < 1 || d>12) { cout << "月号错误!" << endl;mon = 0; }
		else mon = d;
		//if (!Jugedate(e)) { cout << "日号错误!" << endl;day = 0; }
		//else 
		day = e;
	}
	CPc(const CPc& B) {
		Id = B.Id;
		Price = B.Price;
		Amount = B.Amount;
		mon = B.mon;
		day = B.day;
	}
	void   CountTotal(void);    //计算总价值
	void   Join(CPc& that);     //将对象that数量值合并到对象this中
	int   Getdays();            //计算从1月1日起至该对象进货日期的天数
	//int  Jugedate(int d) { ... }  //此函数的代码略，日期合法返回1，否则返回0
	friend void Print(CPc& p);    //输出信息
};
void CPc::CountTotal(void) {
	cout << "编号为" << Id;
	cout << "的商品总价值:" << Price * Amount << endl;
}
void CPc::Join(CPc& that) {
	if (Id == that.Id) {
		Amount += that.Amount;
		that.Amount = 0;
	}
	else cout << "不同商品无法合并!" << endl;
}
int CPc::Getdays() {  //计算当年从1月1日起至该日的天数
	int daynum = 0;
	switch (mon) {
	case 12:daynum += 30;
	case 11:daynum += 31;
	case 10:daynum += 30;
	case 9:daynum += 31;
	case 8:daynum += 31;
	case 7:daynum += 30;
	case 6:daynum += 31;
	case 5:daynum += 30;
	case 4:daynum += 31;
	case 3:daynum += 28;
	case 2:daynum += 31;
	case 1:   break;
	default:cout << "日期错误!" << endl;
	}
	daynum = daynum + day - 1;
	return daynum;
}
void Print( CPc& P) {
	cout << "商品信息:" << endl;
	cout << "产品编号:" << P.Id << '\t' << "价格:" << P.Price << '\t'
		<< "数量:" << P.Amount << '\t';
	cout << "进货日期:" << P.mon << "月" << P.day << "日" << endl;

}
void test16() {
	CPc S(4216, 22.5, 800, 12, 31), T(4218, 58.6, 200, 7, 23);
	CPc W(S);
	Print(S);
	Print(T);
	T.CountTotal();
	S.Join(W);
	Print(S);
	Print(W);
	cout << "T从1月1日起至进货日的天数:" << T.Getdays() << endl;
	cout << "S从1月1日起至进货日的天数:" << S.Getdays() << endl;
}

//函数重载的验证
int Mo(int a, int b = 0) { 
	cout << "Mo1\n";
	cout << a << endl; return 1; 
};
double Mo(double a, int b, int c = 0) {
	cout << "Mo2\n";
	cout << a << " " << b << endl;
	return 1.4;
};
void test17() {
	double x = Mo('2');
	cout <<setw(2) << x << endl;
	double y = Mo(3.2 / 5, 6 / 7);
}

//explicit的验证:只能用于类内的构造函数。
class Test1{
public:
	Test1(int num) :n(num) {}
private:
	int n;
};
class Test2{
public:
	explicit Test2(int num) :n(num) {}
private:
	int n;
};
int test18() {
	Test1 t1 = 12;
	Test2 t2(13);
	//Test2 t3 = 14;
	return 0;
}

//验证（a+b）/（2c-2d）
void test19() {
	double a = 1.5, b = 2.5;
	double c = 2.3, d = 1.3;
	double s = (a + b) / 2 / (c - d);
	cout << "s = " << s << endl;
}

//验证c语言字符串
void test20() {
	char name[] = "asdgaw";
	cout << name << endl;
}
void output(char[]);
class Point {
public:
	//cout << "2" << endl;
	//即使这里可以设置默认值并正确编译，但最好不要这样
	//还是需要使用默认构造函数
	int x = 1, y = 0, z = 0;
	Point() {};
	Point(int a,int b,int c) :x(a), y(b), z(c) {};
};

void test21() {
	int(*ptr)[4];
	int a[2][4];
	ptr = a;
	char s[] = "aegbr";
	//char* a = s;
}

//字符串测试
void find(char a[], int m) {
	char* p;
	int i = 0;
	p = a;
	while (i <= m && *p != '\0') {
		cout << *p;
		p++;
		i++;
	}
	cout << endl;
}
void test22(){
	char s[] = "WINDOWS-SYSTEM";
	for (int i = 2; i < 5; i++) //i:2,3,4
		find(s + i, i);
}

//反转字符测试
void inverse(char str[]) {
	char m;
	int i, j = strlen(str);
	for (i = 0;i < strlen(str) / 2;i++) {
		m = str[i];
		str[i] = str[--j];
		str[j] = m;
	}
}
void test23() {
	char s[] = "agvar1561w";
	cout << strlen(s) << endl;
	cout << s << endl;
	inverse(s);
	cout << s << endl;
}

//c语言测试
void test24(){
	int p[8] = { 11,12,13,14,15,16,17,18 }, i = 0, j = 0;
	while (i++ < 7) if (p[i] % 2) j += p[i];//i:1,2,3,4,5,6,7
	printf("%d\n", j);
}

//深浅拷贝的辨析
//vs的strcpy（）函数实在是用的让人头疼
//还是乖乖用string 吧
namespace strtest {
	class Person {
		char* name;
		int id;
	public:
		Person(char* n = 0, int i = 0) {
			if (n) {
				name = new char[strlen(n) + 2];
				//动态建立 C 风格字符串 
				//name = n;
				//cout << "\tsomething wrong?" << endl;
				//strcpy_s(name, n);
			}
			else name = 0;
			id = i;
			cout << "调用构造函数!"<< endl;
		}
		Person(const Person& R) {
			int len = strlen(R.name);
			if (R.name) {
				name = new char[len + 2];
				//name = R.name;
				//cout << "\tsomething wrong?" << endl;
				//copy(R.name, R.name+len, name);
			}
			id = R.id;
			cout << "复制构造函数的调用！" << endl;
		}
		~Person();
		void print() {
			cout << name << ',' << id;// << "succesfully printed!!\n";
		}
	};
	Person::~Person() {
		//修 改 后 的 输 出 结 果 ：
			if (name) delete[]name;
		cout << "调用析构函数!" << endl;
	}
}
void test25() {
	using namespace strtest;
	char s[] = "zhang";
	Person p1(s, 101);
	//调用构造函数！
	p1.print();
	Person p2(p1);//由 p1 复制 p2 
	//调用复制构造函数
	//调用复制构造函数
	p2.print();
	//调用析构函数！
	//调用析构函数！
}
void test26() {
	char s[] = "16541asgbw";
	int sl = strlen(s);
	char p[]="agrweseatmjnhgvdf";
	copy(s, s + sl, p);
	cout << p << endl;
	strcpy_s(p, s);
	cout << p << endl;
}
void test27() {
	char s[] = "159", * p;
	p = s;
	printf("%c", *p++);//注意 这里等价于*（p++）
	printf("%c", *p++);
}

namespace test28name {
//#include "stdio.h"
//#include "string.h"
	void f(char* s, char* t){
		char k;
		k = *s; *s = *t; *t = k;
		s++; t--;
		if (*s) f(s, t);
	}
	void fun(char* t, char* s){
		while (*t != 0) t++;
		while ((*t++ = *s++) != 0);
	}
}
void test28() {
	using namespace test28name;
	char str[10] = "abcdefg", * p;
	p = str + strlen(str) / 2 + 1;
	f(p, p - 2);
	printf("%s\n", str);
	//gfedcba
}
void test29() {
	using namespace test28name;
	char ss[10] = "acc", aa[10] = "bbxxyy";
	fun(ss, aa);
	printf("%s,%s\n", ss, aa);
}

void test30() {
	char s[] = "string";
	cout << sizeof(s) << endl;
}

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
		int count = 0;
		PrimeList() {
			head = new Node;
			tail = head;
			head->link = tail;
		}
		PrimeList(Node& x) {
			head = &x;
			tail = head;
			head->link = NULL;
			count++;
		}
		void add(Node* x) {
			tail->link = x;
			tail = x;
			assert(!tail->link);
			//tail->link = NULL;
			count++;
		}
		void show() {
			//int a = 0;
			Node* p = head;
			while (p != NULL) {
				//if (a % 10 == 0) {
				cout << p->val << " ";
				//a = 0;
			//}
				p = p->link;
				//a++;
			}
			cout << endl;
		}
		friend bool PrimeInsert(int, PrimeList&);
		friend bool Prime(int, PrimeList&);
		//friend FivePrime;
		//friend bool Trunc(int, PrimeList&);
		bool Exist(int a) {
			Node* p = head;
			while (p != NULL) {
				if (p->val == a)return 1;
				if (p->val > a) return 0;
				else p = p->link;
			}
			return 0;
		}
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
	bool Prime(int a,PrimeList&L) {
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
	struct FivePrime{
		vector<int> setFive;
		vector<int>::iterator it1 = setFive.begin(), it2 = setFive.begin();
		bool check() {
			while (it1 != setFive.end() && it2 != setFive.end()) {
				string a = toString<int>(*it1), b = toString<int>(*it2);
				int c = fromString<int>(a + b);
				if(!Prime(c))
			}
		};
		int sum() {
			return accumulate(setFive.begin(),setFive.end(),0);
		}
	};
}
void test31() {
	using namespace PrimePair;
	Node x(2);
	PrimeList L(x);
	int i = 2;
	while (i++ < 1000)PrimeInsert(i,L);
	L.show();
}

int main() {
	test31();
	return 0;
}