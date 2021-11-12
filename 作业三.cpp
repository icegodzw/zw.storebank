//f(n)函数的定义为0~n中包含的1的个数
//f(13)是0~13中包含1的有 1，10，11，12，13，所以f(13)=6
//f(1) = 1。
//求另一个f(n)=n的n值 
//求另一个f(n)=n的n值
// 2021-11-04 
#include<stdio.h>
int main(){
	int n,sum=0;  //sum用来储存一的数量 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x=i;
		while(x!=0){
			int digit=x%10;
			if(digit==1) sum++;
			x=x/10;
		}
	}
	printf("%d\n",sum);
	return 0;
} 
