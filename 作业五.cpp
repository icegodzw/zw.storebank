//����һ���ַ���������
//3072x1728,2720x1536,2560x1600,2560x1440,2304x1728,2048x1536,1920x1200,1920x1080,1440x900,1280x800,1280x720,1024x768,1024x640,800x600,800x500,800x450,640x480,640x400,640x360,480x360,480x300,480x270,320x240,320x200,320x180,240x180,176x144,160x120,160x100,160x90,
//����һ����ʾ��֧�ֵķֱ����嵥���м䶺�ŷָ���
//�������뻭��Ŀ�͸ߣ�Ȼ���������嵥����ѡһ����ӽ��ķֱ������
//��������2000��1000������ķֱ���Ӧ����1920x1080����Ϊ�����ֱ��ʵ�������
//������³���
// 2021-11-14
#include <stdio.h>
struct st{
	char s[9];
	long long x;
}ck[100];
int str_length(char str[1000]){    //���ַ����ĳ���
	int length;
	for(length=0;length<=1000;length++){
		if(str[length]=='\0') break;
	}
	return length;
}
int abs(int x){
	if(x<0) x=-x;
	return x;
}
int main(){
    char ress[2048];
    long long x,y;
    int l=0,r,num=0;
    scanf("%s",ress);
    scanf("%lld%lld",&x,&y);
    for(int i=0;i<str_length(ress);i++){
    	if(ress[i]==','){
    		r=i;
    		int k=0;
    		for(int j=l;j<r;j++) ck[num].s[k++]=ress[j];
    		long long length,width;
    		sscanf(ck[num].s,"%dx%d",&length,&width);
    		ck[num].x=length*width;
    		num++;
    		l=i+1;
		}
	}
	long long t=x*y;
	int diff=abs(ck[0].x-t);
	int seat=0;
	for(int i=1;i<num;i++){
		int buf=abs(ck[i].x-t);
		if(buf<diff){
			diff=buf;
			seat=i;
		}
	}
    // ѧϰһ�� sscanf ���Է��㴦�� ress �ַ���
    printf("ѡ�еķֱ�����%s\n",ck[seat].s);
    return 0;
}
