#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

//https://leetcode.cn/problems/reverse-string/
void swapp(char* i,char* j) {
	char t = *i;
	*i = *j;
	*j = t;
}
void reverseString(char* s, int sSize) {
	for (int left = 0, right = sSize - 1; left < right; left++, right--) {
		//printf("%c %c\n", *(s + left), *(s + right));
		swapp(s + left, s + right);
	}
}
void test01() {
	//char* s = (char*)malloc(sizeof(char) * 11);
	char s[12];
	gets(s);
	//s = "123456789a\0";
	printf("%s\n", s);
	reverseString(s, strlen(s));
	printf("%s\n", s);
	//free(s);
}

//https://leetcode.cn/problems/reverse-string-ii/
void reverseIJ(char* s, int i, int j) {
	for (int left = i, right = j; left < right; left++, right--) {
		//printf("%c %c\n", *(s + left), *(s + right));
		swapp(s + left, s + right);
	}
}
char* reverseStr(char* s, int k) {
	int len = strlen(s);
	for (int i = 0; i < len; i+=(2*k)) {
		if (i + k < len) {
			reverseIJ(s, i, i + k-1);
		}
		else {
			reverseIJ(s,i,len-1);
		}
	}
	return s;
}
void test02() {
	char s[56];
	gets(s);
	reverseStr(s, 2);
	printf("%s\n", s);
}

//https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
char* replaceSpace(char* s) {
	char* ans = malloc(sizeof(char) * 100);
	int len = strlen(s);
	int count = 0;
	int i = 0;
	for (; i < len; i++) {
		if (s[i] == ' ') {
			ans[i + count * 2] = '%';
			ans[i + count * 2 + 1] = '2';
			ans[i + count * 2 + 2] = '0';
			count++;
		}
		else {
			ans[i + count * 2] = s[i];
		}
	}
	ans[i + count * 2] = '\0';
	return ans;
}
void test03() {
	char a[56];
	gets(a);
	char* res = replaceSpace(a);
	printf("%s\n", res);
	free(res);
}

//https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
int strStr(char * haystack, char * needle){
    for (int i=0;i<strlen(haystack);i++){
        int j=0;
		for (;j<strlen(needle);j++){
			if(haystack[i+j]==needle[j])continue;
			else break;
		}
        if(j==strlen(needle))return i;
    }
    return -1;
}
void test04(){
	char tar[30],nee[20];
	gets(tar);
	gets(nee);
	printf("%d\n",strStr(tar,nee));
}

//https://leetcode.cn/problems/evaluate-reverse-polish-notation/
void showNums(int *nums,int numsSize){
	for (int i=0;i<numsSize;i++){
		printf("%d ",nums[i]);
	}
	printf("\n");
}
int evalRPN(char ** tokens, int tokensSize){
    int nums[10010];
    char opt[10010];
    int numsSize=0,optSize=0;
    int i=0;
    //int n=tokensSize;
    for (;i<tokensSize;i++){
        //printf("%s\n",tokens[i]);
        if(tokens[i][0]=='+'||tokens[i][0]=='-'||tokens[i][0]=='*'||tokens[i][0]=='/'){
            //printf("%d !!\n",numsSize);
            int a=nums[--numsSize];
            int b=nums[--numsSize];
            int res=0;
            switch(tokens[i][0]){
                case '+':
                    //printf("!!\n");
                    res=a+b;
                    break;
                case '-':
                    res=a-b;
                    break;
                case '*':
                    res=a*b;
                    break;
                case '/':
                    res=a/b;
                    break;
                //defualt: printf("!!\n");
            }
            printf("%d !!\n",numsSize);
            nums[numsSize++]=res;
        }
        else{
            int num=atoi(tokens[i]);
            nums[numsSize++]=num;
        }
    }
    return nums[0];
}

//https://www.nowcoder.com/exam/test/66103138/detail?examPageSource=Intelligent&pid=47419941&testCallback=https%3A%2F%2Fwww.nowcoder.com%2Fexam%2Fintelligent%3FquestionJobId%3D10%26tagId%3D21001&testclass=%E8%BD%AF%E4%BB%B6%E5%BC%80%E5%8F%91
int cmpn(int* nums,int numsSize,int target){
	int left=0,right=numsSize-1;
	int ans = 0;
	while(left<=right){
		int mid = (left + right) >> 1;
		if(nums[mid]==target){
			ans++;
			break;
		}
		else if(nums[mid]>target){
			right = mid - 1;
			ans++;
		}
		else{
			left = mid + 1;
			ans++;
		}
	}
	return ans;
}
//1 2 4 8 16 1

