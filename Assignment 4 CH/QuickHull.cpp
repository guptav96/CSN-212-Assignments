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

int pdistance(Point P,int a,int b)
{
	return abs(P.y-a*P.x-b)/sqrt(1+a*a);
}
vector<Point> qhull;

void findHull (vector<Point> S, Point P,Point Q) 
{ 
   if (S.size()==0) 
        return;
    vector<Point>::iterator it;
    int max=0;
    int count=0;
    int ind=0;
    int indp=0;
    int k=0;
	double sl=double(Q.y-P.y)/double(Q.x-P.x);
    double intercept=P.y-sl*P.x;
   // cout<<sl<<" "<<intercept<<endl;  
    for(it=S.begin(); it!=S.end(); ++it)
    {
    	int d=pdistance(*it,sl,intercept);
    	if(d>max)
    	{
    		max=d;
    		ind=k;
    	}
    	k++;
    }
    for(int i=0;i<qhull.size();i++)
    {
    	if(qhull[i].x==P.x && qhull[i].y==P.y)
    		{
    			indp=i;
    			break;
    		}
    }
    it = qhull.begin();
    qhull.insert (it+indp+1,S.begin()+ind,S.begin()+ind+1);
    vector<Point> S1,S2;
    for(int i=0;i<S.size();i++)
    {
    	if(orientation(S[ind],S[i],P)==1)
    	{
    		S1.push_back(S[i]);
    	}
    	if(orientation(S[i],S[ind],Q)==1)
    	{
    		S2.push_back(S[i]);
    	}
    }
    
    findHull(S1, P, S[ind]) ;
    findHull(S2, S[ind], Q) ;
}
void QuickHull (Point points[], int n) 
{ 
    vector<Point> qhullleft;
	vector<Point> qhullright;
    int min=100000;int max=-100000;
    int a=0;int b=0;
    for(int i=0;i<n;i++)
    {
    	if(points[i].x<min)
    		{
    			min=points[i].x;
    			a=i;
    		}
    	if(points[i].x>max)
    		{
    			max=points[i].x;
    			b=i;
    		}
    }
   qhull.push_back(points[a]);
   qhull.push_back(points[b]);
    for(int i=0;i<n;i++)
    {
    	if(i==a||i==b)continue;
    	if(orientation(points[i],points[a],points[b])==1)
    	{
    		qhullleft.push_back(points[i]);
    	}
    	if(orientation(points[i],points[a],points[b])==2)
    	{
    		qhullright.push_back(points[i]);
    	}

    } 
   findHull(qhullleft, points[a], points[b]) ;
   findHull(qhullright, points[b], points[a]) ;
}



int main()
{
	clock_t t1,t2;
	t1=clock();
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                      {0, 0}, {1, 2}, {3, 1}, {3, 3},{2,7}};
    int n = sizeof(points)/sizeof(points[0]);
    QuickHull(points, n);
    for(int i=0;i<qhull.size();i++)
    {
    	cout<<"("<<qhull[i].x<<","<<qhull[i].y<<")"<<endl;
    }
    t2=clock();
    cout<<" The running time is "<<float(t2)-float(t1)<<endl;
    return 0;
}
