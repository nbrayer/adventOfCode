#include <stdio.h>
#include <stdlib.h>

int jumps(int[],int);

int main(int argc,char* argv[])
{	if(--argc!=1)
	{	if(argc-1)
			printf("\nError: Too many arguments\n");
		else
			printf("\nError: Not enough arguments\n");
		return(argc);
	}

	FILE* file=fopen(argv[argc],"r");

	int instr[1100];
	int len=0;
	char* line=malloc(sizeof(char)*8);

	while(fgets(line,8,file)!=NULL)
	{	instr[len]=atoi(line);
		len++;
	}

	int ans=jumps(instr,len);
	printf("\nNumber of Jumps: %d\n",ans);

	return(0);
}

int jumps(int instr[],int len)
{	int count=0;
	int pos=0;

	while(pos>=0&&pos<len)
	{	int jump=instr[pos];
		if(jump<3)
			instr[pos]++;
		else
			instr[pos]--;
		pos+=jump;
		count++;
	}

	return(count);
}
