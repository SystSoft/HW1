/* Fall 2021 COP 3402 HW1 */
/* Anjaly Davis, Jennifer Nguyen */
/* September 12rd, 2021 */

#include "tester.sh"
#include <stdio.h>

// Global Variables
#define MAX_PAS_LENGTH 500

// For printing
char *opname[] =  { "", "LIT", "OPR", "LOD", "STO", "CAL", "INC", "JMP", "JPC", "SYS", "NEG", "ADD", "SUB", "MUL", "DIV", "ODD", "MOD", "EQL", "NEQ", "LSS", "LEQ", "GTR", "GEQ"};

struct instruction
{
    int OP;         // Operation code
    int L;          // Lexicographical level
    int M;          // Modifier
};

void print_execution(int line, char *opname, struct instruction *IR, int PC, int BP, int SP, int DP, int *pas, int GP)
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
    
    int *pas = calloc(MAX_PAS_LENGTH, sizeof(int));
    int i, j, opercode, lexlev, mod;          // temporary variables for scanning input
    int IR[MAX_PAS_LENGTH];
   
    // Initial Values
    int IC = 0;
    int GP = IC
    int DP = IC - 1;
    // FREE = IC + 40
    int BP = IC;
    int PC = 0;         // Program counter 
    int SP = MAX_PAS_LENGTH;
    
    // Scan in registers from input and organize into catagories in a structure
    i = 0;
    while (fscanf(ifp, "%d %d %d", opercode, lexlev, mod) != EOF)
    {
        struct instruction *new = malloc(sizeof(struct instruction));
        new.OP = opercode;
        new.L = lexlev;
        new.M = mod;
        
        // put each set of instructions into an array 
        IR[i] = new;
        i++
     }
    
    
    // Print headers
    printf(“    PC   BP   SP   DP   data\n");
           
    
    // Execute Cycle
    PC = 0;
    while (PC != i)
    {
            switch(IR.OP)
            {
                case 1:
                    df

            
    }
   
           
   
}
