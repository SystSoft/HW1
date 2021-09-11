/* Fall 2021 COP 3402 HW1 */
/* Anjaly Davis, Jennifer Nguyen */
/* September 12rd, 2021 */

#include "tester.sh"
#include <stdio.h>

// Global Variables
#define MAX_PAS_LENGTH 500

struct instruction
{
    int OP;         // Operation code
    int L;          // Lexicographical level
    int M;          // Modifier
};

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

int main(int argc, char *argv[])
{
    FILE *ifp = fopen(argv[1], "r");
    
    int i, opercode, lexlev, mod;          // temporary variables for scanning input
    instruction IR[MAX_PAS_LENGTH];
    
    
    i = 0;
    while (fscanf(ifp, "%d %d %d", opercode, lexlev, mod) != EOF)
    {
        struct instruction *new = malloc(sizeof(struct instruction));
        new.OP = opercode;
        new.L = lexlev;
        new.M = mod;
        
        IR[i] = new;
        i++
     }
    
    
    // Print headers
    printf(“    PC   BP   SP   DP   data");
           
    // Fetch Cycle
           
    // Execute Cycle
    switch()
    {
        case 1:
            df
              
            
    }
   
}
