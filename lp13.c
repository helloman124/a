#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define FALSE 0
#define TRUE 1
int x[20];
// Function to determine if a queen can be placed on board at column k and row i.
int place(int k,int i){
	int j;
	// Running through all previous queens (j=1;j<=k)
	for(j=1;j<=k;j++){
		if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
			return FALSE; 
	}
	return TRUE; 
}

// Recursive function to solve N-Queens problem
void nqueens(int k,int n){
	int i,a;
	for(i=1;i<=n;i++)
    {
		if(place(k,i))
		{
			x[k]=i;
			if(k==n){// If all queens are placed
				// Print the board configuration
				for(a=1;a<=n;a++)
					printf("%d\t",x[a]);
				printf("\n");
			}
			else nqueens(k+1,n); // Try to place next queen.
		}
	}
}

void main()
{
	int n;
	printf("\nEnter the number of queens:");
	scanf("%d",&n);
	printf("\n The solution to N Queens problem is: \n");
	nqueens(1,n);
}
