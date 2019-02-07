#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build(){
    // build the tree
    // in case of non-commutative use own function
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

// -----------------------------------------------------------------------
// 1. Modify one element.
// 2. Find the sum of elements on some segment.

void modify(int p, int value){
    // set value at position p
    for (t[p+=n]=value; p>1; p>>=1) t[p>>1] = t[p]+t[p^1];
}

int query(int l, int r){
      // sum on interval [l, r)
    int res = 0;
    for (l+=n, r+=n; l<r; l>>=1, r>>=1){
        if (l&1) res+=t[l++];
        if (r&1) res+=t[--r];
    }
    return res;
}

// ------------------------------------------------------------------------
// 1. Add a value to all elements in some interval (modification only, not assignment)
// 2. Compute an element at some position.

void modify(int l, int r, int value){
    for (l += n, r += n; l < r; l >>= 1, r >>= 1){
        if (l&1) t[l++] += value;
        if (r&1) t[--r] += value;
    }
}

int query(int p){
    int res = 0;
    for (p += n; p > 0; p >>= 1) res += t[p];
    return res;
}

void push(){
    // push all the modifications to find the whole array.
    // need to check the extra elements before rebuilding seg. tree afer this step.
    for (int i = 1; i < n; ++i){
        t[i<<1] += t[i];
        t[i<<1|1] += t[i];
        t[i] = 0;
    }
}
// ----------------------------------------------------------------------------



/*int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  modify(0, 1);
  printf("%d\n", query(3, 11));
  return 0;
}*/
