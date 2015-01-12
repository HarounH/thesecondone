/**
*/

#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <cstdlib>

#include <sys/time.h>
#include <time.h>


using namespace std;

const int bignum = 1000000000;
const int NUM_THREADS = 4;


struct sumParameters {
	
	int *a;
	long long l;
	long long u;
	long long* sum;

	sumParameters(int * rand, long long lower , long long upper , long long* finans )
	{
		a = rand;
		l = lower;
		u = upper;
		sum = finans;
		
	}
}; //Struct required to pass parameters to the thread utilizing function


void* summing( void* _args)
{
	// long sum =0;
	sumParameters* args = (sumParameters*) _args; //Assumes that args is a pointer to a struct. (in void* form)
	int* a = args->a ;
	long long lower = args->l;
	long long upper = args->u;
	long long* sum = args->sum;
	for ( int i= lower;i<upper;i++)
	{
		*sum += a[i]; // sum = f(threadID , sum , parameter)
	}
}


int main(int argc , char** argv)

{
	static int val=0;

	int * a =new int [bignum];

	for (int i=0;i<bignum;i++)
		a[i]=i+1;

	long long * sumarr = new long long [NUM_THREADS];
	long long finsum=0;
	for (int i=0;i<NUM_THREADS;i++)
		sumarr[i]=0;

	for (long long i=0;i<NUM_THREADS;i++)
	{
		 sumParameters* summationParam = new sumParameters( a , i*bignum/NUM_THREADS , (i+1)*bignum/NUM_THREADS , &sumarr[i]); // creating the parament.
		 int rc = pthread_create(&threads[i], NULL, summing , (void*) summationParam); //void* casting a struct-pointer because the function assumes that the argument is a struct pointer.
		 if (rc){ //Error checking
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
     	}
	}

	for (int i=0;i<NUM_THREADS;i++)
	{
		int rc = pthread_join(threads[i], NULL);
	    if (rc) {
         printf("ERROR; return code from pthread_join() is %d\n", rc);
         exit(-1);
         }
	}

	for (int i=0;i<NUM_THREADS;i++)
	{
		finsum+=sumarr[i];
	}

	cout<<finsum<< "\n";
	return 0;
}