// File Name: assign6_zms22.cpp
//
// Author: Zachary Stence
// Date: 4/18/2017
// Assignment Number: 6
// CS 2308.256 Spring 2017
// Instructor: Jill Seaman
//
// Prompts the user to enter a filename then tells the user if all brackets
// in said file match and are nested properly. Uses a string to manage a 
// stack of characters in the CharStack class.
///////////////////////////////////////////////////////////////////////////////



using namespace std;
#include "CharStack.h"
#include <iostream>
#include <fstream>

int main() {
  ifstream fin;
  string fileName;
  int count = 0;
  CharStack chStack;
  char ch, close;
  bool run = true;

  cout << "Enter the file name you would like to check: ";
  cin >> fileName;

  fin.open(fileName.c_str());
  if (!fin.is_open()) {
    cout << "File not succesfully opened." << endl;
    run = false;
  }

  while (fin >> ch && run) {
    switch (ch) {
      case '{':
        chStack.push(ch);
        chStack.push('}');
        break;
      case '(':
        chStack.push(ch);
        chStack.push(')');
        break;
      case '[':
        chStack.push(ch);
        chStack.push(']');
        break;
      case '}':
      case ')':
      case ']':
        if (chStack.isEmpty()) {
          cout << "ERROR: unmatched " << ch << endl;
          run = false;
        }
        else if (ch == chStack.peek()) {
          chStack.pop();
          chStack.pop();
          count++;
        }
        else {
          cout << "ERROR: expected " << chStack.peek() << 
            " but found " << ch << endl;
          run = false;
        }
        break;
    }
  }

  if (run) {
    if (chStack.isEmpty())
      cout << count << " bracket pairs were matched" << endl;
    else
      cout << "ERROR: missing " << chStack.peek() << endl;
  }
}
