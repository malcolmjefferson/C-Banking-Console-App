#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Will allow the user to input an amount of money that they want to add to their bank account
//Will also allow the user to query for how much money is in their bank account
//Want to turn into a very very secure banking console app... We'll see how that goes.

void DepositFunc(int *pdeposit, int *pbalance);
void CheckBalance(int *pbalance);

//Function that will handle deposits
void DepositFunc(int *deposit, int *balance) {
	printf("\nEnter the amount that you want to deposit: ");
	fflush(stdout);
	scanf_s("%d", deposit);
	getchar();
	//works the same as adding to the actual value of balance because *balance is a dereferenced pointer to address
	//where actual balance variable is stored
	*balance += *deposit;
	printf("\n%d has been deposited into your account.", *deposit);
	fflush(stdout);
}

//Function that will handle checking of the balance
void CheckBalance(int *balance) {
	printf("\nYour balance is: %d", *balance);
	fflush(stdout);
}

int main() {
	int deposit = 0;
	int balance = 0;
	char userChoice[20];
	//pointers for deposit and balance. Will be used to pass by reference
	int * pdeposit = &deposit;
	int * pbalance = &balance;

	//initial query and deposit
	printf("Enter the amount that you want to deposit: ");
	//flush stdout buffer so no strings bump into each other
	fflush(stdout);
	scanf_s("%d", pdeposit);
	//getchar to capture the newline on the end from pressing the enter key
	getchar();
	balance += deposit;
	printf("\n%d has been deposited into your account.\n",deposit);
	fflush(stdout);

	//will run as long as the user doesn't quit
	while (1)
	{
		printf("\nWould you like to make another deposit, check your balance, or quit? ");
		fflush(stdout);
		//gets user input from stdin
		fgets(userChoice, sizeof(userChoice), stdin);
		//removes the newline from the end of the string and replaces it with a null character
		userChoice[strlen(userChoice) - 1] = '\0';
		//compares the strings, if eq 0 then they are the same
		if (strncmp(userChoice, "make deposit",sizeof(userChoice)) == 0) {
			DepositFunc(pdeposit, pbalance);
		}
		else if (strncmp(userChoice, "check balance", sizeof(userChoice)) == 0) {
			CheckBalance(pbalance);
			printf("\n%d", balance);
		}
		else if(strncmp(userChoice, "quit", sizeof(userChoice)) == 0) {
			exit(0);
		}
		else {
			printf("Try again...\n");
			fflush(stdout);
		}
	}
	return 0;
}