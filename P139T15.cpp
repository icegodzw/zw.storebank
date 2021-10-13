#include<stdio.h>
int main(){
	char ch[80];
	int s,shift;
	printf("Enter message to be encrypted:");
	for(int i=0;i<=80;i++){
		ch[i]=getchar();
		if(ch[i]=='.' || ch[i]=='!' || ch[i]=='?'){
			s=i;
			break;
		}
	}
	printf("Enter shift amount (1-25):");
	scanf("%d",&shift);
	printf("Encrypted message:");
	for(int i=0;i<=s;i++){
		if(ch[i]>='a' && ch[i]<='z') ch[i]=(ch[i]-'a'+shift)%26+'a';//解决了溢出的情况 
		else if(ch[i]>='A' && ch[i]<='Z') ch[i]=(ch[i]-'A'+shift)%26+'A';
	}
	for(int i=0;i<=s;i++){
		printf("%c",ch[i]); 
	} 
	return 0;
} 
