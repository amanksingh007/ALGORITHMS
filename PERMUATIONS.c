// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
#include<math.h>
 
/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}
 
/* Driver program to test above functions */
int main()
{
    char str[] = "12";
    int n = strlen(str);
    permute(str, 0, n-1);
	//printf("\n%f\n",pow(2,75));
	printf("%lld",1000000000010101011);
    return 0;
}
