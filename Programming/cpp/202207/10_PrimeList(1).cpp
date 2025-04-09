#include<iostream>
#include<iomanip>
#include<string.h>
#include<list>
#include<iterator>
#include<functional>
#include<vector>
#include<algorithm>
#include<deque>
#include<cassert>
#include<numeric>
#include<set>
#include<queue>
//#include<iostream>
using namespace std;
namespace questionOne{
	const int m = 5;
	void print(int k) {
		int i;
		if (k < m) {
			for (i = 0;i < k - 1;i++)cout << k << ',';
			cout << k << endl;
			print(k + 1);
		}
	}
	void qiout(int k) {
		static int a = 0;
		int b = 1;
		a += k;b *= k;
		cout << "a=" << a << ',' << "b=" << b << endl;
	}
	void test01() {
		int n = 1;
		qiout(n *= 2);
		print(n);
		qiout(2 * n);
	}
	int fun(int n) {
		int m;
		if (n <= 1)
			return 1;
		cout << n << '#';
		m = n - fun(n - 1);
		cout << n << '*';
		return m;
	}
	void f(int n) {
		cout << n % 10;
		if (n > 10)	f(n / 10);
	}
	void output(int i) {
		cout << setw(5) << i << '\n';
	}
	void output(float fvalue) {
		cout << setprecision(2) << fvalue << '\n';
	}
	void output(char name[]) {
		cout << setw(30) << name << '\n';
	}
	int commonDiv(int n1, int n2) {
		int rd = (n1>n2) ? (n1%n2) : (n2%n1);
		if (rd == 0) return (n1 > n2) ? n2 : n1;
		return commonDiv(((n1 > n2) ? n2 : n1), rd);
	}
	int commonDiv2(int n1, int n2) {
		int rd =n1%n2;
		//cout << "rd = " << rd << endl;
		if (rd == 0) return n2;
		return commonDiv(n2, rd);//����Ľ����Ȼ����ȷ�� 
					//��Ϊ���n2>n1,ͨ��rd���Խ����������ֽ�������
	}
	int func(int a, int& b) {
		a = 5;
		b = 9;
		return a + b;
	}
	int max = 0;
	class A {
		int x, y;
		static int count;
	public:
		//���Դ���Ĭ�Ϲ����ȱʡֵ���캯��
		A(int a = 0, int b = 0) {
			x = a;y = b;max = ++count;
			cout << "calling the constr!\n";
		}
		A(A& a) {
			x = a.x;y = a.y;max = ++count; 
			cout << "calling the copy constr!\n";
		}
		~A() { --count; }
		int getNum() { return count; }
		friend void VR(A);
	};
	int A::count = 0;
	void VR(A a) {
		cout << a.x << endl;
	}
	class A2 {
		int z;
	public:
		A2(int x = 0) {
			z = x + count; //100+1
			count++; //2
			cout << z << '\n';//101 
		}
		static int count;
	};
	int A2::count = 1;
	class Person {
		string name;
		int ID;
	public:
		Person() {
			ID = 90;
			name = "eaijb";
		}
		int getId() {
			return ID;
		}
	};
	class Student :private Person {
	public:
		int getIID() {
			return getId();
		}
	};
	class B {
		int a;
	public:
		B(int k) { a = k; }
	};
}
using namespace questionOne;
namespace test {

