#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <list>
#include <time.h>
using namespace std;
namespace TEST
{
	class ball
	{
	private:
		int r;
		int h;
		static int n;

	public:
		ball(int a = 1, int b = 2);
		void show();
		void set(int a, int b)
		{
			r = a;
			h = b;
			n += a + b;
		}
	};
	ball::ball(int a, int b)
	{
		r = a;
		h = b;
		if (a > 1)
			n += a;
		else if (b > 2)
			n += b;
	}
	void ball::show()
	{
		cout << "r=" << r << " h=" << h << " n=" << n << endl;
	}
	int ball::n = 0;
	class A
	{
	protected:
		int x;

	public:
		A() { x = 10; }
		void prt() { cout << "A.x=" << x << '\t'; }
		virtual void Print() { cout << "A.x=" << x << '\n'; }
	};
	class B : public A
	{
		int y;

	public:
		B(int a = 20)
		{
			x = a;
			y = 300;
		}
		void prt() { cout << "B.x=" << x << '\t'; }
		void Print() { cout << "B.y=" << y << '\n'; }
	};
	class Pupil
	{
	private:
		int bh;		 // ���
		char xm[8];	 // ����
		float cj[3]; // ���ſγɼ�
		void score()
		{
			cout << "�ɼ���";
			for (int i = 0; i < 3; i++)
				cout << cj[i] << ',';
			cout << endl;
		}

