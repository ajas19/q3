#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	MPI_Init(NULL,NULL);
	int rank;
	int size;

	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	char word[100];

	if (rank==0)
	{
		char word[100];
		printf("Enter the word:");
		scanf("%s",word);

		MPI_Send(&word,100,MPI_CHAR,1,111,MPI_COMM_WORLD);

		
	}else if (rank==1)
	{
		char receiveWord[100];
		MPI_Recv(&receiveWord,100,MPI_CHAR,0,111,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		int count=0;
		for (int i = 0; i < strlen(receiveWord); ++i)
		{
			if (isalpha(receiveWord[i]))
			{
				count++;
			}
		}

		MPI_Send(&count,1,MPI_INT,2,222,MPI_COMM_WORLD);
	}else if(rank==2)
	{
		int rCount;
		MPI_Recv(&rCount,1,MPI_INT,1,222,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

		printf("Entered word number of letters: %d\n",rCount);
	}

	MPI_Finalize();
}