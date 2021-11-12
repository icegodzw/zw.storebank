#include<stdio.h>
int a[30],b[30];
int abs(int x){
	if(x<0) x=-x;
	return x;
}
int main(){
	int m,max=0,seat=1;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		b[i]=abs(a[i]);
		if(b[i]>max){
			max=b[i];
			seat=i;
		}
	} 
	printf("%d",a[seat]);
	return 0;
} 
