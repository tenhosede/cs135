/*--------------------------------------------------------------------------------------
  Bruce Powell @ UNLV--------------------------- Exercise 6
  Lecture Section 1003, Lab Section 1009
  This program accepts an existing value file as input and calculates the square root,
  cubed root, and square of the input number.
--------------------------------------------------------------------------------------*/


#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const int columnWidth = 14;

int main()
{

  int n = 0; //n is the number of entries in the file, which is the first integer in the file
  int currentValue = 0;
  int loopIndex = 0;
  double runningValue = 0.0;
  bool valueNegative = false;

  cin >> n;
 
  cout << endl << "Bruce Powell     Lec Sec# 1003, Lab Sec# 1009, Exercise #7" << endl << endl;
  cout << fixed << setprecision(5);
  cout << right << setw(columnWidth) << "Input#" << setw(columnWidth) << "Square Root" << setw(columnWidth);
  cout << "Cube Root" << setw(columnWidth) << "# Squared" << endl;

  for (loopIndex = 0; loopIndex < n; loopIndex++)
    {
      cin >> currentValue;
      valueNegative = false;
      if (currentValue < 0)
	valueNegative = true;
      cout << setw(columnWidth) << setprecision(5) << currentValue;
      if (valueNegative) 
	cout << setw(columnWidth) << " ";
      else
	cout << setw(columnWidth) << sqrt(currentValue);
      cout << setw(columnWidth) << cbrt(currentValue);
      cout << setw(columnWidth) << setprecision(0) <<  pow(currentValue, 2) << endl;
      runningValue = runningValue + static_cast<double>(currentValue);
    }
  cout << endl << "Average = " << setprecision(5) << runningValue/(n) << endl;

}















