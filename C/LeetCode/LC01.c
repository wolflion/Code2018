int* twoSum(int* nums, int numSize, int target){
	int *val = (int*)malloc(2*sizeof(int));
	for (int i = 0; i < numSize; i++)
	{
		for (int j = i+1; j < numSize &&j!=i; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				val[0] = i;
				val[1] = j;
			}
		}
	}
	return val;
}
