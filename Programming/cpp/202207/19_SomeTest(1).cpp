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
//#include<heap.h>//δ�����ļ�
//#include<UFSets.h>
using namespace std;

//ʹ���ַ�����������ת��Ϊ�ַ���
template<class T>
inline string toString(const T& x) {
	ostringstream ost;
	ost << x;//������ַ���
	//Ҫ����<<�ķ���
	// ����Ҫ��x�Ķ�������ostringstream �����ost << x;
	// ʵ���ϼ�ͷ��ʾ��������
	//ofstream ofs >> t;//ofstream���ļ�����
	return ost.str();
}
void test01() {
	string s = "I am a string!";
	int i = 90;
	//ofstream if = toString(i).str;
	string s1 = toString(i);//����ȱʡĬ������
	cout << s1 << endl;
}
//ʹ���ַ��������ַ���ת��Ϊ����
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
	//������Ҫָ��������ΪT�ڷ���ֵ��λ����
	//���޷����ݲ��������Զ��жϡ�
	cout << res << endl;
}

//������ָ��Ĺ�ϵ����ȷ��
void test03() {
	int a = 9;
	int& b = a;//����һ�����ε����ã�b��a��ͬ���Ķ���
	//����ֱ�����b��
	cout << b << endl;
	int* p = &b;
	cout << *p << endl;
}

//ȷ��ָ�볣���ͳ���ָ��Ĺ�ϵ
void test04() {
	int a = 90;
	const int* p = &a;//Ҫ�ѡ�int*�����Ϊһ��ȫ�µ�����
	//*p = 89;
	//p����������ָ�룬��ָ������ǳ��������ܸı�
	int b = 79;
	int* const p2 = &a;
	//p2 = &b;
	//p2������ָ�볣���������Ƶ����ÿ��Բο������γ�����
	//��ʾ���ָ�벻�ܸı䡣
	cout << *p2 << endl;
}

//����������С�������θ�Ч���n���ڵ�����
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
					break;//���������һ�����˼� ���³�������겻����������
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
	//һ���򵥵ĳ���
	//������� ��
	class Person {
	private://����
		int id;//223;
		string name;//Peter �ַ���
	public://��Ϊ
		Person() {};
		//��ȡid��
		int get_id() { return id; }
		//��ȡ����
		string get_name() { return name; }

		//����һ����
		Person(int a, string b) :id(a), name(b) {}

		inline void show() {
			cout << "id: " << id << "\tname: " << name << endl;
		}

		//bool ��������
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

//����������stl�㷨�Ĺ�ϵ
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

//��³˹�����㷨��ʵ��
//�ȶ���ߵĽṹ
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
	//�ں�һ����ֵ����,�ڹ��캯���д���
	MSTEdgeNode<T, E>* edgeV;
	int maxSize, n;
public:
	MinSpanTree(int sz):maxSize(sz),n(0) {
		edgeV = new MSTEdgeNode<T, E>[sz];
	}
	int Insert(MSTEdgeNode<T,E>& item);
};
//��ʵ�ֿ�³˹�����㷨��ʹ��stl�еĶѺͲ��鼯��
//��ʱʵ�ֲ��� ��Ϊ��Ҫ��д���ݽṹ
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

//����������906��ϰ��
const int M = 4;
const int N = 5;
void come(int d[][N], int m) {
	for (int i = 1; i <= M - 2; i++)//1 2 3�� ��1 2
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
	19//��
	*/

	p = a[0];
	cout << *p << endl; //1
	p = a[1];
	cout << *p << endl;//6

	cout << *(p += N) << endl;//11
}
void test10() {
	//int(*ptr)[3];//���������ʲô��
	//ptr = q;

	//int* l = p + q;
	//if (qp)cout << "l" << endl;
	//int b[3];
	//ptr = b;
	//int 
	//ptr = p;
	//cout << ( * ptr)[1] << endl;

	int* p = new int[9]();//��̬����һ�����飬���ã���ȫ����ʼ��Ϊ0
	for_each(p, p+9, print);
	delete[]p;
	cout << endl;

	//�ɾ����
	char s[] = "246", * ptr = s;
	cout << s << endl;
	cout << (char)(*(ptr + 1) + 1) << '\n';
	cout << *(ptr + 1) << endl;
	cout << (char)(53) << endl;


	cout << "ֱ�Ӱ��ַ�+1�� " << '0' + 1 << endl;

	//char* name;
	//name = &"southeast";
	//cout << char(name[1] + 3) << '\n'; //��0��+3//��r��
	//cout << char(*name + 3) << '\n'; //��ȡ�˵�һ���ַ���Ȼ������Ų���� stuvw//v
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
	f(a);//�ѵ�һ����+5
	for (i = 0;i < 5;i++)
		printf("%d,", a[i]);//6,2,3,4,5,
}

void swap(int* a, int* b){
	int* t;
	t = a;a = b;b = t;
}//���ܽ���ʵ��
void swap2(int* a, int* b) {
	int* t = a;
	a = b;b = t;
}//���ܽ���ʵ��
void swap3(int* a, int* b) {
	int t = *a; *a = *b; *b = t;
}//ͨ��* �����õķ�ʽ�ı���ʵ��
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