	public:
		Pupil()
		{
			bh = 0;
			xm[0] = NULL;
			for (int i = 0; i < 3; i++)
				cj[i] = 0;
		}
		void set(int a, char *b, float x[]);
		void modify(int c, char *d);
		void show() { cout << xm << "��ţ�" << bh << endl; }
		char *get() { return xm; }
	};
	void Pupil::set(int a, char *b, float x[])
	{
		bh = a;
		show();
		for (int i = 0; i < 3; i++)
			cj[i] = x[i];
		score(); // set֮��չʾһ��
	}
	void Pupil::modify(int c, char *d)
	{
		bh = c;
	}
}
void test01()
{
	using namespace TEST;
	int ab[3][3] = {1};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << ab[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
int change(const int &a)
{
	return a * a;
}
void test02()
{
	int a[6] = {2, 4, 4, 6, 2, 2};
	vector<int> as(a, a + 6);
	vector<int> bs(6);
	cout << "bs.capacity():  " << bs.capacity() << endl;
	cout << "bs.size():  " << bs.size() << endl;
	transform(as.begin(), as.end(), as.begin(), change);
	copy(as.begin(), as.end(), bs.begin());
	copy(bs.begin(), bs.begin() + bs.size(), ostream_iterator<int>(cout, " "));
	cout << endl;
}
void test03()
{
	int myints[] = {10, 20, 30, 40, 50, 60, 70};
	vector<int> myvector(7);
	copy(myints, myints + 7, myvector.begin());
	cout << "myvector contains:";
	for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;
}
void sub(char *a, int x, int y)
{
	char t, *p, *q;
	p = a + x;
	q = a + y;
	while (p < q)
	{
		t = *p;
		*p = *q;
		*q = t;
		p++;
		q--;
	}
}
void test04()
{
	char *p, dt[18] = "GoodCity&Country";
	int i = 0, n = 0;
	p = dt;
	while (*p != '&')
	{
		cout << *p++;
		n++;
	} // GoodCity 8
	cout << "\n string next: \n";
	p = dt + 9;
	while (*p != '\0')
		cout << *p++; // Country
	cout << endl;
	sub(dt, i, n - 1); // sub(dt,0,7)
	p = dt;
	while (*p != '&')
		cout << *p++; // ytiCdooG
	cout << endl;
}
void test05()
{
	using namespace TEST;
	ball A(5);
	A.show();
	ball B(10, 20), C;
	B.show();
	C.show();
	C.set(3, 2);
	C.show();
	A.show();
}
void test06()
{
	using namespace TEST;
	A a, *p;
	B b, c(8);
	c.prt();
	c.Print();
	p = &a;
	p->prt();
	p->Print();
	p = &c;
	p->prt();
	cout << endl;
	p->Print();
}
void test07()
{
	using namespace TEST;
	float f1[3] = {76, 89, 92}, f2[3] = {86, 90, 64};
	Pupil M[3]; // ������������M
	char a1[] = "Mary", a2[] = "Jack", a3[] = "Tomson";
	M[0].set(228, a1, f1); //
	M[1].set(336, a2, f2);
	M[2] = M[0];
	M[2].modify(885, a3);
	for (int i = 0; i < 3; i++)
		cout << M[i].get() << '\t';
	cout << endl;
}
void sumTwo(stringstream &fs)
{
	string a1, a2;
	fs >> a1;
	fs >> a2;
	// s2 = fs.get();
	cout << "s1: " << a1 << endl;
	cout << "s2: " << a2 << endl;
	string ans = "";
	int temp = 0, carry = 0, i = 19;
	// cout <<"���һλ�� "<< a1[i] << ' ' << a2[i] << endl;
	while (i >= 0)
	{
		temp = a1[i] - 48 + a2[i] - 48 + carry;
		// cout << "temp: " << temp <<'\t';
		int ge = temp % 10;
		// cout << "ge: " << ge << endl;
		carry = temp / 10;
		ans += ge + 48;
		i--;
	}
	// cout << "i: " << i << endl;
	if (carry != 0)
		ans += static_cast<char>(carry + 48);
	reverse(ans.begin(), ans.end());
	fs << ans << endl;
}
void test08()
{
	/*ofstream ofs;
	ofs.open("text01.txt");
	if (!ofs.is_open())cout << "failed!\n";*/

	stringstream fs;
	// fs.open("text01.txt", ios::in | ios::out);
	// if (!fs.is_open())cout << "failed to open the file!\n";

	srand((unsigned int)time(NULL));
	string s1 = "", s2 = "", s3;
	for (int i = 0; i < 20; i++)
	{
		int a = rand() % 9 + 1;
		int b = rand() % 9 + 1;
		// cout << a << ' ';
		s1 += char(a + 48);
		s2 += b + 48;
	}
	// cout << s1 << endl;
	fs << s1 << endl
	   << s2 << endl;

	sumTwo(fs);

	fs >> s3;

	cout << "s3: " << s3 << endl;
}
void test09()
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i, *p1, *p2, k;
	p1 = a;
	p2 = &a[9];
	while (p1 < p2) // ��ָ��p1��p2δ����ʱ��������
	{
		if (*p1 % 2 == 1)
		{
			p1++;
			continue;
		} // ���p1�����������Ԫ�ز��ô���
		while (p1 < p2 && (*p2) % 2 == 0)
			p2--;
		if (p1 < p2)
		{ // p1��p2��ָ���Ԫ�ؽ���
			k = *p1;
			*p1 = *p2;
			*p2 = k; // ָ�벢û�н��� ��������ֵ
		}
	}
	for (i = 0; i < 10; i++)
		cout << a[i] << "  ";
}
void test10()
{
	// ���������ַ����Ĳ���
	char *p1; // �ö�����vs2022��Ϊconst char*
	p1 = const_cast<char *>("awg");
	cout << "p1: " << p1 << endl;

	char p2[] = "sagf";
	cout << "p2: " << p2 << endl;

	char p3[6] = "asdga";
	cout << "p3: " << p3 << endl;

	int a[23] = {1, 24, 24, 2};
	// cout << "a: " << a << endl;//������char[]һ�����
}
namespace leetCode
{
	struct TreeNode
	{
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	};
	class Node
	{
	public:
		int val;
		vector<Node *> neighbors;
		Node()
		{
			val = 0;
			neighbors = vector<Node *>();
		}
		Node(int _val)
		{
			val = _val;
			neighbors = vector<Node *>();
		}
		Node(int _val, vector<Node *> _neighbors)
		{
			val = _val;
			neighbors = _neighbors;
		}
	};
	struct ListNode
	{
		int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
	};
	vector<ListNode *> PasPQ(ListNode *head)
	{
		// ���㷨��ʹ���κθ����ռ� �������head ���� ������������P���У���ż������Q�У�
		ListNode *p = head;
		ListNode *PH = NULL, *QH = NULL;

		cout << "original: ";
		ListNode *out = head;
		while (out)
		{
			cout << out->val << " ";
			out = out->next;
		}
		cout << endl;

		while (p)
		{
			ListNode *i = p;	// ѭ��ָ��
			ListNode *mini = p; // ��С�ڵ�ָ��
			int minx = p->val;
			while (i != NULL)
			{
				if (i->val < minx)
				{
					minx = i->val;
					mini = i;
				}
				i = i->next;
			}
			int temp = p->val;
			p->val = minx;
			mini->val = temp; // ֻ����val
			p = p->next;
		} // ֱ��ѡ������
		p = head;

		cout << "after sorted: ";
		out = head;
		while (out)
		{
			cout << out->val << " ";
			out = out->next;
		}
		cout << endl;

		ListNode *pr = NULL, *qr = NULL;
		if (p->val % 2 == 1)
		{
			PH = p; // ������ͷ��

			cout << "PH: " << PH->val; // << "   QH: " << QH->val << endl;
			while (p->next->val % 2 == 1)
				p = p->next;

			cout << "PH: " << PH->val << "   QH: " << QH->val << endl;
			pr = p;		  // ������β
			QH = p->next; // ż����ͷ
			while (p->next->val % 2 == 0)
				p = p->next;
			qr = p; // ż����β
		}
		else
		{
			QH = p; // ż����ͷ
			while (p->next->val % 2 == 0)
				p = p->next;
			qr = p;		  // ż����β
			PH = p->next; // ������ͷ��
			while (p->next->val % 2 == 1)
				p = p->next;
			pr = p; // ������β
		}
		vector<ListNode *> ans;
		ans.emplace_back(PH);
		ans.emplace_back(QH);

		p = p->next;

		cout << "PH: " << PH->val << "  QH: " << QH->val << endl;
		cout << "p: " << p->val << "  pr: " << pr->val << "  qr: " << qr->val << endl;

		while (p)
		{
			cout << "p: " << p->val << endl;
			if (p->val % 2 == 1)
			{
				pr->next = p;
				pr = pr->next;
			}
			else
			{
				qr->next = p;
				qr = qr->next;
			}
			p = p->next;
		}
		pr->next = NULL;
		qr->next = NULL;
		cout << "done!" << endl;
		return ans;
	}
	class Solution
	{
	public:
		map<Node *, Node *> visited;
		Node *cloneGraph(Node *node)
		{
			// ��Ҫ���ձ����㷨
			visited[node] = new Node(node->val);
			queue<Node *> que;
			que.push(node);
			while (!que.empty())
			{
				Node *p = que.front();
				que.pop();
				for (auto it = p->neighbors.begin();
					 it != p->neighbors.end(); it++)
				{
					// ����ÿһ���ھ���˵
					Node *w = *it;
					if (visited.find(w) == visited.end())
					{
						// ���û�з��ʹ� �ͼ�����У�
						visited[w] = new Node(w->val);
						que.push(w);
					}
					visited[p]->neighbors.emplace_back(visited[w]);
				}
			}
			return visited[node];
		}
		int sumOfLeftLeaves(TreeNode *root)
		{
			if (!root)
				return 0;
			queue<pair<TreeNode *, bool>> que;
			que.push(make_pair(root, 0));
			TreeNode *p = root;
			int ans = 0;
			while (!que.empty())
			{
				p = que.front().first;
				que.pop();
				if (p->left)
					que.push(make_pair(p->left, 1));
				if (p->right)
					que.push(make_pair(p->right, 0));
				if (!p->left && !p->right)
					ans++;
			}
			return ans;
		}
		int islandPerimeter(vector<vector<int>> &grid)
		{
			int m = grid.size();
			int n = grid[0].size();
			cout << "m: " << m << "\tn: " << n << endl;
			int ans = 0;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (grid[i][j])
						ans += 4;
					int a = 0;
					if (i != 0 && grid[i - 1][j])
						a++;
					if (j != 0 && grid[i][j - 1])
						a++;
					if (i != m - 1 && grid[i + 1][j])
						a++;
					if (j != n - 1 && grid[i][j + 1])
						a++;
					ans -= a;
				}
			}
			return ans;
		}
		inline bool valid(int i, int j, int m, int n)
		{
			return (i >= 0 && j >= 0 && i <= m - 1 && j <= n - 1);
		}
		inline int status(vector<vector<int>> &board, int i, int j, int m, int n)
		{
			int num = 0;

			for (int k = -1; k <= 1; k++)
				if (valid(i - 1, j + k, m, n) && board[i - 1][j + k])
					num++;
			if (valid(i, j - 1, m, n) && board[i][j - 1])
				num++;
			if (valid(i, j + 1, m, n) && board[i][j + 1])
				num++;
			for (int k = -1; k <= 1; k++)
				if (valid(i + 1, j + k, m, n) && board[i + 1][j + k])
					num++;

			if (board[i][j] && (num < 2 || num > 3))
				return 1;
			if (board[i][j] && (num == 2 || num == 3))
				return 2;
			if (!board[i][j] && num == 3)
				return 4;
		}
		void gameOfLife(vector<vector<int>> &board)
		{
			int m = board.size(), n = board[0].size();
			vector<vector<int>> change = board;
			// change�� 1��ʾ1->0;  2��ʾ1->1;    4��ʾ0->1
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					change[i][j] = status(board, i, j, m, n);
				}
			}
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (change[i][j] == 1)
						board[i][j] = 0;
					else
						board[i][j] = 1;
				}
			}
		}
		vector<int> spiralOrder(vector<vector<int>> &matrix)
		{
			int m = matrix.size();
			int n = matrix[0].size();
			if (m == 1)
			{
				return matrix[0];
			}
			if (n == 1)
			{
				vector<int> ans;
				for (int i = 0; i < m; i++)
				{
					ans.emplace_back(matrix[i][0]);
				}
				return ans;
			}
			int up = 1, right = n - 1, low = m - 1, left = 0;
			int k = 1;
			int dir = 1;
			int i = 0, j = 0;
			vector<int> ans;
			while (k <= m * n)
			{
				ans.emplace_back(matrix[i][j]);
				if (dir == 1)
				{
					j++;
					k++;
					if (j == right)
					{
						dir = 2;
						right--;
					}
					continue;
				}
				if (dir == 2)
				{
					i++;
					k++;
					if (i == low)
					{
						dir = 3;
						low--;
					}
					continue;
				}
				if (dir == 3)
				{
					j--;
					k++;
					if (j == left)
					{
						dir = 4;
						left++;
					}
					continue;
				}
				if (dir == 4)
				{
					i--;
					k++;
					if (i == up)
					{
						dir = 1;
						up++;
					}
					continue;
				}
			}
			return ans;
		}
		vector<vector<int>> generateMatrix(int n)
		{
			if (n == 1)
				return {{1}};
			vector<vector<int>> ans(n, vector<int>(n));
			int up = 1, right = n - 1, low = n - 1, left = 0;
			int k = 1;
			int dir = 1;
			int i = 0, j = 0;
			while (k <= n * n)
			{
				ans[i][j] = k;
				if (dir == 1)
				{
					j++;
					k++;
					if (j == right)
					{
						dir = 2;
						right--;
					}
					continue;
				}
				if (dir == 2)
				{
					i++;
					k++;
					if (i == low)
					{
						dir = 3;
						low--;
					}
					continue;
				}
				if (dir == 3)
				{
					j--;
					k++;
					if (j == left)
					{
						dir = 4;
						left++;
					}
					continue;
				}
				if (dir == 4)
				{
					i--;
					k++;
					if (i == up)
					{
						dir = 1;
						up++;
					}
					continue;
				}
			}
			return ans;
		}
		void printList(ListNode *p)
		{
			while (p)
			{
				cout << p->val << " ";
				p = p->next;
			}
			cout << endl;
		}
		ListNode *removeNthFromEnd(ListNode *head, int n)
		{
			ListNode *non = new ListNode(0, head);
			ListNode *p = head;
			stack<ListNode *> st;
			st.push(non);
			while (p)
			{
				st.push(p);
				p = p->next;
			}
			st.push(NULL);

			if (st.size() == 3 && n == 1)
				return NULL;
			while (n)
			{
				st.pop();
				n--;
			}

			p = st.top();
			st.pop();
			ListNode *pre = st.top();

			pre->next = p->next;
			delete p;
			return non->next;
		}
		int minPathSum(vector<vector<int>> &grid)
		{
			int m = grid.size();
			int n = grid[0].size();
			vector<vector<int>> dp(m, vector<int>(n));
			dp[0][0] = grid[0][0];
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; ++j)
				{
					if (i == 0 && j == 0)
						continue;
					if (i == 0)
					{
						dp[i][j] = grid[i][j] + dp[i][j - 1];
						continue;
					}
					if (j == 0)
					{
						dp[i][j] = grid[i][j] + dp[i - 1][j];
						continue;
					}
					dp[i][j] = min(grid[i][j] + dp[i - 1][j], grid[i][j] + dp[i][j - 1]);
				}
			}
			return dp[m - 1][n - 1];
		}
		void showStack(stack<char> st)
		{
			while (!st.empty())
			{
				cout << st.top() << " ";
				st.pop();
			}
			cout << endl;
		}
		bool isValid(string s)
		{
			int i = 0, l = s.size();
			stack<char> st;
			st.push('$');
			while (i < l)
			{
				if (s[i] == '{' || s[i] == '[' || s[i] == '(')
					st.push(s[i]);
				if (s[i] == '}' && st.top() == '{')
					st.pop();
				if (s[i] == ']' && st.top() == '[')
					st.pop();
				if (s[i] == ')' && st.top() == '(')
					st.pop();
				i++;
				showStack(st);
			}
			cout << st.top() << endl;
			if (st.top() != '$')
				return false;
			else
				return true;
		}
	};
}
void test11()
{
	using namespace leetCode;
	Solution so;
	vector<vector<int>> tes = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16} //[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
	};
	// vector<int> ans = so.spiralOrder(tes);
	// copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));

	vector<vector<int>> kl = so.generateMatrix(4);
	for (auto s : kl)
	{
		copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	cout << endl;
}
void test12()
{
	using namespace leetCode;

	Solution so;
	ListNode *p = new ListNode(1);
	// ListNode* p(5);
	ListNode *p2 = new ListNode(2, p);

	// so.printList(p2);

	ListNode *p5 = so.removeNthFromEnd(p2, 2);

	so.printList(p5);
}
void cumulating()
{
	string path = "D:/project_cs/Practice/Practice_Daily/codes_path";
}
void test13()
{
	using namespace leetCode;
	Solution so;
	vector<vector<int>> tes = {
		{1, 3, 1},
		{1, 5, 1},
		{4, 2, 1}};
	//[[1,3,1],[1,5,1],[4,2,1]]
	int ans = so.minPathSum(tes);
	cout << ans << endl;
}
namespace BinarySearch
{
	int MidIndex(vector<int> arr, int key)
	{
		int left = 0, right = arr.size() - 1;
		int mid = left + (right - left) / 2;
		while (left <= right)
		{
			if (arr[mid] == key)
				break;
			if (arr[mid] > key)
				right = mid - 1;
			if (arr[mid] < key)
				left = mid + 1;
			mid = left + (right - left) / 2;
		}
		if (arr[mid] != key)
			mid = -1;
		return mid;
	}
}
void test14()
{
	using namespace BinarySearch;
	int a[3] = {1, 3, 5};
	vector<int> arr(a, a + 3);
	cout << "mid: " << MidIndex(arr, 3) << endl;
}
void test15()
{
	using namespace leetCode;
	Solution solu;
	string s = "(]";
	cout << solu.isValid(s) << endl;
}
namespace se
{
	class person
	{
		string name;
		int age;

