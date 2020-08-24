
#include <mpi.h>
#include <iostream>

void listing2() {
	int commsize;
	int rank;
	int length;
	char name[80];

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &commsize);
	MPI_Get_processor_name(name, &length);

	int tag = 30;
	if (rank == 0) {
		//Specific send code for process 0
		double send_buffer[2] = { 100.0, 200.0 };
		MPI_Send(send_buffer, 2, MPI_DOUBLE, 1, tag, MPI_COMM_WORLD);
	}

	if (rank == 1)
	{
		//Specific receive code for process 1
		double recv_buffer[2] = { 0.0, 0.0 };
		MPI_Status* status = new MPI_Status;
		MPI_Recv(recv_buffer, 2, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, status);
		std::cout << recv_buffer[0] << "\n";
		std::cout << recv_buffer[1] << "\n";
		delete status;
	}
	MPI_Finalize();
}