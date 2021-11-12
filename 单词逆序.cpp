#include<stdio.h>
char s[100];
int str_length(char str[18]);    //求字符串的长度
void ReverseOrder(char str[100],int l,int r);//单词反向 
int main(){
	fgets(s,200,stdin);
	int length=str_length(s)-1;
	int l=0,r=0,last;
	//for(int i=length-1;i>0;i--){
	//	if(s[i]>'a' && s[i]<'z' || s[i]>'A' && s[i]<'Z' ){
	//		last=i;
	//		break;
	//	}
	//}
	for(int i=0;i<length;i++){
		if(s[i]>'a' && s[i]<'z' || s[i]>'A' && s[i]<'Z'){
			l=i;
			for(int j=l;j<length;j++){
				if(!(s[j]>'a' && s[j]<'z' || s[j]>'A' && s[j]<'Z')){
					r=j-1;
					break;
			    }
			}
			ReverseOrder(s,l,r);
			i=i+r-l;
		}
	}
	//ReverseOrder(s,l,last);
	printf("%s",s);
}
int str_length(char str[18]){    //求字符串的长度
	int length;
	for(length=0;length<=18;length++){
		if(str[length]=='\0') break;
	}
	return length;
}
void ReverseOrder(char str[100],int l,int r){
	char temp[100];
	for(int i=l;i<=r;i++) temp[i]=str[i];
	for(int i=l;i<=r;i++) str[i]=temp[r-i+l];
}
