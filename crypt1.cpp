/*
ID:kevin_s1
PROG:crypt1
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
int isInSet[10];
int N;
int num[11];
int result;
//==================


//function==========
int bitnum(int num){
	if((num/1000) >= 1 && (num/10000) == 0)
		return 4;
	if((num/100) >= 1 && (num/1000) == 0)
		return 3;
}

bool test(int num){
	bool flag = true;
	while(num != 0){
		int x = num % 10;
		if(!isInSet[x]){
			flag = false;
		}
		num = num / 10;
	}
	return flag;
}

//==================

int main(){
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	memset(isInSet,0,sizeof(isInSet));
	result = 0;
	cin>>N;
	for(int i = 1; i <= N; i++){
		cin>>num[i];
		isInSet[num[i]] = 1;
	}
		
	int a1,a2,a3,b1,b2;
	for(int i = 1; i <= N; i++){
		a1 = num[i];
		for(int j = 1; j <= N; j++){
			a2 = num[j];
			for(int k = 1; k <= N; k++){
				a3 = num[k];
				for(int l = 1; l <= N; l++){
					b1 = num[l];
					for(int m = 1; m <= N; m++){
						b2 = num[m];
						int a = a1 * 100 + a2 * 10 + a3;
						int b = b1 * 10 + b2;
						int c1 = a * b1;
						int c2 = a * b2;
						int c = a * b;
						if(test(c) && test(c1) && test(c2) && bitnum(c) == 4 && bitnum(c1) == 3 && bitnum(c2) == 3){
							if(c1 * 10 + c2 == c){
								/*
								cout<<" "<<a1<<" "<<a2<<" "<<a3<<endl;
								cout<<"x"<<" "<<b1<<" "<<b2<<endl;
								cout<<"----------"<<endl;
								cout<<" "<<c2<<endl;
								cout<<c1<<endl;
								cout<<"----------"<<endl;
								cout<<" "<<c<<endl;
								cout<<endl;
								cout<<endl;
								cout<<endl;
								*/
								result++;
							}
						}
					}
				}
			}
		}
	}
	
	cout<<result<<endl;
	return 0;
}
