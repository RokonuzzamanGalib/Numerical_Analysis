#include<bits/stdc++.h>
#define EPSILON .001
using namespace std;

double func(double x)
{
	return x*sin(x)+cos(x);
}
double derivFunc(double x)
{
	return x*cos(x);
}

void newtonRaphson(double x)
{
	double h = func(x) / derivFunc(x);
	while (abs(h) >= EPSILON)
	{
		h = func(x)/derivFunc(x);
		x = x - h;
	}
	cout << "The value of the root is : " << x;
}

int main()
{
	double x0 = 3.14; 
	newtonRaphson(x0);
	return 0;
}
