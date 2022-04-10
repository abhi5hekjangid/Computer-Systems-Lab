#include<stdio.h>
#include<conio.h>
int main()
{
int a[3][3],i,j;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("Enter Matrix Element ");
scanf("%d",&a[i][j]);
}
}
printf("\nMatrix is\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%d ",a[i][j]);
}
printf("\n");
}
return 0;
}