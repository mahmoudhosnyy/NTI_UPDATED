#include <stdio.h>
#include <conio.h>

int arr[5]={0x75,0x75,0x75,0x75,0x75};
void main(void){
char x;
short z;
char r;
int k;

x= arr[0]& (0x35);
z= ((arr[0]& (0xC0))>>6) | (arr[1]<<2);
r= arr[2] &(0x03);
k= ((arr[2]&0xFC)>>2) | (arr[3]<<6) | (arr[4]<<14); 

printf("%d  %d  %d  %d",x,z,r,k);
getch();

}