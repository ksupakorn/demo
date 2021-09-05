#include <stdio.h>


int test_pointer() {

	double total = 500.0;
	int count = 34;
	double average = total / count;
	printf("The average of %d units totaling %.1f is %.2f\n",
		count, total, average);

	// Now let's reproduce some of that work with pointers
	double* total_ptr = &total;
	int* count_ptr = &count;
	printf("total_ptr is the same as the address of total:\n");
	printf("  total_ptr %p == %p &total\n", total_ptr, &total);

	// We can manipulate the value at the end of a pointer
	// with the '*' prefix (dereferencing)
	printf("The current total is: %.1f\n", *total_ptr);
	// Let's pretend we forgot two units and correct our count:
	*count_ptr += 2;
	average = *total_ptr / *count_ptr;
	printf("The corrected average of %d units totaling %.1f is %.2f\n",
		count, total, average);
}


void test_array_pointer() {
	char name[] = "a.c. Programmer";             
	printf("Before manipulation: %s\n", name);
	

	*name = 'A';
	*(name + 2) = 'C';
	printf("After manipulation: %s\n", name);
}



struct transaction {
	double amount;
	int day, month, year;
};




void processTransaction() {
	int count;
	char message[] = "Your money is safe with us!";
	struct transaction bill;

	bill.amount = 56.75;
	bill.month = 7;
	bill.day = 15;
	bill.year = 2021;

	struct transaction deposit = { 200.00, 6, 20, 2021 };

	printf("Your deposit of $%0.2f was accepted.\n", deposit.amount);
	printf("Your bill is due on %d/%02d\n", bill.month, bill.day);

	bill.amount = bill.amount + bill.amount * 0.05;

	printf("Our final bill: $%0.2f\n", bill.amount); // $59.59
	printf("Our deposit: $%0.2f\n", deposit.amount); // $200.00

}


void test_pointer_to_struct() {

	struct transaction tmp = { 68.91, 8, 1, 2020 };
	struct transaction* payment;
	struct transaction* withdrawal;

	payment = &tmp;
	withdrawal = malloc(sizeof(struct transaction));

	withdrawal->amount = -20;
	(*withdrawal).amount = -20;

}


void printTransaction1(struct transaction tx) {
	printf("%2d/%02d/%4d: %10.2f\n", tx.month, tx.day, tx.year, tx.amount);
}

void printTransaction2(struct transaction* ptr) {
	printf("%2d/%02d/%4d: %10.2f\n",
		ptr->month, ptr->day, ptr->year, ptr->amount);
}

void testPrintTransaction1() {

	struct transaction bill = { 56.75, 7, 15, 2021 };
	struct transaction deposit = { 200.00, 6, 20, 2021 };

	printTransaction1(bill);
	printTransaction1(deposit);
}

void testPrintTransaction2() {

	struct transaction tmp = { 68.91, 8, 1, 2020 };
	struct transaction* payment;
	struct transaction* withdrawal;

	

	payment = malloc(sizeof(struct transaction));
	payment->amount = 56.75;
	payment->month = 7;
	payment->day = 15;
	payment->year = 2021;

	withdrawal = malloc(sizeof(struct transaction));
	withdrawal->amount = 10.00;
	withdrawal->month = 5;
	withdrawal->day = 1;
	withdrawal->year = 2021;

	printTransaction2(&tmp);
	printTransaction2(payment);
	printTransaction2(withdrawal);

}




