#include<stdio.h>
/*
void test01(){
	char *s = "1314520";
    int v1 = 0, v2 = 0, v3 = 0, v4 =0;
    for (int i = 0; s[i]; i++) {
        switch(s[i]) {
            default: v4++;
            case '1': v1++;
            case '2': v2++;
            case '3': v3++;
        }
    }
    printf("%d, %d, %d, %d", v4,v1,v2,v3);
}
*/
void test02(){	
	int m=0123,n=123;//m已经是八进制 
	printf("%d,%d\n",m,n);
}
void test03(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, *p = a + 5, *q = NULL;
    *q = *(p+5);
    printf("%d %d\n", *p, *q);
}
void test04(){
	char ch=-1;
	printf("%02x,%02x\n",ch,(unsigned char)ch);
}
int main(){
    test04();
    return 0;
}
