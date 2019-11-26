#include <stdio.h>
#include <limits.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


void program2_6(void) {

	float radius = 0.0f;                  // The radius of the table
	float diameter = 0.0f;                // The diameter of the table
	float circumference = 0.0f;           // The circumference of the table
	float area = 0.0f;                    // The area of the table
	float Pi_3 = 3.14159265f;


	printf("\nThe value of Pi is %.2f\n", Pi_3);

	int number = INT_MAX;

	size_t size = sizeof(int);

	enum Weekday { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
	enum Weekday today = Wednesday;


	_Bool _valid = 1;                            // Boolean variable initialized to true
	bool valid = true;         // Boolean variable initialized to true
}


void program3_4(void)
{
	char letter = 0;                          // Stores a character

	printf("Enter an uppercase letter:");     // Prompt for input
	letter = 'A';

	// Check whether the input is uppercase
	if (letter >= 'A')                         // Is it A or greater?
		if (letter <= 'Z')                       // and is it Z or lower?
		{                                       // It is uppercase
			letter = letter - 'A' + 'a';          // Convert from upper- to lowercase
			printf("You entered an uppercase %c\n", letter);
		}
		else                                    // It is not an uppercase letter
			printf("Try using the shift key! I want a capital letter.\n");




}


void program4_1(void)
{


	for (int count = 1; count <= 10; ++count)
	{
		printf("  %d", count);
	}

}


void program5_1(void)
{


	int data[5];
	for (int i = 0; i < 5; ++i)
	{
		data[i] = 12 * (i + 1);
		printf("data[%d] address: %p  contents: %d\n", i, &data[i], data[i]);

		//data[0] address: 000000D494F6F5F8  contents : 12
		//data[1] address : 000000D494F6F5FC  contents : 24
		//data[2] address : 000000D494F6F600  contents : 36
		//data[3] address : 000000D494F6F604  contents : 48
		//data[4] address : 000000D494F6F608  contents : 60


	}

}


//String and Text
void program6_1(void)
{



	//printf("This is a string.");
	//printf("This is on\ntwo lines!");
	//printf("For \" you write \\\".");

	//const char message[] = "The end of the world is nigh.";
	//printf("\nThe message is: %s", message);

	char str[][70] = {
				  "Computers do what you tell them to do, not what you want them to do.",
				  "When you put something in memory, remember where you put it.",
				  "Never test for a condition you don't know what to do with.",
	};
	unsigned int count = 0;                              // Length of a string
	unsigned int strCount = sizeof(str) / sizeof(str[0]);  // Number of strings
	printf("There are %u strings.\n", strCount);

	//char b[] = str[1];


	//printf("%s", str[0]);
	//printf("%s", str[0][0]);

	// find the lengths of the strings
	for (unsigned int i = 0; i < strCount; ++i)
	{
		count = 0;
		while (str[i][count])
			++count;

		printf("The string:\n    \"%s\"\n contains %u characters.\n", str[i], count);
	}

	int x = 1;

#if defined __STDC_LIB_EXT1__
	printf("Optional functions are defined.\n");
#else
	printf("Optional functions are not defined.\n");
#endif

}

//strcpy_s 
void program6_2(void)
{

	char source[] = "Only the mediocre are always at their best.";
	char destination[50];
	if (strcpy_s(destination, sizeof(destination), source))
		printf("An error occurred copying the string.\n");


	printf("%s", destination);




}


//strcat_s
void program6_3(void)
{


	char str1[50] = "To be, or not to be, ";
	char str2[] = "that is the question.";
	int retval = strcat_s(str1, sizeof(str1), str2);
	if (retval)
		printf("There was an error joining the strings. Error code = %d", retval);
	else
		printf("The combined strings:\n%s\n", str1);


}


//Searching a String for a Substring
void program6_4(void)
{


	char text[] = "Every dog has his day";
	char word[] = "dog";
	char* pFound = NULL;
	pFound = strstr(text, word);

	printf("%s", pFound);

}

// TOKENIZING A STRING
void program6_5() {


	char delimiters[] = " \".,;:!?)(";       // Prose delimiters
	char buf[100];                           // Buffer for a line of keyboard input
	char str[1000];                          // Stores the prose to be tokenized
	char* ptr = NULL;                        // Pointer used by strtok_s()
	str[0] = '\0';                           // Set 1st character to null

	size_t str_len = sizeof(str);
	size_t buf_len = sizeof(buf);
	printf("Enter some prose that is less than %zd characters.\n"
		"Terminate input by entering an empty line:\n", str_len);


	printf("The words in the prose that you entered are:\n", str);

	// Find and list all the words in the prose
	unsigned int word_count = 0;
	char* pWord = strtok_s(str, &str_len, delimiters, &ptr);  // Find 1st word
	if (pWord)
	{
		do
		{
			printf("%-18s", pWord);
			if (++word_count % 5 == 0)
				printf("\n");
			pWord = strtok_s(NULL, &str_len, delimiters, &ptr);    // Find subsequent words
		} while (pWord);                                           // NULL ends tokenizing
		printf("\n%u words found.\n", word_count);
	}
	else
		printf("No words found.\n");

}

//Converting Strings to Numerical Values
void program6_6() {

	char value_str[] = "98.4";
	double value = atof(value_str);         // Convert string to floating-point

	char value_str2[] = "98";
	int value2 = atoi(value_str2);         // Convert string to floating-point

	char value_str2_1[] = "98.5";
	int value2_1 = atoi(value_str2_1);

	printf("%u", value2_1);

	int x = 1;


}


void program6_7() {


	int number = 0;                 // A variable of type int initialized to 0
	int* pnumber = NULL;            // A pointer that can point to type int

	number = 10;
	printf("number's address: %p\n", &number);               // Output the address
	printf("number's value: %d\n\n", number);                // Output the value

	pnumber = &number;              // Store the address of number in pnumber

	printf("pnumber's address: %p\n", (void*)& pnumber);      // Output the address
	printf("pnumber's size: %zd bytes\n", sizeof(pnumber));  // Output the size
	printf("pnumber's value: %p\n", pnumber);                // Output the value (an address)
	printf("value pointed to: %d\n", *pnumber);              // Value at the address

}

void program6_8() {

	char board[3][3] = {
					 {'1','2','3'},
					 {'4','5','6'},
					 {'7','8','9'}
	};

	// List all elements of the array
	for (int i = 0; i < 9; ++i)
		printf(" board: %c\n", *(*board + i));




}





int sum(int x, int y)
{
	return x + y;
}

int product(int x, int y)
{
	return x * y;
}

int difference(int x, int y)
{
	return x - y;
}


void program9_1() {

	int a = 10;                         // Initial value for a
	int b = 5;                          // Initial value for b
	int result = 0;                     // Storage for results

	int (*pfun)(int, int);              // Function pointer declaration

	pfun = sum;                         // Points to function sum()
	result = pfun(a, b);                // Call sum() through pointer
	printf("pfun = sum             result = %2d\n", result);

	pfun = product;                     // Points to function product()
	result = pfun(a, b);                // Call product() through pointer
	printf("pfun = product         result = %2d\n", result);

	pfun = difference;                  // Points to function difference()
	result = pfun(a, b);                // Call difference() through pointer
	printf("pfun = difference      result = %2d\n", result);

}