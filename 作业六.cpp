// 卷积（Convolution）是当前神经网络的基础算法
// 卷积的原理不复杂，网上有大量资料和实现，包括C语言实现
// 大家自行设计一个卷积函数，输入一个向量和卷积核，输出卷积的结果
// 2021-11-21 
#include<stdio.h>
int main(){
	int x[4][4],a[2][2];
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	scanf("%d",&a[i][j]);
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	scanf("%d",&x[i][j]);
	int f[2][2]={0,0,0,0};
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	for(int m=i;m<i+2;m++)
	for(int n=j;n<j+2;n++)
	f[i][j]+=x[m+i][n+j]*a[i][j];
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("%d ",f[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
