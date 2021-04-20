#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isEven(int num);

int main(int argc, char** command) 
{ 
    char ADD[]="ADD", SUB[]="SUB",EOR[]="EOR";
   
    printf("Enter a number : ");
    int x;
    scanf("%d",&x);
    if(isEven(x))
        printf("number is even\n");
    else
        printf("number is odd\n");
   
 
     int machineCode = 0x8b020020; //Add R0,R1,R2
    
     int newcode = 0x00FFFFFF;
     
     newcode = machineCode&newcode;
     
     int newopcode = 0xca000000 | newcode;
     
    printf("EOR machine code: %x \n",newopcode);
    
    
    
    if(argc!=2)
      printf("Wrong number of command line args!");
      
    else if(strcmp(ADD,command[1])==0)
        printf("Machine code: %x",machineCode);
    
        else if(strcmp(SUB,command[1])==0) {
            newopcode= 0xcb000000 | newcode;
            printf("Machine code: %x\n",newopcode);
        }
            else if(strcmp(EOR,command[1])==0)
                printf("Machine code: %x\n",newopcode);
              
                else  
                    printf("ERROR - unknown opcode!\n");
       
    
    
    return 0; 
} 


bool isEven(int num) {
    int mask = 0b1;
    
    num = num & mask;
    
    if(num==0)
        return true;
    return false;
}