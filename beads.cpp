/*
ID:kevin_s1
PROG:beads
LANG:C++
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int N;
char beads[351];

int Next(int turn){
	int pos = (turn + 1)%N;
	return (pos != 0 ? pos:N);
}

int Pre(int turn){
	int pos = (turn - 1 + N)%N;
	return (pos != 0 ? pos:N);
}


int main(){

	int maxnum = 0;
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	cin>>N;
	for(int i = 1; i <= N; i++){
		cin>>beads[i];
	}
	for(int i = 1; i <= N; i++){
		int index = i;
		char first = beads[index];
		char second = beads[Pre(index)];
		if(first == 'w'){
			int ne = index;
			while(beads[ne] == 'w'){
				ne = Next(ne);
				if(ne == index){
					maxnum = N;
					break;
				}
			}
			first = beads[ne];
		}
		if(second == 'w'){
			int pr = Pre(index);
			while(beads[pr] == 'w'){
				pr = Pre(pr);
				if(pr == Pre(index)){
					maxnum = N;
					break;
				}
			}
			second = beads[pr];
		}
		//
		int _pre = Pre(index);
		int _next = index;
		int count1 = 0,count2 = 0;

		while((first == beads[_next] || beads[_next] == 'w' ) && _next != _pre){
			count1++;
			_next = Next(_next); 
		}
		_next= Pre(_next);
		while((second == beads[_pre] || beads[_pre] == 'w' ) && _pre != _next){
			count2++;
			_pre = Pre(_pre);
		}
		if(count1 + count2 > maxnum){
			maxnum = count1 + count2;	
		}
	}
	cout<<maxnum<<endl;

	return 0;
}
