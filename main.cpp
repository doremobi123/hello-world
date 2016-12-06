#include <iostream>
#define CERTAIN_AGE 8
using namespace std;

int numLeapYear(int beginYear, int endYear) // Calculate number of leap years between 2 year(include those 2 years)
{
    int s = 0; // Create a variable to store the number of leap years
    for(int i = beginYear; i <= endYear; i++) // Run from the beginning year to the ending year
        if((i%4)==0) // If the year is divisible by 4 it's a leap year
            s = s + 1; // Then add 1 more year to s
    return s;
}
int dayOrderInYear(int day, int month, int year) // Order of present day in the year(not include 29/2 if it's a leap year)
{
    int order = 0; // Create a variable to store the order of the day in the year
    for(int i = 1; i < month; i++) // Run from January to the month before the present month
        switch(i) // Check to see what month it is
        {
            case 4: case 6: case 9: case 11: // If it's April or June or September or November the add 30 to "order"
                order = order + 30;
                break;
            case 2: // If it's February add 28
                order = order + 28;
                break;
            default: order = order + 31; // If it's another month add 31
        }
    order = order + day; // The final order will be the "order" added by day
    return order;
}
int main()
{
    int birDay, birMonth, birYear; // Declare birthday day, month and year
    int preDay, preMonth, preYear; // Declare present day, month and year
    int birthTime = 0; // Declare number of birthdays that have been celebrated since CERTAIN_AGE
    cout << "Enter birthday day, month and year: ";
    cin >> birDay >> birMonth >> birYear; // Enter birthday day, month and year
    cout << "Enter present day, month and year: ";
    cin >> preDay >> preMonth >> preYear; // Enter present day, month and year
    int preOrder = dayOrderInYear(preDay, preMonth, preYear); // Assign order of present day to a variable
    int birOrder = dayOrderInYear(birDay, birMonth, birYear); // Assign order of birthday to a variable
    if(birDay==29 && birMonth==2)
    {
        if((preYear%4==0 && (preMonth>2 || (preMonth==2 && preDay==29) )) || preYear%4!=0)
            birthTime = numLeapYear(birYear+CERTAIN_AGE, preYear);
        else birthTime = numLeapYear(birYear+CERTAIN_AGE, preYear) - 1;
    }
    /*  * If (present year is a leap year & present time is bigger than 29/2) or (present year is not a leap year)
            then birthTime equals to number of leap year from CERTAIN_AGE to present time.
        * If not birthTime equals to number of leap year from CERTAIN_AGE to present time minus 1.
    */
    // If present day is beyond birthday :
    else if(preOrder>=birOrder) birthTime = preYear - (birYear + CERTAIN_AGE) + 1;
    // If present day haven't passed birthday yet :
    else birthTime = preYear - (birYear + CERTAIN_AGE);
    cout << "The number of birthdays that have been celebrated since " << CERTAIN_AGE << "th age is: " << birthTime << endl;
    //Print out the number of birthdays that have been celebrated since CERTAIN_AGE
    return 0;
}
