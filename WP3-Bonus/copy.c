/* ----------------------------- Include section ---------------------------- */
#include <stdio.h>
#include <string.h>

/* ----------------------------- Define section ----------------------------- */
#define MAX 4

/* -------------------------- Function declaration -------------------------- */
int validate_num(char a);

/* -------------------------- Main program section -------------------------- */

/**
 * This program adds two matrix (e.g.: 2x2) using pointers or arrays (max size should be 4x4).
 */

// Main function
int main()
{
    char size1; // define a variable to store the first size input
    char size2; // define a variable to store the second size input

    printf("Input the size:\n");
    scanf("%c %c", &size1, &size2); // retrieve user input for sizes

    // validate user input number
    if (validate_num(size1) == 0 || validate_num(size1) == 0 || (size1 - '0') > MAX || (size2 - '0') > MAX)
    {
        printf("Error: Invalid input");
        return 2; // terminate the program if the input is invalid, return 2 error code
    }
    int sizes[2] = {size1 - '0', size2 - '0'}; // declare an array to store the sizes of the two arrays later
    int matrix1[sizes[0]][sizes[0]];           // declare a 2-dimentional array with the index-0 size in the sizes array
    int matrix2[sizes[1]][sizes[1]];           // declare a 2-dimentional array with the index-1 size in the sizes array

    int i, j; // declare 2 int variables, used as indexes for looping through the arrays
    char c;   // declare a variable to store temporary stdin char

    /* ------------------------------ First matrix ------------------------------ */

    printf("Input matrix1[%d][%d]:\n", sizes[0], sizes[0]);
    // loop throughthe maxtrix1 array to fill in the values with user input
    for (i = 0; i < sizes[0]; i++) // loop the row
    {
        for (j = 0; j < sizes[0]; j++) // loop the column
        {
            scanf("%d", &matrix1[i][j]); // propmt for user input
        }
    }

    int status = 0;                // declare an int variable to store the validated status of user input, 0 -> success, 1 -> fail
    while ((c = getchar()) != EOF) // loop to get the rest of the stdin from user input
    {
        if (c == '\n') // break out the loop if it encounters new line
        {
            break;
        }
        if (c != ' ') // check if there is more user inputs other than the required number of inputs
        {
            status = 1; // if there is, set the input validation status fail(1)
        }
    }
    if (status != 0) // when the input validation status did not succeed
    {
        printf("Error: Invalid input");
        return 2; // stop the program with 2 as returning error code
    }

    // loop throug the matrix1 to validate the value
    for (i = 0; i < sizes[0]; i++) // loop through rows
    {
        for (j = 0; j < sizes[0]; j++) // loop through columns
        {
            if (validate_num(matrix1[i][j] + '0') != 1) // validate the value
            {
                printf("Error: Invalid input");
                return 2; // stop the program if there is invalid value
            }
        }
    }

    /* ------------------------------ Second matrix ----------------------------- */
    status = 0; // reset the validating status to success (0)

    printf("Input matrix2[%d][%d]:\n", i, j);
    for (i = 0; i < sizes[1]; i++) // loop through rows
    {
        for (j = 0; j < sizes[1]; j++) // loop through columns
        {
            scanf("%d", &matrix2[i][j]); // fill in matrix2 values from user input
        }
    }
    while ((c = getchar()) != EOF) // loop to get the rest of the stdin from user input
    {
        if (c == '\n') // break out the loop if it encounters new line
        {
            break;
        }
        if (c != ' ') // check if there is more user inputs other than the required number of inputs
        {
            status = 1; // if there is, set the input validation status fail(1)
        }
    }

    if (status != 0) // when the input validation status did not succeed
    {
        printf("Error: Invalid input");
        return 2; // stop the program with 2 as returning error code
    }

    // loop throug the matrix2 to validate the value
    for (i = 0; i < sizes[1]; i++) // loop through rows
    {
        for (j = 0; j < sizes[1]; j++) // loop through columns
        {
            if (validate_num(matrix2[i][j] + '0') != 1) // validate the value
            {
                printf("Error: Invalid input");
                return 2; // stop the program if there is invalid value
            }
        }
    }

    /* ------------------------- Sum matrix1 and matrix2 ------------------------ */

    int sep = sizes[0] % 2 + sizes[0] / 2; // define a variable to store how many items should be on 1 line, for printing formatting purpose
    for (i = 0; i < sizes[0]; i++)         // loop through rows
    {
        for (j = 0; j < sizes[0]; j++) // loop through columns
        {
            printf("%d ", (*(*(matrix1 + i) + j)) + *(*(matrix2 + i) + j));
            if (j == sep) // if column reaches the seperation number, the rest of the printed values will be moved to a new line
            {
                printf("\n");
            }
        }
    }

    // exit the program successfully
    return 0;
}

// This function validate the input is a number
int validate_num(char a)
{
    if (a < '0' || a > '9') // check whether the input is a valid number
    {
        return 0; // returns 0 (false)
    }
    return 1; // returns 1 (true)
}