/* ----------------------------- Include section ---------------------------- */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ------------------------------ Define macro ------------------------------ */
#define MAX 10

/* -------------------------- Function declaration -------------------------- */
int validate_input(char *input, int *counter);
void permute(char *str, int start, int end, char **output);
void swap(char *m, char *n);
int factorial(int str_len);

/* -------------------------- Main program section -------------------------- */
/**
 * This program prints all permutations of a given string using pointers.
 * The string should be provided as an argument to your program.
 * The limit of the number of characters in the input is 10.
 * The program should store all the permutations in a large array.
 *
 * Note: This permutation solution is inspired by "Permutations of given String" from geeksforgeeks
 * link: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
 *
 */

// Main function
int main(int argc, char **argv)
{
    int counter = 0;                                        // define a counter to count the number of characters in the input
    if (argc < 2 || validate_input(argv[1], &counter) == 0) // validate input
    {
        printf("Error: Invalid\n");
        return 0; // terminate the program with invalid input
    }

    int possibilities = factorial(counter);                                          // calculate the number of permutation possibilities
    char *output = malloc((possibilities * (counter + 1) + counter) * sizeof(char)); // define a large array to store all the permutations

    if (output == NULL) // check if the memory has not been allocated successfully
    {
        printf("Memory allocated failed.\n");
        return 0; // terminate the program
    }
    printf("All permutations of the string %s are:\n", argv[1]);
    memset(output, ' ', (possibilities * (counter + 1) + counter) * sizeof(char)); // initialize each element of dynamically allocated array a given value
    char *output_ptr = output;                                                     // define a pointer to the array
    char **ptr_ptr = &output_ptr;                                                  // define a pointer of pointer
    permute(argv[1], 0, strlen(argv[1]) - 1, ptr_ptr);                             // permutate the input string
    output[possibilities * (counter + 1) + counter - 1] = '\0';                    // add terminator
    printf("%s", output);

    free(output); // free the memory
    printf("\nMemory Freed\n");

    // exit the program successfully
    return 0;
}

// This function validates the input: 1. it has to be characters, 2. it has to be max 10 characters
int validate_input(char *input, int *counter)
{
    char *c = input; // define a pointer to the parameter input
    // int counter = 0; // define a counter to count the number of charaters in the input
    while (*c)
    {
        if ((*c < 'a' && *c > 'Z') || *c > 'z' || (*c < 'A' && *c > '9') || *c < '0')
        {
            return 0; // return false if input is invalid
        }
        (*counter)++; // increment the counter by 1
        c++;
    }
    if (*counter > MAX) // if the number of charaters exceeds the limit
    {
        return 0; // return false if input is invalid
    }
    return 1; // return true if input is valid
}

// This functioin permutes the given input string
// (reference link: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/)
void permute(char *str, int start, int end, char **output)
{
    if (start == end) // when the first index equals to the last index, store the result into the output array
    {
        int i = 0;     // define a counter
        char *c = str; // define a pointer to the current str
        // loop to store the characters in the str into the final output array
        while (*c && i < strlen(str))
        {
            **output = *c; // store the current char into the output
            c++;           // move the pointer further
            i++;           // increment the counter by 1
            // printf("*output: %s \n", *output);
            (*output)++; // move the output pointer further
            // printf("%s", *output);
        }
        **output = ' '; // add a blank space
        *output += 1;   // move the pointer further
    }
    else
    {
        for (int i = start; i <= end; i++) // loop through the indexes
        {
            swap(str + start, str + i);           // swap the values
            permute(str, start + 1, end, output); // increment the start index by 1, and recursively permute the rest of the string
            swap(str + start, str + i);           // reset the values back in the orginal addresses
        }
    }
}

// This function swap the values of two pointers
void swap(char *m, char *n)
{
    char value = *m; // store the value of m in a local variable temporarily
    *m = *n;         // replace the value of m with the value in n
    *n = value;      // replace the value of n with the value in the m previously
}

// This function calculates the number of permutation possibilities for a given input string
int factorial(int str_len)
{
    int output = str_len;   // define a variable to store the return result
    while (str_len - 1 > 0) // loop until str_len reaches 1
    {
        str_len -= 1;              // decrement the str_len value by 1
        output = output * str_len; // continuely multiply the new value with the current output
    }
    return output; // return the calculation result
}
