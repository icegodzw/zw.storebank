#include<stdio.h>
int main(){
	int item,month,day,year;
	float price;
	printf("Enter item number:");
	scanf("%d",&item);
	printf("Enter unit number:");
	scanf("%f",&price);
	printf("Enter purchase date (mm/dd/yyyy):");
	scanf("%d/%d/%d",&month,&day,&year);
	printf("Item\tUnit\tPurchase\n\tPrice\tDate\n");
	printf("%d\t%.2f\t%.2d/%.2d/%.4d",item,price,month,day,year);
	return 0;
} 
