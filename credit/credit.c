#include<stdio.h>

int countClumps(int arr1[], int m)
{
  int l = m;
  int current = -1, clump = 0;
  for(int i = 0; i < l - 1; i++)
  {
    if(arr1[i] == arr1[i + 1] && arr1[i] != current)
	{
       current = arr1[i];
       clump++;
    }
	else
	{
       if(arr1[i] != current)
	   {
          current = -1;
       }
    }
  }
  return clump;
}
int main()
{
    int arr1[] = {17, 42, 42, 42, 42, 7, 24, 24, 17, 54, 17};
    int arr_size = sizeof(arr1)/sizeof(arr1[0]);
    int i = 0;
   //------------- print original array ------------------
	printf("The given array is:  \n");
	for(i = 0; i < arr_size; i++)
		{
			printf("%d  ", arr1[i]);
		}
	printf("\n");
//-----------------------------------------------------------
    printf("The number of clumps in the array is:  %d\n", countClumps(arr1,arr_size));
    return 0;
}
