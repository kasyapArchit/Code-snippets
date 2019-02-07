#include <bits/stdc++.h>
#define mod 1000000007
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long int lli;

// Property
lli gcd(lli a, lli b)
{
    while(a != b)
    {
        if(a>b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

// Euclid method
lli gcd(lli a, lli b)
{
    if(a == 0)
        return b;

    return gcd(b%a, a);
}
