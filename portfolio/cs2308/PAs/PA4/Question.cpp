// File Name: Question.cpp
//
// Author: Zachary Stence
// Date: 3/20/2017
// Assignment Number: 4
// CS 2308.256 Spring 2017
// Instructor: Jill Seaman
//
// The Question class. Contains all member function definitions.

#include <iostream>
using namespace std;
#include "Question.h"

//*****************************************************************************
// Question: default constructor for an instance of the question class which
// initializes member variables to default values.
//
// param-1:
// param-2:
// returns:
//*****************************************************************************
Question::Question() {
  stem = "";
  for (int i = 0; i < NUM_ANSWERS; i++) {
    answers[i] = "";
  }
  key = 'X';
}

//*****************************************************************************
// Question: constructor for an instance of the question class which
// initializes member variables to specified arguments.
//
// st: the desired stem passed in from main()
// ans: the desired answer choices passed in from main()
// k: the desired key passed in from main()
//*****************************************************************************
Question::Question(string st, string ans[4], char k) {
  stem = st;
  for (int i = 0; i < NUM_ANSWERS; i++) {
    answers[i] = ans[i];
  }
  key = k;
}

//*****************************************************************************
// setStem: sets the stem member variable to st
//
// st: the desired question stem passed in from main()
//*****************************************************************************
void Question::setStem(string st) {
  stem = st;
}

//*****************************************************************************
// setAnswers: sets the answers member variable to ans 
//
// ans: an array containing the desired answer choices passed in from main()
//*****************************************************************************
void Question::setAnswers(string ans[NUM_ANSWERS]) {
  for (int i = 0; i < NUM_ANSWERS; i++) {
    answers[i] = ans[i];
  }
}

//*****************************************************************************
// setKey: sets the key member variable to k
//
// k: the desired character for the correct answer to the question passed in
// from main
//*****************************************************************************
void Question::setKey(char k) {
  key = k;
}

//*****************************************************************************
// getStem: returns the stem of the question object
//
// returns: the stem of the question object (specified in main using the dot
// operator)
//*****************************************************************************
string Question::getStem() const {
  return stem;
}

//*****************************************************************************
// getAnswer: returns the answer at index i
//
// i: the index of the desired answer
// returns: the answer choice specified by the provided index
//*****************************************************************************
string Question::getAnswer(int i) {
  return answers[i];
}

//*****************************************************************************
// getKey: returns the correct answer to a question
//
// returns: the answer to the specified question
//*****************************************************************************
char Question::getKey() const {
  return key;
}

//*****************************************************************************
// display: outputs the question and 4 answer choices to the console
//*****************************************************************************
void Question::display() const {
  cout << stem << endl;
  for (int i = 0; i < NUM_ANSWERS; i++) {
    cout << char('A' + i) << ". " << answers[i] << endl;
  }
}
