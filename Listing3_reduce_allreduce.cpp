#define _USE_MATH_DEFINES
#include <mpi.h>
#include <cmath>
#include <iostream>


//Program to sum Pi using Leibniz formula:
// Pi = 4 * Sum_n ( (-1)**n/(2*n+1) )
double listing3_sum_pi_allreduce()
{
	double returnvalue = 0.0;;
	int max_n = 10000;
	double sum = 0;
	MPI_Init(NULL, NULL);
	int num_procs;
	int rank;
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	for (int n = rank; n < max_n; n += num_procs)
	{
		double temp = 1.0 / (2.0*((double)(n)) + 1.0);
		if (n % 2 == 0) { // n is even
			sum += temp;
		}
		else { // n is odd
			sum -= temp;
		}
	}

	double global_sum;
	MPI_Allreduce(&sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
	returnvalue = 4.0*global_sum;

	MPI_Finalize();

	return returnvalue;


}