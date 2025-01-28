#include <bits/stdc++.h>
using namespace std;


float U(float u, int n)
{
	float temp = u;
	for (int i = 1; i < n; i++)
		temp = temp * (u - i);
	return temp;
}

int factorial(int n)
{
	int f = 1;
	for (int i = 2; i <= n; i++)
		f *= i;
	return f;
}

int main()
{

    cout<<"Enter The Number of X  ";
    int n;
    cin>>n;
    float x[n];
    float y[n] ;
    for (int i = 0; i < n; i++)
    {
        cout<<"X"<<i+1<<" = ";
        cin>>x[i];
        cout<<"Y"<<i+1<<" = ";
        cin>>y[i];

    }
    


	float del_Y[n][n];

    for (int i = 0; i < n; i++)
    {
        del_Y[i][0]=y[i];
    }
    
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++)
			del_Y[j][i] = del_Y[j + 1][i - 1] - del_Y[j][i - 1];
	}

	cout<<"\n\t\t\tThe Forward Difference Table\n";

	for (int i = 0; i < n; i++) {
		cout << setw(4) << x[i] 
			<< "\t";
            
		for (int j = 0; j < n - i; j++)
			cout << setw(4) << del_Y[i][j] 
				<< "\t";
		cout << endl;
	}

	float X ;
    cout << "\nPlease enter the value of X where you'd like to find the interpolated value: ";
    cin>>X;
    
	float sum = del_Y[0][0];
	float h = (x[1] - x[0]);
	float u = (X - x[0]) / h;
	for (int i = 1; i < n; i++) {
		sum = sum + (U(u, i) * del_Y[0][i]) /factorial(i);
	}

	cout << "\n Value at " << X << " is "<< sum << endl;

	cout << "\n";
	
	return 0;
}
