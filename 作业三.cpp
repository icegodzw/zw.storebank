//f(n)�����Ķ���Ϊ0~n�а�����1�ĸ���
//f(13)��0~13�а���1���� 1��10��11��12��13������f(13)=6
//f(1) = 1��
//����һ��f(n)=n��nֵ 
//����һ��f(n)=n��nֵ
// 2021-11-04 
#include<stdio.h>
int main(){
	int n,sum=0;  //sum��������һ������ 
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
