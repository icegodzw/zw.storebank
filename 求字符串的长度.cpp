#include<stdio.h>
int str_length(char str[100]){    //���ַ����ĳ���
	int length;
	for(length=0;length<=100;length++){
		if(str[length]=='\0') break;
	}
	return length;
}
int main(){
	char s[100];
	fgets(s,100,stdin);
	int l=str_length(s)-1;
	printf("%d",l); 
} 
