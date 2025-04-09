#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void test03(){
	string num1,num2;
	cin>>num1>>num2;
	if(num1=="0" || num2=="0"){
		cout<<"0"<<endl;
		return;
	}
	int l1=num1.size(),l2=num2.size();
	vector<int> carry(l1+l2,0);
	vector<int> ans(l1+l2,0);
	for (int i=l2-1;i>=0;i--){ // num2
		for (int j=l1-1;j>=0;j--){ //num1
			ans[i+j+1]+=(num2[i]-'0')*(num1[j]-'0');
		}
	}
	for (int i=l1+l2-1;i>=0;i--){
		if(i>0){
			ans[i-1]+=ans[i]/10;
			ans[i]%=10;
		}
	}
	int start=0;
	while(ans[start]==0) start++;
	string mul="";
	for (int i=start;i<l1+l2;i++){
		char ch='0'+ans[i];
		mul+=ch;
	}
	cout<<mul<<endl;
}
void test02(){
	vector<int> ed;
	int a,b,c;
	cin>>a>>b>>c;
	if (a==0 || b==0 || c==0){
		cout<<"false"<<endl;
		return;
	}
	ed.push_back(a);
	ed.push_back(b);
	ed.push_back(c);
	sort(ed.begin(),ed.end());
	if(ed[0]+ed[1]>ed[2])cout<<"true"<<endl;
	else cout<<"false"<<endl;
}
void test01(){
    int a;
    cin >> a;
    vector<int> dig(64, 0);
    int index = 63;
    vector<int> used(10, 0);
    while(a){
        if (used[a%10]==0){
            used[a % 10] = 1;
            dig[index--] = a % 10;
        }
        a /= 10;
    }
    int ans = 0;
    for (int i = 63; i > index;i--){
        ans = ans * 10 + dig[i];
    }
    cout << ans << endl;
}
int main(){
    test03();
    return 0;
}
