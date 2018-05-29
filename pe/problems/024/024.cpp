#include<iostream>
#include<algorithm>
using namespace std;

//searches through the string and returns the index where a descending string called
//descEnd starts
int whereDesc(string s) {
  int i = s.length()-1;
  while (s[i-1] > s[i])
    i--;
  return i;
}

// returns the lexicographic permutation following s
string nextPerm(string s) {
  int d = whereDesc(s);
  if (d == s.length()-1) {
    swap(s[s.length()-1], s[s.length()-2]);
    return s;
  }
  else if (d == 0) {
    return "";
  }
  else {
    int c = d-1;
    for (int x = s.length()-1; x > c; x--) {
      if (s[x] > s[c]) {
        swap(s[x], s[c]);
        sort(s.begin()+d, s.end());
        return s;
      }
    }
  }
}

int main() {
  string s = "0123456789";
  string ans;
  
  for (int i = 0; i < 1000000; i++) {
    ans = s;
    s = nextPerm(s);
  }
  
  cout << ans << endl;
}
