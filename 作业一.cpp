//超级素数：它劳动，各位数字和，各位数字的平方和，都是素数。
//求100~10000内的所有超级素数，及它们的平均数。
// 2021-10-29
#include<stdio.h>
#include<math.h>
int isPrime(int x);
int splitNum(int x,int num[]);
int main(){
	int num[5],digit,digit_sum=0,digitdouble_sum=0,superprime_num=0;
	double superprime_sum=0;
	for(int i=100;i<=10000;i++){
		digit=splitNum(i,num);
		for(int j=0;j<=digit-1;j++) digit_sum+=num[j];
		for(int j=0;j<=digit-1;j++) digitdouble_sum+=num[j]*num[j];
		int _bool1=isPrime(i);
		int _bool2=isPrime(digit_sum);
		int _bool3=isPrime(digitdouble_sum);
		if(_bool1==1 && _bool2==1 && _bool3==1){
			printf("%d\n",i); 
		    superprime_sum+=i;
		    superprime_num++;
		}
	}
	printf("%f\n",superprime_sum/superprime_num);
	return 0;
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
int isPrime(int x){
	int _bool=1;
	if(x==1) return 0;
	else if(x==2 || x==3) return 1;
	else if(x>=4){
		for(int i=2;i<=sqrt(x);i++){
		    if(x%i==0){
			    _bool=0;
			    return 0;
			    break;
		    }
	    }
	    if(_bool==1) return 1; 
	}
} 
