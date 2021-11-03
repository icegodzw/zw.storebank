#include<stdio.h>//bool ture=1 false=0
#include<cstdlib>
int main(){
	char a;
	float b,c;
	printf("输入两个数：");
	scanf("%f%f",&b,&c);
	fflush(stdin);//避免第十行的scanf误把回车读入 
	printf("输入符号：");
	scanf("%c",&a);
	switch(a){
		case '+': printf("%f\n",b+c);
		          break;
		case '-': printf("%f\n",b-c);
		          break;
		case '*': printf("%f\n",b*c);
		          break;
		case '/': if(c!=0) printf("%f\n",b/c);
		          else printf("error\n");
		          break;
	    default:  printf("error\n");
	}
	return 0;
} 
