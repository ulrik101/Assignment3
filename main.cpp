#include <iostream>
//#include "GenStack.h"
//#include "DelimiterCheck.h"

#include "DelimiterChecker.h"
#include "UserInput.h"

#include "FileInput.h"

using namespace std;
//using namespace GenStack;



int main()
{


  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  //std::cout << "Has Delims: " << checker.checkDelimiters() << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  while(true)
  {

    std::string filename = getFileName("Enter Filename: ");
    DelimiterChecker checker(filename);
    if(checker.checkDelimiters() == false)
    {
      break;
    }
    if(getUserBool("Analyze another File?  [y/n]","y","n") == false)
    {
      break;
    }
    std::cin.ignore(1000,'\n');//
  }


  //std::cout << returnOpening('') << std::endl;
  //checkString("{}te(st");
  //checkString("{(){(){[]}[]}}");



  //std::cout << "END" << std::endl;


  return EXIT_SUCCESS;
}
