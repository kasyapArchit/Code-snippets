#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main(){
	_
	int n, m;
	cin >> n >> m;
	int a[m][3], res[n+1]={0};
	for(int i=0; i<m; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
	
	for(int i=0; i<m; i++){
		int x1 = a[i][0];
		int x2 = a[i][1];
		int x3 = a[i][2];

		if(res[x1]+res[x2]+res[x3]==0){
			res[x1] = 1;
			res[x2] = 2;
			res[x3] = 3;
		}
		else if(res[x1]!=0){
			if(res[x1]==1){
				res[x2] = 2;
				res[x3] = 3;
			}
			else if(res[x1]==2){
				res[x2] = 1;
				res[x3] = 3;
			}
			else{
				res[x2] = 1;
				res[x3] = 2;
			}
		}
		else if(res[x2]!=0){
			if(res[x2]==1){
				res[x1] = 2;
				res[x3] = 3;
			}
			else if(res[x2]==2){
				res[x1] = 1;
				res[x3] = 3;
			}
			else{
				res[x1] = 1;
				res[x3] = 2;
			}
		}
		else{
			if(res[x3]==1){
				res[x1] = 2;
				res[x2] = 3;
			}
			else if(res[x3]==2){
				res[x1] = 1;
				res[x2] = 3;
			}
			else{
				res[x1] = 1;
				res[x2] = 2;
			}
		}
	}
	for(int i=1; i<n+1; i++)
		cout << res[i] << " ";
	return 0;
}
