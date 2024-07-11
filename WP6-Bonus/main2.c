/* ----------------------------- Include section ---------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -------------------------- Function declaration -------------------------- */
char **find_shortest(char **array);

/* -------------------------- Main program section -------------------------- */

/**
 * This program reads 5 strings from a console, stores them in an array and finds the shortest string in the array.
 * The program should contain a function that takes as parameter the array, find the shortest string,
 * remove it and return the array that is shorter by one element.
 * The program should read the strings from the console
 * The program should have a separate function for finding and removing the string.
 * The program should write the string that has been removed to the console.
 * The program should also write all elements of the array before and after removal of the shortest string.
 */
// Main function
int main(int argc, char **argv)
{
    // store the 5 strings in an array
    char *array[] = {argv[1], argv[2], argv[3], argv[4], argv[5], "\0"};

    // array_ptr = array;
    char **new_array = find_shortest(array);
    char **c = new_array;
    printf("Array after removal:\n");
    while (c - new_array < 4)
    {
        printf("%s\n", *c);
        c++;
    }

    for (int i = 0; i < 4; i++)
    {
        free(new_array[i]);
    }
    free(new_array);
    //   exit the program succussfully
    return 0;
}

// This function takes as parameter the array, find the shortest string, remove it and return the array that is shorter by one element.
char **find_shortest(char **array)
{
    char **new_array;

    // initialize the array
    new_array = (char **)calloc(4, (sizeof(char *)));

    char **c = array;
    //  printf("%s\n", *c);
    int len = strlen(*c);
    c++;
    int index = 0;
    int i = 0;
    //(*c)++;
    // ab abc abcd a b

    // find the shortest string
    while (c - array < 5)
    {
        i++;
        // printf("current c len: %lu\n", strlen(*c));
        if (strlen(*c) < len)
        {
            len = strlen(*c);
            index = i;
        }
        c++;
    }
    // printf("index: %d\n", index);
    printf("Shortest string removed: %s\n", (array)[index]);
    c = array; // reset c pointer

    i = 0;
    int d = 0;
    //*array = (char **)realloc(*array, 5 * (sizeof(char *)));
    while (c - array < 5)
    {
        if (i != index)
        {
            new_array[d] = strdup(array[i]);
            //(new_array)[d] = *c;
            d++;
        }
        c++;
        i++;
    }
    return new_array;
}