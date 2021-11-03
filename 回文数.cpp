#include<stdio.h>
int a[1000],x[1000],s[1000];
int main(){
	int n,j;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) a[i]=0;
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=1;i<=n;i++){
		j=0;
		while(x[i]!=0){
			s[j]=x[i]%10; //
			x[i]=x[i]/10;
			j++;
		}
		for(int k=0;k<j;k++){
			if(s[k]!=s[j-k-1]) a[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0) printf("Yes\n");
		else printf("No\n");
	}
}
