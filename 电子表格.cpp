#include<stdio.h>
int a[100][100];  //前面是行 后面是列 
int r,c;
void SR(int v1,int v2){
	int temp[100];
	for(int i=1;i<=c;i++) temp[i]=a[v1][i];
	for(int i=1;i<=c;i++) a[v1][i]=a[v2][i];
	for(int i=1;i<=c;i++) a[v2][i]=temp[i];
}
void SC(int v1,int v2){
	int temp[100];
	for(int i=1;i<=r;i++) temp[i]=a[i][v1];
	for(int i=1;i<=r;i++) a[i][v1]=a[i][v2];
	for(int i=1;i<=r;i++) a[i][v2]=temp[i];
}
void DR(int v1){
	for(int i=v1;i<=r;i++){
		for(int j=1;j<=c;j++){
			a[i][j]=a[i+1][j];
		}
	}
}
void DC(int v1){
	for(int i=v1;i<=c;i++){
		for(int j=1;j<=r;j++){
			a[j][i]=a[j][i+1];
		}
	}
}
void IR(int v1){
	for(int i=r+1;i>=v1+1;i--){
		for(int j=1;j<=c;j++){
			a[i][j]=a[i-1][j];
		}
	}
	for(int j=1;j<=c;j++) a[v1][j]=0;
}
void IC(int v1){
	for(int i=c+1;i>=v1+1;i--){
		for(int j=1;j<=r;j++){
			a[j][i]=a[j][i-1];
		}
	}
	for(int j=1;j<=r;j++) a[j][v1]=0;
}
int main(){
	int n,v1,v2;
	char u[5];
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		fflush(stdin);
		scanf("%s",u);
		if(u[0]=='S' && u[1]=='R'){
			scanf("%d%d",&v1,&v2);
			SR(v1,v2);
		}
		else if(u[0]=='S' && u[1]=='C'){
			scanf("%d%d",&v1,&v2);
			SC(v1,v2);
		}
		else if(u[0]=='D' && u[1]=='R'){
			scanf("%d",&v1);
			DR(v1);
			r--;
		}
		else if(u[0]=='D' && u[1]=='C'){
			scanf("%d",&v1);
			DC(v1);
			c--;
		}
		else if(u[0]=='I' && u[1]=='R'){
			scanf("%d",&v1);
			IR(v1);
			r++;
		}
		else if(u[0]=='I' && u[1]=='C'){
			scanf("%d",&v1);
			IC(v1);
			c++;
		}
	}
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			printf("%d",a[i][j]);
			if(j==c) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
