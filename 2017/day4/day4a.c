//////////////////////////////////////////
//	Written by:	Noah Brayer	//
//	On:		2018/08/07	//
//	For:		Advent of Code	//
//////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValid(char*[],int);
int myStrCmp(char*,char*);

int main(int argc,char* argv[])
{	if(--argc!=1)
	{	if(argc-1)
			printf("\nError: Too many arguments\n");
		else
			printf("\nError: Not enough arguments\n");
		return(argc);
	}

	FILE* file=fopen(argv[argc],"r");

	char* line=malloc(sizeof(char)*1024);
	char* words[32];

	int count=0;

	while(fgets(line,1024,file)!=NULL)
	{	int i=0;
		words[i]=malloc(sizeof(char)*32);
		words[i++]=strtok(line," ");
		while((words[i++]=strtok(NULL," "))!=NULL)
			words[i]=malloc(sizeof(char)*32);
		if(isValid(words,i-1))
			count++;
	}

	printf("\n%d passphrases are valid\n",count);

	return(0);
}

int isValid(char* words[],int num)
{	for(int i=0;i<num;i++)
		for(int j=i+1;j<num;j++)
			if(!myStrCmp(words[i],words[j]))
				return(0);
	return(1);
}

int myStrCmp(char* s1,char* t1)
{	char* s=s1;
	char* t=t1;
	
	while((*s!='\0')&&(*t!='\0'))
	{	if(*(s++)!=*(t++))
			return(1);
	}
	if((*s!='\0')||(*t!='\0'))
	//if(*s!=*t)
	{printf("\n%s\t%s\t%c\t%c\t%c\t%c",s1,t1,*s,*--s,*t,*--t);
		return(1);
	}
	else
		return(0);
}
