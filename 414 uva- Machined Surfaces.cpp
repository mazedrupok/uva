#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;

string str [15] ;
int countX[15] ;
int n ;

int main(){
  int i , j , k , ans ,len ,maxi;
  //freopen ("in.txt", "r", stdin);
  while ( cin>>n )
  {
         if( n == 0 )
          break ;
      maxi = 0;
      getchar() ;
      for ( i = 0 ; i < n ; i++)
      {

          countX[i] = 0 ;
          getline ( cin , str[i]);
          //cout << str[i] <<" ";
          len = str[i].length();
          for ( j = 0 ; j < len ; j++)
          if ( str[i][j] == 'X' )
          countX[i]++;
          if ( countX[i] > maxi)
          maxi =countX[i];
      //cout << countX[i] << endl;
      }
      ans = 0 ;
      for ( i = 0 ; i < n ; i++)
      ans += maxi - countX[i] ;
    printf("%d\n",ans);
  }
return 0 ;
}
