/*
ID:kevin_s1
PROG:frac1
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
#define MAXN 20000 

//gobal variable====
struct frac{
	int a;
	int b;
	double c;
};

vector<frac> fracs;

int hash[170][170];

int N;

//==================


//function==========

int gcd(int a, int b){

	while(a = a % b){
		a ^= b;
		b ^= a;
		a ^= b;
	}
	return b;
}

int cmp(frac a, frac b){
	return a.c < b.c;
}

//==================

int main(){
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	cin>>N;
	int index = 0;
	memset(hash, 0 ,sizeof(hash));
	frac fr1,fr2;
	fr1.a = 0;
	fr1.b = 1;
	fr1.c = 0;
	fracs.push_back(fr1);
	fr2.a = 1;
	fr2.b = 1;
	fr2.c = 1;
	fracs.push_back(fr2);
	hash[0][1] = 1;
	hash[1][1] = 1;
	for(int i = 2; i <= N; i++){
		for(int j = 1; j < i; j++){
			int x = i;
			int y = j;
			int m = gcd(x, y);
			if(m > 1){
				x = x / m;
				y = y / m;
			}
			if(hash[y][x] == 0){
				frac fr;
				fr.a = y;
				fr.b = x;
				fr.c = (double)y / (double)x;
				fracs.push_back(fr);
				hash[y][x] = 1;
			}
		}
	}
	sort(fracs.begin(), fracs.end(), cmp);
	vector<frac>::iterator iter = fracs.begin();
	for(; iter != fracs.end(); iter++){
		cout<<iter->a<<"/"<<iter->b<<endl;
	}
	return 0;
}
