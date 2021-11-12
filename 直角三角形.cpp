#include<stdio.h>
int rt(int a,int b,int c){
	int ret=0;
	if(a>0 && b>0 && c>0){
		int buf1=a*a-b*b-c*c;
	    int buf2=b*b-a*a-c*c;
	    int buf3=c*c-b*b-a*a;
	    if(buf1==0 || buf2==0 || buf3==0) ret=1;
	} 
	return ret;
}
int main(){
	int n,a,b,c;
	scanf("%d",&n);
	int ret[n+1]; 
	for(int i=1;i<=n;i++) ret[i]=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a,&b,&c);
		ret[i]=rt(a,b,c);
	} 
	for(int i=1;i<=n;i++){
		if(ret[i]==1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 
