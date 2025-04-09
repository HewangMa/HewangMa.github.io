#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void test01(){
	vector<int> ans;
	for (int i=0;i<8;i++){
		ans.push_back(i);
	}
	cout<<accumulate(ans.begin(),ans.end(),0)<<endl;
}
int main(){
	test01();
	return 0;
} 
