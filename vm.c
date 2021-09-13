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
	//LIT
    case 1:
            
	fprintf(ofp, "LIT\t");
	if(bp == gp)
	{
		dp = dp+1;
		pas[dp] = M;
        }
	else
        {
		sp = sp-1;
		pas[sp] = M;
	}
	break;
	
	//RTN
	case 2:
		fprintf(ofp, "RTN\t");
		sp = bp + 1;
		bp = pas[sp-2];
		pc = pas[sp-3];
		break;
		
	//NEG
	case 3:
		fprintf(ofp, "NEG\t");
		if(bp == gp)
		{
			pas[dp] = -1*pas[dp];
        	}
		else
        	{
			pas[sp] = -1*pas[sp];
		}
        	break;		
		
	//ADD
	case 4:
		fprintf(ofp, "ADD\t");
		if(bp == gp)
		{
			dp = dp-1;
			pas[dp] = pas[dp] + pas[dp+1];
        	}
		else
        	{
			sp = sp+1;
			pas[sp] = pas[sp] + pas[sp-1];
		}
		break;
	
	//SUB
	case 5:
		fprintf(ofp, "SUB\t");
		if(bp == gp)
		{
			dp = dp-1;
			pas[dp] = pas[dp] - pas[dp+1];
        	}
		else
        	{
			sp = sp+1;
			pas[sp] = pas[sp] - pas[sp-1];
		}
		break;
	
	//MUL
	case 6:
		fprintf(ofp, "MUL\t");
		if(bp == gp)
		{
			dp = dp-1;
			pas[dp] = pas[dp] * pas[dp+1];
        	}
		else
        	{
			sp = sp+1;
			pas[sp] = pas[sp] * pas[sp-1];
		}
		break;
		
	//DIV
	case 7:
		fprintf(ofp, "DIV\t");
		if(bp == gp)
		{
			dp = dp-1;
			pas[dp] = pas[dp] / pas[dp+1];
        	}
		else
        	{
			sp = sp+1;
			pas[sp] = pas[sp] / pas[sp-1];
		}
		break;
		
	//ODD
	case 8:
		fprintf(ofp, "ODD\t");
		if(bp == gp)
		{
			pas[dp] = pas[dp] % 2;
        	}
		else
        	{
			pas[sp] = pas[sp] % 2;
		}
		break;
		
	//MOD
	case 9:
		fprintf(ofp, "MOD\t");
		if(bp == gp)
		{
			dp = dp-1;
			pas[dp] = pas[dp] % pas[dp+1];
        	}
		else
        	{
			sp = sp+1;
			pas[sp] = pas[sp] % pas[sp-1];
		}
		break;
		
	//EQL
	case 10:
		fprintf(ofp, "EQL\t");
		if(bp == gp)
		{
			dp = dp-1;
			pas[dp] = pas[dp] == pas[dp+1];
        	}
		else
        	{
			sp= sp+1;
			pas[sp] = pas[sp] == pas[sp-1];
		}
		break;
		
	//NEQ
	case 11:
		fprintf(ofp, "NEQ\t");
		if(bp == gp)
		{
			dp = dp-1;
			pas[dp] = pas[dp] != pas[dp+1];
        	}
		else
        	{
			sp = sp+1;
			pas[sp] = pas[sp] != pas[sp-1];
		}
		break;
		
	//LSS
	case 12:
		fprintf(ofp, "LSS\t");
		if(bp == gp)
		{
			dp = dp-1;
			pas[dp] = pas[dp] < pas[dp+1];
        	}
		else
        	{
			sp = sp+1;
			pas[sp] = pas[sp] < pas[sp-1];
		}
		break;
		
	//LEQ
	case 13:
		fprintf(ofp, "LEQ\t");
		if(bp == gp)
		{
			dp = dp-1;
			pas[dp] = pas[dp] <= pas[dp+1];
        	}
		else
        	{
			sp = sp+1;
			pas[sp] = pas[sp] <= pas[sp-1];
		}
		break;
		
	//GTR
	case 14:
		fprintf(ofp, "GTR\t");
		if(bp == gp)
		{
			dp = dp - 1;
			pas[dp] = pas[dp] > pas[dp+1];
        	}
		else	
        	{    
			sp = sp+1;
			pas[sp] = pas[sp] > pas[sp-1];
		}
		break;
		
	//GEQ
	case 15:
		fprintf(ofp, "GEQ\t");
		if(bp == gp)
		{
			dp = dp-1;
			pas[dp] = pas[dp] >= pas[dp+1];
        	}
		else
        	{
			sp sp+1;
			pas[sp] = pas[sp] >= pas[sp-1];
        	}
		break;
		
	//LOD
	case 16:
		fprintf(ofp, "LOD\t");
		if(bp == gp)
		{
			dp = dp+1;
			pas[dp] = pas[gp+M];
        	}	
		else if(base(L) == gp)
        	{
			sp = sp-1;
			pas[sp] = pas[gp+M];
        	}
		else
        	{
			sp = sp-1;
			pas[sp] = pas[base(L)-M];
        	}
		break;
		
	//STO
	case 17:
		fprintf(ofp, "STO\t");
		if(bp == gp)
		{
			pas[gp+M] = pas[dp];
			dp = dp-1;
        	}
		else if(base(L) == gp)
        	{
			pas[gp+M] = pas[sp];
			sp = sp+1;
        	}
		else
        	{
			pas[base(L)-M] = pas[sp];
			sp = sp+1;
        	}
		break;
		
	//CAL
	case 18:
		fprintf(ofp, "CAL\t");
		pas[sp-1] = base(L);
		pas[sp-2] = bp;
		pas[sp-3] = pc;
		bp = sp-1;
		pc = M;
		break;
		
	//INC
	case 19:
		fprintf(ofp, "INC\t");
		if(bp == gp)
		{
			dp = dp+M;
        	}
		else
        	{
			sp = sp-M;
		}
		break;
		
	//JMP
	case 20:
		fprintf(ofp, "JMP\t");
		pc = M;
		break;
		
	//JPC
	case 21:
		fprintf(ofp, "JPC\t");
		if(bp == gp)
		{
			if(pas[dp] == 0
			{
				pc = M;
			}
			dp = dp-1;
			
			else if(pas[sp] == 0
			{
				pc = M;
			}
			sp = sp+1;
		}
		break;
		
  // SYS
  case 22:
      switch(IR.M)
      {
         fprintf(ofp, "SYS\t");
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
 default:
     fprintf(ofp, "err\t");
     return;
 }                        
}
}
