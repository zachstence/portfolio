// File Name: QuizDriver.cpp
//
// Author: Zachary Stence
// Date: 3/20/2017
// Assignment Number: 4
// CS 2308.256 Spring 2017
// Instructor: Jill Seaman
//
// Creates an array to hold 5 questions. Initializes the 5 questions to
// the given questions and answers. These questions are managed by the
// member variables and member functions of the Question class.

#include <iostream>
using namespace std;
#include "Question.h"

const int NUM_QUESTIONS = 5;

int main() {
  
  string q1Stem = "What name is given to half of a Byte (4 bits)?";
  string q1Answers [] = {"Nibble","Ort","Scrap","Snippet"}; //answer A
  string q2Stem = "Which country is home to the Kangaroo?";
  string q2Answers [] = {"China","India","Mexico","Australia"}; //answer D
  string q3Stem = "What do you use to measure an angle?";
  string q3Answers [] = {"Compass","Protractor","Ruler","T-Square"}; //ans B
  string q4Stem = 
  "The Great Sphinx has the head of a human and the body of a what?";
  string q4Answers [] = {"Camel","Eagle","Lion","Alligator"}; //answer C
  string q5Stem = 
  "What is the flat rubber disc used in a game of ice hockey?";
  string q5Answers [] = {"Birdie","Puck","Dart","Tile"}; //answer B

  Question questions[NUM_QUESTIONS];
  questions[0].setStem(q1Stem);
  questions[0].setAnswers(q1Answers);
  questions[0].setKey('A');
  questions[1].setStem(q2Stem);
  questions[1].setAnswers(q2Answers);
  questions[1].setKey('D');
  questions[2].setStem(q3Stem);
  questions[2].setAnswers(q3Answers);
  questions[2].setKey('B');
  questions[3].setStem(q4Stem);
  questions[3].setAnswers(q4Answers);
  questions[3].setKey('C');
  questions[4].setStem(q5Stem);
  questions[4].setAnswers(q5Answers);
  questions[4].setKey('B');

  for (int i = 0; i < NUM_QUESTIONS; i++) {
    cout << i + 1 << ". ";
    questions[i].display();
    cout << endl;
  }

  cout << "Answers:" << endl;
  for (int i = 0; i < NUM_QUESTIONS; i++) {
    cout << questions[i].getKey() << " ";
  }
  cout << endl;
}
