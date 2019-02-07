// C++ program to find multiplicative modulo inverse using
// Extended Euclid algorithm.
// Recursive Algo
// Running Time O(log m)
// Works when a and m  are coprime i.e gcd(a, m)=1
// This algo actually gives 'x' and 'y' such that [a*x + b*y = gcd(a, b)].
#include<iostream>
using namespace std;

// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y);

// Function to find modulo inverse of a
void modInverse(int a, int m){
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else{
        // m is added to handle negative x
        int res = (x%m + m) % m;
        cout << "Modular multiplicative inverse is " << res;
    }
}

// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y){
    // Base Case
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

// Driver Program
int main(){
    int a = 3, m = 11;
    modInverse(a, m);
    return 0;
}


// Iterative C++ program to find modular
// inverse using extended Euclid algorithm
#include <stdio.h>

// Returns modulo inverse of a with respect
// to m using extended Euclid Algorithm
// Assumption: a and m are coprimes, i.e.,
// gcd(a, m) = 1
int modInverse(int a, int m){
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1){
        // q is quotient
        int q = a / m;
        int t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
       x += m0;

    return x;
}

// Driver program to test above function
int main(){
    int a = 3, m = 11;

    printf("Modular multiplicative inverse is %d\n",
          modInverse(a, m));
    return 0;
}
