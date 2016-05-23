/*
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com || mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok

   Catagory: Graph (Floyd Warshal Algorithm)
   Comment:  Finding All Pairs Shortest Path.
*/
#include <bits/stdc++.h>
using namespace std;
#define MX  30050
typedef long long LL;
#define V 101
#define INF 1e9

void printSolution(int dist[][V]);
void floydWarshall (int graph[][V]) {
    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++){
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    double sum = 0, cnt = 0;
   for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
         if (dist[i][j] != INF) {
            sum += dist[i][j];
            if (i != j) cnt++;
         }
      }
   }
   double a = sum /cnt;
   printf ("%.3lf", a);
    //printSolution(dist);
}
//void printSolution(int dist[][V])
//{
//    printf ("Following matrix shows the shortest distances"
//            " between every pair of vertices \n");
//    for (int i = 0; i < V; i++){
//        for (int j = 0; j < V; j++){
//            if (dist[i][j] == INF)
//                printf("%7s", "INF");
//            else
//                printf ("%7d", dist[i][j]);
//        }
//        printf("\n");
//    }
//}

int main()
{
    int graph[V][V];
    int a, b, cs = 0;
    //freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);
    while (cin >> a >> b) {
      if (a == 0 && b == 0) break;
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
         if (i == j) graph[i][j] = 0;
         else graph[i][j] = INF;
      }
    }
    graph[a][b] = 1;
    while (cin >> a >> b) {
       if (a == 0 && b == 0) break;
       graph[a][b] = 1;
    }
   printf ("Case %d: average length between pages = ", ++cs);
    floydWarshall(graph);
   printf (" clicks\n");
    }
    return 0;
}
