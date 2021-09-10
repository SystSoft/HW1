/* Fall 2021 COP 3402 HW1 */
/* Anjaly Davis, Jennifer Nguyen */
/* September 12rd, 2021 */

#include "tester.sh"
#include <stdio.h>

// Global Veriables
#define MAX_PAS_LENGTH 

void print_execution(int line, char *opname, int *IR, int PC, int BP, int SP, int DP, int *pas, int GP)
{
    int i;
    // print out instruction and registers
    printf("%2d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t", line, opname, IR[1], IR[2], PC, BP, SP, DP);
    
    // print data section
    for (i = GP; i <= DP; i++)
        printf("%d ", pas[i]);
    
    printf("\n");
    
    // print stack
    printf("\tstack : ");
    
    for (i = MAX_PAS_LENGTH - 1; i >= SP; i--)
        printf("%d ", pas[i]);printf("\n");
}

int base(int L)
{
    int arb = BP;   // arb = activation record base
    while ( L > 0)     //find base L levels down
    {
        arb = pas[arb];
        L--;
    }
    return arb;
}

int main(int argc, char **argv)
{
    
}