	using namespace questionOne;
	void test01() {
		//using namespace questionOne;
		char name[] = "C++ Progamming Language";
		int ivalue = 9656;
		float fvalue = 39.8891;
		output(ivalue);
		output(fvalue);
		output(name);
	}
	void test02() {
		//using namespace questionOne;
		int n1, n2;
		cin >> n1 >> n2;
		cout << commonDiv2(n1, n2) << endl;
	}
	void test03() {
		int i = 0, j = 9;
		//func(i, j + 2);
	}
	void test04() {
		int left = 9;
		double Pi = 3.1415926;
		cout << setprecision(3) << Pi << endl;
		//cout << fixed;
		//cout << fixed;
		cout << setprecision(5) << Pi << endl;
		//cout << ios::left << endl;
		cout << setfill('*') << setw(20) << setiosflags(ios::left) << Pi << endl;
		//cout << setprecision(15) << Pi << endl;
	}
	void test05() {
		A a, a2(10, 20);
		cout << a2.getNum() << endl;
		A a3 = a;
		cout << a2.getNum() << endl;
		a = A(20, 30);
		cout << a2.getNum() << endl;
		cout << questionOne::max << endl;
		VR(a);
	}
	void test06() {
		A2 a(100);
		A2 b;
		A2 c(200);
		cout << "count=" << b.count << endl;
	}
	int k = 5;
	void test07() {
		int k = 10;
		for (int i = 1;i < 5;i++) { //1234
			int k = 0;
			k += i; //k=1,k=2
			cout << k << ','  << '\n';
			//1,5
		   //2,6
		   //3,7
		   //4,8
			k++; //k=2
			//::k++; //k=6,7
		}
		cout << k << '\n'; //10
	}
	void test08() {
		Student ui;
		cout << ui.getIID();
	}
	void test09() {
		//int maxio(int a, int b);//���������������ڣ����ǲ���д������ʵ�֡�
		//cout << maxio(3785, 4364758) << endl;
		int a[3][4] = {
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12}
		};
		int b[4][3];
		for (int i = 0;i < 4;i++) {
			for (int j = 0;j < 3;j++) {
				b[i][j] = a[j][i];
			}
		}
		for (int i = 0;i < 4;i++) {
			for (int j = 0;j < 3;j++)cout << b[i][j] << ' ';
			cout << endl;
		}
	}
	void sortAndShow(int a[], int n) {
		for (int i = 0;i < n;i++) {
			int minx = INT_MAX;
			int index = 0;
			for (int j = i;j < n;j++) {
				if (a[j] < minx) {
					minx = a[j];
					index = j;
				}
			}
			for (int k = index;k >= i;k--) {
				a[k] = a[k - 1];
			}
			a[i] = minx;
		}
		for (int i = 0;i < n;i++)cout << a[i] << ' ';
		cout << endl;
	}
	void sortAndShow2(int* a, int n) {
		for (int i = 0;i < n;i++) {
			int minx = INT_MAX;
			int index = 0;
			for (int j = i;j < n;j++) {
				if (*(a + j) < minx) {
					minx = *(a + j);
					index = j;
				}
			}
			for (int k = index;k >= i;k--) {
				*(a + k) = *(a + k - 1);
			}
			*(a + i) = minx;
		}
		for (int i = 0;i < n;i++)cout << a[i] << ' ';
		cout << endl;
	}
	void test10() {
		int(*p)[5] = new int[9][5];
		p[1][4] = 0;
		delete[]p;
		char str[8];
		str[0] = 'a';
		str[1] = '\0';
		str[2] = 'w';
		for (int i = 0;i < 5;i++)cout << str[i];
		cout << endl;
		char a = '\0';
		cout << "a = " << (int)a << endl;
		string s1 = "awgr";
		string s2 = "aw";
		cout << (s1 > s2) << endl;
	}
	void test11() {
		B x[2] = { B(1),B(3) };
	}
	void fun(int a) {
		int i = 0, y = 0, s = 1;
		while (++i <= a) //i=1 2 3
			y += s *= i;
		cout << y << ',' << s << endl;
	}
	void test12() {
		int i, a[4] = { 0,1,2,3 };
		for (i = 0;i < 4;i++) {
			if (i % 2 == 0) continue;
			::fun(a[i]); //fun(a[1]);fun(a[3]);
		}
	}
	void test13() {
		int a[4][4] =
		{ 1,2,3,4
			,2,2,5,6
			,3,5,2,7
			,4,6,4,7 };
		int i, j, flag = 0, sum = 0;
		for (j = 0;j < 4;j++)
			for (i = 0;i <= j;i++) {
				if (a[j][i] == a[i][j]) {
					sum += a[i][j];
					continue;
				}
				flag = 1;
			}
		if (flag)cout << "No!" << endl;
		else cout << "All Right!" << endl;
		cout << "sum=" << sum << endl;
	}
