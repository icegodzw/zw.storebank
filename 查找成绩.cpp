#include<stdio.h>
char name[1000][11],id[1000][18],score[1000][3];
char target[18];
int num_score[1000],score_length[1000],rank[1000];
int number[1000],mark[1000]={0};      //mark用来标记该行是否有目标字符串 number标记编号 
int str_length(char str[11]){    //求字符串的长度
	int length;
	for(length=0;length<=11;length++){
		if(str[length]=='\0') break;
	}
	return length;
}
void swap(int *a,int *b){
	int buf=*a;
	*a=*b;
	*b=buf;
} 
/*void str_swap(char str1[18],char str2[18]){        //交换两个学生的信息，交换他们的行数 
	char buf[18];
	for(int i=0;i<=18;i++){
		buf[i]=str1[i];
	}
	for(int i=0;i<=18;i++){
		str1[i]=str2[i];
	}
	for(int i=0;i<=18;i++){
		str2[i]=buf[i];
	}
}*/ 
int search(char str1[18],char str2[18]){    //在字符串str2中查找str1函数 
	int i,j,mark=0;
	int length1=str_length(str1);
	int length2=str_length(str2);
	for(i=0;i<=length2-2;i++){
		for(j=0;j<length1;j++){
			if(str1[j]!=str2[i+j]) break;
		}
		if(j==length1){
			mark=1;
			break;
		}
	} 
	return mark;
}
int main(){
	int num;
	scanf("%d",&num);
	scanf("%s",target);
	int target_length=str_length(target);
	for(int i=1;i<=1000;i++) number[i]=i;  //初始化number 
	for(int i=1;i<=num;i++){
		scanf("%s%s%s",name[i],id[i],score[i]);
		score_length[i]=str_length(score[i]);
    }
    //把学生成绩由字符型转为整数型，如果缺考，定义他的成绩为-1 
    for(int i=1;i<=num;i++){
    	if(score[i][0]=='n' && score[i][1]=='/' && score[i][2]=='a') num_score[i]=-1;
        else if(score_length[i]==1) num_score[i]=(int)(score[i][0]-'0');
		else if(score_length[i]==2) num_score[i]=(int)(score[i][0]-'0')*10+(int)(score[i][1]-'0');
		else num_score[i]=(int)(score[i][0]-'0')*100+(int)(score[i][1]-'0')*10+(int)(score[i][2]-'0');
	}
	//冒泡法对n个学生按照成绩排序，缺考放在最后,从大到小 
	for(int i=1;i<=num;i++){
		for(int j=1;j<=num-1;j++){
			if(num_score[j]<num_score[j+1]){
				//str_swap(name[j],name[j+1]);
				//str_swap(id[j],id[j+1]);
				//str_swap(score[j],score[j+1]);
				int *p1,*p2;
				p1=&num_score[j],p2=&num_score[j+1];
	            swap(p1,p2);
	            int *q1,*q2;
				q1=&number[j],p2=&number[j+1];
	            swap(q1,q2);
			}
		}
	}
	//在rank中储存学生的排名 若缺考，排名为-1 
	for(int i=1;i<=num;i++){
		if(num_score[i]==-1) rank[i]=-1;
		else rank[i]=i;
	}
	//实现成绩相同的学生拥有相同的排名 
	for(int i=1;i<=num;i++){
		for(int j=i+1;i<=num;j++){
			if(num_score[j]==num_score[i]) rank[j]=rank[i];
			else{
				i=j;
				break;
			}
		}
	}
	//在学生信息中寻找给定的字符串
	for(int i=1;i<=num;i++){
		mark[i]=search(target,name[i]);
		if(mark[i]==1) printf("%s %s %s %d\n",name[i],id[i],score[i],rank[i]);
		else{
			mark[i]=search(target,id[i]);
			if(mark[i]==1) printf("%s %s %s %d\n",name[i],id[i],score[i],rank[i]);
			else{
				mark[i]=search(target,score[i]);
				if(mark[i]==1) printf("%s %s %s %d\n",name[i],id[i],score[i],rank[i]);
			}
		}
	}
	return 0;
} 














/*描述
读入n名学生的姓名、身份证号、成绩。查找并输出匹配查找串的学生的姓名和学号和成绩。
学生名单中可能缺考，没有成绩，表示为n/a。
如果查找串是针对姓名或者身份证号，则是模糊查找，即只要其中包含查找串(区分大小写)即算满足条件，
如果查找串是针对成绩，则是精确查找。
输入
每个测试输入包含1个测试用例，格式为
  第1行：正整数n  待查找串
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名为不超过10个字符的字符串，身份证是标准18位，成绩为0到100之间的一个整数。
输出
输出包含相应查找串的学生信息(姓名 学号 成绩  排名)(如果成绩为n/a，则排名就为n/a)，
项之间用空格隔开。每个学生一行。其中排名是按照成绩降序排列的排名。
如果有多个学生的成绩相同，则这些学生的排名相同，并且随后的几个排名将跳过。
满足条件的多个学生按照输入的顺序输出。
样例1
输入
3 Joe
Joe 510502199001011234 89
Mike 51050220000101123x 100
Mary 510502199901011235 n/a
输出
Joe 510502199001011234 89 2
样例2
输入
3 1234
Joe 510502199001011234 89
Mike 51050220000101123x 100
Mary 510502199901011235 90
输出
Joe 510502199001011234 89 3
*/
