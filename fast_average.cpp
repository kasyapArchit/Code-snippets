// C++ program to find average without using
// division.
#include <bits/stdc++.h>
//right shift in bit
int floorAvg(int x, int y) {
     return (x + y) >> 1;
}

int main() {
  int x = 10, y = 20;
  printf("\n\nAverage = %d\n\n", floorAvg(x, y));
  return 0;
}
