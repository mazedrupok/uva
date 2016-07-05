/**
   MMM   MMM     A     ZZZZZZZ EEEEEEE DDDDD
   MM MMM MM    AAA    Z   ZZ  EE    E DDDDDDD
   MM  M  MM   AA AA      ZZ   EEEE    DD   DD
   MM     MM  AAAAAAA   ZZ   Z EE    E DDDDDDD
   MMM   MMM AA     AA ZZZZZZZ EEEEEEE DDDDD
   
 Name:     Md. Abdul Mazed (RUPOK)
           Noakhali Science & Technology University
 Email:    mazedrupok@gmail.com || mazed4g@gmail.com
 FB id:    www.facebook.com/mazedrupok
 github:   www.github.com/mazedrupok
 problem:  UVA-1213
 Catagory: BackTracking & DP
*/
#include <bits/stdc++.h>
using namespace std;
int prime[187]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,
                79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,
                163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,
                251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,
                349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,
                443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,
                557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,
                647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,
                757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,
                863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,
                983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,
                1069,1087,1091,1093,1097,1103,1109,1117};
int n, k;
int dp[187][1121][15];
int func (int i, int sum, int cnt) {
    if (cnt == k) {
        if (sum == 0) return 1;
        return 0;
    }
    if (sum < 0 || i < 0) return 0;
    if (dp[i][sum][cnt] != -1) return dp[i][sum][cnt];

    int v1 = 0, v2 = 0;
    if (sum - prime[i] >= 0) v1 = func (i-1, sum - prime[i], cnt+1);
    v2 = func (i-1, sum, cnt);
    return dp[i][sum][cnt] = (v1+v2);
}
int main() {
    //freopen ("in.txt", "r", stdin);
    while (scanf (" %d %d", &n, &k) == 2, (k||n)) {
        memset (dp, -1, sizeof (dp));
        printf ("%d\n", func(186, n, 0) );
    }
    return 0;
}
