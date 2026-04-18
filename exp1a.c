#include<stdio.h>
void printfib(int n)
{
	if (n<1)
	{
		printf("Invalid number!");
	}
	int prev2=0;
	int prev1=1;
	int i;
	for( i=1; i<=n; i++)
	{
		if (i>2)
		{
			int curr=prev1+prev2;
			prev2=prev1;
			prev1=curr;
			printf("%d\n",curr);
		}
		else if(i==1)
		{
			printf("%d\n",prev2);
		}
		else if (i==2)
		{
			printf("%d\n%d\n",prev2,prev1);
		}
	}
}
int main()
{
	int n;
	printf("Enter the n value:",n);
	scanf("%d",&n);
	printfib(n);
	return 0;
}
