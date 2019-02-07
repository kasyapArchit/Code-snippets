#include <bits/stdc++.h>
#define pb push_back
#define MAXN 10000001
using namespace std;
//stores 'smallest prime factor' for that number
int spf[MAXN];
int i;

//can work till 10^7 O(nlog(log n))
void seive(){
    for(i=1;i<MAXN;i++)
        spf[i]=i;
    //multiples of 2
    for(i=4;i<MAXN;i+=2)
        spf[i]=2;
    //all multiples of primes
    for(i=3;i*i<MAXN;i++){
        if(spf[i]==i){
            for(int j=i*i;j<MAXN;j+=i)
                if(spf[j]==j)
                    spf[j]=i;
        }
    }
}

//for finding prime factors
//O(log n) algorithm by dividing with spf each time
vector<int> getFactorization(int x){
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
