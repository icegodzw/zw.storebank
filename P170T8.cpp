#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int num1,num2;
bool result;
int roll_dice(){
	num1=rand()%6+1;
	num2=rand()%6+1;
	return num1+num2;
}
bool play_game(){
	int sum,target;
	srand((unsigned) time(NULL));
	sum=roll_dice();
	printf("You rolled:%d\n",sum);
	if(sum==7 || sum==11) return true;
	else if(sum==2 || sum==3 || sum==11) return false;
	else{
		printf("You point is %d\n",sum);
		target=sum;
		for(int i=1;i<=1000;i++){
			sum=roll_dice();
			printf("You rolled:%d\n",sum);
			if(sum==target) {
				return true;
				break;
			}
			else if(sum==7){
				return false;
				break;
			}
		}
	}
}
int main(){
	char sign;
	int num_win=0,num_lose=0; 
	for(int i=1;i<=1000;i++){
		result=play_game();
		if(result==true) printf("You win!\n\n"),num_win++;
		else printf("You lose!\n\n"),num_lose++;
		printf("Play again?");
		sign=getchar();
		fflush(stdin);
		if(sign!='y' && sign!='Y'){
			printf("Wins:%d lose:%d",num_win,num_lose);
			break;
		}
	}
	return 0;
} 
