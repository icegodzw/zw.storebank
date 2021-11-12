#include<stdio.h>
#include<math.h>
int isPrime(int x){
	int _bool=1;
	if(x==2 || x==3) return 1;
	else if(x>=4){
		for(int i=2;i<=sqrt(x);i++){
		    if(x%i==0){
			    _bool=0;
			    break;
		    }
	    }
	    return _bool; 
	}
} 
int main(){
	int n;
	scanf("%d",&n);
	if(n>=6 && n%2==0){
		for(int a=3;a<=n/2;a++){
			int b=n-a;
			int buf1=isPrime(a);
		    int buf2=isPrime(b);
		    if(buf1==1 && buf2==1) printf("%d %d\n",a,b);
		}
	}
	else printf("ERROR\n");
	return 0;
} 
