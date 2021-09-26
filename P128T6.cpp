//P128 T6
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int i,a;
	cout<<"Enter message:";
	cin>>s;
	for (i=0;i<=s.length();i++){//32  65-90ด๓ะด 97-122ะกะด 
		a=(int)s[i];
		if( a<=122 && a>=97) {
			a-=32;
			s[i]=a;
		}
	}
	for (i=1;i<=s.length();i++){
		a=(int)s[i];
		if(a==65) s[i]=52;
		else if(a==66) s[i]=56;
		else if(a==69) s[i]=51;
		else if(a==73) s[i]=49;
		else if(a==79) s[i]=48;
		else if(a==83) s[i]=53;
	}
	cout<<"In BLFF-speak:"<<s<<"!!!!!!!!!!";
	return 0;
}
