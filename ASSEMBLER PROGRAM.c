void ps_2()//START OF PASS 2:------------------------------------
          {
                FILE *inter,*output;
                char record[30],part[8],value[5];
                int currenttxtln=0,fndopcode,foundoperand,check1,oprand_address,recaddress=0;
                inter=fopen("INTERMEDIATE.txt","r");
                output=fopen("OUTPUT.txt","w");
                fgets(line_1,20,inter);

                R_line_1();
                if(!strcmp(opcode,"START")) fgets(line_1,20,inter);
               printf("\n\n...CORRESSPONDING OBJECT CODE IS...\n");//PRINTING OF OBJECT CODE
               printf("\nH^ %s ^ %d ^ %d ",programmename,startaddress,length);//FOR HEADER RECORD
               fprintf(output,"\nH^ %s ^ %d ^ %d ",programmename,startaddress,length);
               recaddress=startaddress; record[0]='\0';
               while(strcmp(line_1,"END")!=0)
                        {
                                oprand_address=foundoperand=fndopcode=0;
                                value[0]=part[0]='\0';
                                R_line_1();
            for(check1=0;check1<3;check1++)
             {
               if(!strcmp(opcode,myopcodetab[check1].code))
               {
               fndopcode=1;
               strcpy(part,myopcodetab[check1].objcode);

             if(operand[0]!='\0')
             {
             for(check1=0;check1<sym_count;check1++)

             if(!strcmp(mysymbol_tab[check1].symbol,operand))
             {
             itoa(mysymbol_tab[check1].addr,value,10);
             strcat(part,value);
             foundoperand=1;
             }
              if(!foundoperand)strcat(part,"err");
              }
              }
              }
               if(!fndopcode)
               {
                               if(strcmp(opcode,"BYTE")==0||strcmp(opcode,"WORD")||strcmp(opcode,"RESB"))
                               {