#define N 4 
	void test14() {
		int a[N][N] = {
			1,2,3,4,
			5,6,7,8,
			9,10,11,12,
			13,14,15,16
		};
		int i, j, t;

		for (i = 0;i < N;i++) {

			for (j = 0;j < N;j++)
				if ((i == 0) || (i == N - 1))
					a[i][j]++;
				else if ((j == 0) || (j == N - 1))
					cout << a[i][j] << '\t';

		}
		cout << '\n';
		/*
		5	8	9	12

		*/
	}
}
namespace questionT {
	int min(int b[], int n) {
		int minx = INT_MAX;
		int index = 0;
		for (int i = 0;i < n;i++) {
			if (b[i] < minx) {
				minx = b[i];
				index = i;
			}
		}
		return index;
	}
	int gys(int b[], int n) {
		int index = min(b, n);
		int minx = b[index];
		cout << minx << endl;
		while (minx > 1) {
			int i = 0;
			cout << minx << endl;
			for (i = 0;i < 10;i++) {
				if (b[i] % minx != 0) {
					minx--;
					break;
				}
			}
			if (i == 10)break;
		}
		return minx;
	}
}
void test15() {
	using namespace questionT;
	int a[10] = { 92,84,56,68,64 ,36,48,80,92,40 };
	for (int i = 0;i < 10;i++)cout << a[i] << ' ';
	cout << "\n��ʮ���������Լ��Ϊ�� ";
	cout<< gys(a, 10) << endl;
}
namespace questionW {
	int maxmin(int a, int b, int c) {//b�Ƿ�Ϊ��ֵ
		if (b >= a && b >= c) return 1;
		else if (b <= a && b <= c) return -1;
		else return 0;
	}
	void verse(int p[][5]) {//ת��
		int i, j, t;
		for (i = 0;i < 5;i++)
			for (j = i;j < 5;j++) {
				t = p[i][j];
				p[i][j] = p[j][i];
				p[j][i] = t;
			}
	}
	void process(int p[][5], int t[], int& c) {
		//���Զ�ά����Ĵ������������һά������ 
		for (int i = 1;i < 4;i++)//1..3
			for (int j = 1;j < 4;j++) {//1..3
				int k = maxmin(p[i][j - 1], p[i][j], p[i][j + 1]);
				if (k == 0) continue;
				int l = maxmin(p[i - 1][j], p[i][j], p[i + 1][j]);
				if (l == 0) continue;
				if (k * l == 1) { t[c] = p[i][j]; c++; }
			}
	}
	int test1() {
		int a[5][5] ={ 
			{11,18,16,12,7},
			{24,4,10,20,25},
			{2,15,13,14,1},
			{21,22,9,17,19},
			{3,8,23,5,6} 
		};
		int m[9];//�����м�Ÿ����Ƿ��Ǽ���
		int cm = 0; //���� m ��ʵ��Ԫ�ظ���
		int i, j;
		verse(a);//����m���û��Ӱ��
		for (i = 0;i < 5;i++) {
			for (j = 0;j < 5;j++)
				cout << a[i][j] << '\t';
			cout << endl;
		}
		cout << endl;
		process(a, m, cm);
		for (i = 0;i < cm;i++)
			cout << m[i] << '\t';//4 22 9
		cout << endl;
		return 0;
	}
}
//��=���븴�ƹ��캯���Ƿ���ȫһ����
class Person {
	int id;
	string name;
	int  passport;
public:
	Person(int a, string b, int p) :id(a), name(b), passport(p) {};
	Person(const Person& x) :id(x.id), name(x.name), passport(x.passport) {};
	Person& operator=(const Person& x) {
		cout << "the operator= called! " << endl;
		id = x.id + 1;
		name = x.name + "s";
		passport = x.passport + 23;
	}
	friend ostream& operator<<(ostream &out, const Person& x);
};
ostream& operator<<(ostream &out, const ::Person& x) {
	out << "the id: " << x.id << "\t the name: "
		<< x.name << "\t the passport: "
		<< x.passport << endl;
	return out;
}
void test16() {
	::Person a(23,"abn",2984);
	::Person b = a;//���ø��ƹ��캯�� ������operator=
	cout << "a: " << a << "\t b: " << b << endl;
}
//���<list>�еĺ�����û��ʲôreset����//����û��
void test17() {
	//list<int> s;
	istream_iterator<int>i2(cin);//��i2��λ�ÿ�ʼ����
	//iendֻ��Ҫ��һ���յ�istream_iterator<int>�Ϳ�����
	//istream_iterator<int> iend;
	//if(i1)
	vector<int>se(i2, istream_iterator<int>());//iend��һ����ʱ������it
	sort(se.begin(), se.end());
	deque<int> s;//(i2, iend);
	for (vector<int>::iterator it = se.begin();
		it != se.end();it++) {
		if (*it % 2 == 0) s.push_back(*it);
		else s.push_front(*it);
	}
	//i1(cin);
	//advance(i1,3);
	//s.assign(i1,i2);
	//s.reset();
	//ostream ous;
	ostream_iterator<int> ost(cout," ");
	copy(s.begin(), s.end(),ost);//�������������Ҳ�����ĳ�·�ۡ�
	//*ost;
	//ost << 5 << endl;
	cout << endl;
}
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
		count++;
	}
	void show() {
		Node* p=head;
		while (p != NULL) {
			cout << p->val << " ";
			p=p->link;
		}
		cout << endl;
	}
	friend bool PrimeY(int, PrimeList&);
	friend bool Trunc(int, PrimeList&);
	bool Exist(int a) {
		Node* p = head;
		while (p != NULL) {
			if (p->val == a)return 1;
			if (p->val > a) return 0;
			else p=p->link;
		}
		return 0;
	}
};
bool PrimeY(int a,PrimeList &x) {
	Node* p = x.head;
	while (1) {
		if (p->val*p->val > a) {
			x.add(new Node(a));
			return true;
		}
		if (a % p->val == 0) {
			return false;
		}
		else p=p->link;
	}
}
bool Trunc(int a, PrimeList& x) {
	vector<int> s;
	int temp = a/10;
	while (temp > 0) {
		s.push_back(temp);
		temp /= 10;
	}
	int wei = 10;
	while (a > wei) {
		s.push_back(a % wei);
		wei *= 10;
	}
	for (auto i : s) {
		if (!x.Exist(i)) return false;
	}
	return true;
}
void test18() {
	int i = 2;
	vector<int> s;
	Node x(i++);//i=3
	PrimeList m(x);
	//m.show();
	while (s.size()<11) {
		//�ȵ���PrimeY�������Trunc�����Trunc(i,m)�е�iһ��������
		if (PrimeY(i, m)&&Trunc(i,m)) {
			if (i > 10) {
				s.push_back(i);
				//copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
				//cout << endl;
				//cout << s.size() << endl;
			}//2 3 5 7 ����
		}
		i += 2;
	}
	//m.show();
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	int ans = accumulate(s.begin(), s.end(),0);
	//m.show();
	cout << ans << endl;//748317
}

