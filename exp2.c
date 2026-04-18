#include<stdio.h>
#include<conio.h>
void towers(int,char,char,char); 
int main()
{
int num;
printf("enter the number of disks");
scanf("%d",&num);
printf("the sequence of moves involved in towers of hanoi:/t");
towers(num,'A','C','B');
return 0;
}
void towers(int num,char source,char dest,char spare)
{
if(num==1)
{
printf("\n move the disc 1 source %c to dest %c", source , dest); return;
}
towers(num-1,source,spare,dest);
printf("\n move the disc %d source %c to dest %c",num,source,dest);
towers(num-1,spare,dest,source);
}
