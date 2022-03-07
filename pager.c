//Jacob Silveira
//CST-315
//3-6-2022
//This program converts a logical address to a physical adress with a user inputted file size and page size, using this it caclualtes frame numbers and page numbers and accepts the valid logical address finally displaying the physical address.
//To compile: gcc pager.c
//To run: ./a.out

//needed header files
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct MainMem
{
//declaration of int variables
    int start_add;
    int pn;
};
//the main function
int main()
{
    //declaring int and struct variables needed
    int s,i,totalPgs,pgnum,offset,n,r,arr[200]={0},phy_add,fno[100];
    struct MainMem mainM[100];
    srand((unsigned)time(NULL));
    //print statments
    printf("Converting Logical Address To Physical Address\n");
    printf("Input Size of File : ");
    scanf("%d",&n); //prompts user to input size of the file
    printf("Input Page Size : ");
    scanf("%d",&s); //prompts user to input page size
    totalPgs=n/s; //int the total pages to n/s
    for(i=0;i<totalPgs;i++) //for the condition i=0 i < total pages increment the values for i
    {
      r=rand()%totalPgs;
      //if the condition r = 1 then continously decremnt the value of i
      if(arr[r] == 1)
      {
        i--;
        continue;
      } 
      //computing main memeory start
      arr[r]=1;
      mainM[i].pn=r;
      mainM[i].start_add=i*s;
      fno[r]=i;
}
  
//print statments to show the main memeory and frame number next to page number
printf("Main Memory Structure\n"); 
printf("***********\n");
printf("Frame\tPage\nNumber\tNumber\n------\t------\n");
//for the condition i = 0 i < total pages, increment values for i
for(i=0; i < totalPgs; i++)
{
    //print to show values for frame number and page number
    printf("%d\t%d\n",i,mainM[i].pn);
}
printf("***********\n");
printf("Input Logical Address\nPage Number : ");
scanf("%d",&pgnum); //asks user for input for page number
printf("Input Offset : ");
scanf("%d",&offset); // asks user to offset input
//if the page number >= total pages or offset is > than page size input is invalid and error is printed
if(pgnum >= totalPgs || offset > s)
{
    printf("Error Invalid Input\n");
    return 0;
}
phy_add = mainM[fno[pgnum]].start_add + offset;
printf("***********\n");
printf("Physical Address : %d\n",phy_add);
printf("***********\n");
return 0;
}
/*
*/
