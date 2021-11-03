#include<stdio.h>
#include<math.h> 
int power(int base,int index){
	int buf=base;
	for(int i=1;i<=index-1;i++)
	base=base*buf;
	return base;
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
int main(){
	int p,q;
	scanf("%d%d",&p,&q);
	int buf=power(p,q)+power(q,p);
	int _bool=isPrime(buf);
	if(_bool==1) printf("%d",buf);
	return 0;
} 
