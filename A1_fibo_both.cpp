#include<bits/stdc++.h>
using namespace std;


int fibo_rec(int n,vector<int> &rec)
{
	if(n==1)
	{
		rec[0]=0;
		return 0;
	}
	if(n==2)
	{
		rec[1]=1;
		return 1;
	}
	else 
	{
		int ans=fibo_rec(n-1,rec)+ fibo_rec(n-2,rec);
		rec[n-1]=ans;
		return ans;
	}
}
void fibo_itr(int n)
{
   int x = 0, y = 1, z = 0;
   for (int i = 0; i < n; i++) {
      cout << x << " ";
      z = x + y;
      x = y;
      y = z;
   }
	
}
int main()
{
	int n;
	cout<<"Enter the number of fibonacci numbers required :: ";
	cin>>n;
	vector<int> rec(n,0);
	fibo_rec(n,rec);
	cout<<"\n\n";
	cout<<"Fibonacci series recursive :: ";
	for(auto val: rec)
	{
		cout<<val<<" ";
	}
	cout<<"\n";
	cout<<"Fibonacci series iterative :: ";
	fibo_itr(n);
}

