#include<stdio.h>
#include<string.h>
void check_lb();
void check_opcd();
void R_line_1();
struct opcodetab//CREATION OF OPCODE TABLE
{
    char  code[10],objcode[10];
}myopcodetab[5]={
                   {"LDA","00"},
                   {"JMP","01"},
                   {"STA","02"},
                    {"WORD","03"}
                    };


struct symbol_tab{//CREATION OF SYMBOL TABLE
                    char symbol[10];
                    int addr;
              }mysymbol_tab[10];

int startaddress,loc_ctr,sym_count=0,length;
char line_1[20],lbl[8],opcode[8],operand[8],programmename[10];

           void ps_1()//START OF PASS 1:------------------------------------
                  {
                       FILE *input,*inter,*fp;
                       char ch;
                        printf("\n\n...THE CONTENTS OF INPUTED FILE IS...\n\n");//PRINTING OF INPUT FILE
                        fp=fopen("INPUT.txt","r");
                        ch=fgetc(fp);
                    while(ch!=EOF)
                        {
                            printf("%c",ch);
                            ch=fgetc(fp);
                        }
                            printf("\n");

                       input=fopen("INPUT.txt","r");
                       inter=fopen("INTERMEDIATE.txt","w");
                       printf("\n---FILE AFTER ADDRESSING IS---\n");//PRINTING OF INTERMEDIATE FILE
                        printf("\nLOCATION_LABEL\tOPERAND\tOPCODE\n");
                    printf("_____________________________________");
                        fgets(line_1,20,input);

                      R_line_1();

                     if(!strcmp(opcode,"START"))
                      {

                       startaddress=atoi(operand);
                       loc_ctr=startaddress;
                      strcpy(programmename,lbl);

                        fprintf(inter,"%s",line_1);
                       fgets(line_1,20,input);
                       }
                      else
                      {
                          programmename[0]='\0';
                          startaddress=0;
                          loc_ctr=0;
                      }
                         printf("\n %d\t %s\t%s\t %s",loc_ctr,lbl,opcode,operand);

                           while(strcmp(line_1,"END")!=0)
                          {

