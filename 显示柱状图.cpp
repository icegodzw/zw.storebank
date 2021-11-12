#include<stdio.h>
char s[3],sign[25];
char a[40][30];
int num[25];
int nummax(int n[],int size){
	int max=0;
	for(int i=0;i<size;i++)
	if(n[i]>max) max=n[i];
	return max;
}
int nummin(int n[],int size){
	int min=0;
	for(int i=0;i<size;i++)
	if(n[i]<min) min=n[i];
	return min;
}
int main(){
	int m;
	scanf("%d",&m);
	//num存储了字符的个数，sign存储字符的类型 
	for(int i=0;i<m;i++){
		scanf("%s",s);
		if(s[0]>='0' && s[0]<='9'){
			if(!(s[1]>='0' && s[1]<='9')){
				num[i]=(int)(s[0]-'0');
				if(s[1]!='\0') sign[i]=s[1];
				else sign[i]='+';
			}
			else if(s[1]>='0' && s[1]<='9'){
				num[i]=(int)(s[0]-'0')*10+(int)(s[1]-'0');
				if(s[2]!='\0') sign[i]=s[2];
				else sign[i]='+';
			}
		}
		else if(s[0]=='-'){
			if(!(s[2]>='0' && s[2]<='9')){
				num[i]=-(int)(s[1]-'0');
				if(s[2]!='\0') sign[i]=s[2];
				else sign[i]='+';
			}
			else if(s[2]>='0'&&s[2]<='9'){
				num[i]=-(int)(s[1]-'0')*10-(int)(s[2]-'0');
				if(s[3]!='\0') sign[i]=s[3];
				else sign[i]='+';
			}
		}
	}
	int max=nummax(num,m);
	int min=nummin(num,m);
	for(int i=0;i<=max-min+1;i++){
		for(int j=0;j<=2*m-2;j++){
			a[i][j]=' ';
		}
	}
	for(int i=0;i<=max-min+1;i++){
		for(int j=0;j<=2*m-2;j++){
			a[max][j]='-';
			if(j%2==0){
				if(num[j/2]>0){
					for(int k=max-1;k>=max-num[j/2];k--)
					a[k][j]=sign[j/2];
				}
				else{
					for(int k=max+1;k<=max-num[j/2];k++)
					a[k][j]=sign[j/2];
				}
			}
		}
	}
	for(int i=0;i<=max-min+1;i++){
		for(int j=0;j<=2*m-2;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
