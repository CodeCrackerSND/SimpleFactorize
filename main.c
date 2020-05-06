/****************************************************************************
 *                                                                          *
 * File    : main.c                                                         *
 *                                                                          *
 * Purpose : Console mode (command line) program.                           *
 *                                                                          *
 * History : Date      Reason                                               *
 *           00/00/00  Created                                              *
 *                                                                          *
 ****************************************************************************/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdint.h>

// This method check if number is prime
unsigned int IsPrime(unsigned int n)
{
if (n<=3) return n>1;
else if ((n&1)==0) return 0;  // number is divisible by 2 if last bit is 0

for (unsigned int i=3;i<=7;i+=2)  // we should check if numbers are divisible by 3,5,7
if (n!=i&&(n%i)==0) return 0;

unsigned int SquareRoot = (int)sqrt((double)n);  // in PellesC is not necesary to do any casting, in VS yes

for (unsigned int i=11;i<=SquareRoot;i+=30)
{
if ((n % i)==0) return 0;
if ((n % (i+2))==0) return 0;
if ((n % (i+6))==0) return 0;
if ((n % (i+8))==0) return 0;
if ((n % (i+12))==0) return 0;
if ((n % (i+18))==0) return 0;
if ((n % (i+20))==0) return 0;
if ((n % (i+26))==0) return 0;
}

return 1;
}

/****************************************************************************
 *                                                                          *
 * Function: main                                                           *
 *                                                                          *
 * Purpose : Main entry point.                                              *
 *                                                                          *
 * History : Date      Reason                                               *
 *           00/00/00  Created                                              *
 *                                                                          *
 ****************************************************************************/

int main(int argc, char *argv[])
{

	printf("Prime numbers are:\r\n");
	for (int i=0;i<200;i++)
	if (IsPrime(i))
	printf("%d\r\n", i);

    return 0;
}


void TestSpeeed()
{
	clock_t time_req;
	time_req = clock();

	unsigned int Number = 0xFFFFFFFB;
	int isPrime = 0;

	isPrime = IsPrime(5);
	for (int i=0;i<0xFFF;i++)
	{
	isPrime = IsPrime(Number);
	}

    time_req = clock() - time_req;
	printf("IsPrime() took %f seconds\r\n",(float)time_req/CLOCKS_PER_SEC);
}
