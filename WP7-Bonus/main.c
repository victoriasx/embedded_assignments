/* ----------------------------- Include section ---------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------------------------------ Define struct ----------------------------- */
typedef struct n
{
    struct n *prev;
    int data;
    struct n *next;
} node;

/* ------------------------------ Define macro ------------------------------ */
#define MAX 47

/* -------------------------- Function declarations ------------------------- */
node *store_fibonacci_nums();            // creates and stores Fibonacci numbers as a linked list
void calculate_nums(int num, node *cur); // uses the elements in the list to calculate the numbers
int convert_num(char *input, int len);   // convert the the input string to integer

/* -------------------------- Main program section -------------------------- */

/**
 * This program calculates and stores Fobonacci sequences.
 * The program should take one argument
 * - the Fibonacci number
 * - and then generate the correct Fibonacci sequence.
 * The program should store all Fibonacci numbers as a linked list
 * and use the elements in the list to calculate the numbers.
 * For example when calculating the fourth number (3),
 * the program should take the third number (2)
 * and the second number (1) from the list.
 */

// Main function
int main(int argc, char **argv)
{
    int len = strlen(argv[1]);           // define a variable to store the length of the input string
    int num = convert_num(argv[1], len); // store the converted number into a variable

    // check if the return num is 0
    if (num == 0)
    {
        printf("0"); // output "0"
        return 0;    // terminate the program
    }
    node *cur, *head = NULL; // define two node pointers

    head = store_fibonacci_nums(); // retrieve the head node of the Fibonacci numbers linked list
    cur = head;                    // set the node pointer cur to head

    // print out the Fibonacci numbers in the linked list
    while (cur != NULL)
    {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
    cur = head; // reset the node pointer cur to head

    calculate_nums(num, cur); // generate the correct Fibonacci sequence based on a given number

    // free the allocated memory
    while ((cur = head) != NULL)
    {
        head = cur->next; // move the pointer to the next node address
        free(cur);        // free the memory
    }
    // exit the program successfully
    return 0;
}

// This function stores all Fibonacci numbers as a linked list
node *store_fibonacci_nums()
{
    node *head, *current = NULL, *old = NULL; // define 3 node pointers
    int m = 0;                                // define a variable to store the first Fibonacci number
    head = (node *)malloc(sizeof(node));      // create node head
    // old = (node *)malloc(sizeof(node));  // create node old
    if (head != NULL) // check item has been created
    {
        head->data = m;    // set the head node data
        head->prev = NULL; // set the head's previous address to null
    }
    int counter = 1;      // define a counter
    int i = 1;            // define a variable to store the second Fibonacci number
    int j = m + i;        // define a variable to store the third Fibonacci number
    while (counter < MAX) // loop until the counter reaches the MAX
    {
        if (current != NULL) // check if the current node is not NULL
        {
            old = current; // set the old node pointer to the current node
        }
        current = (node *)malloc(sizeof(node)); // create node current
        if (current != NULL)                    // check if the current node is not NULL
        {
            current->data = i; // set the current node data to i
            if (old != NULL)   // check if the old node is not NULL
            {
                current->prev = old; // set the current node's prev points to the old node address
                old->next = current; // set the old node's next points to the current node address
            }
        }

        if (counter == 1) // check if the counter is 1, i.e., it is the node right after the head node
        {
            current->prev = head; // set the current node's prev points to the head node
            head->next = current; // set the head node's next points to the current node
        }
        m = i;     // update m with the value of i
        i = j;     // update the i with the value of j
        j = m + i; // update the j value with the addition of i+j, which is the next Fibonacci number
        counter++; // incremment the counter by 1
    }
    current->next = NULL; // set the current node's next to NULL, since it is the last node
    return head;          // return the head node
}

// This function uses the elements in the list to calculate the number
void calculate_nums(int num, node *cur)
{
    while (cur != NULL) // loop through the linked list
    {
        if (cur->data == num) // if the cur node's data is num
        {
            if (cur->prev != NULL) // if the cur node's prev is not NULL
            {
                printf("\n%d\n", cur->prev->data);
                cur = cur->prev;       // move the pointer to the previous node
                if (cur->prev != NULL) // if the previous node is not NULL
                {
                    printf("%d\n", cur->prev->data);
                }
            }
            return; // exit the function
        }
        cur = cur->next; // move the pointer to the next node
    }
}

// This function converts the command-line argument to an integer
int convert_num(char *input, int len)
{
    if (input[0] == '-') // check if the input is a negative number
    {
        return 0; // return 0
    }

    int num = 0;                  // define an output variable
    for (int i = 0; i < len; i++) // loop through the input string
    {
        if (i == 0) // if it is the first charactor
        {
            num += input[i] - '0'; // convert the char to int
        }
        else // if it is not the first charactor
        {
            num = (input[i] - '0') + num * 10; // update the number with the current char
        }
    }
    return num; // return the output num
}
