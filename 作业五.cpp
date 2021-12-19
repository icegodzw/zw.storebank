//输入一个字符串，形如
//3072x1728,2720x1536,2560x1600,2560x1440,2304x1728,2048x1536,1920x1200,1920x1080,1440x900,1280x800,1280x720,1024x768,1024x640,800x600,800x500,800x450,640x480,640x400,640x360,480x360,480x300,480x270,320x240,320x200,320x180,240x180,176x144,160x120,160x100,160x90,
//这是一个显示器支持的分辨率清单，中间逗号分隔。
//现在输入画面的宽和高，然后在上述清单中挑选一个最接近的分辨率输出
//比如输入2000，1000，输出的分辨率应该是1920x1080，因为其它分辨率的误差更大。
//完成如下程序
// 2021-11-14
#include <stdio.h>
struct st{
	char s[9];
	long long x;
}ck[100];
int str_length(char str[1000]){    //求字符串的长度
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
    // 学习一下 sscanf 可以方便处理 ress 字符串
    printf("选中的分辨率是%s\n",ck[seat].s);
    return 0;
}
