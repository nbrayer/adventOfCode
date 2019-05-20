//////////////////////////////////////////
//	Written by:	Noah Brayer	//
//	Last Modified:	2018/11/29	//
//	For:		Advent of Code	//
//////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{	if(--argc!=1)
	{	if(argc--)
			printf("\nToo many arguments\n");
		else
			printf("\nNot enough arguments\n");
		return(argc);
	}

	int num=0,nxt_i=0,sum=0;
	char nxt_c;

	FILE* file=fopen(argv[argc],"r");

	while(1)
	{	nxt_c=fgetc(file);
		nxt_i=atoi(&nxt_c);
		if(num==nxt_i)
			sum+=num;
		if(nxt_i)
			num=nxt_i;
		else
		{	rewind(file);
			nxt_c=fgetc(file);
			nxt_i=atoi(&nxt_c);
			if(num==nxt_i)
				sum+=num;
			break;
		}
	}
	printf("Total:\t%d\n",sum);

	return(0);
}
