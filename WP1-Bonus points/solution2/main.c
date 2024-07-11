// Include section
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Main program section
/**
 * This program takes a decimal number as argument,
 * and output the decimal number, its binary representation, and the number of 0s and 1s.
 * The solution was inspired by the book 'C How to Program, Fifth Edition (oreilly.com)'.
 */

// Function prototype
int check_number(char *input);

// Main function in the program
int main(int argc, char *argv[])
{
    // handle errors (including 2 cases)
    if (argc < 2) // error case 1: check the argument is empty
    {
        printf("Error: No number provided. Please provide a number as a command line argument.\n");
    }
    else if (check_number(argv[1]) == 0) // error case 2: check the argument is not a number
    {
        printf("Error: Invalid number.\n");
    }
    // if there are no errors, convert the number from decimal to binary
    else
    {
        unsigned c;                     // declare and initialize bit counter
        unsigned int num_of_0 = 0;      // declare and initialize a counter for counting 0
        unsigned int num_of_1 = 0;      // declare and initialize a counter for counting 1
        int number = atoi(argv[1]);     // declare and initialize a int variable to store command-line argument after converting it from char to int.
        unsigned displayMask = 1 << 31; // define displayMask and left shift 31 bits

        printf("Number: %d\n", number);
        printf("Binary: 0b");

        // loop through bits
        for (c = 1; c <= 32; c++)
        {
            unsigned int bit_num = number & displayMask ? '1' : '0'; // use an unsigned int variable to temporarily store the after-masked bit result

            // get a 1 for bit result for the first time (according to the order: from leftmost bit to the rightmost bit),
            // the purpose of doing this is to skip all the leading 0s
            if (num_of_1 == 0 && bit_num == '1')
            {
                putchar(bit_num); // output the bit number 1
                num_of_1++;       // increment the num_of_1 counter by 1
            }
            else if (num_of_1 != 0) // when it is not the first time to get 1 as bit result (according to the order: from leftmost bit to the rightmost bit)
            {
                putchar(bit_num);   // output the bit number 0/1
                if (bit_num == '1') // when the bit result is 1
                {
                    num_of_1++; // increment the num_of_1 counter by 1
                }
                else if (bit_num == '0') // when the bit result is 0
                {
                    num_of_0++; // increment the num_of_0 counter by 1
                }
            }
            displayMask >>= 1; // right shift the displayMask with 1 position
        }
        putchar('\n'); // output a next line
        printf("Number of 0s: %d\n", num_of_0);
        printf("Number of 1s: %d\n", num_of_1);
    }

    // exit the program
    return 0;
}

// Check number function with 0/1 as return value:
// 0 -> false, i.e., input is not a number;
// 1 -> true, i.e., input is a number
int check_number(char *input)
{
    // loop through chars in the char array (i.e., input)
    for (int i = 0; i < strlen(input); i++)
    {
        if (isdigit(input[i]) == 0) // when the char at the current index is not a digit, then it is equal to 0(false)
        {
            return 0; // return 0 means that input is not a number
        }
    }
    return 1; // return 1 means that input is a number
}