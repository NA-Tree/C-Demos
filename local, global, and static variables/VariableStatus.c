#include <stdio.h>

#define OURINTEGER 123
int Variable;
//these are two different values, OURINTEGER is a macro and is treated as if it is hard coded, Variable is an actual variable
//Don't get them confused

void functionThree()
{
printf("\t\t\t[In fucntionThree] Variable @ %p = %d\n", &Variable, Variable);
Variable = 400;
printf("\t\t\t[In fucntionThree] Variable @ %p = %d\n", &Variable, Variable);
}

void functionTwo()
{

int Variable = 345;
static int StaticVar = 1;
printf("\t\t[In fucntionTwo] Variable @ %p = %d\n", &Variable, Variable);
printf("\t\t[In fucntionTwo] StaticVar @ %p = %d\n", &StaticVar, StaticVar);
StaticVar++;
Variable++;
functionThree();
}

void functionOne()
{
int Variable = 234;
printf("\t[In fucntionOne] Variable @ %p = %d\n", &Variable, Variable);
functionTwo();
functionTwo();
printf("\t[In fucntionOne] Variable @ %p = %d\n", &Variable, Variable);
}

void main()
{
Variable = 100;
printf("[In Main] Variable @ %p = %d\n", &Variable, Variable);
functionOne();
printf("[In Main] Variable @ %p = %d\n", &Variable, Variable);
//explaination
/*********************************************************************************************************************************************

-notice that all of the places that Variable wasn't redefined, uses the same address but all different ones for when it is redefined
-also notice that the StaticVar changed between run throughs while the local variable did not. even though they both kept their addresses 
-global variables can be accessed and editted by any instance and are static between all run throughs of all instances
-static variables can be accessed and editted only by it's original instance but is static between all run throughs for that instance
-local  variables can be accessed and editted by it's original instance and are not static between run throughs

*********************************************************************************************************************************************/
}