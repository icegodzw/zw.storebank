#include<stdio.h>//bool ture=1 false=0
#include<cstdlib>
int main(){
	char a;
	float b,c;
	printf("������������");
	scanf("%f%f",&b,&c);
	fflush(stdin);//�����ʮ�е�scanf��ѻس����� 
	printf("������ţ�");
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
