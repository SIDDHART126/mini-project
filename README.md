MINI-PROJECT-5TH-SEM

PROGRAM-Take your own hypothetical machine - create different mnemonics that can be used for that machine. Write an assembler for performing the conversion of assembly into machine code. Write the object program in another file and load the file in memory. Show the output of every step. 

An assembler is a translator, that translates an assembler program into a conventional machine language program. Basically, the assembler goes through the program one line at a time, and generates machine code for that instruction. Then the assembler procedes to the next instruction. In this way, the entire machine code program is created. For most instructions this process works fine, for example for instructions that only reference registers, the assembler can compute the machine code easily, since the assembler knows where the registers are.

This program mainly works on two passes of assembler...pass1 and pass2
The program takes input.txt as input file in pass 1 and intermediate.txt as input in pass 2 and writes result in output.txt
IN pass 1 addressing of the input code takes place which is in input.txt...and addressed file is written in intermediate.txt..which is the intermediate file of this program
Now that addressed code is written in intermediate.txt file which is used as an input for pass 2..
In pass 2 intermediate.txt is opened in read mode and the object code of program is writen in output.txt


