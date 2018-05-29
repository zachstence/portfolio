#include<iostream>
#include<math.h>
using namespace std;

int count(int num) {
  int hundreds = num / 100;
  int tens = num / 10;
  int ones = num % 10;
  int c = 0;

  if (num == 1000) { //4 digits
    c += 11; //"one thousand" has 11 letters
  }


  else if (num <= 999 && num >= 100) { //3 digits
    if (num % 100 == 0) // ... hundred
      c += (count(hundreds) + 7);
    else { // ... hundred and ...
      c += (count(hundreds) + 7 + 3);
      c += count(num % 100);
    }
  }


  else if (num <= 99 && num >= 10) { //2 digits
    switch(tens) {
      case 1:
        switch(ones) {
          case 0: c += 3; break; //ten
          case 1: c += 6; break; //eleven
          case 2: c += 6; break; //twelve
          case 3: c += 8; break; //thirteen
          case 4: c += 8; break; //...
          case 5: c += 7; break;
          case 6: c += 7; break;
          case 7: c += 9; break;
          case 8: c += 8; break;
          case 9: c += 8; break; //nineteen
        }
        return c;
      case 2: c += 6; break; //twenty
      case 3: c += 6; break; //thirty
      case 4: c += 5; break; //fourty
      case 5: c += 5; break; //...
      case 6: c += 5; break;
      case 7: c += 7; break;
      case 8: c += 6; break;
      case 9: c += 6; break; //ninety
    }
    c += count(ones);
  }


  else if (num <= 9 && num >= 1){ //1 digit
    switch (num) {
      case 0: break;
      case 1: c += 3; break; //one
      case 2: c += 3; break; //two
      case 3: c += 5; break; //three
      case 4: c += 4; break; //four
      case 5: c += 4; break; //...
      case 6: c += 3; break;
      case 7: c += 5; break;
      case 8: c += 5; break;
      case 9: c += 4; break; //nine
    }
  }


  return c;
}





int main() {
  int sum = 0;
  for (int i = 1; i <= 1000; i++) {
    sum += count(i);
  }
  cout << sum << endl;
}
