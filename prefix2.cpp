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

#define sigma_size 26
#define MAX_LEN 2000001

//gobal variable====

struct trie_node{
	trie_node* next[sigma_size];
	bool is_terminal;
	trie_node(){
		memset(next, 0, sizeof(next));
		is_terminal = false;
	}
};


struct Trie{
	trie_node* root;
	int size;
	int idx(char ch){
		return ch - 'A';
	}
	Trie(){
		root = new trie_node();
		size = 1;
	}

	void Insert(string str){
		trie_node* cur = root;
		int len = str.length();
		for(int i = 0; i < len; i++){
			int ch = idx(str[i]);
			if(cur->next[ch] == NULL){
				cur->next[ch] = new trie_node();
			}
			cur = cur->next[ch];
		}
		cur->is_terminal = true;
	}

	bool Query(string str){
		trie_node* cur = root;
		int len = str.length();
		for(int i = 0; i < len; i++){
			int ch = idx(str[i]);
			if(cur->next[ch] == NULL){
				return false;
			}
			else
				cur = cur->next[ch];
		}

		if(cur->is_terminal)
			return true;
		else
			return false;

	}
	
};

int DP[MAX_LEN];
string S;
//==================


//function==========

//==================

int main(){
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	Trie prefix;
	string str;
	char ch[201];
	while(scanf("%s",ch) && strcmp(ch, ".") != 0){
		str = ch;
		prefix.Insert(str);
	}
	str.clear();
	int c;
	while((c = getchar()) != EOF){
		if(!isspace(c))
			S = S + (char)c;
	}
	int Len = S.length();
	memset(DP, 0, sizeof(DP));
	DP[Len] = 0;
	for(int i = Len - 1; i >= 0; --i){
		for(int j = 1; j <= 10 && (i + j - 1) < Len; ++j){
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
