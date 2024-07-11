/* ----------------------------- Include section ---------------------------- */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* -------------------------- Define macro section -------------------------- */
#define MAX_WEEK 5

/* -------------------------- Define enums section -------------------------- */
enum day // Define enum day with 7 days
{
    Mon = 1, // define the index of first element as 1
    Tue,
    Wed,
    Thu,
    Fri,
    Sat,
    Sun
};
enum week // Define enum week with 5 weeks
{
    week1 = 1, // define the index of first element as 1
    week2,
    week3,
    week4,
    week5
};

/* -------------------------- Function declarations ------------------------- */
char *getDay(int day);   // This function takes user input day and return a corresponding day string for printing
char *getWeek(int week); // This function takes user input week and return a corresponding week string for printing

/* -------------------------- Main program section -------------------------- */

/**
 * The program should ask the user to provide the start day and week.
 * Every time the program increments the day,
 * it should write the week and day on the console.
 */

/* -------------------------- Function definitions -------------------------- */

// Main function
int main()
{

    int week_num = getchar() - '0'; // define a variable to store the week number from user input
    char c;                         // define a variable to store input character
    while ((c = getchar()) != '\n' && c != EOF)
        ; // read the rest of the input char and do nothing

    if ((week_num > 5) || (week_num < 1)) // check for incorrect input from the user
    {
        printf("%s", getWeek(week_num));
        return 0; // exit the program with error code 1
    }

    int day_num = getchar() - '0'; // define a variable to store the day number from user input
    while ((c = getchar()) != '\n' && c != EOF)
        ; // read the rest of the input char and do nothing
    // printf("get day: %d", day_num);
    if (day_num > 8 || day_num < 1) // check for incorrect input from the user
    {
        printf("%s", getDay(day_num));
        return 0; // exit the program with error code 1
    }

    for (int j = week_num; j <= week5; j++) // loop through the weeks until week5
    {
        for (int i = day_num; i <= Sun; i++) // loop through the days until Sun
        {
            printf("%s, %s\n", getWeek(week_num), getDay(i));
            sleep(1); // pause the program to sleep for 1 second
        }
        day_num = Mon; // reset the day to Mon
        week_num++;    // increment the week number
    }
    // exit the program successfully
    return 0;
}

// This function uses the parameter day in a switch case, and returns a string for printing
char *getDay(int day)
{
    switch (day) // switch case according to the day value
    {
    case 1:                   // when the day is int 1
        return "Monday";      // return the corresponding day in string
    case 2:                   // when the day is int 2
        return "Tuesday";     // return the corresponding day in string
    case 3:                   // when the day is int 3
        return "Wednesday";   // return the corresponding day in string
    case 4:                   // when the day is int 4
        return "Thursday";    // return the corresponding day in string
    case 5:                   // when the day is int 5
        return "Friday";      // return the corresponding day in string
    case 6:                   // when the day is int 6
        return "Saturday";    // return the corresponding day in string
    case 7:                   // when the day is int 7
        return "Sunday";      // return the corresponding day in string
    default:                  // when the day number is invalid
        return "invalid day"; // return an error message
    }
}

// This function uses the parameter day in a switch case, and returns a string for printing
char *getWeek(int week)
{
    switch (week) // switch case according to the week value
    {
    case 1:                    // when the week is int 1
        return "Week 1";       // return the corresponding week in string
    case 2:                    // when the week is int 2
        return "Week 2";       // return the corresponding week in string
    case 3:                    // when the week is int 3
        return "Week 3";       // return the corresponding week in string
    case 4:                    // when the week is int 4
        return "Week 4";       // return the corresponding week in string
    case 5:                    // when the week is int 5
        return "Week 5";       // return the corresponding week in string
    default:                   // when the week number is invalid
        return "invalid week"; // return an error message
    }
}