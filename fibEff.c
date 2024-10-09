#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>

long limit = 0;

int main(int argc, char *argv[]) {
	// Get User Input 
	if (argc != 2)
	{
		printf("Improper input. Exiting.\n");
		return -1; 
	}
	
	limit = strtol(argv[1], NULL, 10);
	
	mpz_t res;
	mpz_init(res);
	
	clock_t start_time = clock();
	
	mpz_fib_ui(res, limit);
	
	clock_t end_time = clock();
	
	printf("Fibonacci Number %ld: ", limit);
   	mpz_out_str(stdout, 10, res);
   	printf("\n");

   	mpz_clear(res);

    double time_taken = ((double) end_time - start_time)  / CLOCKS_PER_SEC;
    printf("Calculation Time: %f seconds\n", time_taken);
}