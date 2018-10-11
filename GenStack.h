#include <iostream>
using namespace std;
template <typename E>
class GenStack
{
  public:
    GenStack();//default constructor
    GenStack(int maxSize);//overloaded constructor
    ~GenStack();
    int getSize() const;//return size

    void push(const E& e);
    const E& pop();


    const E& peek();
    bool isFull() const;
    bool isEmpty() const;
    //NEED COPY



  private:
    int size;
    int numberCount;
    int top;

    E *myArray;
};

template<typename E> GenStack<E>::GenStack()//defualt constructor
{
    myArray = new E[5];
    size = 5;

    numberCount = 0;
    top = -1;
}
template<typename E> GenStack<E>::GenStack(int maxSize)//overloaded constructor
{
  myArray = new E[maxSize];
  size = maxSize;
  numberCount = 0;
  top = -1;

}
template<typename E> GenStack<E>::~GenStack()//destructor
{
  delete myArray;
  //cout <<"Stack Destroyed"<<endl;
}

template<typename E> void GenStack<E>::push(const E& e)//adds
{
  if(isFull() == true)
  {
    size = 2 * size;
    E *tempArray = new E[size];
    for(int i = 0; i < size; i++)
    {
      tempArray[i] = myArray[i];
    }
    delete [] myArray;
    myArray = tempArray;
  }

  //check if not full
  //responsible for error/bound checking
  numberCount+=1;
  myArray[++top] = e;
}

template<typename E> const E& GenStack<E>::pop()//returns and removes top
{
  //error checks first
  //check if empty
  if(isEmpty() != true)
  {
    numberCount-=1;
    return myArray[top--];
  }
  else//if stack is empty
  {
    throw std::logic_error("Error: Popping Empty Stack");
  }
}

template<typename E> int GenStack<E>::getSize() const
{
  return size;
}

template<typename E> const E&  GenStack<E>::peek()//returns top, but not remove
{
  return myArray[top];
}


template<typename E> bool GenStack<E>::isFull() const
{
  return (top == size-1);
}

template<typename E> bool GenStack<E>::isEmpty() const
{
  return (top == -1);
}
