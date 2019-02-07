#include <bits/stdc++.h>
using namespace std;
//"and" the number with 1
bool evn(int x){
    return (x & 1)?0:1;
}

int main(){
   int x = 18;
   if(evn(x))cout<<"Even Number\n";
   return 0;
}
