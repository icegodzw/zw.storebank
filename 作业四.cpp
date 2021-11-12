/*$p^q + q^p$是一个素数，求$p$和$q$
$p^q + q^p$是一个素数，
$p$和$q$也是素数，
求$p$和$q$*/ 
#include<stdio.h>
#include<math.h>
int power(int base,int index){
	int buf=base;
	for(int i=1;i<=index-1;i++)
	base=base*buf;
	return base;
}
int main(){
	int n;
	printf("Enter a prime:");
	scanf("%d",&n);
	
	return 0;
} 
