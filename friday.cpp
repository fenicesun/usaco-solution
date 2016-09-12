/* 
ID:kevin_s1
PROG:friday
LANG:C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int N;
int frequency[8];
int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isLeapYear(int year){
	if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return true;
	else
		return false;
}

int main(){

	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
	memset(frequency,0,sizeof(frequency));
	int currentday = 1;
	cin>>N;
	for(int year = 1900; year <= 1900 + N - 1; year++){
		if(isLeapYear(year) == true)
			month[2] = 29;
		else
			month[2] = 28;
		for(int mon = 1; mon <= 12; mon++){
			for(int day = 1; day <= month[mon]; day++){
				if(day == 13){
					frequency[currentday]++;
				}
				currentday = (currentday + 1) % 7;
			}
		}

	}

	cout<<frequency[6]<<" "<<frequency[0];
	for(int i = 1; i <= 5; i++)
		cout<<" "<<frequency[i];
	cout<<endl;
	return 0;
}
