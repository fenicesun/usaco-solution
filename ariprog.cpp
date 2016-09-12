/*
ID:kevin_s1
PROG:ariprog
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
int doubleSqure[999999];
int table[999999];
int _index;
int M,N;
int lim;

struct node{
	int a;
	int d;
	
};

vector<node> result;
//==================


//function==========
void init(){
	memset(table,0,sizeof(table));
	_index = 1;
	for(int i = 0; i <= M; i++){
		for(int j = 0; j <= M; j++){
			int num = i * i + j * j;
			if(table[num] == 0){
				doubleSqure[_index++] = num;
				table[num] = 1;
			}	
		}
	}
	_index--;
}

void deal(int x){
	int num = doubleSqure[x];
	for(int i = x + 1; i <= _index - N + 2; i++){
		if(doubleSqure[x] + (doubleSqure[i] - doubleSqure[x])*(N - 1) > lim)
			break;
		int d = doubleSqure[i] - num;
		bool flag = true;
		int count = doubleSqure[i];
		for(int j = 3; j <= N; j++){
			count += d;
			if(table[count] == 0)
				flag = false;
		}
		if(flag){
			node no;
			no.a = num;
			no.d = d;
			result.push_back(no);
		}
	}
}

bool cmp(const node& n1, const node& n2){
	if(n1.d == n2.d)
		return n1.a < n2.a;
	else
		return n1.d < n2.d;
}

//==================

int main(){
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	cin>>N>>M;
	init();
	sort(doubleSqure, doubleSqure + _index);
	lim = doubleSqure[_index];
	
	for(int i = 1; i <= _index - N + 1; i++){
		deal(i);
	}
	sort(result.begin(), result.end(), cmp);
	vector<node>::iterator iter;
	if(result.size() == 0)
		cout<<"NONE"<<endl;
	else{
		for(iter = result.begin(); iter != result.end(); iter++){
			cout<<iter->a<<" "<<iter->d<<endl;
		}
	}
	return 0;
}
