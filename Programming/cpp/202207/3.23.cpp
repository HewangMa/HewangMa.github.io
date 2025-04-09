#include<stdio.h>
#include<stdlib.h>
int main(){
	char a[23]="3.225613";
	double n=atof(a);
	printf("%06.2f\n",n);
	return 0;
} 