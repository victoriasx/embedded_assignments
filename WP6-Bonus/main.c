/* ----------------------------- Include section ---------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -------------------------- Function declaration -------------------------- */
char **find_shortest(char ***array, char *shortest_string);

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
int main()
{
    char str1[256]; // declare a variable to store strings

    char **array = (char **)malloc(5 * (sizeof(char *)));
    int d = 0; // define a counter for array index

    // store the 5 strings in an array
    while (d < 5) // loop 5 times to prompt 5 strings
    {
        fgets(str1, sizeof(str1), stdin);        // store keyboard input string
        const unsigned short len = strlen(str1); // define a variable to store the length of the input string

        if (str1[len - 1] == '\n')                          // check if the end character is a new line
            str1[len - 1] = '\0';                           // set it to the end character
        array[d] = (char *)calloc((len + 1), sizeof(char)); // dynamically allocate memory to the current element

        strcpy(array[d++], str1); // copy the input and store it in the array
    }
    char **array_ptr = array; // define a pointer of pointer to the array of strings

    char ***ptr = &array_ptr; // define a pointer of pointer of pointer to the array_ptr address

    char **new_array = find_shortest(ptr, str1); // retrieve the result of removing the shortest string
    char **c = new_array;                        // define a pointer of pointer to the new array of strings

    printf("Shortest string removed: %s\n", str1);
    printf("Array after removal:\n");
    while (c - new_array < 4) // loop through the new_array
    {
        printf("%s\n", *c);
        c++; // move the pointer of pointer forward
    }

    // free memory
    for (int i = 0; i < 4; i++) // loop throught the new_array
    {
        free(new_array[i]); // free the allocated memory to each element
    }
    for (int i = 0; i < 5; i++) // loop throught the array
    {
        free(array[i]); // free the allocated memory to each element
    }
    free(array);     // free the allocated memory to the array
    free(new_array); // free the allocated memory to the new_array

    //   exit the program succussfully
    return 0;
}

// This function takes as parameter the array, find the shortest string, remove it and return the array that is shorter by one element.
char **find_shortest(char ***array, char *shortest_string)
{
    char **new_array; // declare an array

    // allocate memory to the array
    new_array = (char **)malloc(4 * (sizeof(char *)));

    char **c = *array; // define a pointer of pointer to the parameter array

    int len = strlen(*c); // define a variable to store the string length of the first element in the array
    c++;                  // move the pointer forward
    int index = 0;        // define an index
    int i = 0;            // define a counter

    // find the index of the shortest string in the array
    while (c - *array < 5)
    {
        i++;                  // increment the counter by 1
        if (strlen(*c) < len) // check if the current string element length is shorter than the first element
        {
            len = strlen(*c); // update the length
            index = i;        // update the index of the shortest string
        }
        c++; // move the pointer of pointer forward
    }
    // printf("Shortest string removed: %s\n", (*array)[index]);
    strcpy(shortest_string, (*array)[index]);

    c = *array;            // reset c pointer
    i = 0;                 // reset the counter
    int d = 0;             // define a counter for the index in the new_array
    while (c - *array < 5) // loop through the array
    {
        if (i != index) // if the current element index is not the found shortest string
        {
            (new_array)[d] = (char *)calloc((strlen(*c) + 1), sizeof(char)); // dynamically allocate memory to the current element
            strcpy(new_array[d++], *c);                                      // copy the string and store it in the new_array, and increment the index d by 1
        }
        c++; // move the pointer forward
        i++; // increment thr counter by 1
    }

    return new_array; // return the new_array with one element removed
}