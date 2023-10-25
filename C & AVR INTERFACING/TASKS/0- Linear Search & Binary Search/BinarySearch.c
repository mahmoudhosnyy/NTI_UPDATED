

#include <stdio.h>
#include <conio.h>


void main (void){
	int temp;
	int index;
	int Found_Flag=0;
	int Search_num=0;
	int arr[10];
	int size =10;
	int mid;
	int L=0;
	int H=9;
	for (int i=0;i<size;i++){
		printf("please enter arr[%d] : ",i+1);
		scanf("%d",&arr[i]);
	}
	
	/* BUBBLE Sorting */
	
	for (int i=0;i<size;i++){
		for (int j=0;j<size-i;j++){
			if (arr[j]>arr[j+1]){
				temp= arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	/*SEARCHING */
	
	printf("\nPlease Enter The num you need to search for : ");
	scanf("%d",&Search_num);
	while (L<=H){
		mid=((L+H)/2);
		if (Search_num==arr[mid]){
			Found_Flag=1;
			index=mid;
			break;
		}
		else if (Search_num>arr[mid]){
			L=mid+1;
		}
		else if (Search_num<arr[mid]){
			H=mid-1;
		}		
	}
	
	
	if(Found_Flag==1){printf("FOUND.. Its arr[%d] ",index+1);}
	else if(Found_Flag==0){printf("NOT FOUND");}
	getch();
}