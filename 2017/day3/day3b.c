//////////////////////////////////////////
//	Written by:	Noah Brayer	//
//	On:				//
//	For:		Advent of Code	//
//////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{	if(--argc!=1)
	{	if(argc-1)
			printf("\nError: Too many arguments\n");
		else
			printf("\nError: Not enough arguments\n");
		return(argc);
	}

	int goal=atoi(argv[argc]);

	int storage[100];
	for(int i=0;i<100;storage[i++]=0);
	storage[0]=1;

	int corner=0;
	int len=0;
	int i;
	int isOdd=0;
	for(i=0;i<30;i++)
	{	
printf("\nCount:\t%d\t",i+1);
printf("\n\tStart:\t%d\t%d\t%d\t%d\t%d\n\t",corner+1,len,i+1,storage[i],(4-(isOdd%2)));
		if((i-1)>=0)
			storage[i]+=storage[i-1];
		if(((corner-i)==(len-1))&&((i-2)>=0))
				{	storage[i]+=storage[i-2];
printf("special\n\t");
				}
		int test=i-(4-(isOdd%2))*len;
		if(i>2)
		switch(corner-i)
		{	default:
printf("1\t");
				if(((test+4)>=0)&&!((corner-i)==(len-1)))
				{	storage[i]+=storage[test+4];
printf("%d\t",storage[test+4]);				
				}
			case(1):
printf("2\t");
				if((test+3)>=0)
				{	storage[i]+=storage[test+3];
printf("%d\t",storage[test+3]);				
				}
			case(0):
printf("3\t");
				if((test+2)>=0)
				{	storage[i]+=storage[test+2];
printf("%d\t",storage[test+2]);				
				}
		}
		
		if(corner==i)
		{	len+=(++isOdd%2);
			corner+=len;
		}
printf("\n\tEnd:\t%d\t%d\t%d\t%d\t%d",corner+1,len,i+1,storage[i],(4-(isOdd%2)));
	}
	for(int j=0;j<i;j++)
	{	printf("\n%d:\t%d",j+1,storage[j]);
	}
	printf("\nFirst value larger than goal:\t%d\n",storage[i-1]);

	return(0);
}
