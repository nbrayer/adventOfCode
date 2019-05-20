#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[])
{	if(--argc!=1)
	{	printf("\nIncorrect number of arguments\n");
		return(-1);
	}

	char* filename=argv[argc];
	FILE* file=fopen(filename,"r");

	int dcount=0,tcount=0;
	int checksum;
	char* line=malloc(sizeof(char)*30);

	while(fgets(line,30,file)!=NULL)
	{	char acount[26];
		/* initialize alphabet count */
		for(int i=0;i<26;i++)
		{	acount[i]=0;
		}

		char c;
		/* count letters */
		while((c=*(line++))!='\n')
		{	if(!islower(c))
			{	printf("\nInvalid input\n");
				return(-1);
			}
			acount[c-97]++;
		}

		/* check for a double */
		for(int i=0;i<26;i++)
		{	if(acount[i]==2)
			{	dcount++;
				break;
			}
		}
		/* check for a triple */
		for(int i=0;i<26;i++)
		{	if(acount[i]==3)
			{	tcount++;
				break;
			}
		}
	}

	checksum=dcount*tcount;
	printf("\nChecksum: %d\n",checksum);
	fclose(file);

	return(0);
}
