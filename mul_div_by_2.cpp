#include <bits/stdc++.h>
using namespace std;
//right and left shifts
int mul_2(int x){return x << 1;}

int div_2(int x){return x >> 1;}

int main(){
    int x=20;
    cout<<"2*x = "<<mul_2(x)<<"\nx/2 = "<<div_2(x)<<endl;
}