	public:
		void init1(string str, int k)
		{
			name = str;
			age = k;
		}
		virtual void disp()
		{
			cout << "name: " << name << endl;
			cout << "age: " << age << endl;
		}
	};
	class student : public person
	{
		int num;
		double avg;

	public:
		void init2(int i, double f)
		{
			num = i;
			avg = f;
		}
		void disp()
		{
			cout << "num: " << num << endl;
			cout << "avg: " << avg << endl;
		}
	};
}
void test16()
{
	using namespace se;
	person A, *p;
	student B = student(); // ��һ��ᱨ��
	A.init1("asg", 19);
	p = &A;
	p->disp();
	B.init2(20090332, 97.5);
	p = &B;
	p->disp();
}
void test17()
{
	using namespace leetCode;
	int a[13] = {11, 15, 8, 2, 5, 4, 9, 5, 2, 16, 1, 7, 0};
	ListNode *p = NULL;
	for (int i = 12; i >= 0; i--)
	{
		p = new ListNode(a[i], p);
	}
	vector<ListNode *> ans = PasPQ(p);
	ListNode *PH = ans[0];
	ListNode *QH = ans[1];

	cout << "PH: ";
	ListNode *out = PH;
	while (out)
	{
		cout << out->val << " ";
		out = out->next;
	}

	cout << endl
		 << "QH: ";
	out = QH;
	while (out)
	{
		cout << out->val << " ";
		out = out->next;
	}
}
void test18()
{
	int a[13] = {11, 15, 8, 2, 5, 4, 9, 5, 2, 16, 1, 7, 0};
	list<int> L(a, a + 13);
	L.sort();

	cout << "after sorted: ";
	copy(L.begin(), L.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	list<int>::iterator it = L.begin();
	list<int> PH, QH;
	while (it != L.end())
	{
		if (*it % 2 == 1)
			PH.emplace_back(*it);
		else
			QH.emplace_back(*it);
		it++;
	}

	cout << "PH: ";
	copy(PH.begin(), PH.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "QH: ";
	copy(QH.begin(), QH.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}
int main()
{
	test18();
	cout << "\n\n\nsafly running!\n";
	return 0;
}