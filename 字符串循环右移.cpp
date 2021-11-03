#include<stdio.h>
int str_length(char str[300]){    //求字符串的长度
	int length;
	for(length=0;length<=300;length++){
		if(str[length]=='\0') break;
	}
	return length;
}
int main(){
	char s[300],b;
	int m,l;
	scanf("%d",&m);
	scanf("%c",&b);
	fgets(s,200,stdin);
	l=str_length(s)-1;
	//printf("%d\n",l);
	for(int i=l-m;i<l;i++) printf("%c",s[i]);
	for(int i=0;i<l-m;i++) printf("%c",s[i]);
	return 0;
}
