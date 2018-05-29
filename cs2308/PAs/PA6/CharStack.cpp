// File Name: CharStackDriver.cpp
//
// Author: Zachary Stence
// Date: 4/18/2017
// Assignment Number: 6
// CS 2308.256 Spring 2017
// Instructor: Jill Seaman
//
// All function definitions for the CharStack.h class. Functions modify a stack
// of characters represented as a string.
///////////////////////////////////////////////////////////////////////////////


using namespace std;
#include "CharStack.h"
#include <cassert>
#include <iostream>

//*****************************************************************************
// CharStack: constructor for the character stack. Initializes the stack to
//   empty
//*****************************************************************************
CharStack::CharStack() {
  stackString = "";
}

//*****************************************************************************
// push: adds a character to the top of the stack (end of the string).
//
// char ch: the character to be added
//*****************************************************************************
void CharStack::push(char ch) {
  assert(!isFull());
  stackString += ch;
}

//*****************************************************************************
// pop: removes the top character from the stack (end of the string).
//*****************************************************************************
void CharStack::pop() {
  assert(!isEmpty());
  stackString.erase(stackString.size()-1,1);
}

//*****************************************************************************
// peek: allows the user to look at the top character in the stack without
//   popping it.
// returns: the top character in the stack (end of the string).
//*****************************************************************************
char CharStack::peek() {
  assert(!isEmpty());
  return stackString[stackString.size()-1];
}

//*****************************************************************************
// isFull: returns true if the stack is full, false if otherwise
//
// returns: false because the stack is never full (unless you run out of
//   memory).
//*****************************************************************************
bool CharStack::isFull() const {
  return 0;  
}

//*****************************************************************************
// isEmpty: returns true if the stack is empty (contains no characters) and
//   false otherwise.
// returns: true if the string has size zero, false otherwise.
//*****************************************************************************
bool CharStack::isEmpty() const {
  return (stackString.size()==0);
}
