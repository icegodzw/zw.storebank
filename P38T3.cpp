#include<stdio.h>
int main(){
	int a,b,c,d,e;
	printf("Enter ISBN:");
	scanf("%d-%d-%d-%d-%d",&a,&b,&c,&d,&e);
	printf("GSl prefix:%.3d\n",a);
	printf("Group identifier:%d\n",b);
	printf("Publisher code:%.3d\n",c);
	printf("Item number:%.5d\n",d);
	printf("Check digit:%d\n",e);
}
