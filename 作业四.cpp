/*$p^q + q^p$��һ����������$p$��$q$
$p^q + q^p$��һ��������
$p$��$q$Ҳ��������
��$p$��$q$*/ 
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
