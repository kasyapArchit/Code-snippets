#include <bits/stdc++.h>
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef long long int lli;

class UFDS{
private:
	vi p, rank, setSize;
	int numSets;
public:
	UFDS(int N){
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i=0; i<N; i++)
			p[i] = i;
		setSize.assign(N, 1);
	}

	int findSet(int i) {return (p[i] == i) ? i : p[i] = findSet(p[i]);}
	bool isSameSet(int i, int j) {return findSet(i) == findSet(j);}

	void unionSet(int i, int j){
		if (!isSameSet(i, j)){
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]){
				p[y] = x;
				setSize[x] += setSize[y];
			}
            else{
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
				setSize[y] += setSize[x];
			}
			numSets--;
		}
	}
	int numDisjointSets() {return numSets;}
	int sizeOfSet(int i) {return setSize[i];}
};
