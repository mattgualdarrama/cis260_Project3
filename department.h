//file: Department.h
/*  Matt Gualdarrama
 *  CIS-260 ME1
 *  Project 3
 *  04/08/2019
*/

/**
 *  A class that stores and maintains a departemnts employee ID's and their salaries. 
*/
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <iostream>

template<class Type>
class Department
{
  private:
    const static int MAX = 5; 
    mutable int counter;
    typedef std::string sArray[MAX];
    typedef Type tArray[MAX];

    std::string deptName;
    mutable sArray employee;
    mutable tArray salary;

    /** A function to determine if the arrays are full
     * @pre None.
     * @post Compare current counter with array size
     * @return If array is full, return 1, otherwise return 0.
     */ 
    bool IsFull() const;

    /** A function to determine if the arrays are empty
     * @pre None.
     * @post Compare current counter with array size
     * @return If array is empty, return 1, otherwise return 0.
     */ 
    bool IsEmpty() const;

    /** A function to search the object for an empoyee stored in its array
     * @pre Function will accept a target as an argument, search the object's arrays for target, and return the results
     * @return  If target is found, return target location, otherwise, return 0.
     */
    int Search(const std::string);
  
  public:
    /** The constructor for Department.
     *  @pre The argument for name must be a string.
     *  @post The data member "counter" is initilized to 0
    */
    Department(const std::string & dept);

    /** A null destructor for Department */
    ~Department(){};

    /** A function to add employees to the object.
     *  @pre Check to see if the object is full
     *  @post Add employee id, and salary to arrays, or print object is full
     *  @return 1 if employee added \n 0 if employee cannot be added
    */
    bool Add() const;

    /** A function to remove employees from the object
      *@pre Check to see if object is is empty 
      *@post Prompt user for ID to delete \n 
      * Search for specified ID \n 
      * If found, remove specified ID from array
      * @return 1 if employee removed \n 0 if employee was not found 
    */
    bool Remove(); 

    /** A function to remove all employees stored in the object.
      * @pre None
      * @post Print current contents of arrays \n
      * Clear contents of arrays \n
      * Reset internal counter
    */
    void Clear();

    /**A function to print all data stored in arrays
      * @pre Accept counter as argument
      * @post Print contents of object's arrays.
    */
    void Print(const int);

    /** A function that retrives the objects internal counter for use outside the class
     * @return the value stored in counter
    */
    int GetCount() const;
};

#include "Department.tpp"
#endif
