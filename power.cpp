#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


// Works in O(log n)
lli power(lli n, lli p)
{
    lli ans = 1;
    while(p > 0)
    {
        if(p & 1)
            ans = (ans*n);

        n = (n*n);
        p >> 1;
    }
    return ans;
}
