#include <iostream>
using namespace std;

bool isLeapYear(int year) {
  if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    return true;
  else
    return false;
}

void displayArr(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int firstWDOY(int year) {
  int x = year-1;
  int firstWDOY = (1 + 5*(x % 4) + 4*(x % 100) + 6*(x % 400)) % 7;
}

bool isIn(int target, int arr[], int size) {
  for (int i = 0; i < size; i++) {
    if (target == arr[i])
      return true;
  }
  return false;
}

int main () {
  int count = 0;
  int yearStart = 1901;
  int yearEnd = 2000;
  for (int year = yearStart; year <= yearEnd; year++) {
    int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int daysInYear = 365;

    //if leap year, add one to february and total days
    if (isLeapYear(year)) {
      months[1] += 1;
      daysInYear += 1;
    }

    int firsts[12] = {1};
    //set up array containing days of year that are firsts of month
    for (int i = 1; i < 12; i++) {
      firsts[i] = firsts[i-1] + months[i-1];
    }

    int weekDay = firstWDOY(year);
    int doy = 1;
    while (doy <= daysInYear) {
      if (weekDay == 7)
        weekDay = 0;

      if (isIn(doy, firsts, 12) && (weekDay % 7 == 0)) {
          count++;
      }
      weekDay++;
      doy++;
    }

  }
  cout << count << endl;
}