//��ĩ���еĴ��� �Ҿ��ò���ô����
class CPc {
private:
	int  Id;                //��Ʒ���
	double   Price;         //�۸�
	int   Amount;           //����
	int   mon;              //���������º�
	int   day;              //���������պ�
public:
	CPc(int a, double b, int c, int d, int e) {
		Id = a; Price = b; Amount = c;
		if (d < 1 || d>12) { cout << "�ºŴ���!" << endl;mon = 0; }
		else mon = d;
		//if (!Jugedate(e)) { cout << "�պŴ���!" << endl;day = 0; }
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
	void   CountTotal(void);    //�����ܼ�ֵ
	void   Join(CPc& that);     //������that����ֵ�ϲ�������this��
	int   Getdays();            //�����1��1�������ö���������ڵ�����
	//int  Jugedate(int d) { ... }  //�˺����Ĵ����ԣ����ںϷ�����1�����򷵻�0
	friend void Print(CPc& p);    //�����Ϣ
};
void CPc::CountTotal(void) {
	cout << "���Ϊ" << Id;
	cout << "����Ʒ�ܼ�ֵ:" << Price * Amount << endl;
}
void CPc::Join(CPc& that) {
	if (Id == that.Id) {
		Amount += that.Amount;
		that.Amount = 0;
	}
	else cout << "��ͬ��Ʒ�޷��ϲ�!" << endl;
}
int CPc::Getdays() {  //���㵱���1��1���������յ�����
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
	default:cout << "���ڴ���!" << endl;
	}
	daynum = daynum + day - 1;
	return daynum;
}
void Print( CPc& P) {
	cout << "��Ʒ��Ϣ:" << endl;
	cout << "��Ʒ���:" << P.Id << '\t' << "�۸�:" << P.Price << '\t'
		<< "����:" << P.Amount << '\t';
	cout << "��������:" << P.mon << "��" << P.day << "��" << endl;

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
	cout << "T��1��1�����������յ�����:" << T.Getdays() << endl;
	cout << "S��1��1�����������յ�����:" << S.Getdays() << endl;
}

//�������ص���֤
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

//explicit����֤:ֻ���������ڵĹ��캯����
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

//��֤��a+b��/��2c-2d��
void test19() {
	double a = 1.5, b = 2.5;
	double c = 2.3, d = 1.3;
	double s = (a + b) / 2 / (c - d);
	cout << "s = " << s << endl;
}

//��֤c�����ַ���
void test20() {
	char name[] = "asdgaw";
	cout << name << endl;
}
void output(char[]);
class Point {
public:
	//cout << "2" << endl;
	//��ʹ�����������Ĭ��ֵ����ȷ���룬����ò�Ҫ����
	//������Ҫʹ��Ĭ�Ϲ��캯��
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

//�ַ�������
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

//��ת�ַ�����
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

//c���Բ���
void test24(){
	int p[8] = { 11,12,13,14,15,16,17,18 }, i = 0, j = 0;
	while (i++ < 7) if (p[i] % 2) j += p[i];//i:1,2,3,4,5,6,7
	printf("%d\n", j);
}

//��ǳ�����ı���
//vs��strcpy��������ʵ�����õ�����ͷ��
//���ǹԹ���string ��
namespace strtest {
	class Person {
		char* name;
		int id;
	public:
		Person(char* n = 0, int i = 0) {
			if (n) {
				name = new char[strlen(n) + 2];
				//��̬���� C ����ַ��� 
				//name = n;
				//cout << "\tsomething wrong?" << endl;
				//strcpy_s(name, n);
			}
			else name = 0;
			id = i;
			cout << "���ù��캯��!"<< endl;
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
			cout << "���ƹ��캯���ĵ��ã�" << endl;
		}
		~Person();
		void print() {
			cout << name << ',' << id;// << "succesfully printed!!\n";
		}
	};
	Person::~Person() {
		//�� �� �� �� �� �� �� �� ��
			if (name) delete[]name;
		cout << "������������!" << endl;
	}
}
void test25() {
	using namespace strtest;
	char s[] = "zhang";
	Person p1(s, 101);
	//���ù��캯����
	p1.print();
	Person p2(p1);//�� p1 ���� p2 
	//���ø��ƹ��캯��
	//���ø��ƹ��캯��
	p2.print();
	//��������������
	//��������������
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
	printf("%c", *p++);//ע�� ����ȼ���*��p++��
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

	//һ�����ڴ��������list
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
	//����һ����򵥵�����
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
	//ɾ���ͼ��Mlist
	class Mlist {
	public:
		//�򵥵�Ĭ�Ϲ���
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
		//����
		int len() {
			ListNode* h = head;
			int i = 0;
			while (h != NULL) {
				i++;
				h = h->link;
			}
			return i;
		}
		//���ӽڵ�
		void add(int u) {
			ListNode x(u);
			tail->link = &x;
			tail = &x;
			//cout << "successfully added\n";
		}
		//�ۼ�
		unsigned long long accum() {
			//����ʾ10^19;
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