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

  https://stackoverflow.com/questions/41898990/find-corners-of-a-rotated-rectangle-given-its-center-point-and-rotation
  https://www.rapidtables.com/convert/number/degrees-to-radians.html
  https://github.com/UAPSPC/Code-Archive/blob/master/2d_geometry/convex_hull.cpp\
  https://github.com/UAPSPC/Code-Archive/blob/master/2d_geometry/area_regpoly.c

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/


const double Epsilon = 1E-10;

typedef complex<double> Point;
bool operator<(const Point & p1, const Point &p2)
{
    return p1.imag() < p2.imag() || 
            (fabs(p1.imag() - p2.imag()) < Epsilon && p1.real() < p2.real());
}

double cross(const Point &a, const Point &b) {
    return imag(conj(a)*b);
}


Point P0;

enum Direction {CCW, CW, CL};

Direction cross_prod_dir(const Point &p1, const Point &p2, const Point &p0)
{
    double res = cross(p1 - p0, p2 - p0);

    if (fabs(res) < Epsilon)
        return CL;
    else if (res > 0.0)
        return CW;
    else
        return CCW;
}


bool polar_cmp(Point p1, Point p2)
{
    Direction res = cross_prod_dir(p1, p2, P0);

    if (res == CW)
        return true;
    else if (res == CCW)
        return false;
    else {
        double d = norm(p1 - P0) - norm(p2 - P0);

        if (fabs(d) < Epsilon)
            return false;
        else if (d < 0.0)
            return true;
        else
            return false;
    }
}

vector<Point> convex_hull(vector<Point> &poly)
{
    if (poly.size() <= 1)
        return poly;

    vector<Point> hull;

    int min = 0;
    P0 = poly[0];

    // Find point that has lowest y, and then has lowest x
    for (int i = 1; i < poly.size(); i++) {
        if (poly[i].imag() < P0.imag() || (fabs(poly[i].imag() - P0.imag()) < Epsilon && (poly[i].real() < P0.real()))) {
          min = i;
          P0 = poly[i];
        }
    }

    // Put P0 into start of poly
    poly[min] = poly[0];
    poly[0] = P0;
    hull.push_back(P0);

    sort(poly.begin() + 1, poly.end(), polar_cmp);
  
    // Find first distinct element from P0
    int i;
    for (i = 1; i < poly.size(); i++) {
        if (norm(poly[i] - P0) > Epsilon)
          break;
    }

    if (i == poly.size())
        return hull;

    hull.reserve(poly.size());
    hull.push_back(poly[i++]);

    for ( ; i < poly.size(); i++) {
        while (hull.size() > 1 && cross_prod_dir(poly[i], *(hull.end() - 1), *(hull.end() - 2)) != CCW)
            hull.pop_back();

        hull.push_back(poly[i]);
    }

    return hull;
}

double area_poly(const vector<Point> &p){
    double sum = 0;

    for(int i = p.size()-1, j = 0; j < p.size(); i = j++)
        sum += cross(p[i], p[j]);

    return sum/2.0;
}

double pi = acos(-1);

int main() {
    int n, b;
    cin >> n;

    double x, y, w, h, v;
    while (n--) {
        int b_area = 0;
        cin >> b;
        vector<Point> all_points;
        all_points.reserve(b*4);

        for (int i = 0; i < b; ++i) {
            cin >> x >> y >> w >> h >> v;

            
            v *= pi/180.0;

            b_area += w*h;

            Point adjh(sin(v),cos(v)), adjw(-cos(v),sin(v)), center(x,y);
            adjh = adjh*(h/2); adjw = adjw*(w/2);

            all_points.push_back(center + adjh + adjw);
            all_points.push_back(center + adjh - adjw);
            all_points.push_back(center - adjh + adjw);
            all_points.push_back(center - adjh - adjw);
        }
        vector<Point> hull = convex_hull(all_points);

        double hull_area = area_poly(hull);

        cout << fixed << setprecision(1) << (b_area / hull_area) * 100 << " %\n";

    }
}