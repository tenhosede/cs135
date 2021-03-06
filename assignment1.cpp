//Bruce Powell @ UNLV
//Assignment 1
//Lecture Section 1003, Lab Section 1009
//Expects 6 integer style values in 2 sets of 3
//one set per equation. 
//Uses Cramer's rule of matrices to calculate a ratio
//of determinants to find values and display for x and y.


#include<iostream>
using namespace std;

int main()
{

  double a = 0.0; //coefficient for x in first equation
  double b = 0.0; //coefficient for y in first equation
  double c = 0.0; //output of  first equation
  double d = 0.0; //coefficient for x in second equation
  double e = 0.0; //coefficient for y in second equation
  double f = 0.0; //output of second equation
  double x = 0.0; //solution for x
  double y = 0.0; //solution for y
  double matrixDeterminant = 0.0; //determinant of coefficient matrix
 
  cout << "Enter the constants (a, b, c) for equation 1" << endl;
  cin >> a >> b >> c;
  cout << "Enter the constants (d, e, f) for equation 2" << endl;
  cin >> d >> e >> f;
  
  cout << "-----------------------------------------" << endl;
  cout << "Bruce Powell 1003 1009      Assignment #1" << endl;
  cout << "-----------------------------------------" << endl;

  //math to find the denominator determinant (only one operation)
  //then each numerator operation (two operations) then ratios
  // which yield the correct values
  matrixDeterminant = (a * e - b * d);
  cout << a << "x + " << b << "y = " << c <<  endl;
  cout << d << "x + " << e << "y = " << f <<  endl;
  if (matrixDeterminant != 0)
			  {
  x = (c * e - b * f)/matrixDeterminant;
  y = (a * f - c * d)/matrixDeterminant;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
			  }
  else
	{
  cout << "Cramer's Rule cannot be used for this matrix" << endl;
  cout << "Coefficient Matrix determinant = 0" << endl;
    }
}

