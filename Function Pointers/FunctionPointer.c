#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{

int function1(void *input)
{
return *((int*)input) += 1;
}
int function2(void *input)
{
return *((int*)input) += 2;
}
int function3(void *input)
{
return *((int*)input) += 3;
}

int (*functionPtr)(void*);
int value = 0;
functionPtr = &function1;                                   //will be the function to add 1 to 0
printf("running functionPtr with input %d:\t", value);
printf("%d\n",functionPtr(&value));
functionPtr = &function2;                                   //will be the function to add 2 to 1
printf("running functionPtr with input %d:\t", value);
printf("%d\n",functionPtr(&value));
functionPtr = &function3;                                   //will be the function to add 3 to 3
printf("running functionPtr with input %d:\t", value);
printf("%d\n\n",functionPtr(&value));

float add(int x, int y)
{
return x+y;
}
float subtract(int x, int y)
{
return x-y;
}
float multiply(int x, int y)
{
return x*y;
}
float divide(int x, int y)
{
return x/y;
}

float (*operations[4])(int,int);
operations[0] = add;                    //2+2=4
operations[1] = subtract;               //2-2=0
operations[2] = multiply;               //2*2=4
operations[3] = divide;                 //2/2=1

printf("Here are the outputs for the function pointer 'operations'\n");
for(int i = 0; i < 4; i++)
{
    printf("%d\n",(int)operations[i](2,2));
}

}