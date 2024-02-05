#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	MPI_Init(NULL,NULL);
	int size;
	int rank;

	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	int num;
	
	if (rank==0)
	{
		printf("**Process 1**\n");
		printf("Enter the number:");
		scanf("%d",&num);

		MPI_Send(&num,1,MPI_INT,1,111,MPI_COMM_WORLD);	
		MPI_Send(&num,1,MPI_INT,2,111,MPI_COMM_WORLD);
		MPI_Send(&num,1,MPI_INT,3,111,MPI_COMM_WORLD);
	}
	else if (rank==1)
	{
		MPI_Recv(&num,1,MPI_INT,0,111,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("\n\n**Process 2**");
		int temp=1;
		for (int i = num; i > 0; i--)
		{
			temp*=i;
		}

		printf("%d factorial is %d\n",num,temp);
	}
	else if (rank==2)
	{
		MPI_Recv(&num,1,MPI_INT,0,111,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("\n\n**Process 3**\n");
		if (num%2==0)
		{
			printf("%d is a even number\n",num);
		}else{
			printf("%d is a odd number\n",num);
		}
	}
	else if (rank==3)
	{
		MPI_Recv(&num,1,MPI_INT,0,111,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("\n\n**Process 4**\n");
		for (int i = 0; i < num; ++i)
		{
			printf("ICT329\n");
		}
	}
	MPI_Finalize();
}