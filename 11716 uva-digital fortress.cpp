#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
   char s[100000];
   int i , tes , j , k , l , m , n;
   double x;
   scanf("%d",&tes);
   gets(s);
   while(tes--)
   {
      gets(s);
      l = strlen(s);
      x = sqrt(l);
      if(x - (int)x != 0)
         printf("INVALID\n");
      else
      {
         for(j = 0; j < (int)x; j++)
            for(i = j; i < l; i = i + (int)x)
               printf("%c",s[i]);
         printf("\n");
      }
   }
   return 0;
}
