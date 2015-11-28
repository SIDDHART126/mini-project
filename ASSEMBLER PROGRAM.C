#include<stdio.h>
#include<string.h>
void check_lb();//FUNCTION TO CHECK LABELS
void check_opcd();//FUNCTIONS TO CHECK OPCODES
void W_line_1();
struct opcde_tab//CREATION OF OPCODE TABLE
{
    char  cde[10],objcde[10];
}myopcde_tab[5]={
                   {"LDA","10"},
                   {"JMP","21"},
                   {"STA","32"},
                    {"WORD","43"},
                    {"LDCH","53"}
                    };


struct sym_tb{//CREATION OF SYMBOL TABLE
                    char sym[10];
                    int address;
              }mysym_tb[10];

int startaddressess,loc_ctr,sym_count=0,len,f=0;
char line_1[20],lbl[8],opcde[8],oprnd[8],programmename[10];

           void ps_1()//START OF PASS 1:------------------------------------
                  {
                       FILE *fp1;FILE *fp2; FILE *fp;//FILE POINTERS
                       char ch;
                        printf("\n...CONTENTS OF INPUT FILE IS...\n");//PRINTING OF INPUT FILE
                        fp=fopen("INPUT.txt","r");//OPENING INPUT FILE IN READ MODE
                        ch=fgetc(fp);
                    while(ch!=EOF)
                        {
                            printf("%c",ch);
                            ch=fgetc(fp);
                        }
                            printf("\n");

                       fp1=fopen("INPUT.txt","r");
                       fp2=fopen("INTERMEDIATE.txt","w");//OPENING INTERMEDIATE FILE IN WRITE MODE
                       printf("\n---INTERMEDIATE FILE IS---\n");//PRINTING OF INTERMEDIATE FILE
                        printf("\nADDRESS\tLABEL\tOPERAND\tOPCODE\n");
                    printf("_____________________________________");
                        fgets(line_1,20,fp1);

                      W_line_1();

                     if(!strcmp(opcde,"PROG"))//CHECKING OF STARTING SYMBOL
                      {

                       startaddressess=atoi(oprnd);
                       loc_ctr=startaddressess;
                      strcpy(programmename,lbl);

                        fprintf(fp2,"%s",line_1);
                       fgets(line_1,20,fp1);
                       }
                      else
                      {
                          programmename[0]='\0';
                          startaddressess=0;
                          loc_ctr=0;
                      }
                         printf("\n %d\t %s\t%s\t %s",loc_ctr,lbl,opcde,oprnd);

                           while(strcmp(line_1,"END")!=0)//CHECKING FOR END SYMBOL
                          {

                                   W_line_1();
                                   printf("\n %d\t %s \t%s\t %s",loc_ctr,lbl,oprnd);
                                   if(lbl[0]!='\0')check_lb();
                                   check_opcd();
                                   fprintf(fp2,"%s %s %s\n",lbl,oprnd);
                                   fgets(line_1,20,fp1);
                          }

                   printf("\n %d\t\t%s",loc_ctr,line_1);
                   fprintf(fp2,"%s",line_1);

                    fclose(fp2);//CLOSING OF INERMEDIATE FILE
                    fclose(fp1);//CLOSING OF INPUT FILE
                      }

          void ps_2()//START OF PASS 2:------------------------------------
          {
                FILE *fp2,*output;//FILE POINTERS
                char recrd[30],prt[8],vlue[5];
                int currenttxtln=0,fndopcode,foundoperand,check1,oprand_address,recaddress=0;
                fp2=fopen("INTERMEDIATE.txt","r");//OPENING INTERMEDIATE FILE IN READ MODE
                output=fopen("OUTPUT.txt","w");//OPENING OUTPUT FILE IN WRITE MODE
                fgets(line_1,20,fp2);

                W_line_1();
                if(!strcmp(opcde,"PROG")) fgets(line_1,20,fp2);
               printf("\n\n... OBJECT CODE IS...\n");//PRINTING OF OBJECT CODE
               printf("\nH^ %s ^ %d ^ 00%d \n",programmename,startaddressess,len);//FOR HEADER RECORD
               fprintf(output,"\nH^ %s ^ %d ^ 00%d \n",programmename,startaddressess,len);
               recaddress=startaddressess; recrd[0]='\0';
               while(strcmp(line_1,"END")!=0)
                        {
                                oprand_address=foundoperand=fndopcode=0;
                                vlue[0]=prt[0]='\0';
                                W_line_1();
            for(check1=0;check1<3;check1++)
             {
               if(!strcmp(opcde,myopcde_tab[check1].cde))
               {
               fndopcode=1;
               strcpy(prt,myopcde_tab[check1].objcde);

             if(oprnd[0]!='\0')
             {
             for(check1=0;check1<sym_count;check1++)

             if(!strcmp(mysym_tb[check1].sym,oprnd))
             {
             itoa(mysym_tb[check1].address,vlue,10);
             strcat(prt,vlue);
             foundoperand=1;
             }
              if(!foundoperand)strcat(prt,"err");
              }
              }
              }
               if(!fndopcode)
               {
                               if(strcmp(opcde,"BYTE")==0||strcmp(opcde,"WORD")||strcmp(opcde,"RESB"))
                               {
                                   strcat(prt,oprnd);
                              }
               }
               if((currenttxtln+strlen(prt))<=8)
               {
                strcat(recrd," ");
                strcat(recrd,prt);

                currenttxtln=currenttxtln+strlen(prt);
               }
                else
                {
                    if(f==0)
                 {
                     printf(" T^ %d %s",recaddress,recrd);//FOR TEXT RECORD
                 fprintf(output," T^ %d %s",recaddress,recrd);
                 recaddress+=currenttxtln/2;
                 currenttxtln=strlen(prt);
                 strcpy(recrd,prt);
                 f=1;
                 }
                 else{
                    printf(" ^ %d %s",recaddress,recrd);//FOR TEXT RECORD
                 fprintf(output," ^ %d %s",recaddress,recrd);
                 recaddress+=currenttxtln/2;
                 currenttxtln=strlen(prt);
                 strcpy(recrd,prt);
                 }
                }
          fgets(line_1,20,fp2);
                }
                      printf(" ^%d %s",recaddress,recrd);
                      fprintf(output," ^ %d %s",recaddress,recrd);
                      printf("\nE^ %d\n",startaddressess);//FOR END RECORD
                      fprintf(output,"\nE^ %d\n",startaddressess);
                      fclose(fp2);
                      fclose(output);
       }

       void W_line_1()
       {
            char buffer[8],firstwrd[8],sendwrd[8],thirdwrd[8];
            int i,j=0,count=0;
             lbl[0]=opcde[0]=oprnd[0]=firstwrd[0]=sendwrd[0]=thirdwrd[0]='\0';
                 for(i=0;line_1[i]!='\0';i++)
                      {
                   if(line_1[i]!=' ')buffer[j++]=line_1[i];
                   else
                      {
                     buffer[j]='\0';
                     strcpy(thirdwrd,sendwrd);strcpy(sendwrd,firstwrd);strcpy(firstwrd,buffer);
                     j=0;count++;
                      }
                      }
                      buffer[j-1]='\0';
                      strcpy(thirdwrd,sendwrd);
                      strcpy(sendwrd,firstwrd);
                      strcpy(firstwrd,buffer);
                    switch(count)
                       {
                            case 0:strcpy(opcde,firstwrd);break;
                            case 1:{strcpy(opcde,sendwrd);strcpy(oprnd,firstwrd);}break;
                            case 2:{strcpy(lbl,thirdwrd);strcpy(opcde,sendwrd);strcpy(oprnd,firstwrd);}break;
                       }
                       }

            void check_lb()//CHECK FOR SYMBOL TABLE
                  {
                       int k,dupsy=0;
                     for(k=0;k<sym_count;k++)
                     if(!strcmp(lbl,mysym_tb[k].sym))
                     {
                                                          mysym_tb[k].address=-1;
                                                          dupsy=1;
                                                          break;
                                                          }
               if(!dupsy)
               {
               strcpy(mysym_tb[sym_count].sym,lbl);
               mysym_tb[sym_count++].address=loc_ctr;
                }
                }

  void check_opcd()//CHECK FOR OPCODE TABLE
         {

          int l=0,found=0;
          for(l=0;l<3;l++)


                          if(!strcmp(opcde,myopcde_tab[l].cde))
                          {

                                                     loc_ctr+=3;
                                                     found=1;
                                                     break;
                           }

    }
  int main()
                    {

                            int i;
                            ps_1();//CALLING OF PASS 1
                            len=loc_ctr-startaddressess;
                            printf("\t\n\n");
                          printf("\n\n...THE SYMBOL TABLE IS...\n\n");//PRINTING OF SYMBOL TABLE
                         for(i=0;i<4;i++)
                        {
                            printf("%s\t%d\n",mysym_tb[i].sym,mysym_tb[i].address);
                        }
                        ps_2();//CALLING OF PASS 2
                    }
