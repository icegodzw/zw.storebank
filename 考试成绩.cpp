#include<stdio.h>
char name[11],id[18],score[3];
char max_name[11]={'z'},max_id[18],min_name[11]={'z'},min_id[18];
int str_length(char str[11]){    //求字符串的长度
	int length;
	for(length=0;length<=11;length++){
		if(str[length]=='\0') break;
	}
	return length;
}
int name_sort(char name1[11],char name2[11]){    //名字按照字典顺序排序 
	int i;
	for(i=0;i<=11;i++){
		if(name1[i]<name2[i]){  //ascii小 即字典顺序中该名字小 
			return 1;
			break;
		}
		if(name1[i]>name2[i]){
			return 2;
			break;
		}
	}
	if(i==11) return 2;
}
void max_copy(){    //将数据存储在max_id等中 
	for(int j=0;j<=11;j++){
		max_name[j]=name[j];
	}
	for(int j=0;j<=18;j++){
		max_id[j]=id[j];
	}
}
void min_copy(){
	for(int j=0;j<=11;j++){
		min_name[j]=name[j];
	}
	for(int j=0;j<=18;j++){
		min_id[j]=id[j];
	}
}
int main(){
	int num,length,num_score,max_score=0,min_score=100;
	scanf("%d",&num);
	fflush(stdin);
	for(int i=1;i<=num;i++){
		scanf("%s%s%s",name,id,score);
		length=str_length(score); 
		if(!(score[0]=='n' && score[1]=='/' && score[2]=='a')){
			if(length==1) num_score=(int)(score[0]-'0');
			else if(length==2) num_score=(int)(score[0]-'0')*10+(int)(score[1]-'0');
			else num_score=(int)(score[0]-'0')*100+(int)(score[1]-'0')*10+(int)(score[2]-'0');
			if(num_score>max_score){
				max_score=num_score;
				max_copy();
			}
			if(num_score==max_score){
				int temp=name_sort(name,max_name);
				if(temp==1) max_copy();
			}
			if(num_score<min_score){
				min_score=num_score;
				min_copy();
			}
			if(num_score==min_score){
				int temp=name_sort(name,min_name);
				if(temp==2) min_copy();
			}
		}
	}
	printf("%s %s\n",max_name,max_id);
	printf("%s %s",min_name,min_id);
	return 0;
}
