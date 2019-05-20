//////////////////////////////////////////
//	Written by:	Noah Brayer	//
//	On:				//
//	For:		Advent of Code	//
//////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[])
{	if(--argc!=1)
	{	if(argc--)
			printf("\nError: Too many arguments\n");
		else
			printf("\nError: Not enough arguments\n");
		return(argc);
	}

	FILE* file=fopen(argv[argc],"r");
	
	char* line_s=malloc(sizeof(char)*1024);
	char* num_s=malloc(sizeof(char)*8);
	int* line_i=malloc(sizeof(int)*128);
	int num_i;
	int sum=0;

	while(fgets(line_s,1024,file)!=NULL)
	{	int len=0;
		
/*		num_s=strtok(line_s," \t");
		do
		{	num_i=atoi(num_s);
			line_i[len++]=num_i;
		}while((num_s=strtok(NULL," \t"))!=NULL);
*/
/*		for(line_i[len++]=atoi(strtok(line_s,"\t"));(num_s=strtok(NULL,"\t"))!=NULL;line_i[len++]=atoi(num_s))//;
			printf("%d\t",line_i[len-1]);
			printf("\n");
*/

		for(int i=0;i<len;i++)
		{	for(int j=0;j<len;j++)
			{	if((j!=i)&&!(line_i[i]%line_i[j]))
					sum+=(line_i[i]/line_i[j]);
			}
		}
	}
	printf("Checksum:\t%d\n",sum);

	return(0);
}
