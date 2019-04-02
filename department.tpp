//file Department.tpp
#include <string>
#include <iostream>

template<class Type>
bool Department<Type> :: IsFull() const
{
  return counter == MAX;
}

template<class Type>
bool Department<Type> :: IsEmpty() const
{  
  return counter == 0;
}

template<class Type>
int Department<Type> :: Search(const std::string targ)
{ 
  for (int i = 0 ; i <= MAX ; i++)
  {
    if (employee[i] == targ)
      return i; 
  }
  return -1;
}

template<class Type>
Department<Type> :: Department(const std::string & dept) : counter(0)
{//[Constructor]
  deptName = dept;

  if (deptName.empty())
  {
    std::cout << "Enter deptartment name:\t"; std::cin >> deptName;
  }
}

template<class Type>
bool Department<Type> :: Add() const
{
  if (IsFull())
  {
    std::cout<<"Cannot add, storage full\n"; 
    return 0;
  }
  else
  {
    std::cout << "Enter employee ID:\t"; std::cin >> employee[counter];
    std::cout << "Enter employee salary:\t"; std::cin>>salary[counter];
  
    counter++;
    return 1;
  }


}

template<class Type>
bool Department<Type> :: Remove()
{
  if (IsEmpty())
  {
    std::cout<<"\nCannot remove, no data\n"; 
    return 0;
  }
  else
  {
    std::string target; int result;
    std::cout << "Enter ID to delete: \t"; std::cin >> target;
    result = Search(target);    
    if (result == - 1)
      return 0;
    else
    {
      //shift remaining elements down;
      for (int i = result ; i < counter - 1 ; i++)
      {
      	employee[i] = employee[i+1];
      	salary[i] = salary[i+1];
      }
      
      counter--;
      return 1;
    }
  }
}

template<class Type>
void Department<Type> :: Clear()
{
  Print(counter);

  for (int i = 0 ; i < counter ; i++)
     employee[i] = salary[i] = "";
  
  counter = 0;
  std::cout << "\nData has been cleared\n";

}

template<class Type>
void Department<Type> :: Print(const int count) 
{	
  std::cout << "\nEMPLOYEE:\tSALARAY:\n";
  for (int i = counter-1 ; i > -1 ; i-- )
    std::cout << employee[i] << "\t\t\t" << salary[i] << '\n';

}

template<class Type>
int Department<Type> :: GetCount() const {return counter;}
