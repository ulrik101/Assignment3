#include <iostream>
#include<fstream>

using namespace std;
class FileInput
{
  public:
    std::string getFileName(std::string prompt);
};


std::string getFileName(std::string prompt)//gets file name from user
{
  std::string filename;
  while(true)
  {
    std::cout<< prompt << endl;
    //std::cin >> filename;
    
    std::getline(std::cin, filename);
    if(filename.find('.') != std::string::npos)
    {
      ifstream file(filename);
      try
      {
        if(file.is_open())//if file is open
        {
          std::cout << "File Selected." << std::endl;
          return filename;
          break;
        }
      }
      catch(const std::exception& e)
      {
        std::cout << "Error. Please try again. Proper format example: folder/file.txt  or  file.txt" << std::endl;
      }
    }
    else
    {
      std::cout << "Input does not contain a proper format. Proper format example: folder/file.txt  or  file.txt" << std::endl;
    }
  }
  return filename;
}
