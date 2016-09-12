/*
ID:kevin_s1
PROG:calfflac
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
string str;
int start,end;
int maxlen = 0;
string result;
//==================


//function==========

bool isChar(char ch){
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return true;
	else
		return false;	
}

bool isPalindrome(string _str){
	string _str1;
	bool flag = true;
	for(int i = 0; i <= _str.length() - 1; i++){
		if(isChar(_str[i])){
			_str1.append(1,tolower(_str[i]));
		}
	}
	for(int i = 0; i <= _str1.length()/2; i++ ){
		if(_str1[i] != _str1[_str1.length() - i - 1]){
			flag = false;
		}
	}
	return flag;
}

void judge(int s,int e){
	if(s > e)
		return;
	int len = e - s + 1;
	string sstr = str.substr(s, len);
	if(isPalindrome(sstr)){
		if(len > maxlen){
			maxlen = len;
			start = s;
			end = e;
			result = sstr;
			//cout<<sstr<<endl;
		}
		return;
	}
	else{
			judge(s + 1,e);
			judge(s, e - 1);
		//judge(s + 1, e - 1);
	}
	return;
}

//==================

int main(){
	freopen("calfflac.in","r",stdin);
	freopen("calfflac.out","w",stdout);
	string _str;
	
	while(getline(cin, _str)){
		str += _str;	
	}
	maxlen = 0;
	judge(0,str.length() - 1);
	
	while(!isChar(str[start]))
		start++;
	while(!isChar(str[end]))
		end--;
	for(int i = start; i <= end; i++){
		cout<<str[i];
	}
	cout<<endl;
	

	return 0;
}
