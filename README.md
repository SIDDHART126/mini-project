MINI-PROJECT-5TH-SEMESTER

CONTRIBUTERS:
    
    SIDDHART SINGHAL        5TH SEM (CS-C)    ROLLNO.-2007557
    UDIT SINGH              5TH SEM (IT)      ROLLNO.-2007730

PROGRAM-Take your own hypothetical machine - create different mnemonics that can be used for that machine. Write an assembler for performing the conversion of assembly into machine code. Write the object program in another file and load the file in memory. Show the output of every step. 

Breif Description:
An assembler is a translator, that translates an assembler program into a conventional machine language program. Basically, the assembler goes through the program one line at a time, and generates machine code for that instruction. Then the assembler procedes to the next instruction. In this way, the entire machine code program is created. For most instructions this process works fine, for example for instructions that only reference registers, the assembler can compute the machine code easily, since the assembler knows where the registers are.
THE assembler mainly works in 2 passes

Pass-1
1. Assign addresses to all the statements
2. Save the addresses assigned to all labels to be used in Pass-2
3. Perform some processing of assembler directives to find
the length of data areas for assigning the address values.
4. Defines the symbols in the symbol table(generate the symbol table)


Pass-2
1. Assemble the instructions (translating operation codes and looking up addresses).
2. Generate data values defined by BYTE, WORD etc.
3. Perform the processing of the assembler directives not done during pass-1.
4. Write the object program and assembler listing.

ABOUT OUR CODE:
This program mainly works on two passes of assembler...pass1 and pass2
IN assembler program.c we have mainly two functions:

PASS 1-
1)The program takes input.txt as input file in which input code is written (which we have to convert to its machine code) 
in pass 1 and opens it up in read mode an is processed
2)After this an intermediate file intermediate.txt is generated..which is the addressed version of input.txt and this file is latte on used in pass 2 as input.
3)Symbol table is also generated in Pass 1, labels are entered into SYMTAB, along with assigned addresses (using LOCCTR).
In Pass 2, symbols used as operands are look up in SYMTAB to obtain the addresses.

PASS2-
Now that addressed code is written in intermediate.txt file now used as an input for pass 2..
In pass 2 intermediate.txt is opened in read mode and the object code of program is writen in output.txt and displayed on screen and this was the code that we required...


