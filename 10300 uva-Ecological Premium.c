#include<stdio.h>
int main()
{
long long a,t,n,b,c,i,j,s;
while(scanf("%lld",&t)==1)
    {
    for(i=0;i<t;i++)
        {
        s=0;
        scanf("%lld",&n);
        for(j=0;j<n;j++)
            {
            scanf("%lld %lld %lld",&a,&b,&c);
            s+=a*c;
            }
        printf("%lld\n",s);
        }
    }
return 0;
}
