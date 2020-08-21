#include <mpi.h>
#include <iostream>
// basic printing of rank
void listing1() {
	int commsize;
	int rank;
	int length;
	char name[80];

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &commsize);
	MPI_Get_processor_name(name, &length);
	std::cout << "Hello MPI from rank " << rank << " of " << commsize << " processors on " << name << "\n";
	MPI_Finalize();
}