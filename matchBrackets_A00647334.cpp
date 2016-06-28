/*==================================================================================
matchBrackets_A00647334.cpp

Luis Gomez
12/01/2015
CS2308-002-Project #7

This code takes 1 input file and checks to see if all the brackets((), [], {}) 
all match each other. 
================================================================================*/

#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2)
      {
      cout << "Argument required: " << endl
           << "Example: $ ./executable <filename>" << endl;
      return false;
      }
   
    ifstream fin;
    fin.open(argv[1]);

    //checks to make sure there is an input file
    if(!fin)
      {
      cout << "Error opening file!" << endl;
      fin.close();
      return false;
      }

    stack <char> s;
    int ln = 1;
    char ch;

        while (fin >> noskipws >> ch) 
               { 
              //if( ch == '\n')
                //  ln++;
              if(ch == '{')
                 s.push('}');
              if(ch == '(')
                 s.push(')');
              if(ch == '[')
                 s.push(']');

              if(ch == ')' || ch == ']' || ch == '}')
                  {
                  if(s.empty())
                     {
                     cout << "ERROR (line " << ln << "): unmatched " << ch << endl; 
                     return false;
                     }
                  if(ch != s.top())
                     {
                     cout << "ERROR (line " << ln << "): expected " << s.top() 
                          << " but found " << ch << endl;
                     return false;
                     }  
                     s.pop();
                    }
                  if(ch == '\n')
                     ln++;
                   }    
                    
    if(!s.empty())
      {
      cout << "ERROR (line " << ln << "): missing " << s.top() << endl;
      return false;
      }

    cout << "No errors found!" << endl;
 
    return true;
}                 
