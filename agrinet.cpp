/* ID:kevin_s1 
 * PROG:agrinet
 * LANG:C++
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <list>
#include <cmath>

using namespace std;

#define MAXN 110
#define INF 100001

//gobal variable====

int N;
int Edge[MAXN][MAXN];
int lowcost[MAXN];
int sumdist;

//==================


//function==========
void prim(){
	lowcost[1] = -1;
	int v;
	for(int i = 2; i <= N; i++){
		lowcost[i] = Edge[1][i];	
	}
	for(int i = 2; i <= N; i++){
		int min = INF;
		for(int k = 2; k <= N; k++){
			if(lowcost[k] != -1 && lowcost[k] < min){
				v  = k;
				min = lowcost[k];
			}
		}
		sumdist += min;
		lowcost[v] = -1;
		for(int k = 1; k <= N; k++){
			if(lowcost[k] > Edge[v][k])
				lowcost[k] = Edge[v][k];
		}
	}
}

//==================

int main(){
	freopen("agrinet.in","r",stdin);
	freopen("agrinet.out","w",stdout);
	cin>>N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin>>Edge[i][j];
		}
	}
	memset(lowcost, 0, sizeof(lowcost));
	sumdist = 0;
	prim();
	cout<<sumdist<<endl;
	return 0;
}
