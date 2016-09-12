/*
ID:kevin_s1
PROG:checker
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

//gobal variable====
const int MAXN = 15;
int N;
int X[MAXN];
int cnt;
//==================


//function==========
bool Place(int k){
	bool flag = true;
	for(int i = 1; i < k; i++){
		if(X[k] == X[i] || abs(k - i) == abs(X[k] - X[i]))
			flag = false;
	}
	return flag;
}

void print(int x[]){
	for(int i = 1; i <= N; i++){
		cout<<x[i];
		if(i != N)
			cout<<" ";
	}
	cout<<endl;
}

int DFS(int t){
	if(t > N && N > 0){
		cnt++;
		if(cnt == 1){
			print(X);
		}
		if(cnt == 2){
			print(X);
		}
		if(cnt == 3){
			print(X);
		}
	}
	for(int i = 1; i <= N; i++){
		X[t] = i;
		if(Place(t)){
			DFS(t + 1);
		}
	}
	return cnt;
}


//==================

int main(){
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);
	cin>>N;
	int ans = 0;
	memset(X, 0, sizeof(X));
	cnt = 0;
	ans = DFS(1);
	cout<<ans<<endl;
	return 0;
}
