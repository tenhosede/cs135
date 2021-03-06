// Bruce Powell, Lecture Section 1003, Lab Section 1009, Exercise 8
// Purpose: This program is designed to compute the solutions to
//          a series of polynomial equations of the form:
//          ax^2 + bx + c = 0
// Input:   for each equation the program will read the three
//          integer coefficients of the terms in the equation
//          (a, b, and c)
// Output:  the equation to be solved: ax^2 + bx + c = 0
//          (if coefficient is 0, term is not displayed) 
//          the type of equation (linear or quadratic and type of roots)
//          solution(s) with labels and 3 digits to the right of the decimal

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void print_equation (int,int,int);
double linearroot (int,int);
void realroot (int,int,int,double&,double&);
void complexroot (int,int,int,double&,double&);

int main()
{
  int a,b,c;           // coefficients of the terms in the polynomial
  int discrim;         // discriminant of quadratic formula
  double linear;       // root of linear equation
  double root1_real;   // first real root of a quadratic
  double root2_real;   // second real root of a quadratic
  double root_imag;    // first imaginary root of a quatric
  cout << fixed << setprecision(3);
  cout << "Bruce Powell, LecSec# 1003, LabSec# 1009, Exercise# 08" << endl << endl;;
  cin >> a;
  while (cin)
    {
      cin >> b >> c;
      print_equation(a,b,c);    // display the equation in required format
      discrim = b * b - 4 * a * c;
      if (a == 0)
	{
	  cout << "Linear equation" << endl;
	  linear = linearroot(b,c); // compute and return linear solution
	  if (linear == -0.0)
	    linear = 0.0;
	  cout << "x = " << linear << endl;
	}
      else if (discrim >= 0)
	{
	  cout << "Quadratic equation with real roots." << endl;
	  realroot(a,b,c, root1_real, root2_real);   // compute and print real solution(s)
	  if (root1_real == -0.0)
	    root1_real == 0.0;
	  cout << "x = " << root1_real;
	  if (root1_real != root2_real)
	    cout << " or x = " << root2_real;
	  cout << endl << endl;
	}
      else
	{
	complexroot(a,b,c, root1_real, root_imag);     // compute and print complex solutions
	if (root1_real == -0.0)
	  root1_real = 0.0;
	cout << "Quadratic equation with comblex roots." << endl;
	cout << "x = " << root1_real << " + " << root_imag <<  "i or ";
	cout << " x = " << root1_real << " - " << root_imag << "i" << endl;
	}
      cout << endl;
      cin >> a;
    }
  return 0;
}

void print_equation(int a, int b, int c)
// Given the coefficients: a, b, and c of a 2nd degree polynomial,
// display the equation in the form: ax^2 + bx + c = 0

// a, b, and c must be displayed as integers.
// Display only terms with non-zero coefficients.
// Examples:
// if a = 3 b = -2 c = 5 display 3x^2 + -2x + 5 = 0 
// if a = 0 b = -5 c = -3 display -5x + -5 = 0
// if a = -4 b = 3 c = 0 display -4x^2 + 3x = 0
// Assume a, b, and c will define a solvable equation.
// Assume at least one coefficient will be non-zero.
{
  if (a != 0)
    cout << a << "x^2 + ";
  if (b != 0)
    cout << b << "x + ";
  if (c != 0)
    cout << c;
  cout << " = 0" << endl;

}

double linearroot(int b, int c)
// Given the values of b and c in an equation of the form bx + c = 0,
// compute and return the value of x.
{
  double root = 0.0;
 
  root = (-c) / b;

  return root;
}

void realroot(int a, int b, int c, double& root1_real, double& root2_real)
// Given the coefficients of a 2nd degree polynomial where the roots
// are real, solve for x1 and x2. Display the type of equation
// (quadratic with real roots) and roots with labels and 3 digits to
// right of decimal. If both roots are the same, display only one value
// for x.
{ 
  root1_real = ((-b) + sqrt(pow(b,2) - 4 * a * c)) / (2 * a);
  root2_real = ((-b) - sqrt(pow(b,2) - 4 * a * c)) / (2 * a);

}
 
void complexroot(int a, int b, int c, double& root1_real, double& root_imag)
// Given the coefficients of a 2nd degree polynomial where the roots
// are complex, solve for the 2 imaginary roots. Display the type
// of equation (quadratic with complex roots) and the roots in
// the form x + yi and x - yi with labels. x and y should be
// displayed with 3 digits to the right of the decimal. Do not display
// x + -yi and x - -yi. 
{
  root1_real = (-b)/(2*a);
  root_imag = sqrt(4*a*c - pow(b,2)/(2*a));
}




