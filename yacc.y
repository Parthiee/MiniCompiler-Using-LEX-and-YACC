%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern FILE *yyin;
FILE *inter;
FILE *assembly;
FILE *inter_op;


struct Operation
{
	char* operand1;
	char* operator;
	char* operand2;
}conds;

int yyerror(char *s);
char *truelabel, *falselabel, *nextlabel; 
char* createTemp()
{
  static int tempcount=0;
  char* temp = malloc(10);
  sprintf(temp,"t%d",tempcount++);
  return temp;
}

char* createRegister()
{
  static int registercount=0;
  char* temp = malloc(10);
  sprintf(temp,"R%d",registercount++);
  return temp;
}
char* createLabel()
{
  static int labelcount=100;
  char* temp = malloc(10);
  sprintf(temp,"L%d",labelcount++);
  return temp;
}



%}

%union
{
int intval;
float floatval;
char* addr;
}

%left '+' '-'
%left '*' '/'
%right UMINUS
%token <addr>ID INT FLOAT UMINUS <addr>REL_LT <addr>REL_LTEQ <addr>REL_EQ <addr>REL_NEQ <addr>REL_GT <addr>REL_GTEQ IF ELSE <intval>NUM
%type <addr>S <addr>E <addr>REL_E <intval>NUM_E

%%
SS : 
   | SS P
   ;
   

P : D
  | S
  ;
  
D : T DD ';'D
   |
   ;
  
DD : ID ',' DD
   | ID
   ;

T : INT | FLOAT
  ;
  
S : ID '=' E ';' { fprintf(inter,"%s := %s\n",$1,$3); 

fprintf(assembly,"MOV %s,%s\n",$1,$3);
}
  | ID '=' NUM_E ';' { fprintf(inter,"%s := %d\n",$1,$3); 
  fprintf(assembly,"MOV %s,#%d\n",$1,$3);
}
  ;
  
E : E '+' E { 
  $$ = createTemp();
  
  if(!strcmp($1,"0"))
  {
      fprintf(inter,"%s := %s\n",$$,$3); 
      char* temp = createRegister();
      fprintf(assembly,"MOV %s,%s\n",temp,$3);
      fprintf(assembly,"MOV %s,%s\n",$$,temp);
  }
  else if(!strcmp($3,"0"))
  {
  	fprintf(inter,"%s := %s\n",$$,$1); 
  	
      char* temp = createRegister();
      fprintf(assembly,"MOV %s,%s\n",temp,$1);
      fprintf(assembly,"MOV %s,%s\n",$$,temp);
  }
  else
    {
      char* temp1 = createRegister();
      char* temp2 = createRegister();
      fprintf(inter,"%s := %s + %s\n",$$,$1,$3); 
      fprintf(assembly,"MOV %s,%s\n",temp1,$1);
      fprintf(assembly,"MOV %s,%s\n",temp2,$3);
      fprintf(assembly,"ADD %s,%s\n",temp1,temp2);
      fprintf(assembly,"MOV %s,%s\n",$$,temp1);
    }

  
 
  } 
	
  | E '-' E { 
  $$ = createTemp();
  fprintf(inter,"%s := %s - %s\n",$$,$1,$3); 
  
      char* temp1 = createRegister();
      char* temp2 = createRegister();
      fprintf(assembly,"MOV %s,%s\n",temp1,$1);
      fprintf(assembly,"MOV %s,%s\n",temp2,$3);
      fprintf(assembly,"SUB %s,%s\n",temp1,temp2);
      fprintf(assembly,"MOV %s,%s\n",$$,temp1);
  }
  | E '*' E { 
  $$ = createTemp();
  
   if(!strcmp($1,"1"))
  {
      fprintf(inter,"%s := %s\n",$$,$3); 
      char* temp = createRegister();
      fprintf(assembly,"MOV %s,%s\n",temp,$3);
      fprintf(assembly,"MOV %s,%s\n",$$,temp);
  }
  else if(!strcmp($3,"1"))
  {
      fprintf(inter,"%s := %s\n",$$,$1); 
      char* temp = createRegister();
      fprintf(assembly,"MOV %s,%s\n",temp,$1);
      fprintf(assembly,"MOV %s,%s\n",$$,temp);
  }
  else{
      char* temp1 = createRegister();
      char* temp2 = createRegister();
        fprintf(inter,"%s := %s * %s\n",$$,$1,$3); 
      fprintf(assembly,"MOV %s,%s\n",temp1,$1);
      fprintf(assembly,"MOV %s,%s\n",temp2,$3);
      fprintf(assembly,"MUL %s,%s\n",temp1,temp2);
      fprintf(assembly,"MOV %s,%s\n",$$,temp1);
  
  }
  

  
  
  }
  | E '/' E { 
  $$ = createTemp();
  fprintf(inter,"%s := %s / %s\n",$$,$1,$3); 
  
     char* temp1 = createRegister();
      char* temp2 = createRegister();
      fprintf(assembly,"MOV %s,%s\n",temp1,$1);
      fprintf(assembly,"MOV %s,%s\n",temp2,$3);
      fprintf(assembly,"DIV %s,%s\n",temp1,temp2);
      fprintf(assembly,"MOV %s,%s\n",$$,temp1);
      
  }
  | '-' E %prec UMINUS { 
  $$ = createTemp();
  fprintf(inter,"%s := - %s\n",$$,$2); 
  
      char* temp1 = createRegister();
      char* temp2 = createRegister();
      fprintf(assembly,"MOV %s,%s\n",temp1,$2);
      fprintf(assembly,"NOT %s\n",temp1);
      fprintf(assembly,"ADD %s,#1\n",temp1);
      fprintf(assembly,"MOV %s,%s\n",$$,temp1);
  
  }
  | ID { $$ = strdup($1); }
  | NUM_E {
  	$$ = malloc(10);
  	sprintf($$,"%d",$1);
  }
  ;
  
 NUM_E : NUM_E '+' NUM_E { $$ = $1 + $3; }
       | NUM_E '-' NUM_E { $$ = $1 - $3; }
       | NUM_E '*' NUM_E { $$ = $1 * $3; }
       | NUM_E '/' NUM_E { $$ = $1 / $3; }
       | '-' NUM_E { $$ = -$2; }
       | NUM {$$ = $1; }
       ;

