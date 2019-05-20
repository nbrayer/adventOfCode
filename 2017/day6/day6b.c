#include <stdio.h>
#include <stdlib.h>

void redist(int[],int);
int check(int[],int);

int main(int argc,char* argv[])
{	if(--argc!=1)
	{	if(argc-1)
			printf("\nError: Too many arguments\n");
		else
			printf("\nError: Not enough arguments\n");
		return(argc);
	}

	FILE* file=fopen(argv[argc],"r");

	int mem[16];
	int len=0;
	char* line=malloc(sizeof(char)*8);

	while(fgets(line,8,file)!=NULL)
	{	mem[len]=atoi(line);
		len++;
	}
int count=0;
	while(!check(mem,len))
	{	printf("\nmem:");
		for(int i=0;i<len;i++)
			printf("\t%d",mem[i]);
		redist(mem,len);
		count++;
	}

	printf("\nNumber of Redistributions: %d\n",count);

	return(0);
}

void redist(int mem[],int len)
{	int max=0;
	int pos;

	for(int i=0;i<len;i++)
	{	if(mem[i]>max)
			max=mem[i];
	}
//printf("\nmax: %d",max);
	for(int i=0;i<len;i++)
	{	if(mem[i]==max)
		{	pos=i+1;
			mem[i]=0;
			break;
		}	
	}
	while(max-->0)
	{	//printf("\npos: %d",pos);
		if(pos>=len)
			pos=0;
		mem[pos++]++;
	}
}

int check(int mem[],int len2)
{	static int seen[30000][16];
	static int len1=0;

	for(int i=0;i<len1;i++)
	{	for(int j=0;j<len2;j++)
		{	if(mem[j]!=seen[i][j])
				break;
			if(j==len2-1)
			{	printf("\nLength of Loop: %d",len1-i+1);
				return(1);
			}
		}
	}

	len1++;
	for(int i=0;i<len2;i++)
		seen[len1][i]=mem[i];

	return(0);
}
