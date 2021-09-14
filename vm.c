/* Fall 2021 COP 3402 HW1 */
/* Anjaly Davis, Jennifer Nguyen */
/* September 15th, 2021 */

#include <stdio.h>
#include <stdlib.h>

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
    printf("%2d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t", line, opname, IR->L, IR->M, PC, BP, SP, DP);
    
    // print data section
    for (i = GP; i <= DP; i++)
        printf("%d ", pas[i]);
    
    printf("\n");
    
    // print stack
    printf("\tstack : ");
    
    for (i = MAX_PAS_LENGTH - 1; i >= SP; i--)
        printf("%d ", pas[i]);printf("\n");
}

int base(int L, int *pas, int BP)
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
    FILE * ifp;
    ifp = fopen(argv[1], "r");
    
    int pas[MAX_PAS_LENGTH];
    int i;          // temporary variables for scanning input
    struct instruction *IR = malloc(sizeof(struct instruction));
   
    // Initial Values
    int IC = 0;
    int GP = IC;
    int DP = IC - 1;
    // FREE = IC + 40
    int BP = IC;
    int PC = 0;         // Program counter
    int SP = MAX_PAS_LENGTH;
    
    for (i = 0; i < MAX_PAS_LENGTH; i++)
    {
        pas[i] = 0;
    }
    
    i = 0;
    // Scan in registers from input and organize into catagories in a structure
    while (fscanf(ifp, "%d", &pas[PC]) != EOF)
    {
        i++;
    }
    
    // Print headers
    printf("    PC   BP   SP   DP   data\n");
    
    while (PC != i)
    {
        // Fetch Cycle
        IR->OP = pas[PC];
        IR->L = pas[PC+1];
        IR->M = pas[PC+2];
        PC += 3;
        // Execute Cycle

        switch(IR->OP)
        {
            //LIT
            case 1:
            if(BP == GP)
            {
                DP = DP+1;
                pas[DP] = IR->M;
            }
            else
            {
                SP = SP-1;
                pas[SP] = IR->M;
            }
            print_execution(PC/3, "LIT", IR, PC, BP, SP, DP, pas, GP);
            break;

            //RTN
            case 2:
                SP = BP + 1;
                BP = pas[SP-2];
                PC = pas[SP-3];
                break;

            //NEG
            case 3:
                if(BP == GP)
                {
                    pas[DP] = -1*pas[DP];
                }
                else
                {
                    pas[SP] = -1*pas[SP];
                }
                print_execution(PC/3, opname[2], IR, PC, BP, SP, DP, pas, GP);
                break;

            //ADD
            case 4:
                if(BP == GP)
                {
                    DP = DP-1;
                    pas[DP] = pas[DP] + pas[DP+1];
                }
                else
                {
                    SP = SP+1;
                    pas[SP] = pas[SP] + pas[SP-1];
                }
                print_execution(PC/3, opname[1], IR, PC, BP, SP, DP, pas, GP);
                break;

            //SUB
            case 5:
                if(BP == GP)
                {
                    DP = DP-1;
                    pas[DP] = pas[DP] - pas[DP+1];
                }
                else
                {
                    SP = SP+1;
                    pas[SP] = pas[SP] - pas[SP-1];
                }
                break;

            //MUL
            case 6:
                
                if(BP == GP)
                {
                    DP = DP-1;
                    pas[DP] = pas[DP] * pas[DP+1];
                }
                else
                {
                    SP = SP+1;
                    pas[SP] = pas[SP] * pas[SP-1];
                }
                break;

            //DIV
            case 7:
                
                if(BP == GP)
                {
                    DP = DP-1;
                    pas[DP] = pas[DP] / pas[DP+1];
                }
                else
                {
                    SP = SP+1;
                    pas[SP] = pas[SP] / pas[SP-1];
                }
                break;

            //ODD
            case 8:
               
                if(BP == GP)
                {
                    pas[DP] = pas[DP] % 2;
                }
                else
                {
                    pas[SP] = pas[SP] % 2;
                }
                break;

            //MOD
            case 9:
               
                if(BP == GP)
                {
                    DP = DP-1;
                    pas[DP] = pas[DP] % pas[DP+1];
                }
                else
                {
                    SP = SP+1;
                    pas[SP] = pas[SP] % pas[SP-1];
                }
                break;

            //EQL
            case 10:
              
                if(BP == GP)
                {
                    DP = DP-1;
                    pas[DP] = pas[DP] == pas[DP+1];
                }
                else
                {
                    SP= SP+1;
                    pas[SP] = pas[SP] == pas[SP-1];
                }
                break;

            //NEQ
            case 11:
            
                if(BP == GP)
                {
                    DP = DP-1;
                    pas[DP] = pas[DP] != pas[DP+1];
                }
                else
                {
                    SP = SP+1;
                    pas[SP] = pas[SP] != pas[SP-1];
                }
                break;

            //LSS
            case 12:
       
                if(BP == GP)
                {
                    DP = DP-1;
                    pas[DP] = pas[DP] < pas[DP+1];
                }
                else
                {
                    SP = SP+1;
                    pas[SP] = pas[SP] < pas[SP-1];
                }
                break;

            //LEQ
            case 13:
               
                if(BP == GP)
                {
                    DP = DP-1;
                    pas[DP] = pas[DP] <= pas[DP+1];
                }
                else
                {
                    SP = SP+1;
                    pas[SP] = pas[SP] <= pas[SP-1];
                }
                break;

            //GTR
            case 14:
                
                if(BP == GP)
                {
                    DP = DP - 1;
                    pas[DP] = pas[DP] > pas[DP+1];
                }
                else
                {
                    SP = SP+1;
                    pas[SP] = pas[SP] > pas[SP-1];
                }
                break;

            //GEQ
            case 15:
              
                if(BP == GP)
                {
                    DP = DP-1;
                    pas[DP] = pas[DP] >= pas[DP+1];
                }
                else
                {
                    SP = SP+1;
                    pas[SP] = pas[SP] >= pas[SP-1];
                }
                break;

            //LOD
            case 16:
                
                if(BP == GP)
                {
                    DP = DP+1;
                    pas[DP] = pas[GP+IR->M];
                }
                else if(base(IR->L, pas, BP) == GP)
                {
                    SP = SP-1;
                    pas[SP] = pas[GP+IR->M];
                }
                else
                {
                    SP = SP-1;
                    pas[SP] = pas[base(IR->L, pas, BP)-IR->M];
                }
                break;

            //STO
            case 17:
               
                if(BP == GP)
                {
                    pas[GP+IR->M] = pas[DP];
                    DP = DP-1;
                }
                else if(base(IR->L, pas, BP) == GP)
                {
                    pas[GP+IR->M] = pas[SP];
                    SP = SP+1;
                }
                else
                {
                    pas[base(IR->L, pas, BP)-IR->M] = pas[SP];
                    SP = SP+1;
                }
                break;

            //CAL
            case 18:
              
                pas[SP-1] = base(IR->L, pas, BP);
                pas[SP-2] = BP;
                pas[SP-3] = PC;
                BP = SP-1;
                PC = IR->M;
                break;

            //INC
            case 19:
      
                if(BP == GP)
                {
                    DP = DP+IR->M;
                }
                else
                {
                    SP = SP-IR->M;
                }
                break;

            //JMP
            case 20:
              
                PC = IR->M;
                break;

            //JPC
            case 21:
        
                if(BP == GP)
                {
                    if(pas[DP] == 0)
                    {
                        PC = IR->M;
                    }
                    DP = DP-1;
                }
                else
                {
                    if(pas[SP] == 0)
                    {
                        PC = IR->M;
                    }
                    SP = SP+1;
                }
                break;

          // SYS
          case 22:
              switch(IR->M)
              {
                 if (BP == GP)
                 {
                     printf("%d", pas[DP]);
                     DP = DP -1;
                 }
                 else
                 {
                      printf("%d", pas[SP]);
                      SP = SP + 1;
                 }

                 if (BP == GP)
                 {
                      DP = DP + 1;
                      printf("Please Enter an Integer: ");
                      scanf("%d", &pas[DP]);
                 }
                 else
                 {
                      SP = SP - 1;
                      scanf("%d", &pas[SP]);
                 }
             }
             break;
             
             
         default:
                printf("err\t");
         
        }
    }
    return 0;
}

                             
