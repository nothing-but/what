#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>

long limit = 0;

int main(int argc, char *argv[]) {
	// Get User Input 
	if (argc < 2 || argc > 3)
	{
		printf("Improper input. Exiting.\n");
		return -1; 
	}
	
	//"verbose" command line option
	_Bool verbose = argc == 3 && argv[2][0] == '-' && argv[2][1] == 'v';
	
	limit = strtol(argv[1], NULL, 10);
	
	mpz_t res;
	mpz_init(res);
	
	mpz_fib_ui(res, limit);

	if(verbose) {
	  printf("Fibonacci Number %ld: ", limit);
	}
	
   	mpz_out_str(stdout, 10, res);
   	printf("\n");

   	mpz_clear(res);
}