/*
Bruce Powell @ UNLV
Lecture section 1003, Lab section 1009
Exerise 8
This program accepts values for a polynomial in the form of ax^2 + bx + c, and determines
real and complex roots. The real and complex roots are then output with the original equations 
*/

#include<iostream>
#include<cmath>

double calc_discriminant(double a, double b, double c, double discriminant);
void calc_roots_quadratic(double a, double b, double c, double& root1, double& root2);


int main();
{
}



double calc_discriminant(double a, double b, double c, double discriminant)
{
  discriminant = pow(b,2) - (4 * a * c); //calculate discriminant
}

void calc_roots_real(double a, double b, double c, double& root1, double& root2)
{
  root1 = ((-b) + sqrt(pow(b,2) - 4 * a * c)) / (2 * a);
  root2 = ((-b) - sqrt(pow(b,2) - 4 * a * c)) / (2 * a);
}
void calc_roots_imag(double a, double b, double c, double& root_real, double& root_imag)
{
  root_real = (-b)/(2*a);
  root_imag = sqrt(4*a*c - pow(b,2))/(2*a);




