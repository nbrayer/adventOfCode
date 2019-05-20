#include <ctype.h>
#include <math.h>
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

	char c;
	int nlines=0;
	int len=0,maxlen;

	while(!feof(file))	// counts lines and finds the maximum length of a line
	{	c=fgetc(file);
		len++;
		if(c=='\n')
		{	nlines++;
			if(len>maxlen)
				maxlen=0;
			len=0;
		}
	}
printf("\nMax length: %d\n",maxlen);
	rewind(file);

	int checksum[nlines];
	char* line[nlines];
	char* common=malloc(sizeof(char)*maxlen);
	int lflag1,lflag2,cflag=0;

	for(int i=0;i<nlines;i++)
	{	line[i]=malloc(sizeof(char)*(maxlen+1));
		fgets(line,maxlen+1,file);
		char c;


		/* generate quick checksum */
		checksum[i]=0;
		while((c=*(line[i]++))!='\0')
		{	if(!islower(c))
			{	printf("\nInvalid input: %c\n",c);
				return(-1);
			}
printf("\nchar: %c",c);
			checksum[i]+=c;
		}
printf("\nChecksum: %d\n",checksum[i]);

		/* compare checksums and strings */
		for(int j=i;j>0;j--)
		{	if(abs(checksum[i]-checksum[j])<26)
			{	cflag=0;
				int k;
				for(k=0;(*(line[i]+k)!='\0')&&(*(line[j]+k)!='\0');k++)
				{	if((*(line[i]+k))!=(*(line[j]+k)))
					{	if(cflag)
							break;
						else
							cflag=k+1;
					}
					else
					{	*(common+k)=*(line[i]+k);
					}
				}
				if((*(line[i]+k)=='\0')&&(*(line[j]+k)=='\0'))
				{	lflag1=i;
					lflag2=j;
					break;
				}	
			}
		}
	}

	printf("\nCommon letters: %s\n",common);
	fclose(file);

	return(0);
}
