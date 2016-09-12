/*
ID:kevin_s1
PROG:barn1
LANG:C++
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

int cmp(int a,int b){
	return a > b;
}

int stalls[201];
int intervals[201];
int M,S,C;

int main(){
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
	cin>>M>>S>>C;
	int min = 9999999;
	int max = 0;
	for(int i = 1; i <= C; i++){
		cin>>stalls[i];
		if(stalls[i] > max)
			max = stalls[i];
		if(stalls[i] < min)
			min = stalls[i];
	}
	sort(stalls + 1, stalls + C + 1);
	for(int i = 1; i <= C; i++){
		intervals[i] = stalls[i + 1] - stalls[i];
	}
	sort(intervals + 1,intervals + C,cmp);

	int result = 0;
	for(int i = 1; i <= M - 1; i++){
		result += intervals[i];
	}
	int ans = max - min - result + M ;
	if(M >= C)
		ans = C;
	cout<<ans<<endl;
	return 0;
}
