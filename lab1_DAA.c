#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**
*Exch - swaps the numbers
*@p: first integer
*@q: second integer
*/
void Exch(int *p, int *q)
{
        int temp = *p;
        *p = *q;
        *q = temp;
}
/**
*QuickSort - Sorts the ints in order
*@a: An array 
*@low: lowest int
*@high: highest int
*/
void QuickSort(int a[], int low, int high)
{
        int i, j, key;
        if(low>=high)
        return;
        key=low;
        i=low+1; j=high;
        while(i<=j)
        {
                while ( a[i] <= a[key] )
                i=i+1;
                while ( a[j] >a[key] )
                j=j -1;
                if(i<j)
		{
                	Exch(&a[i], &a[j]); 
		}
        }
	Exch(&a[j], &a[key]);
        QuickSort(a, low, j-1);
        Exch(&a[j], &a[key]);
        QuickSort(a, low, j-1);
        QuickSort(a, j+1, high);
}
/**
*main - Entry point
*
*Return: always 0
*/
int main(void)
{
         int n, a[1000], k;
	clock_t et;
        double ts; 
        printf("\n Enter How many Numbers: ");
        scanf("%d", &n);
        printf("\nThe Random Numbers are:\n");
        for(k=1; k<=n; k++)
        {
                a[k]=rand(); printf("%d\t",a[k]);
        }
        ts = clock();
        QuickSort(a, 1, n);
        et = clock();
        ts = (double)(et-ts)/CLOCKS_PER_SEC;
	printf("\nSorted Numbers are:\n ");
        for(k=1; k<=n; k++)
        printf("%d\t", a[k]);
        printf("\nThe time taken is %e",ts);
	return (0);
}
