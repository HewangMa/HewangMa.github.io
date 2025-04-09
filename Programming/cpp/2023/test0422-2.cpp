#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void test03(){
	int w,n;
	cin>>w>>n;
	vector<int> pen;
//	vector<vector<int>> ranges(n,vector<int>{0,0});
	vector<int> preSum(n,0);
	vector<int> postSum(n,0);
	int sum=0;
	for (int i=0;i<n;i++){
		int temp;
		cin>>temp;
		pen.push_back(temp);
		preSum[i]=sum+i;//这个值就是第i个颜色最左边的位置 
		sum+=temp;
	}
//	for (int i=0;i<pen.size();i++)cout<<pen[i]<<' ';
//	cout<<endl;
	sum=0;
	for (int i=n-1;i>=0;i--){
		postSum[i]=w-sum-(n-i);
		sum+=pen[i];
	}
//	cout<<"pre: ";
//	for (int i=0;i<n;i++)cout<<preSum[i]<<' ';
//	cout<<endl<<"post: ";
//	for (int i=0;i<n;i++)cout<<postSum[i]<<' ';
//	cout<<endl;
	vector<int> fit;
	for (int i=0;i<n;i++){
		//对于每个颜色都确定是否有覆盖
		int Lr= preSum[i]+pen[i]-1;
		int Rl=postSum[i]-pen[i]+1;
//		cout<<Lr<<' '<<Rl<<endl;
		if (Rl<=Lr) for (int j=Rl;j<=Lr;j++) fit.push_back(j+1);
	}
	cout<<fit.size()<<endl;
	for (int i=0;i<fit.size();i++)cout<<fit[i]<<' ';
	cout<<endl;
}
void test02(){
	int n;
	cin>>n;
	vector<int> nums;
	for (int i=0;i<n;i++){
		int temp;
		cin>>temp;
		nums.push_back(temp);
	}
	string cols;
	cin>>cols;
	vector<int> red,blue;
	int r1=0,r2=0x80000000,r3=0x7fffffff,r4=0;//分别是红色的最小负数，最大负数，最小正数，最大正数 
	int b1=0,b2=0x80000000,b3=0x7fffffff,b4=0;
//	bool rHave=false,bHave=false;
	for (int i=0;i<n;i++){
		if(cols[i]=='R'){
			int a=nums[i];
			if(a>0){
				r3=min(r3,a);
				r4=max(r4,a);
			}
			else{
				r1=min(r1,a);
				r2=max(r2,a);
			}
		}
		else {
			int b=nums[i];
			if(b>0){
				b3=min(b3,b);
				b4=max(b4,b);
			}
			else{
				b1=min(b1,b);
				b2=max(b2,b);
			}
		}
	}
	vector<long long>anss;
	anss.push_back(1LL*r1*b1);
	anss.push_back(1LL*r4*b4);
	anss.push_back(1LL*r2*b3);
	anss.push_back(1LL*r3*b2);
	sort(anss.begin(),anss.end());
	int index=3;
	while(anss[index]==0) index--;
	cout<<anss[index]<<endl;
}
void test01(){
	int a=1;
	int index=0;
	int n;
	cin>>n;
	while(index<n-1){
		if(index%2==1){
			a=(a*2)%1000000007;
		}
		else{
			a=(a+1)%1000000007;
		}
		//cout<<a<<endl;
		index++;
	}
	cout<<a<<endl;
}
int main(){
	test03();
	return 0;
}
