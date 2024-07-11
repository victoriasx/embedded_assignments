// Include section
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Main program section
/**
 * This program takes a decimal number as argument,
 * and output the decimal number, its binary representation, and the number of 0s and 1s.
 * Part of the solution was inspired by PREPBYTES from https://www.prepbytes.com/blog/c-programming/c-program-to-convert-decimal-numbers-to-binary-numbers/
 */

// Function prototype
void convert_number_to_Binary(int number);
int check_number(char *input);

// Main function in the program
int main(int argc, char *argv[])
{
    // handle errors (including 2 cases)
    if (argc < 2) // error case 1: check the argument is empty
    {
        printf("You need to provide a number.\n");
    }
    else if (check_number(argv[1]) == 0) // error case 2: check the argument is not a number
    {
        printf("Your input is not valid. Pls. provide a number.\n");
    }
    // if there are no errors, convert the number from decimal to binary
    else
    {
        int number = atoi(argv[1]); // declare and initialize a int variable to store command-line argument after converting it from char to int.
        printf("Number: %d\n", number);
        convert_number_to_Binary(number); // convert the number to binary representation
    }

    // exit the program
    return 0;
}

// Binary convertion function with no return value
void convert_number_to_Binary(int number)
{
    int num_of_0 = 0,      // declare and initialize a counter for counting 0
        num_of_1 = 0,      // declare and initialize a counter for counting 1
        binary_result = 0, // declare and initialize the result in binary
        position = 1;      // declare and initialize the position of the int result, e.g., 132 -> 2 is at position 10^0, 3 is at position 10^1, 1 is at position 10^3.

    while (number != 0) // use a loop to keep dividing the number by 2 until the updated number is 0
    {
        if (number % 2 == 1) // check when the result of division is 1
        {
            ++num_of_1; // increment the num_of_1 counter by 1
        }
        else if (number % 2 == 0) // check when the result of division is 0
        {
            ++num_of_0; // increment the num_of_0 counter by 1
        }
        // The binary result is the sum of the previous result and the current result.
        // The current result is the remainder of the current number divided by 2 multiplied by position 10^x to add one digit.
        // For example, if the previous result was 10 and the current number is 2,
        // then the current result is 2 % 2 * 10^3 = 100, so the updated binary result is 10 + 100 = 110.
        binary_result += (number % 2) * position;
        number /= 2;    // divide the current number by 2 to update the current number
        position *= 10; // multiply the current position by 10 to prepare for calculating of the updated number
    }

    printf("Binary: 0b%d\n", binary_result);
    printf("Number of 0s: %d\n", num_of_0);
    printf("Number of 1s: %d\n", num_of_1);
}

int check_number(char *input)
{
    for (int i = 0; i < strlen(input); i++)
    {
        if (isdigit(input[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}