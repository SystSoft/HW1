/* Fall 2021 COP 3402 HW1 */
/* Anjaly Davis, Jennifer Nguyen */
/* September 15th, 2021 */

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
    int i;          // temporary variables for scanning input
    struct instruction IR = malloc(sizeof(struct instruction));
   
    // Initial Values
    int IC = 0;
    int GP = IC
    int DP = IC - 1;
    // FREE = IC + 40
    int BP = IC;
    int PC = 0;         // Program counter 
    int SP = MAX_PAS_LENGTH;
    
    i = 0;
    // Scan in registers from input and organize into catagories in a structure
    while (fscanf(ifp, "%d", pas[PC]) != EOF)
    {
        i++
    }
    
    // Print headers
    printf(“    PC   BP   SP   DP   data\n");
    
    while (PC != i)
    {
        // Fetch Cycle
        IR.OP = pas[PC];
        IR.L = pas[PC+1];
        IR.M = pas[PC+2];
        PC += 3;
        // Execute Cycle
                switch(IR.OP)
                {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                    case 8:
                        break;
                    // SYS
                    case 9:
                        switch(IR.M)
                        {
                            case
                            if (bp == gp)
                            {
                                printf(“%d”, pas[dp]); 
                                dp = dp -1;
                            }
                            else
                            {
                                printf(“%d”, pas[sp]); 
                                sp = sp + 1;
                            }

                            if (bp == gp)
                            {
                                dp = dp + 1;
                                printf("Please Enter an Integer: ");
                                scanf("%d", pad[dp]);
                            }
                            else
                            {
                                sp = sp - 1;
                                scanf(“%d”, pas[sp]);
                            }
                        }
                        break;
                    
                        
                     

            
    }
   
           
   
}
