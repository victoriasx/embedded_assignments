// Include section
#include <stdio.h>
#include <string.h>

// Main program section

/**
 * Bonus points WP0 - hello X
 *
 * This program displays "Hello X, how is your day today?"
 */
int main(int argc, char *argv[]) // define main with command-line arguments to take user input after the program name
{
    // initialize the string length
    int length;

    // no name received as the command-line argument
    if (argv[1] == NULL)
    {
        printf("No command line argument provided, please provide a name."); // the output for not receiving any name
    }
    else // a name received as the command-line argument
    {
        // calculate the string length of the command-line argument (i.e., name here)
        length = strlen(argv[1]);

        // check whether name input is valid
        if (length > 50) // the name should be at most 50 characters
        {
            printf("Name too long, max 50 characters"); // the output for for longer names
        }
        else if (length < 3) // the name should be at least 3 characters
        {
            printf("Name too short, min 3 characters"); // the output for for longer names
        }
        else
        {
            printf("Hello %s, how is your day today?", argv[1]); // the output for for valid names
        }
    }

    // leaving the program
    return 0;
}