int Conta(int s) {
	int res = 0;
	int t = s * s / 2;
	//cout << t << endl;
	for (int i = 2;i < s/2;i++) {
		//cout << " i : " << i;
		for (int j = 1;j < i;j++) {
			//cout << " " << j;
			if (i + j < s - i - j) continue;
			//int you = ;
			//cout << you << endl;
			if (t == s * i + s * j - i * j) {
				//cout << "at least one?" << endl;
				res++;
			}
		}
		//cout << endl;
	}
	return res;
}
void test19() {
	int n = 4;
	int maxx = INT_MIN;
	int ans = 12;
	//cout << Conta(12) << endl;
	while (n <= 1000) {
		int t = Conta(n);
		cout << "n :" << n << endl;
		//cout << "Conta(n): " << t << endl;
		if (t > maxx) {
			ans = n;
			maxx = t;
		}
		n += 4;
	}
	cout << ans << endl;
}
void test20() {
	set<int> s;
	for (int i = 1;i <30000;i++) {
		int t = i * (3 * i - 1) / 2;
		s.insert(t);
	}
	//copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	//cout << endl;
	for (int i = 1;i <10000;i++) {
		for (int j = i+1;j <20000;j++) {
			int ai = i * (i * 3 - 1) / 2;
			int aj = j * (j * 3 - 1) / 2;
			int sum = ai+aj;
			int dis = aj-ai;
			//if(s.find(sum)!=s.end())cout << "sum: " << sum << "\tdis: " << dis << endl;
			if (s.find(sum) != s.end() &&
				s.find(dis) != s.end()) {
				cout << "dis: "<<dis << endl;//5482660
			}
		}
	}
}

