#include<iostream>
//#include<cstdio.h>
//#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
//template<class T, int size>
//class arrays {
//	T a[size];
//	int last;
//	int maxSize;
//public:
//	arrays() { last = -1; maxSize = size; }
//	bool isfull() { if (last == maxSize - 1) return true; else return false; }
//	bool isempty() { if (last == -1) return true; else return false; }
//	void insertRear(T data) {     //��data�����������һ����Ԫ��λ��
//		if (!isfull()) { last++;  a[last] = data; }
//		else cout << "array is full,can not insert!" << endl;
//	}
//	T deleteRear() {      //���������һ��Ԫ�ش�������ɾ����ֵ����
//		if (!isempty()) { return   a[last--]; }
//		else cout << "array is empty,can not delete!" << endl;
//	}
//	friend ostream& operator<<(ostream& os, arrays& ar)	{ //���������������������ar��ȫ��Ԫ��
//		int i;
//		for (i = 0; i <= last; i++)  os << ar[i] << '\t';
//		os << endl;
//		return os;
//	}
//};
//template<class T, int size>
//class stack : public arrays<T, size> {
//public:
//	void push(T data) {
//		insertRear(data);  //һ��Ԫ�ؽ�ջ
//	}
//	T pop() {
//		return deleteRear();  //���س�ջԪ�ص�ֵ
//	}
//	friend ostream& operator<< (ostream& os, stack& st) {
//		this->arrays::operator <<(os, st);
//	}
//};
//void test15() {
//	stack<char, 12>stg;
//	stg.push('1');
//	stg.push('6');
//	stg.push('4');
//	cout << stg << endl;
//}
class base {
private:
	int pri;
public:
	int pub;
	base(int p1 = 0, int p2 = 2, int p3 = 3) :pri(p1), pub(p2), prot(p3) {}
	virtual int fc(int m = 90) { cout << "that of base!\n";return 0; }
protected:
	int prot;
};
class deprived :public base{
public:
	//��ʹ�������Ʋ�ͬ��Ĭ��ֵҲ��ͬ Ҳͬ��ʵ�ֶ�̬
	int fc(int s = 78) { cout << "that of deprived!\n";  return 0; }
};
void test06() {
	base b,*p;
	deprived d;
	p = &d;
	p->fc();
}
/*
class person {
	char name[10];
	int age;
public:
	void init1(const char* str, int k) {
		strcpy_s(name, str);
		age = k;
	}
	virtual void disp(){
		cout << "name: " << name << endl;
		cout << "age: " << age << endl;
	}
};
class student : public person{
	int num;
	double avg;
public:
	void init2(int i, double f) {
		num = i;
		avg = f;
	}
	void disp()	{
		cout << "num: " << num << endl;
		cout << "avg: " << avg << endl;
	}
};
*/
class Person {
protected:
	string name;
public:
	Person(string Name = "#") { name = Name; }
	virtual void show() {
		cout << "�ҵ������ǣ�" << name << endl;
	}
};
class student :public Person {
	string No;
public:
	student(string Name = "#", string num = "0") :Person(Name) { No = num; }
	void show() {
		cout << "�ҵ�ѧ���ǣ�" << No << '\t' << "�ҵ������ǣ�" << name << endl;
	}
};
class teacher :public Person {
	string special;
public:
	teacher(string Name = "#", string sp = "��") :Person(Name) { special = sp; }
	void show() {
		cout << "�ҵ�רҵ�ǣ�" << special << '\t' << "�ҵ������ǣ�" << name << endl;
	}
};
int test03() {
	Person* pp, ps;
	pp = &ps;pp->show();//�ҵ������ǣ� #
	student st("���", "06007126");
	pp = &st;pp->show();//�ҵ�ѧ���ǣ� 06007126	�ҵ�������asdkljg
	teacher tc("���", "�����");
	pp = &tc;pp->show();//�ҵ�רҵ�ǣ� 534 �ҵ�������5aw�ر���
	return 0;
}
/*
int test01(){
	person A, * p;
	student B;
	A.init1("����", 19);
	p = &A;
	p->disp();//name: ����  age: 19
	B.init2(20090332, 97.5);
	p = &B;
	p->disp();//num: 20090332 avg: 97.5
	return 0;
}
*/
class CShape{
public:
	 void Display() { cout << "Shape\n"; }
};
class CEllipse : public CShape{
public:
	 void Display() { cout << "Ellipse\n"; }
};
class CCircle : public CEllipse{
public:
	 void Display() { cout << "Circle\n"; }
};
class point {
private:
	float x, y;
public:
	void setcon(float i, float j) { x = i; y = j; }
	float area() { return 0.0; }
};
const double PI = 3.14159;
class circle : public point {
private:
	float radius;
public:
	void setsize(float r) { radius = r; }
	float area() { return PI * radius * radius; }
};
void test04() {
	point p;
	float a = p.area();
	cout << "The area of the point p is " << a << endl;//The area of the point p is 0
	point* pp;
	circle c;
	c.setsize(1.0);
	a = c.area();
	cout << "The area of the circle c is " << a << endl;//The area of the circle c is 3.14159
	pp = &c;
	cout << pp->area();//0
}
class Tree {
public:
	virtual void fa() { cout << "Tree:higher" << endl; }
	virtual void fb() { cout << "Tree:lower" << endl; }
	virtual int fc(int m) { return 3 * m; }
};
class Grass :public Tree {
public:
	void fa() { cout << "Grass:wide" << endl; }
	void fc() { cout << "Grass:thin" << endl; }
};
class Leaf :public Grass {
public:
	void fa() { cout << "Leaf:green" << endl; }
	void fb(int i = 0) { cout << "Leaf_age:" << i << endl; }
	int fc(int n = 1) { cout << "Leaf_num=" << n <<"doing!" << endl;return 0; }
};
void test05(){
	Grass a;
	Leaf b;
	Tree c, * p = &b;
	a.fc();//Grass:thin
	p->fa();//Grass:wide//x Leaf:green
	p->fb();//Leaf_age: 0//Tree:lower//fb�����б�ͬ û�м̳�
	b.fb(c.fc(6));//b.fb(18) Leaf_age:18 
	b.fc(p->fc(6));//b.fc(18) Leaf_num=18 //Leaf_num=6//b.fc(0) Leaf_num=0
}
void test02(){
	CShape Shape;
	CEllipse Ellipse;
	CCircle Circle;
	CShape* pShapeArray[3] = { &Shape, &Ellipse, &Circle };
	for (int i = 0;i < 3;i++)
		pShapeArray[i]->Display();//Shape Ellipse Circle
	//Shape Shape Shape
}
class Pet {
protected:
	string name;
	int age;
public:
	Pet(string n = "maomao", int a = 0) {
		name = n;
		age = a;
	}
	virtual void showInfo()	{
		cout << "Pet name:" << name << " age:" << age;
	}
};
class Dog :public Pet {
	string type;
public:
	Dog(string n = "maomao", string t= "unknown", int a = 0) :Pet(n, a)	{
		type = t;
	}
	void showInfo()	{
		cout << " Dog name:" << name << " age:" << age << " Dog type:" << type;
	}
};
void test07() {
	Dog d2("Solder", "Wolf", 1);//Dog name: Solder age: 1 Dog Type: Wolf
	d2.showInfo();
	cout << endl;
	Pet* pa, a;
	Dog d1("WaWa", "JiWaWa", 2);
	pa = &a;
	pa->showInfo();//Pet name: maomao age: 0 Dog Type: unknown
	cout << endl;
	pa = &d1;//����d1������
	pa->showInfo();//Dog name: Solder age: 1 Dog Type: Wolf
	cout << endl;
}
class X {
public:
	virtual void f() { cout << "a"; }
};
class Y :public X {
public:
	void f() { cout << "b"; }
};
void test08(){
	Y y;
	X* xp = &y;
	xp->f();//b
}
class Solution {
public:
	bool huiwen(string s, int i, int j) {
		int k = i;
		while (k <= i + (j - i) / 2) {
			//cout << s[k] << " " << s[j - k + i] << endl;
			if (s[k] != s[j - (k - i)]) return false;
			k++;
		}
		return true;
	}
	string longestPalindrome2(string s) {
		int i = 0, j = 0;
		int maxlen = 1, index = 0;
		int n = s.length();
		if (n == 1) return s;
		for (i = 0;i <= n - 2;i++) {
			for (j = i + 1;j <= n - 1;j++) {
				if (huiwen(s, i, j) && (j - i + 1 > maxlen)) {
					maxlen = j - i + 1;
					index = i;
				}
			}
		}
		//cout << index << " " << maxlen << endl;
		return s.substr(index, maxlen);
	}
	string longestPalindrome(string s) {
		int  n = s.size();
		cout << n << endl;
		vector<vector<bool>> dp(n,vector<bool>(n));
		for (int i = 0;i < n;i++) {
			dp[i][i] = true;//dp[i][j]��ʾs[i..j]�ǲ��ǻ��Ĵ�
		}
		int maxlen = 1, index = 0;
		for (int l = 2;l <= n;l++) {//�ִ�����
			for (int i = 0;i < n;i++) {//��ʼλ��
				int j = i + l - 1;
				if (j >= n) break;
				
				if (l <= 2) {
					dp[i][j] = (s[i] == s[j]);
				}
				else {
					if (s[i] == s[j])dp[i][j] = dp[i + 1][j - 1];
					else dp[i][j] = false;
				}
				if (dp[i][j]) {
					if (l > maxlen) {
						maxlen = l;
						index = i;
					}
				}
			}
		}
		return s.substr(index, maxlen);
	}
	string longestPalindrome3(string s) {
		int n = s.size();
		if (n < 2) {
			return s;
		}
		int maxLen = 1;
		int begin = 0;
		// dp[i][j] ��ʾ s[i..j] �Ƿ��ǻ��Ĵ�
		vector<vector<int>> dp(n, vector<int>(n));
		// ��ʼ�������г���Ϊ 1 ���Ӵ����ǻ��Ĵ�
		for (int i = 0; i < n; i++) {
			dp[i][i] = true;
		}
		// ���ƿ�ʼ
		// ��ö���Ӵ�����
		for (int L = 2; L <= n; L++) {
			// ö����߽磬��߽���������ÿ��Կ���һЩ
			for (int i = 0; i < n; i++) {
				// �� L �� i ����ȷ���ұ߽磬�� j - i + 1 = L ��
				int j = L + i - 1;
				// ����ұ߽�Խ�磬�Ϳ����˳���ǰѭ��
				if (j >= n) {
					break;
				}

				if (s[i] != s[j]) {
					dp[i][j] = false;
				}
				else {
					if (j - i < 3) {
						dp[i][j] = true;
					}
					else {
						dp[i][j] = dp[i + 1][j - 1];
					}
				}

				// ֻҪ dp[i][L] == true �������ͱ�ʾ�Ӵ� s[i..L] �ǻ��ģ���ʱ��¼���ĳ��Ⱥ���ʼλ��
				if (dp[i][j] && j - i + 1 > maxLen) {
					maxLen = j - i + 1;
					begin = i;
				}
			}
		}
		return s.substr(begin, maxLen);
	}
	bool nonover(string s) {
		set<char> st;
		int i = 0;
		while (i <= s.size()) {
			if (st.find(s[i]) != st.end()) return false;
			else {
				st.emplace(s[i]);
				i++;
			}
		}
		return true;
	}
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		if (n < 2)return n;
		int maxlen = 1;
		for (int i = 0;i < n;i++) {
			for (int j = i + 1;j < n;j++) {
				if (nonover(s.substr(i, j-i+1))) {
					//cout << s.substr(i, j-i+1) <<" ";
					maxlen = max(maxlen, j-i+1);
					//cout << maxlen << endl;
				}
			}
		}
		return maxlen;
	}
	bool isValidSudoku(vector<vector<char>>& board) {
		set<char>st;
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				char c = board[i][j];
				if (c != '.') {
					if (st.count(c) == 0) {
						st.emplace(c);
					}
					else {
						return false;
					}
				}
			}//�ų���i��
			st.clear();
			if (i == 0 || i == 3 || i == 6) {
				for (int j = 0;j <= 6;j += 3) {
					for (int m = 0;m < 3;m++) {
						for (int n = 0;n < 3;n++) {
							char c = board[m + i][m + j];
							if (c != '.') {
								if (st.count(c) == 0) {
									st.emplace(c);
								}
								else {
									return false;
								}
							}
						}
					}
					st.clear();
				}
			}//�ų���i��j������
		}
		for (int j = 0;j < 9;j++) {
			for (int i = 0;i < 9;i++) {
				if (board[i][j] != '.') {
					char c = board[i][j];
					if (c != '.') {
						if (st.count(c) == 0) {
							st.emplace(c);
						}
						else {
							return false;
						}
					}
				}
			}
			st.clear();
		}
		return true;
	}
};
void test09() {
	string s = "mpugbrowdqcoevhecfenvkixevnrwyzipuqtngrqwtfcpogrtmhqwrpdmcwkawurslkftdvqzauqqbjjpqbmj";
	Solution so;
	//if (so.huiwen("1231",0,3))cout << "doing\n";
	//cout << so.longestPalindrome(s) << endl;
	//cout << so.nonover(s) << endl;
	cout << so.lengthOfLongestSubstring(s) << endl;

}
int main() {
	//test01();
	test09();
	return 0;
}