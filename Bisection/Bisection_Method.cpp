#include <iostream>
using namespace std;
#define EP 0.0005

double solution(double x) {
   return x*x*x-2*x-5;
}


void Bisection(double a, double b) {

   if (solution(a) * solution(b) >= 0) {
      cout << "There is no root between a and b\n";
      return;
   }

   double m = a;

   while ((b-a) >= EP) {
    
      m = (a+b)/2;
     
      if (solution(m) == 0.0)
         break;
    
      else if (solution(m)*solution(a) < 0)
         b = m;

      else
         a = m;
   }
   cout << "The value of root is : " << m;
}

int main() {
   double a =-1;
   double b = 16;
   Bisection(a, b);
   return 0;
}