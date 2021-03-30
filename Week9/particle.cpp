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

https://gamedev.stackexchange.com/questions/15911/how-do-i-calculate-the-exit-vectors-of-colliding-projectiles
https://stackoverflow.com/questions/33140999/at-what-delta-time-will-two-objects-collide
https://www.quora.com/How-do-I-normalize-a-complex-vector

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

using ld = long double;
typedef complex<ld> Point;
// #define EPS 1e-
ld dot(Point p, Point q) { return real(p*conj(q)); }

ld will_hit(Point p1, Point p2, ld r, Point vec) {
    ld x = p1.real() - p2.real();
    ld y = p1.imag() - p2.imag();
    ld xp = vec.real();
    ld yp = vec.imag();

    ld a = pow(xp, 2) + pow(yp, 2);
    ld b = 2*(x*xp + y*yp);
    ld c = pow(x, 2) + pow(y, 2) - pow((r+r), 2);

    // ld a = dot(yp, yp);
    // ld b = 2*dot(yp, xp);
    // ld c = dot(xp, xp) - r*r;
    if (b*b < 4*a*c) return -1.0;



    ld disc = pow(b, 2) - 4.0*a*c;
    ld t = (-b - sqrt(disc)) / (2*a);
    if (t < 0) return -1.0;
    return t;
} 

Point col(Point p1, Point p2, Point vec) {
    Point n = p1 - p2;
    // normalize n
    n = ((ld)1.0/sqrt(pow(n, 2))) * n;
    ld a1 = dot(vec, n);

    ld opt = (2.0 * (a1)) / 2;

    return vec + opt * n;
}


int main() {
    ld x, y, r;
    Point ps[3];
    for (int i = 0; i < 3; ++i) {
        cin >> x >> y;
        ps[i] = Point(x, y);
    }

    cin >> x >> y >> r;
    Point vec(x, y);
    ld ret;
    if ((ret = will_hit(ps[0], ps[1], r, vec)) > 0) {
        ps[0] += vec * ret;
        vec = col(ps[0], ps[1], vec);
        if ((ret = will_hit(ps[1], ps[2], r, vec)) > 0) {
            cout << 1 << endl;
        } else {
            cout << 3 << endl;
        }
    }
    else if ((ret = will_hit(ps[0], ps[2], r, vec)) > 0) {
        ps[0] += vec * ret;
        vec = col(ps[0], ps[2], vec);
        if ((ret = will_hit(ps[2], ps[1], r, vec) > 0)) {
            cout << 2 << endl;
        } else {
            cout << 4 << endl;
        }
    } else {
        cout << 5 << endl;
    }

}