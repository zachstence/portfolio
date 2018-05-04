// File Name: Question.h
//
// Author: Zachary Stence
// Date: 3/20/2017
// Assignment Number: 4
// CS 2308.256 Spring 2017
// Instructor: Jill Seaman
//
// The header file for the Question class. Contains, public and private
// variables and function definitions.

#include <string>
using namespace std;

const int NUM_ANSWERS = 4;

class Question {
  private:
    string stem;
    string answers[NUM_ANSWERS];
    char key;

  public:
    Question();
    Question(string, string [NUM_ANSWERS], char);
    
    void setStem(string);
    void setAnswers(string [NUM_ANSWERS]);
    void setKey(char);
    string getStem() const;    
    string getAnswer(int);
    char getKey() const;
    
    void display() const;
};
