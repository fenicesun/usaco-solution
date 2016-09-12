/*
ID:kevin_s1
PROG:humble
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

#define MAXK 110

//gobal variable====
int K, N;

long int S[MAXK];
set<long int> humble;

//==================


//function==========

//==================

int main(){
	freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);
	cin>>K>>N;
	for(int i = 1; i <= K; i++){
		cin>>S[i];
		humble.insert(S[i]);
	}
	for(int i = 1; i <= K; i++){
		set<long int>::iterator iter = humble.begin();
		while(1){
			long int tmp = (*iter) * S[i];
			if(tmp < 0)
				break;
			if(humble.size() > N){
				humble.erase(--humble.end());
				if(tmp > (*(--humble.end())))
					break;
			}
			humble.insert(tmp);
			iter++;
		}
	}
	cout<< *(--humble.end())<<endl;
	return 0;
}
