#include<stdio.h>
#include<math.h>
int main(){
	float x1,x2,a,b,c;
	printf("������ϵ����"); 
	scanf("%f,%f,%f",&a,&b,&c);
	if(b*b-4*a*c>=0){
		x1=(-b-sqrt(b*b-4*a*c))/(2*a);//���̳��ȣ���һ��temp=b*b-4*a*c;�� 
	    x2=(-b+sqrt(b*b-4*a*c))/(2*a);
	    if(x1==x2) printf("���̵Ľ��ǣ�%f",x1);
	    else printf("���̵Ľ��ǣ�%f %f",x1,x2);
	}
	else printf("�����޽�");
	return 0;
} 
