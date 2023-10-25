/*
 * hmi.h
 *
 *  Created on: July 18, 2023
 *      Author: Mahmoud
 */
#include <stdio.h>
#include <conio.h>


 
typedef struct{
	char name[20];
	char number[20];
	char message[30];
}Contact;

Contact arr[5];

void main(void){
	int choice;	
	while (1){
			static signed int Contact_counter=-1;
	printf("Press 0 For Add New User \nPress 1 For Print Contacts ");
	scanf("%d",&choice);
		if (choice==0){
		 Contact_counter++;
				if (Contact_counter==4){printf("Full, Cannot Add New User");break;}
			printf("Please Enter Contact Name, number , message :");
			scanf("%s",&arr[Contact_counter].name);
			scanf("%s",&arr[Contact_counter].number);
			scanf("%s",&arr[Contact_counter].message);
			
		}
		
		else if (choice==1){
			if (Contact_counter==-1){printf("THERE IS NO CONTACTS TO PRINT\n");}
			else {
				int j;
					for ( j=0;j<=Contact_counter;j++){
						printf("Contact %d Name is : %s \n",Contact_counter,arr[j].name);
						printf("Contact %d Number is : %s \n",Contact_counter,arr[j].number);
						printf("Contact %d Message is : %s \n \n",Contact_counter,arr[j].message);
					}
			
			
			}
		}
		
		else {printf("wrong Choice");}
	}
	getch();
}