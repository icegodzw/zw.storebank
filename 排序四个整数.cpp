#include<stdio.h>
void swap(int *a,int *b); //交换a，b的值 
int main(){
    int n,i;
    scanf("%d", &n);  // 有n组数据
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
        // 读入4个整数，对这4个整数排序，并输出结果
        // 请将排序代码写在这里，不能使用循环语句
	}
    return 0;
}
void swap(int *a,int *b){
	int buf=*a;
	*a=*b;
	*b=buf;
} 
