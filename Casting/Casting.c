#include <stdio.h>

void main()
{
    char Letter = 'A';
    int Number = 101;

    printf("%d\n", Letter);   // Here, what we are doing is pointing to the letter for memory but displaying it as an integer
    printf("%c\n", Number);   // Here, what we are doing is pointing to the number for memory but displaying it as a character

    /**
    What if we want to do math based on the information between variable types?
    we use typecasting
    **/

    char Letter_OneAdvanced;
    int Letter_integerRepresentation;

    Letter_integerRepresentation = (int) Letter;
    Letter_OneAdvanced = (char)(Letter_integerRepresentation+1);
    // we just converted 'Letter' to an integer, stored it in a variable to do math before converting it back
    printf("%c", Letter_OneAdvanced);
    //the third line of the output should thus be 'B'
}