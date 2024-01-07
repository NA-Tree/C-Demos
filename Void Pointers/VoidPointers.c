#include <stdio.h>
#include <stdlib.h>

void main(void)
{

int x = 10;
char character;

printf("the value x @ %p:\t%d\n", &x, x);
void *myVoidPtr = &x;
printf("assigning myVoidPtr @ %p to %p which has the value %d\n", &myVoidPtr, myVoidPtr, *((int *)myVoidPtr));
*((int *)myVoidPtr) += 10;
printf("adding 10 to the value of what myVoidPtr is pointing to: %d\n", *((int*)myVoidPtr));
myVoidPtr = &character;
*((char *)myVoidPtr) = 'C';
printf("assigning myVoidPtr @ %p to %p which has the value %c\n", &myVoidPtr, myVoidPtr, *((char *)myVoidPtr));

}