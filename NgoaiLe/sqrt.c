#include <math.h>
#include <stdio.h>

int main() {
   double number, squareRoot;


   scanf("%lf", &number);

   // computing the square root
   squareRoot = sqrt(number);

   printf("Square root of %.2lf =  %.2lf", number, squareRoot);

   return 0;
}