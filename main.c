#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int number;
	int primes = 0;
	printf("Enter a number above 1 (Below 10000 is recommended for lower runtime) : ");
	// Take input and see if input returns an error
	if (scanf("%d", &number) != 1) {
		// If input returns an exit code other than 1, move stdin pointer to the end then restart
		fseek(stdin, 0, SEEK_END);
		main();
		return 0;
	}
	// Ask again if input is below 1 or lower
	if (number < 2) {
		main();
		return 0;
	}
	// Begin a loop that goes through all of the numbers between 2 and the selected number one by one
	for (int i = 2; i < number+1;i++) {
		// Send every number to the function primeCheck to see if the number is a prime
		if (primeCheck(i) == 0) {
			// If the number is a prime, print it and att to the total amount of primes
			printf("%d is Prime\n", i);
			primes++;
		}
	}
	// Confirm to the user that the calculations are finished and tell them how many numbers were prime in their selected range
	printf("Those are all the %d primes between 1 and %d! Press Q to exit or any key to continue.\n", primes, number);
	// If the user presses any key except q the program will start over, if they press q it will exit
	if (tolower(getch()) != 'q')
		main();
	printf("\nPress any key to continue...\033[30m");
	return 0;
}

int primeCheck(int i) {
	// Start a new loop that goes through all numbers between 2 and i-1
	for (int j = 2; j < i; j++) {
		// If i is dividable by j, return 1 (not prime) 
		if (i % j == 0) {
			return 1;
		}
	}
	// If the loop finishes without returning 1, return 0 (prime)
	return 0;
}