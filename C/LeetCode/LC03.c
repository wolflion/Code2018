int lengthOfLongestSubstring(char* s) {
	char *t=s;                           
	int max=0,i=0,j;                     
	while(*(s+i)!='\0')
	{  
		int a[128]={0};                  
		j=i+1;
		while(*(t+j)!='\0')
		{
			if(a[*(t+j)]==0&&*(s+i)!=*(t+j))
			{
				a[*(t+j)]=1;
				j++;
				max=j-i>max?j-i:max;

			}
			else
			{
				max=j-i>max?j-i:max;
				i++;
				break;
			}
		}
		max=j-i>max?j-i:max;
		if(*(t+j)=='\0')      
			return max;
	}
	return max;
}
