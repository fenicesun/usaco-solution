/*
ID:kevin_s1
PROG:prefix
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

#define MAX_NODE 90000
#define sigma_size 26	
#define MAX_LEN 200001

//gobal variable====
int DP[MAX_LEN];

string S;

struct Trie{
	int child[MAX_NODE][sigma_size];
	int value[MAX_NODE];
	int size;
	Trie(){
		size = 1;
		memset(child[0], 0, sizeof(child[0]));
		memset(value, 0, sizeof(value));
	}

	int idx(char ch){
		return ch - 'A';
	}
	
	void Insert(string str, int val){
		int u = 0, num = str.length();
		for(int i = 0; i < num; i++){
			int ch = idx(str[i]);
			if(!child[u][ch]){
				memset(child[size], 0, sizeof(child[size]));
				value[size] = 0;
				child[u][ch] = size++;
			}
			u = child[u][ch];
		}
		value[u] = val;
	}

	int Query(string str){
		int u = 0, num = str.length();
		for(int i = 0; i < num; i++){
			int ch = idx(str[i]);
			if(child[u][ch]){
				u = child[u][ch];
			}
			else{
				return 0;
			}
		}

		if(value[u] == 1)
			return 1;
		else
			return 0;
	}

};

//==================


//function==========

//==================

int main(){
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	Trie prefix;
	string str;
	while(cin>>str && str != "."){
		prefix.Insert(str, 1);
	}
	str.clear();
	while(cin>>str){
		S += str;
	}
	int len = S.length();
	memset(DP, 0, sizeof(DP));
	DP[len] = 0;
	for(int i = len - 1; i >= 0; --i){
		for(int j = 1; j <= 10 && (i + j - 1) < len; ++j){
			string sub = S.substr(i, j);
			if(prefix.Query(sub)){
				if(DP[i + j] + j > DP[j])
					DP[i] = DP[i + j] + j;
			}
		}
	}
	cout<<DP[0]<<endl;
	return 0;
}
