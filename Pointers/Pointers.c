#include <stdio.h>
#include <stdlib.h>

int stdFunctionSqr(int input){
input *= input;
return input;
}

int* ptrFunctionSqr(int *input){
*input *= *input;
return input;
}

void main(void)
{

int value = 10;
int *valPtr = &value;
printf("value  @ %p holds the value %d\n", &value, value);
printf("valPtr @ %p holds the value %p\n", &valPtr, valPtr);


printf("\n\n\n");


int intInput = 5;
int prtInput = 5;

printf("the output of stdFunctionSqr is %d\n", stdFunctionSqr(intInput));
printf("the output of ptrFunctionSqr is %d\n", *ptrFunctionSqr(&prtInput));
printf("the value of the original intInput is %d\n", intInput);
printf("the value of the original ptrInput is %d\n", prtInput);

}