set<int> prinfac(int a,PrimeList &x) {
	set<int> s;
	Node* p = x.getHead();
	while (p != NULL) {
		if (a % p->val == 0) {
			s.insert(p->val);
		}
		p = p->link;
	}
	return s;
}
void test21() {
	Node x(2);
	PrimeList m(x);
	for (int i = 3;i < 2000;i += 2) {
		PrimeY(i, m);
	}
	queue<int> num;
	set<int> s;
	int truncatable = 0;
	for (int i = 180;i < 1000000;i++) {
		s.clear();
		s = prinfac(i,m);
		num.push(s.size());
		if (num.size() > 4) num.pop();
		if (num.back() == 4) {
			truncatable++;
		}
		else truncatable = 0;
		if (truncatable == 4) {
			cout << i - 3;
			break;
		}
	}
}
unsigned long long selfPow(int a) {
	unsigned long long res=1;
	for (int i = 1;i <= a;i++) {
		res *= a;
		if (res > 10000000000) res %= 10000000000;
	}
	return res;
}
unsigned long long test22() {
	unsigned long long ans = 0;
	cout << selfPow(10) << endl;
	for (int i = 1;i < 1000;i++) {
		ans = (ans + selfPow(i)) % 10000000000;
	}
	return ans;
}
set<int> PrimeSet() {
	set<int>s;
	s.insert(2);
	set<int>::iterator it = s.begin();
	int i = 3;
	while (i<10000) {
		//cout << "*it: " << *it << " i: "<<i<<endl;
		if ((*it) * (*it) > i) {
			s.insert(i);
			i += 2;
			it = s.begin();
			continue;
		}
		if (i % (*it) == 0) {
			i += 2;
			it = s.begin();
			continue;
		}
		else it++;
	}
	//copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	//cout << endl;
	//cout << s.size() << endl;
	return s;
}
multiset<int> putdig(int a) {
	multiset<int> s;
	while (a > 0) {
		s.insert(a % 10);
		a /= 10;
	}
	return s;
}
void test23() {
	Node x(2);
	PrimeList m(x);
	set<int> s = PrimeSet();
	//set<int>::iterator i1 = s.begin(), i2 = s.begin();
	//advance(i1, 168);//��һ����λ����������
	//advance(i2, 169);
	//copy(i1, s.end(), ostream_iterator<int>(cout, " "));
	//cout << endl;
	//cout << *i1 << " " << *i2 << endl;
	//multiset<int>s1, s2, s3;
	//while (1) {
	//	int x3 = *i2 + (*i2 - *i1);//�Ȳ�����
	//	if (s.find(x3) != s.end() &&
	//		 firstTwo(*i1, *i2, s1, s2)) {
	//		//cout << "i1: " << *i1 << " i2: " << *i2 << endl;
	//		while (x3 > 0) {
	//			s3.insert(x3 % 10);
	//			x3 /= 10;
	//		}
	//		if (s3 == s2) {
	//			cout << *i1 << " " << *i2 << " " << x3 << endl;
	//			break;
	//		}
	//	}
	//}

	set<int>::iterator a1 = s.begin(), a2 = s.begin();
	advance(a1, 168);//��һ����λ����������
	advance(a2, 169);
	while (a1 != s.end() && a2 != s.end()) {
		for (;a2 != s.end();a2++) {
			//cout << "*a1: " << *a1 << "\t*a2: " << *a2 << endl;
			int x3 = *a2 + (*a2 - *a1);//�Ȳ�����
			if (s.find(x3) != s.end()) {
				multiset<int>s1 = putdig(*a1);
				multiset<int>s2 = putdig(*a2);
				multiset<int>s3 = putdig(x3);
				//if (s1 == s2) cout << "at least! " << endl;
				if (s1 == s2 && s2 == s3) {
					cout << *a1 << ' ' << *a2 << ' ' << x3 << endl;
					//1487 4817 8147
					//2969 6299 9629
					//296962999629
					//exit(0);
				}
			}
		}
		a1++;
		a2 = a1;a2++;
	}

	//multiset<int>s1 = putdig(1487);
	//multiset<int>s2 = putdig(4817);
	//multiset<int>s3 = putdig(8147);
	//copy(s1.begin(), s1.end(), ostream_iterator<int>(cout, " "));cout << endl;
	//copy(s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));cout << endl;
	//copy(s3.begin(), s3.end(), ostream_iterator<int>(cout, " "));cout << endl;
	//cout << (s1 == s2) << endl;
	//			multiset<int>s1 = putdig(*a1);
	//			multiset<int>s2 = putdig(*a2);
	//			multiset<int>s3 = putdig(x3);;
	//cout << endl;
}
void test24() {
	unsigned long long s = 1;
	int round = 2;
	int last = 1;
	while (round <= 501) {
		int k = round * 2 - 2;
		s += 4 * last + 10 * k;
		last += 4 * k;
		round++;
	}
	cout << s << endl;
}
int main() {
	test21();
	//cout << INT_MAX << endl;
	//test24();
	//cout << LONG_MAX << endl;
	//cout << "aregwv" << endl;
	return 0;
}
