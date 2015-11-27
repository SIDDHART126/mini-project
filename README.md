MINI-PROJECT-5TH-SEM

    SIDDHART SINGHAL        5TH SEM (CS-C)    ROLLNO.-2007557
    UDIT SINGH              5TH SEM (IT)      ROLLNO.-2007

PROGRAM-Take your own hypothetical machine - create different mnemonics that can be used for that machine. Write an assembler for performing the conversion of assembly into machine code. Write the object program in another file and load the file in memory. Show the output of every step. 

An assembler is a translator, that translates an assembler program into a conventional machine language program. Basically, the assembler goes through the program one line at a time, and generates machine code for that instruction. Then the assembler procedes to the next instruction. In this way, the entire machine code program is created. For most instructions this process works fine, for example for instructions that only reference registers, the assembler can compute the machine code easily, since the assembler knows where the registers are.



This program mainly works on two passes of assembler...pass1 and pass2
The program takes input.txt as input file in pass 1 and open it up in read mode and the intermediate.txt is  generated..which is the addressed version of input.txt and this file is latte on used in pass 2. and the object program is generated in passs 2 which is stored in output.txt

IN pass 1 addressing of the input code takes place which is in input.txt...and addressed file is written in intermediate.txt..which is the intermediate file of this program

Now that addressed code is written in intermediate.txt file now this  is used as an input for pass 2..
In pass 2 intermediate.txt is opened in read mode and the object code of program is writen in output.txt and displayed on screen
their are opcodes and symbol table too....which are used in both pass1 and pass2...

pass 1 generate the symbol table and which is latter on used in pass 2 for generating the object code if the program....



