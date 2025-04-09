#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void test01()
	{
		cout << "hello" << endl;
	}
};

int main()
{
	vector<int> v;
	v.push_back(34);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	Solution s;
	s.test01();
	return 0;
}
