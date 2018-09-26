#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    int *res=(int *)malloc(sizeof(int)*2);
    *returnSize=2;
    int i,min=area-1,L=area;
    for(i=2;i<sqrt(area)+1;i++)
    {
    	if(area%i==0)
    	{
    		if((area/i-i)<min)
    		{
    			min=(area/i-i);
    			L=area/i;
			}
		}
	}
	if(L>area/L)
		*res=L;
	else *res=area/L;
	*(res+1)=area/(*res);
	return res;
}
int main(int argc, char **argv)
{
    
    return 0;
}