#include<stdio.h>
#include<math.h>
int main(){
	float x1,x2,a,b,c;
	printf("请输入系数："); 
	scanf("%f,%f,%f",&a,&b,&c);
	if(b*b-4*a*c>=0){
		x1=(-b-sqrt(b*b-4*a*c))/(2*a);//缩短长度：加一条temp=b*b-4*a*c;等 
	    x2=(-b+sqrt(b*b-4*a*c))/(2*a);
	    if(x1==x2) printf("方程的解是：%f",x1);
	    else printf("方程的解是：%f %f",x1,x2);
	}
	else printf("方程无解");
	return 0;
} 
