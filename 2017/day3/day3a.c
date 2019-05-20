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

	int num=atoi(argv[argc]);
	int count=1;
	int len=0;
	int isOdd=0;
	int steps=0;

	for(;count<num;count+=len)
	{	switch(isOdd++%4)
		{	case(0):
				++len;
				++steps;
				break;
			case(1):
				++steps;
				break;
			case(2):
				++len;
				break;
			default:
				break;
				
		}
	}
	if((count-num)>(len/2))
	{	count-=(len+1);
		for(;++count<num;steps--);
	}
	else
		for(;count-->num;steps--);
		

	printf("\nNumber of steps:\t%d\n",steps);

	return(0);
}
