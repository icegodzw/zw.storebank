#include<stdio.h>
int main(){
	int year;
	printf("����һ����ݣ�");
	scanf("%d",&year);
	if(year%4==0 && year%100!=0 || year%400==0) //!(year%100==0)�ȼ� 
	printf("%d������\n",year);
	else printf("%d��������\n",year);
    return 0; 
}
