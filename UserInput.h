#include <iostream>


using namespace std;
class userInput
{
  public:
    bool getUserBool(std::string prompt, std::string boolTrue, std::string boolFalse);
};

bool getUserBool(std::string prompt, std::string boolTrue, std::string boolFalse)//prompts the user for a boolean answer. user must answer with either the second or third input
{
  std::string userInput = "";

  do
  {
    std::cout << prompt << std::endl;
    std::cin >> userInput;
  }while(userInput != boolTrue && userInput != boolFalse);//repeat while incorrect input is given. Stop when correct is given
  if(userInput == boolTrue)
  {
    return true;
  }
  else
  {
    return false;
  }
}
