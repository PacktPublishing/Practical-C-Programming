#include <stdio.h>
#include <assert.h>

int main(void)
{
    int c, noOfPassengers;
    char fl_from[30], fl_to[30], dateofJourney[12];
    printf("How many passengers ? ");
    scanf("%d",&noOfPassengers);
    assert(noOfPassengers > 0 && "Number of passengers should be a positive integer");
    printf("Flight from: ");
    while((c= getchar()) != '\n' && c != EOF);
    gets(fl_from);
    printf("Flight to: ");
    gets(fl_to);
    printf("Date of journey ");
    scanf("%s", dateofJourney);
    printf("The information entered is:\n");
    printf("Number of passengers %d\n", noOfPassengers);
    printf("Flight from: %s\n", fl_from);
    printf("Flight to: %s\n", fl_to);
    printf("Date of journey: %s\n", dateofJourney);
    return 0;
}