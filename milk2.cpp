/*
ID:kevin_s1
PROG:milk2
LANG:C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;

struct interval{
	int begin;
	int end;
}intervals[5001];

bool cmp(interval a,interval b){
	return a.begin < b.begin;	
}

int main(){

	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	cin>>N;
	for(int i = 1; i <= N; i++){
		cin>>intervals[i].begin>>intervals[i].end;
	}
	sort(intervals + 1,intervals + N + 1,cmp);
	int Start,End;
	Start = intervals[1].begin;
	End = intervals[1].end;
	int longest_continuous = End - Start;
	int longest_inter = 0;
	for(int i = 2; i <= N; i++){
		if(intervals[i].begin <= End && intervals[i].end <= End){
			//doNothing
		}
		if(intervals[i].begin <= End && intervals[i].end > End){
			longest_continuous = max(longest_continuous,intervals[i].end - Start);
			End = intervals[i].end;
		}
		if(intervals[i].begin > End){
			longest_inter = max(longest_inter,intervals[i].begin - End);
			Start = intervals[i].begin;
			longest_continuous = max(longest_continuous,intervals[i].end - intervals[i].begin);
			End = intervals[i].end;
		}
	}
	cout<<longest_continuous<<" "<<longest_inter<<endl;
	return 0;
}
