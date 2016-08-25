
#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <stdlib.h>

using namespace std;
void* hello(void *rank);
int thread_count;

int main(int argc, char* argv[])
{
    long thread;
	  pthread_t* thread_handles;
    thread_count=strtol(argv[1], NULL, 10);

    thread_handles = (pthread_t*) malloc(thread_count*sizeof(pthread_t));

    for (thread = 0; thread < thread_count; thread++)
    {
        pthread_create(&thread_handles[thread], NULL, hello, (void*)thread);
    }


   for(thread = 0; thread < thread_count; thread++)
   {
       pthread_join(thread_handles[thread], NULL);
   }

   free(thread_handles);

   return 0;
}

void *hello(void *rank)
{
    long my_rank = (long) rank;
	  cout << "Hello from " << my_rank << " of " << thread_count << endl;
}
