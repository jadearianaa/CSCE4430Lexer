#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <string>

using namespace std;

/* Name: Jade Mitchell
   EUID: jam1375
   Class: CSCE 4430.001
*/

const string keywords[] = {"auto", "break", "case", "char", "const",
 "continue", "default", "do", "double", "else", "enum", "extern", 
 "float", "for", "goto", "if", "int", "long", "register", "return", 
 "short", "signed", "sizeof", "static", "struct", "switch", "typedef", 
 "union", "unsigned", "void", "volatile", "while"};

const char operators[] = {'+', '-','*', '/', '=', '%'};
const char punctuations[] = {'(', ')', '{', '}', ';', ',', '#', '<', '>', '.', '"'};

string token;
ifstream fin;
ofstream fout;

bool isKeyword(const string& str)
{
    for(int i = 0; i < (sizeof(keywords)/ sizeof(keywords[0])); i++) 
    {
        if(str == keywords[i])
        {
            return true;
        }
    }

    return false;
}

bool isOperator(char ch)
{
    for(char oper : operators)
    {
        if(ch == oper)
        {
            return true;
        }
    }
    return false;
}

bool isPunctuation(char ch)
{
    for( char punc : punctuations)
    {
        if(ch == punc)
        {
            return true;
        }
    }
    return false;
}

bool isIdentifier(const string& str)
{
    if(str.empty() || isdigit(str[0]))
    {
        return false;
    }

    for(char ch : str)
    {
        if(!isalnum(ch) && ch!= '_')
        {
            return false;
        }
    }

    return true;
}

bool isInt(const string& str)
{
    if(str.empty())
    {
        return false;
    }

    for(char ch : str)
    {
        if(!isdigit(ch))
        {
            return false;
        }
    }

    return true;
}

void addChar(char ch)
{
    token += ch;
}

void tokenAnalyzer(ofstream &fout)
{
    if(isKeyword(token))
    {
        fout<<token<<", keyword"<<endl;
    }
    else if(isIdentifier(token))
    {
        fout<<token<<", identifier"<<endl;
    }
    else if(isInt(token))
    {
        fout<<token<<", integer"<<endl;
    }

    token.clear();
    
}

void codeAnalyzer(ofstream &fout, const string& code)
{
    for(int i = 0; i< code.length(); i++)
    {
        char ch = code[i];

        if(isspace(ch))
        {
            if (!token.empty()) 
            { 
                tokenAnalyzer(fout);
            }
        } 
        else if (isOperator(ch)) 
        {
            fout<<ch<<", operator"<<endl;
            tokenAnalyzer(fout);

        } else if (isPunctuation(ch)) 
        {
            fout<<ch<<", punctuation"<<endl;
            tokenAnalyzer(fout);
            
        } 
        else 
        {
            addChar(ch);
        }
    }
    if(!token.empty())
    {
        tokenAnalyzer(fout);
    }
  
}



int main()
{
    string file;
    string output;
    string line;
    string code;

    cout<<"Enter file name you would like to open: ";
    cin>>file;
    fin.open(file);

    if(fin.fail())
    {
        cout<< "ERROR - cannot open "<<file<<endl;
        exit(1);
    }



    while(getline(fin, line))
    {
        code += line + '\n';
    }

    fin.close();

    cout<<"Enter output file name: ";
    cin>>output;


    fout.open(output);

	if(fout.fail())
	{cout<<"ERROR - cannot open output file "<<endl;
		exit(1);
	}

    codeAnalyzer(fout, code);

    fout.close();

    return 0;
}

