#include<bits/stdc++.h>
using namespace std;
int main()
{
	ofstream myfile;
	myfile.open("C:\\Users\\VIVEK GUPTA\\Desktop\\in10000.txt");
	int t=1000;
	for(int i=0;i<t;i++)
	{
		myfile<<rand()%10000<<" "<<rand()%10000<<endl;
	}
	myfile.close();
}
