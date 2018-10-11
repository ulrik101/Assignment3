#include <iostream>
#include<fstream>
#include "GenStack.h"
using namespace std;
class DelimiterChecker
{
public:
  DelimiterChecker();
  DelimiterChecker(std::string inputFileName);
  ~DelimiterChecker();
  void setFileName(std::string inputFileName);
  bool checkDelimiters();

private:
  std::string fileName;
  int lineCount;
  int openDelimCount;
  int closedDelimCount;
  std::string openDelChar = "{([";
  std::string closDelChar = "])}";

  bool checkLine(std::string input);
  char returnOpposite(char delim);
  GenStack<char> stack;

};
void setFileName(std::string inputFileName)
{

}
DelimiterChecker::DelimiterChecker()
{
  lineCount = 0;
  openDelimCount = 0;
  closedDelimCount = 0;
}
DelimiterChecker::DelimiterChecker(std::string inputFileName)
{
  fileName = inputFileName;
  lineCount = 0;
  openDelimCount = 0;
  closedDelimCount = 0;
}
DelimiterChecker::~DelimiterChecker()
{

}
char DelimiterChecker::returnOpposite(char delim)
{
  if(delim == '}')
  {
    return '{';
  }
  if(delim == ')')
  {
    return '(';
  }
  if(delim == ']')
  {
    return '[';
  }


  if(delim == '{')
  {
    return '}';
  }
  if(delim == '(')
  {
    return ')';
  }
  if(delim == '[')
  {
    return ']';
  }

  return '\0';
}

bool DelimiterChecker::checkLine(std::string input)
{
  lineCount++;
  for(int i = 0; i < input.size(); i++)//for each character in the line
  {
        if(openDelChar.find(input[i]) != std::string::npos)//if opening delimiter is found
        {
          stack.push(input[i]);//add to stack
          openDelimCount+=1;
        }
        if(closDelChar.find(input[i]) != std::string::npos)//if closing delimiter is found
        {
          if(stack.isEmpty() == false)
          {
            closedDelimCount+=1;
            if(stack.peek() == returnOpposite(input[i]))//if delimiter matches Stack
            {
                stack.pop();//pop Stack
            }
            else//throw error that delimiter did not match
            {
              //std::cout << "Found "<< input[i] <<" on line "<< lineCount << " but previous " << stack.peek() << " requires " << returnOpposite(stack.peek()) << std::endl;
              std::cout << "Line " << lineCount << " Error: Expected " << returnOpposite(stack.peek()) << " but found "  << input[i] << std::endl;

              return false;
            }
          }
          else//closing delim but empty stack
          {
            //std::cout << "Found "<< input[i] <<" on line "<< lineCount <<" that is missing expected opening delimiter " << returnOpposite(input[i]) << std::endl;
            std::cout << "Line "<< lineCount << " Error: Found unexpected closing delimiter " << input[i] << std::endl;

            return false;
          }
        }//end of open and close delim check
  }//end of for each check
  return true;
}

bool DelimiterChecker::checkDelimiters()
{
  ifstream file(fileName);
  if(file.is_open())
  {
    while(!file.eof())
    {
      std::string local_string;
      file >> local_string;
      //std::cout << lineCount+1<< ": "<<local_string << std::endl;
      if(checkLine(local_string)!=true)
      {
        return false;
      }
    }
  }
  if(openDelimCount == closedDelimCount)
  {
    std::cout << "Analysis complete. All delimiters accounted for. " << std::endl;
    return true;
  }
  else
  {
    std::cout << "Line " << lineCount <<" Error: Reached end of file but missing closing delimiter " << returnOpposite(stack.peek()) << std::endl;
    return false;
  }
}
