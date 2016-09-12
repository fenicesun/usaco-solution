/*
  ID: lei.i1
  PROG: preface
  LANG: C++
*/
#include <fstream>
#include <map>
#include <string>
using namespace std;
 
ifstream fin("preface.in");
ofstream fout("preface.out");
 
const int MAX = 3500;
static string roman_number[MAX];
void init();
string GetRomanNumber(int n);
map<char, int> GetPreface(int n);
void Output(map<char, int> counter);
 
int main() {
  int n;
  fin >> n;
  init();
  map<char, int> result = GetPreface(n);
  Output(result);
  return 0;
}
 
void init() {
  roman_number[1] = "I";
  roman_number[5] = "V";
  roman_number[10] = "X";
  roman_number[50] = "L";
  roman_number[100] = "C";
  roman_number[500] = "D";
  roman_number[1000] = "M";
  roman_number[2] = "II";
  roman_number[3] = "III";
  roman_number[4] = "IV";
  roman_number[6] = "VI";
  roman_number[7] = "VII";
  roman_number[8] = "VIII";
  roman_number[9] = "IX";
}
 
string GetRomanNumber(int n) {
  // 如果已计算,直接返回,否则对其各位进行分解计算
  if (!roman_number[n].empty())
    return roman_number[n];
 
  // 计算千位,千位小于4000,计算简单,千位以下可递归
  if (n / 1000) {
    string roman;
    int thousand = n / 1000 * 1000;
    if (roman_number[thousand].empty()) {
      string thousand_string;
      for (int i = 1000; i <= thousand; i += 1000)
        thousand_string += "M";
      roman_number[thousand] = thousand_string;
    }
    roman += roman_number[thousand];
    n -= thousand;
    if (n)
      roman += GetRomanNumber(n);
    return roman;
  }
  // 计算百位
  if (n / 100) {
    string roman;
    int hundred = n / 100 * 100;
    if (roman_number[hundred].empty()) {
      switch (hundred) {
        case 200:
        case 300:
          for (int i = 100; i <= hundred; i += 100)
            roman += "C";
          break;
        case 400:
          roman = "CD";
          break;
        case 600:
        case 700:
        case 800:
          roman = "D";
          for (int i = 600; i <= hundred; i += 100)
            roman += "C";
          break;
        case 900:
          roman = "CM";
          break;
        default:
          break;
      }
      roman_number[hundred] = roman;
    }
    roman = roman_number[hundred];
    n -= hundred;
    if (n)
      roman += GetRomanNumber(n);
    return roman;
  }
  // 计算十位，方法同百位类似
  if (n / 10) {
    string roman;
    int ten = n / 10 * 10;
    if (roman_number[ten].empty()) {
      switch (ten) {
        case 20:
        case 30:
          for (int i = 10; i <= ten; i += 10)
            roman += "X";
          break;
        case 40:
          roman = "XL";
          break;
        case 60:
        case 70:
        case 80:
          roman = "L";
          for (int i = 60; i <= ten; i += 10)
            roman += "X";
          break;
        case 90:
          roman = "XC";
          break;
        default:
          break;
      }
      roman_number[ten] = roman;
    }
    roman = roman_number[ten];
    n -= ten;
    if (n)
      roman += GetRomanNumber(n);
    return roman;
  }
}
 
map<char, int> GetPreface(int n) {
  map<char, int> counter;
  string roman;
  for (int i = 1; i <= n; ++i) {
    roman = GetRomanNumber(i);
    for (string::iterator iter = roman.begin(); iter != roman.end(); ++iter)
      ++counter[*iter];
  }
  return counter;
}
 
void Output(map<char, int> counter) {
  string roman("IVXLCDM");
  for (string::iterator iter = roman.begin(); iter != roman.end(); ++iter)
    if (counter[*iter])
      fout << *iter << ' ' << counter[*iter] << '\n';
}
