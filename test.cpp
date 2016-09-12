/*
ID:kevin_s1
PROG:
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
#include <bitset>

using namespace std;

//gobal variable====


//==================


//function==========
int hammingDis(bitset<8> a, bitset<8> b){
	bitset<8> x = a xor b;
	return x.count();
}

//==================

int main(){
	freopen("text.in","r",stdin);
	string str;
	string S;
	while(cin>>str){
		S += str;
	}
	cout<<S<<endl;
	return 0;
}
