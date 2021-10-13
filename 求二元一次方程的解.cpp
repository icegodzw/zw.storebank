#include<stdio.h>
float abs(float val){
	if(val<0) val=-val;
	return val;
}
float mysqrt(float n){
	float x=n/2,r=n,l=0;
	while(abs(n-x*x)>=1e-6){//whileѭ�� ����֤�����Ƿ���� ��������ִ��ѭ�� 
		if(x*x>=n){         //do-whileѭ�� ��ִ��ѭ���� ����֤���ʽ ��������ִ��ѭ�� 
			r=x;
			x=(x+l)/2;
		}
	    else
	    	l=x,x=(r+x)/2;
	}
	return x;
}
int main(){
	float x1,x2,a,b,c,temp;
	printf("Enter the coefficient��"); 
	scanf("%f,%f,%f",&a,&b,&c);
	if(b*b-4*a*c>=0){
		x1=(-b-mysqrt(b*b-4*a*c))/(2*a);
	    x2=(-b+mysqrt(b*b-4*a*c))/(2*a);
	    if(x1==x2) printf("the solve is��%f",x1);
	    else printf("the solves are��%f %f",x1,x2);
	}
	else printf("no solve");
	return 0;
}
