#include<stdio.h>
int main(){
	int year;
	printf("输入一个年份：");
	scanf("%d",&year);
	if(year%4==0 && year%100!=0 || year%400==0) //!(year%100==0)等价 
	printf("%d是闰年\n",year);
	else printf("%d不是闰年\n",year);
    return 0; 
}
