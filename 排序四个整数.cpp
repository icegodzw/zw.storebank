#include<stdio.h>
void swap(int *a,int *b); //����a��b��ֵ 
int main(){
    int n,i;
    scanf("%d", &n);  // ��n������
    for(i=0; i<n;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a>=b) swap(&a,&b);
        if(b>=c) swap(&b,&c);
        if(c>=d) swap(&c,&d);
        if(a>=b) swap(&a,&b);
        if(b>=c) swap(&b,&c);
        if(a>=b) swap(&a,&b);
        printf("%d %d %d %d\n",a,b,c,d);
        // ����4������������4���������򣬲�������
        // �뽫�������д���������ʹ��ѭ�����
	}
    return 0;
}
void swap(int *a,int *b){
	int buf=*a;
	*a=*b;
	*b=buf;
} 
