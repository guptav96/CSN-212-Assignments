#include <bits/stdc++.h>
using namespace std;
struct Point     
{
    int x, y;
};

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
void giftWrap(Point points[], int n)
{
    if (n < 3) return;
    vector<Point> convexHull;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
 
    int p = l, q;
    do
    {
        convexHull.push_back(points[p]);
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }
        p = q;
 
    } while (p != l);
    for (int i = 0; i < convexHull.size(); i++)
        cout << "(" << convexHull[i].x << ", "<< convexHull[i].y << ")"<<endl;
}

int main()
{
	clock_t t1,t2;
	t1=clock();
    Point points[10000];
    for(int i=0;i<10000;i++)
    {
    	cin>>points[i].x;
    	cin>>points[i].y;
    }
    int n = sizeof(points)/sizeof(points[0]);
    giftWrap(points, n);
    t2=clock();
    cout<<" The running time is "<<float(t2)-float(t1)<<endl;
    return 0;
}
