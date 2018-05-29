///////////////////////////////////////////////////////////////////////////////
// File Name: StringList.cpp
//
// Author: Zachary Stence
// Date: 4/6/2017
// Assignment Number: 5
// CS 2308.256 Spring 2017
// Instructor: Jill Seaman
//
// Designing a class that controls a linked list of strings using various
// functions: count, add, remove, display, minimum, and sort.
///////////////////////////////////////////////////////////////////////////////

#include "StringList.h"
using namespace std;
#include <iostream>


//*****************************************************************************
// StringList: default StringList constructor
//*****************************************************************************
StringList::StringList() {
  head = NULL;
}

//*****************************************************************************
// ~StringList: StringList destructor (deallocates all StringNodes)
//*****************************************************************************
StringList::~StringList() {
  StringNode* p;
  for (p = head; head; p = head) {
    head = head->next;
    delete p;
  }
}

//*****************************************************************************
// count: Counts the number of nodes in the list
//
// returns: returns the number of nodes in the list (int)
//*****************************************************************************
int StringList::count() {
  StringNode* p = head;
  int count = 0;
  while (p) {
    count++;
    p = p->next;
  }
  return count;
}

//*****************************************************************************
// add: Adds a node to the list containing a specified string
//
// s: The specified string to be added to the list
//*****************************************************************************
void StringList::add(string s) {
  StringNode* newNode = new StringNode;
  newNode->data = s;
  newNode->next = NULL;
  if (!head) {
    head = newNode;
  }
  else {
    StringNode* p = head;
    while (p->next) {
      p = p->next;
    }
    p->next = newNode;
  }
}

//******************************************************************************
// remove: Removes a node containing a specified string
//
// s: The specified string to be removed
// returns: True or false depending on if the node was successfully removed
//******************************************************************************
bool StringList::remove(string s) {
  StringNode* p = head;
  StringNode* n = NULL;
  while (p->data != s) {
    n = p;
    p = p->next;
    if (!p) {
      delete p, n;
      return false;
    }
  }
  if (!n) {
    head = head->next;
    delete p, n;
    return true;
  } else {
    n->next = p->next;
    delete p, n;
    return true;
  }
}

//******************************************************************************
// display: Displays all data from the list
//******************************************************************************
void StringList::display() {
  StringNode* p;
  p = head;
  while (p) {
    cout << p->data << ", ";
    p = p->next;
  }
  cout << endl;
}

//******************************************************************************
// minimum: Finds and returns the string that comes first alphabetically
//
// returns: The string that comes first alphabetically
//******************************************************************************
string StringList::minimum() {
  string minString = head->data;
  for (StringNode* p = head; p; p = p->next) {
    if ((p->data).compare(minString) < 0) {
      minString = p->data;
    }
  }
  return minString;
}

//******************************************************************************
// sort: Sorts the list alphabetically using the minimum function
//******************************************************************************
void StringList::sort() {
  //set new head to NULL
  StringNode* newHead = NULL;

  //loop through existing list
  while (head) {

    //create newNode
    StringNode* newNode = new StringNode;
    newNode->data = minimum();
    newNode->next = NULL;
    
    //if new list is empty, make newHead point to newNode to start list
    if (newHead == NULL) {
      newHead = newNode;
      
      //remove from old list
      remove(minimum());
    }

    else {

      //find last node in new list
      StringNode* p = newHead;
      while (p->next) {
        p = p->next;
      }
      p->next = newNode;
      remove(minimum());
    }
  }
  head = newHead;
}