//https://leetcode.cn/problems/candy/
void locateVally(int* ratings,int ratingsSize,int* vally){
    if(ratings[0]<ratings[1])
		vally[0] = 1;
	if(ratings[ratingsSize-1]<ratings[ratingsSize-2])
		vally[ratingsSize - 1] = 1;
	for (int i=1;i<ratingsSize-1;i++)
		if(ratings[i]<ratings[i-1]&&ratings[i]<ratings[i+1])
			vally[i] = 1;
}
int candy(int* ratings, int ratingsSize){
    //找到所有的低谷，然后从低谷出发，往两边依次增加
	int vally[ratingsSize];
	int candies[ratingsSize];
	for (int i=0;i<ratingsSize;i++){
		vally[i] = 0;
		candies[i] = 1;
	}
	printf("ratingsSize: %d\n", ratingsSize);
	locateVally(ratings, ratingsSize, vally);

	for (int i=0;i<ratingsSize;i++){
        //printf("%d ",i);
        if(vally[i]){//遇到低谷
            for (int j=i+1;j<ratingsSize && ratings[j]>ratings[j-1];j++){//调整右边不是低谷的
                if(candies[j]<=candies[j-1])
					candies[j] = candies[j - 1] + 1;
			}//调整右边的
            for (int j=i-1;j>=0&&ratings[j]>ratings[j+1];j--){//调整左边不是低谷的那些
                if(candies[j]<=candies[j+1])
					candies[j] = candies[j + 1] + 1;
			}//调整左边的
        }
    }
	int sum = 0;
	printf("the ratings:\t");
	for (int i = 0; i < ratingsSize;i++){
		printf("%d ", ratings[i]);
	}
	printf("\ncandies:\t");
    for (int i=0;i<ratingsSize;i++){
        printf("%d ",candies[i]);
        sum+=candies[i];
    }
    printf("\nvally:  \t");
    for (int i=0;i<ratingsSize;i++){
        printf("%d ",vally[i]);
    }
    return sum;
}
//先找到连续上升或连续下降的最长区间
    /*
    int maxDecrease(int* ratings,int ratingsSize,int* left,int* right)
    int maxIncrease(int* ratings,int ratingsSize,int* left,int* right)
    int increaseLeft,increaseRight;
    int decreaseLeft,decreaseRight;
    int decrease=maxDecrease(ratings,ratingsSize,&decreaseLeft,&decreaseRight);
    int increase=maxIncrease(ratings,ratingsSize,&increaseLeft,&increaseRight);
    if(decrease>increase){
        candies[decreaseRight]=1;
    }
    else{
    }
    */
void test05(){
	int ratings[20] = {1, 2, 3, 5, 4, 3, 2, 1, 4, 3, 2, 1, 3, 2, 1, 1, 2, 3, 4};
	printf("\n the result is %d\n", candy(ratings, 19));
}

//https://www.nowcoder.com/exam/test/66924253/detail?pid=48043563&examPageSource=Intelligent&testCallback=https%3A%2F%2Fwww.nowcoder.com%2Fexam%2Fintelligent%3FquestionJobId%3D10
int cnt = 0;
void f(int left,int right){
	if(left>right)
		return;
	if(left==right){
		cnt++;
		return;
	}
	cnt++;
	int mid = (left + right) / 2;
	f(left, mid);
	f(mid + 1, right);
}

//https://www.nowcoder.com/exam/test/66925116/detail?pid=48044220&examPageSource=Intelligent&testCallback=https%3A%2F%2Fwww.nowcoder.com%2Fexam%2Fintelligent%3FquestionJobId%3D10
int waysToGo(int tol){
	int dp[tol + 2];
	//dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= tol;i++){
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return dp[tol];
}
void test06(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, *p = a + 5, *q = NULL;
    *q = *(p+5);
    printf("%d %d\n", *p, *q);
}

//https://leetcode.cn/problems/numbers-with-repeated-digits/
bool dupD(int n){
    set<int> st;
    while(n){
        int a=n%10;
        n/=10;
        if(st.sount[a]==0)st.insert(a);
        else return true;
    }
    return false;
}
int numDupDigitsAtMostN(int n) {
    int dp[12];
    //dp[i]��ʾ[1,10^i]���������ظ����ֵĸ���
    dp[0]=0;
    dp[1]=0;
    dp[2]=10;
    dp[3]=262;//1000
    int ans=0;
    for (int i=1001;i<=10000;i++){
    	if()
	}
    /*
    //dp[4]=
    int wei=0;
    while(n){
        n/=10;
        wei++;
    }
    int ans=0;
    for (int i=pow(10,wei-1)+1;i<=n;i++){
        if(dupD(i))ans++;
    }
    ans+=dp[wei-1];
    */
} 
void main() {
	test06();
	//"%d\n", waysToGo(15));
}
