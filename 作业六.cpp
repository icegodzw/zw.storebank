// �����Convolution���ǵ�ǰ������Ļ����㷨
// �����ԭ�����ӣ������д������Ϻ�ʵ�֣�����C����ʵ��
// ����������һ���������������һ�������;���ˣ��������Ľ��
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
