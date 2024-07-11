/* ----------------------------- Include section ---------------------------- */
#include <stdio.h>
#include <string.h>

/* -------------------------- Function declaration -------------------------- */
int checkInput(char **input); // This function checks whether or not the input bit combination is valid

/* -------------------------- Main program section -------------------------- */

// 1 | 0 1 0 | 0 0 | 0 0

// Main function
int main(int argc, char **argv)
{
    // different number of arguments should result in an error message
    if (argc != 6)
    {
        printf("Error: Invalid");
        return 0; // terminate the program
    }
    char *array[] = {argv[1], argv[2], argv[3], argv[4], argv[5]}; // create an array to store bits from the command-line arguments
    char **ptr = array;                                            // define a pointer of pointer to the array
    if (checkInput(ptr) == 0)                                      // check if the bit combination is invalid
    {
        printf("Error: Invalid");
        return 0; // terminate the program
    }

    // Note: the conversion below uses my previous solution
    unsigned char byte = 0;          // declare a byte variable to pack the input values
    int values[5] = {7, 4, 2, 1, 0}; // define bit shift positions for 5 values
    for (int i = 4; i >= 0; i--)     // loop through the 5 argument values
    {
        byte += (*argv[i + 1] - '0')
                << values[i]; // convert these value to a decimal number with bit shifting
    }
    printf("0x%X", (int)byte);

    // exit the program successfully
    return 0;
}

// This function checks whether or not the input bit combination is valid
int checkInput(char **input)
{
    int i = 0;
    char **ptr = input; // define a pointer of pointer to the input
    while (i < 5)       // loop through the elements in the input array
    {
        if (strlen(*ptr) > 1) // check if the input bit num exceeds the required amount
        {
            return 0; // return false-> invalid
        }
        if (i == 1) // check the 2nd bit input
        {
            if (**ptr > '7' || **ptr < '0') // if the bit is not within the required range 0-7
            {
                return 0; // return false-> invalid
            }
        }
        else if (i == 2) // check the 3rd bit input
        {
            if (**ptr < '0' || **ptr > '3') // if the bit is not within the required range 0-3
            {
                return 0; // return false-> invalid
            }
        }
        else
        {
            if (**ptr != '0' && **ptr != '1') // if the bit is not within the required range 0-1
            {
                return 0; // return false-> invalid
            }
        }
        i++;   // increment the counter i by 1
        ptr++; // move the pointer forward
    }
    return 1; // return true -> valid input
}
