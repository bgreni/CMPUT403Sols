#include <bits/stdc++.h>
using namespace std;

/*
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://math.stackexchange.com/questions/937768/how-to-determine-if-a-triangle-can-be-drawn-with-the-given-points/937774
  https://github.com/UAPSPC/Code-Archive/blob/master/2d_geometry/isect_iline.c

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

// using ld = long double;


typedef struct{
  double x, y;
} P;

#define EPS 1e-8

int isect_iline(P a, P b, P c, P d, P *p){
  double r, denom, num1;

  num1  = (a.y - c.y) * (d.x - c.x) - (a.x - c.x) * (d.y - c.y);
  denom = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);

  if (fabs(denom) >= EPS) {
    r = num1 / denom;
    p->x = a.x + r*(b.x - a.x);
    p->y = a.y + r*(b.y - a.y);
    return 1;
  } 
  if (fabs(num1) >= EPS) return 0;
  return -1;
}

double dist(P a, P b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double perim(P a, P b, P c) {
    double dis = 0;
    dis += dist(a, b);
    dis += dist(b, c);
    dis += dist(a, c);
    return dis;
}

int main() {
    int n;
    cin >> n;
    P lines[n][2];

    double a,b,c,d;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;
        lines[i][0] = {a,b};
        lines[i][1] = {c,d};
    }


    double best = 0;
    int res = 0;
    P in[3];
    for (int i = 0; i < n; ++i) {
        if (i == n-2) break;
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                if (isect_iline(lines[i][0], lines[i][1], lines[j][0], lines[j][1], &in[0]) == 1);
                else continue;
                if (isect_iline(lines[k][0], lines[k][1], lines[j][0], lines[j][1], &in[1]) == 1);
                else continue;
                if (isect_iline(lines[k][0], lines[k][1], lines[i][0], lines[i][1], &in[2]) == 1);
                else continue;
                best = max(best, perim(in[0], in[1], in[2]));
            }   
        }
    }

    if (best == 0) cout << "no triangle" << endl;
    else cout << fixed << setprecision(10) << best << endl;
    

}