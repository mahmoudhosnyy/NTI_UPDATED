#include <stdio.h>
#include <conio.h>

void main(void)
{
    const u8 size = 5;
    u8 i;
    u8 array[size];
    s8 location=-1;
    u8 element;

    printf("Enter the required array: \n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }

    printf("Enter element for search: ");
    scanf("%d",&element);
	
	 for(i=0;i<size;i++)
    {
        if(element==array[i])
        {
        	location=i;
        }
    }

    if(location == -1)
    {
        printf("\nElement not found\n");
    }
    else
    {
        printf("\nThe element at the location: %d",location);
    }
    getch();
}