REL_E :  E REL_LT E { 
  $$ = createTemp();
  fprintf(inter,"%s := %s %s %s\n",$$,$1,$2,$3);
  conds.operand1 = strdup($1);
  conds.operator = strdup($2);
  conds.operand2 = strdup($3);
  }
  | E REL_LTEQ E {
  $$ = createTemp(); fprintf(inter,"%s := %s %s %s\n",$$,$1,$2,$3); 
  conds.operand1 = strdup($1);
  conds.operator = strdup($2);
  conds.operand2 = strdup($3);
  }
  | E REL_EQ E { 
  $$ = createTemp(); fprintf(inter,"%s := %s %s %s\n",$$,$1,$2,$3); 
  conds.operand1 = strdup($1);
  conds.operator = strdup($2);
  conds.operand2 = strdup($3);
  }
  | E REL_NEQ E { 
  $$ = createTemp();
  fprintf(inter,"%s := %s %s %s\n",$$,$1,$2,$3);
  conds.operand1 = strdup($1);
  conds.operator = strdup($2);
  conds.operand2 = strdup($3);
  }
  | E REL_GT E { $$ = createTemp();
  fprintf(inter,"%s := %s %s %s\n",$$,$1,$2,$3); 
  conds.operand1 = strdup($1);
  conds.operator = strdup($2);
  conds.operand2 = strdup($3);
  }
  | E REL_GTEQ E { $$ = createTemp(); 
  fprintf(inter,"%s := %s %s %s\n",$$,$1,$2,$3);
  conds.operand1 = strdup($1);
  conds.operator = strdup($2);
  conds.operand2 = strdup($3);
  
  }
  
S : IF '(' REL_E ')' {
 		truelabel = createLabel();
 		falselabel = createLabel();
		nextlabel = createLabel();
		fprintf(inter, "if_false %s goto %s\n", $3, falselabel);
		fprintf(assembly, "CMP %s,%s\n", conds.operand1, conds.operand2);
		if (!strcmp(conds.operator,"<"))
		 {
		    fprintf(assembly, "JG %s\n",falselabel);
		 }
		 else if (!strcmp(conds.operator,"<="))
		 {
		    fprintf(assembly, "JGE %s\n",falselabel);
		 }
		 else if (!strcmp(conds.operator,"=="))
		 {
		    fprintf(assembly, "JNE %s\n",falselabel);
		 }
		 else if (!strcmp(conds.operator,"!="))
		 {
		    fprintf(assembly, "JE %s\n",falselabel);
		 }
		 else if (!strcmp(conds.operator,">"))
		 {
		    fprintf(assembly, "JL %s\n",falselabel);
		 }
		 else if (!strcmp(conds.operator,">="))
		 {
		    fprintf(assembly, "JLE %s\n",falselabel);
		 }
		
		
		} 
  BLOCK  {
		fprintf(inter, "goto %s\n", nextlabel);
		 fprintf(assembly, "JMP %s\n",nextlabel);

            }
  ELSE     {
         	fprintf(inter, "%s:\n", falselabel); 
         	fprintf(assembly, "%s:\n",falselabel);
          }
  BLOCK 
 	 {
         	fprintf(inter, "%s:\n", nextlabel);
         	fprintf(assembly, "%s:\n", nextlabel); 
          }
  ;

 
  
BLOCK : '{' SS '}';

  
  
  
%%


int yyerror(char *s)
{
	printf("********** INCORRECT **********");
	exit(1);

}


int main(int argc, char **argv)
{
	yyin = fopen(argv[1], "r");
	inter = fopen("intermediate.i","a+");
	assembly = fopen("assembly.s","a+");
	inter_op = fopen("inter_op.i","a+");
	
	if(!yyin)
	{
		fprintf(stderr, "Can't open source code.");
		exit(1);
	}

	if(yyparse() == 0)
	{
		printf("********** CORRECT **********");
	}
	
	
	fclose(yyin);
	fclose(inter);
	fclose(assembly);
	return 0;
}