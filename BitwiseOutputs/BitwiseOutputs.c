#include <stdio.h>
#include <stdlib.h>

void main(void)
{

short Bit;

for(int i=0; i<10; i++)
{
    Bit = (i & 2);                  //here i is 0000 0001 -> 0000 0010 -> 0000 0011 and so on and you are comparing the 0010 place for the boolean return
    printf("%d\n", Bit);
}

}