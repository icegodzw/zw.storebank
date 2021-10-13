#include<stdio.h>
int main(){
	char letter[1000],end;
	int s,l,r;
	printf("Enter a sentence:");
	for(int i=0;i<=1000;i++){
		letter[i]=getchar();
		if(letter[i]=='.' || letter[i]=='!' || letter[i]=='?'){
			end=letter[i];
			s=i;
			break;
		}
	}
	r=s;
	for(int i=s-1;i>=0;i--){
		if(letter[i]==' '){
			l=i;
			for(int j=l+1;j<=r-1;j++){
				printf("%c",letter[j]);
			}
			r=i;
			printf(" ");
		}
	}
	for(int i=0;i<=r-1;i++){
		printf("%c",letter[i]);
	}
	printf("%c",end);
	return 0; 
} 
