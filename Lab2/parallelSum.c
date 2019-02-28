#include <mpi.h>
#include <stdio.h>

int sum(int a[100])
{
	int i,result=0;
	for(i=0;i<100;i++)
	{
		result+=a[i];
	}
	return(result);
}

main(int argc, char** argv)
{
	int rank,size,i,j,k,localsum, finalsum;
	int arr[1000];
	MPI_Init(&argc,&argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int brr[1000/size];
	if(rank==0){
		
		for (i=0;i<1000;i++)
		{
			arr[i]= i+1;
		}
		for (j=1;j<size;j++)
		{
			MPI_Send(&arr[j*1000/size],1000/size,MPI_INT,j,j,MPI_COMM_WORLD);
		}
		localsum=sum(arr);
		finalsum=localsum;
		for(k=1;k<size;k++)
		{
			MPI_Recv(&localsum,1,MPI_INT,k,k,MPI_COMM_WORLD,&status);
			finalsum+=localsum;
		}
		printf("The final sum is %d.",finalsum);
	}
	else
	{

		MPI_Recv(brr,1000/size,MPI_INT,0,rank,MPI_COMM_WORLD,&status);
		localsum=sum(brr);
		printf("localsum from processor %d is %d\n",rank,localsum);
		MPI_Send(&localsum,1,MPI_INT,0,rank,MPI_COMM_WORLD);
	}
	MPI_Finalize();
}
