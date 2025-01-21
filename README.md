# CSCE4430Lexer
Name: Jade Mitchell

HOW TO COMPILE:
1. You first run the file by compiling using the command "g++ lexanalyzer.cpp"
2. You then run the program by using the "./a.out" command.
3. It starts off by asking for the file name. 
Enter the file name of your choosing. (test1.txt, test2.txt, or test3.txt)
4. Once you choose an input file, it will prompt you to enter the name of the output file.
(output1.txt, output2.txt, or output3.txt)
5. Once you have entered the input and output files, the code will run the lexical analyzer and end.
To view the output files, you can entering the cat command and the output file name to show the output.
(e.g. cat output1.txt)



DESCRIPTION: 
My code is a lexical analyzer using C++. It starts off by opening 
a file of the user's choice and gets every line of the file.
I have put all of the 32 keywords into a constant string array
that makes it easier to know when a keyword is detected.
I have used a constant char array for the operators and punctuations.
I then created 5 boolean functions that identify what a character/ string is,
where it's a keyword, identifier, integer literal, operator, or punctuation.
The code analyzer function analyzes the characters of each lines and uses the 5 
functions to decipher which category the character/ token belongs to. In the code 
and token analyzer functions, any outputs, output to a .txt file of
my choosing.
