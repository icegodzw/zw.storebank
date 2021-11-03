#include<stdio.h>
char name[1000][11],id[1000][18],score[1000][3];
char target[18];
int num_score[1000],score_length[1000],rank[1000];
int number[1000],mark[1000]={0};      //mark������Ǹ����Ƿ���Ŀ���ַ��� number��Ǳ�� 
int str_length(char str[11]){    //���ַ����ĳ���
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
/*void str_swap(char str1[18],char str2[18]){        //��������ѧ������Ϣ���������ǵ����� 
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
int search(char str1[18],char str2[18]){    //���ַ���str2�в���str1���� 
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
	for(int i=1;i<=1000;i++) number[i]=i;  //��ʼ��number 
	for(int i=1;i<=num;i++){
		scanf("%s%s%s",name[i],id[i],score[i]);
		score_length[i]=str_length(score[i]);
    }
    //��ѧ���ɼ����ַ���תΪ�����ͣ����ȱ�����������ĳɼ�Ϊ-1 
    for(int i=1;i<=num;i++){
    	if(score[i][0]=='n' && score[i][1]=='/' && score[i][2]=='a') num_score[i]=-1;
        else if(score_length[i]==1) num_score[i]=(int)(score[i][0]-'0');
		else if(score_length[i]==2) num_score[i]=(int)(score[i][0]-'0')*10+(int)(score[i][1]-'0');
		else num_score[i]=(int)(score[i][0]-'0')*100+(int)(score[i][1]-'0')*10+(int)(score[i][2]-'0');
	}
	//ð�ݷ���n��ѧ�����ճɼ�����ȱ���������,�Ӵ�С 
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
	//��rank�д���ѧ�������� ��ȱ��������Ϊ-1 
	for(int i=1;i<=num;i++){
		if(num_score[i]==-1) rank[i]=-1;
		else rank[i]=i;
	}
	//ʵ�ֳɼ���ͬ��ѧ��ӵ����ͬ������ 
	for(int i=1;i<=num;i++){
		for(int j=i+1;i<=num;j++){
			if(num_score[j]==num_score[i]) rank[j]=rank[i];
			else{
				i=j;
				break;
			}
		}
	}
	//��ѧ����Ϣ��Ѱ�Ҹ������ַ���
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














/*����
����n��ѧ�������������֤�š��ɼ������Ҳ����ƥ����Ҵ���ѧ����������ѧ�źͳɼ���
ѧ�������п���ȱ����û�гɼ�����ʾΪn/a��
������Ҵ�����������������֤�ţ�����ģ�����ң���ֻҪ���а������Ҵ�(���ִ�Сд)��������������
������Ҵ�����Գɼ������Ǿ�ȷ���ҡ�
����
ÿ�������������1��������������ʽΪ
  ��1�У�������n  �����Ҵ�
  ��2�У���1��ѧ�������� ѧ�� �ɼ�
  ��3�У���2��ѧ�������� ѧ�� �ɼ�
  ... ... ...
  ��n+1�У���n��ѧ�������� ѧ�� �ɼ�
��������Ϊ������10���ַ����ַ��������֤�Ǳ�׼18λ���ɼ�Ϊ0��100֮���һ��������
���
���������Ӧ���Ҵ���ѧ����Ϣ(���� ѧ�� �ɼ�  ����)(����ɼ�Ϊn/a����������Ϊn/a)��
��֮���ÿո������ÿ��ѧ��һ�С����������ǰ��ճɼ��������е�������
����ж��ѧ���ĳɼ���ͬ������Щѧ����������ͬ���������ļ���������������
���������Ķ��ѧ�����������˳�������
����1
����
3 Joe
Joe 510502199001011234 89
Mike 51050220000101123x 100
Mary 510502199901011235 n/a
���
Joe 510502199001011234 89 2
����2
����
3 1234
Joe 510502199001011234 89
Mike 51050220000101123x 100
Mary 510502199901011235 90
���
Joe 510502199001011234 89 3
*/
