#include <mpi.h>
#include <stdio.h>
main(int argc, char **argv)
{
        MPI_Init(&argc, &argv);
        printf("Hello world!\n");
        MPI_Finalize();
}
