#include<stdio.h>
int num[5];
int isNarcissus(int x);//输出l-r范围内的所有水仙花数 
int splitNum(int x,int num[]);
int main(){
	int n,l,r,x=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&l,&r);
		for(int j=l;j<=r;j++){
			int buf=isNarcissus(j);
			x=buf*x;
		}
		if(x==1) printf("-1");
		printf("\n");
	}
} 
int splitNum(int x,int num[]){
	int i=0;
	while(x!=0){
		num[i]=x-(x/10)*10;
		x=x/10;
		i++;
	}
	return i+1;
}
int isNarcissus(int x){
	int digit_sum=0,buf=1;
	int digit=splitNum(x,num);
	for(int j=0;j<digit;j++){
		digit_sum+=num[j]*num[j]*num[j];
	}
	if(digit_sum==x){
		printf("%d ",x);
		buf=0;
	}
	return buf;
}
