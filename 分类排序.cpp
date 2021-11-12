#include<stdio.h>
int a[100],odd[100],even[100];
int sort(int x,int arr[]);//Ã°ÅİÅÅĞò 
void swap(int *a,int *b);  //½»»»a,bµÄÖµ 
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int j=0;
		int num_odd=0,num_even=0;
		do{
			scanf("%d",&a[j]);
			j++;
		} while(getchar()!='\n');
		for(int k=0;k<j;k++){
			if(a[k]%2==1){
				odd[num_odd]=a[k];
				num_odd++;
			}
			else{
				even[num_even]=a[k];
				num_even++;
			}
		}
		sort(num_odd,odd);
		for(int k=0;k<num_odd;k++) printf("%d ",odd[k]);
		sort(num_even,even);
		for(int k=0;k<num_even;k++) printf("%d ",even[k]);
		printf("\n");
	}
} 
void swap(int *a,int *b){
	int buf=*a;
	*a=*b;
	*b=buf;
}
int sort(int size,int arr[]){
	for(int i=0;i<size;i++){
		for(int j=0;j<size-1;j++){
			if(arr[j]>arr[j+1])
			swap(&arr[j],&arr[j+1]);
		}
	}
}
