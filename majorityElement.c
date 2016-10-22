#include <stdlib.h>
#include <stdio.h>
int comparator(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
int majorityElement(int *nums, int numsSize)
{
	qsort(nums,numsSize,sizeof(int),comparator);
	return nums[numsSize/2];
}

int main()
{
	int nums[3] = {3,2,3};
	int result = majorityElement(nums,3);
	printf("result:%d\n",result);
	return 0;
}
