#include<stdio.h>
char str[1000];
int con[20];
int str_length(char str[100]){    //求字符串的长度
	int length;
	for(length=0;length<=11;length++){
		if(str[length]=='\0') break;
	}
	return length;
}
int main(){
	int num,length,target=0;
	scanf("%d",&num);
	for(int i=0;i<20;i++) con[i]=0;
	for(int i=1;i<=num;i++){
		scanf("%s",str);
		length=str_length(str);
		if(length==3 && str[0]=='S' && str[1]=='C' && str[2]=='U') con[i]=1;
		else{
			for(int k=0;k<=length-1;k++){
				if(str[k]=='S') {
					target=k;
					break;
				}
			}
			if(str[target]=='S' && str[target+1]=='C' && str[target+2]=='U' && target>=1 && target<=length-4){
				con[i]=1;
			    for(int k=0;k<target;k++){
				    if(str[k]!='A') con[i]=0;
			    }
			    for(int k=target+3;k<=length-1;k++){
				    if(str[k]!='A') con[i]=0;
			    }
			} 
		}
	}
	for(int i=1;i<=num;i++){
		if(con[i]==1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
