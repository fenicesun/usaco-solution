/*
ID:kevin_s1
PROG:fracdec
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

#define MAXN 100000+1

//gobal variable====
int N, D;
int used[MAXN];
//==================


//function==========

int solve(int n, int d){
	
	for(used[0] = 1, used[n] = 1, n = n * 10 % d; used[n] != 1; used[n] = 1, n = n*10 % d){
		;
	}

	if(n == 0)
		return -1;
	int t = n;
	int result = 0;
	do{
		result = result * 10 + (n * 10)/ d;
		n = n * 10 % d;
	}while(n != t);
	return result;
}

//==================

int main(){
	//freopen("fracdec.in","r",stdin);
	//freopen("fracdec.out","w",stdout);
	memset(used, 0, sizeof(used));

	cin>>N>>D;
	int ans = solve(N, D);
	cout<<ans<<endl;
	
	return 0;
}
