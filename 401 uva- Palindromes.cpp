#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

int main ()
{
   string a, b, s;
   map <char , char > m;
   int len, i, j;
   //freopen ("in.txt", "r", stdin);

   m['A']='A';
   m['E']='3';
   m['H']='H';
   m['I']='I';
   m['J']='L';
   m['L']='J';
   m['M']='M';
   m['O']='O';
   m['S']='2';
   m['T']='T';
   m['U']='U';
   m['V']='V';
   m['W']='W';
   m['X']='X';
   m['Y']='Y';
   m['Z']='5';
   m['0']='0';
   m['1']='1';
   m['2']='S';
   m['3']='E';
   m['5']='Z';
   m['8']='8';
   while (cin >> s) {
      len = s.size();
      a = b = "";  //removing previous memory..
      for (i = len - 1, j = 0; i >= 0; i--, j++) {
         a += s[i];   //catenating advantage..
         b += m[s[i]];
      }

      if (s==a && s==b)
         cout<<s<<" -- is a mirrored palindrome."<<endl<<endl;
      else if (s==a && s!=b)
         cout<<s<<" -- is a regular palindrome."<<endl<<endl;
      else if (s!=a && s==b)
         cout<<s<<" -- is a mirrored string."<<endl<<endl;
      else
         cout<<s<<" -- is not a palindrome."<<endl<<endl;
   }
}
