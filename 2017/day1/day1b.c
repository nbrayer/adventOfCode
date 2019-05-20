//////////////////////////////////////////
//	Written by:	Noah Brayer	//
//	Last Modified:	2018/11/29	//
//	For:		Advent of Code	//
//////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{	if(--argc!=1)
	{	if(argc++)
			printf("\nToo many arguments\n");
		else
			printf("\nNot enough arguments\n");
		return(argc);
	}

	int len=0,sum=0;
	int num_i=0,hlf_i=0;
	int numPos,hlfPos;
	char num_c,hlf_c;

	FILE* fileN=fopen(argv[argc],"r");
	FILE* fileH=fopen(argv[argc],"r");

	while(fgetc(fileN)!=EOF)
	{	len++;	// find out how long the captcha is
	}
	rewind(fileN);	// set 1st file to read from beginning
	len--;	// for some reason, this while loop counts one too far
	hlfPos=len/2;	// find halfway
	fseek(fileH,hlfPos,SEEK_SET);	// set 2nd file to read from there

	for(int i=0;i<len;i++)
	{	if(i==(len/2))	// when 2nd file reaches the end,
			rewind(fileH);	// go back to the beginning

		num_c=fgetc(fileN);
		num_i=num_c-48;
		hlf_c=fgetc(fileH);
		hlf_i=hlf_c-48;

		if(num_i==hlf_i)
			sum+=num_i;
	}
	printf("Total:\t%d\n",sum);

	return(0);
}
