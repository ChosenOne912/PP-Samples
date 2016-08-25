/**************************************************
OpenMP Helloworld program
***************************************************/

#include <iostream>
#include <stdlib.h>
#include <omp.h>
using namespace std;

int main (int argc, char* argv[])
{

    double wallTime1 = omp_get_wtime();

	  // Prompt user for correct usage if arguments are incorrect.
	  if (argc < 2){
	      cerr <<"Usage: ./program <Number of Threads>"<< endl;
	      return -1;
	  }

	  int thread_count = atoi(argv[1]);
	  #pragma omp parallel num_threads(thread_count)
	  {
		    int my_rank, num_thread;
		    my_rank = omp_get_thread_num(); //What thread am I?
		    num_thread = omp_get_num_threads(); //Get number of thread
	      //#pragma omp critical
		    cout << "Hello from " << my_rank << " of " << num_thread << endl;
	  }
	  return 0;
}
