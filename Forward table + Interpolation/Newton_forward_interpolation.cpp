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
	float x[] = { 1,2,3,4,5,6,7,8 };
	float y[] = {3010,3424,3802,4105,4472,4771,5051,5315};
    int n = sizeof(y)/sizeof(y[0]);

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

	float value = 7;

	float sum = del_Y[0][0];
	float h = (x[1] - x[0]);
	float u = (value - x[0]) / h;
	for (int i = 1; i < n; i++) {
		sum = sum + (U(u, i) * del_Y[0][i]) /factorial(i);
	}

	cout << "\n Value at " << value << " is "<< sum << endl;

	cout << "\n";
	
	return 0;
}
