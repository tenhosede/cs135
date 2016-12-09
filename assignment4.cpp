/* 
Bruce Powell CS135 Lecture Section #1003, Lab Section #1009, Assignment 4

This program expects an input via linux redirection that contains an unknown number of coordinate

sets, (x1,y1) (x2,y2) and computesthe equation of the line in slope intercept form, and it's perpendicular line 
*/

#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;

void printName(int, char);
bool pointCheck(int,int,int,int);
void calcSlope(int x1,int x2,int y1,int y2, int& slopeNum, int& slopeDenom);
void calcMidpoint(int x1, int x2, int y1, int y2, double& midx, double& midy);
double calcLineLength(int x1, int x2, int y1, int y2);
void printSlope (int slopeNumerator, int slopeDenominator);
void printEquation(int x1, int y1, int slopeNumerator, int slopeDenominator, double y_intercept);
double calcIntercept(int x1, int y1, int slopeNumerator, int slopeDenominator); 

int main() {

  int x1 = 0; // coordinates from file
  int x2 = 0;
  int y1 = 0;
  int y2 = 0;
  int slopeNum = 0;
  int slopeDenom = 0;
  double intercept = 0.0; //calculated intercept
  double midx = 0.0; //midpoint coordinates
  double midy = 0.0;
  double lineLength = 0.0; //length of line



  printName(4, 'A');

  cin >> x1;
  cin >> y1;
  cin >> x2;
  cin >> y2;

  cout << endl << endl;

  while (cin)
    {
      if (pointCheck(x1, x2, y1, y2))
	{
	  lineLength = calcLineLength(x1 , x2, y1, y2);
	  calcMidpoint(x1, x2, y1, y2, midx, midy);
	  calcSlope(x1, x2, y1, y2, slopeNum, slopeDenom);

	  cout << left << "Point 1: (" << x1 << "," << y1 << ")";
	  cout << "     Point 2: (" << x2 << "," << y2 << ")" << endl;
	  cout << "Length of defined line segment: " << lineLength << endl;
	  cout << "Midpoint of line segment is: (" << midx << "," << midy << ")" << endl;
	  cout << "Slope of line: ";
	  printSlope(slopeNum, slopeDenom);
	  intercept = calcIntercept(x1, y1, slopeNum, slopeDenom);
	  cout << "Equation: ";
	  printEquation(x1, y1, slopeNum, slopeDenom, intercept);
	  cout << "Slope of perpendicular line: ";
	  printSlope(slopeDenom, (slopeNum * -1));
	  intercept = calcIntercept(x1, y1, slopeDenom, (slopeNum * -1));
	  cout << "Perpendicular Line Equation: ";
	  printEquation(x1, y1, slopeDenom, (slopeNum * -1), intercept); 
	}
      else 
	cout << "Points are equivalent, cannot complete calculations with duplicate set";

      cout << endl << endl;
    
	  cin >> x1;
	  cin >> y1;
	  cin >> x2;
	  cin >> y2;
	  
	}
return 0;
}

void printName(int num, char type)
//prints my name and pertinent information, accepts the assignment or exercise number and a character 'A' or 'a' 
//to print assignment, otherwise prints exercise
{
  cout << "===============================================================" << endl << endl;
  cout << "Bruce Powell, Lecture Section 1003, Lab Section 1005,";
  if (type == 'a' || type == 'A')
    cout << " Assignment #" << num << endl << endl;
  else
    cout << " Exercise #" << num << endl << endl;
  cout << "===============================================================" << endl << endl;
}

bool pointCheck(int xco1, int xco2, int yco1, int yco2)
{
 //if points are the same, return false, otherwise return true

  if (xco1 == xco2 && yco1 == yco2)
    return false;
  else
    return true;
}


void calcSlope(int x1,int x2,int y1,int y2, int& slopeNum, int& slopeDenom)
//calculates the rise over run (y1-y2)/(x1-x2) and give the numerator and denominator back in reduced form
// through slopeNum and slopeDenom
{
  int smaller = 0; // used for reducing
  slopeNum = y1 - y2; //calc rise
  slopeDenom = x1 - x2; // calc run

  if (slopeNum == slopeDenom)
    {
      slopeNum = 1;
      slopeDenom = 1;
    }
  else
    {
      if (slopeNum < slopeDenom)
	smaller = slopeNum;
      else if (slopeDenom < slopeNum)
	smaller = slopeDenom;
      for (int i = abs(smaller); i > 2; i--)
	{
	  if (slopeNum % i == 0 && slopeDenom % i == 0)
	    {
	      slopeNum = slopeNum / i;
	      slopeDenom = slopeDenom / i;
	    }
	}
    }
  if (slopeDenom < 0 && slopeNum < 0)
      {
	slopeDenom = fabs(slopeDenom);
	slopeNum = fabs(slopeNum);
      }
  else if (slopeDenom < 0 && slopeNum > 0)
    {
      slopeNum = slopeNum * -1;
      slopeDenom = fabs(slopeDenom);
    }
  cout << endl;
}

void calcMidpoint(int x1, int x2, int y1, int y2, double& midx, double& midy)
//calculates the midpoint of the line by accepting integer coordinates and writing
// the resulting coordiante to midx and midy
{
  midx = (x1 + x2)/2.;
  midy = (y1 + y2)/2.;
}

double calcLineLength(int x1, int x2, int y1, int y2)
//calculates the length of the line sqrt(pow(x,2) + pow(y,w))
{
  double xlength = 0;
  double ylength = 0;
  xlength = x1 - x2;
  ylength = y1 - y2;
  xlength = pow(xlength, 2);
  ylength = pow (ylength, 2);
  return sqrt(xlength + ylength);
}


void printSlope (int slopeNumerator, int slopeDenominator)
//given the slope numerator and denominator, prints the slope of the equation.
//looks for undefined or 0 slopes
{
  if (slopeDenominator < 0 && slopeNumerator < 0)
      {
	slopeDenominator = fabs(slopeDenominator);
	slopeNumerator = fabs(slopeNumerator);
      }
  else if (slopeDenominator < 0 && slopeNumerator > 0)
    {
      slopeNumerator = slopeNumerator * -1;
      slopeDenominator = fabs(slopeDenominator);
    }

  if (slopeDenominator == 0)
    cout << "undefined" << endl;
  else if (slopeNumerator == 0)
    cout << "0" << endl;
  else
    {
       if (slopeDenominator == 1)
	cout << slopeNumerator << endl;
      else
	cout << slopeNumerator << "/" << slopeDenominator << endl;
    }
}

void printEquation(int x1, int y1, int slopeNumerator, int slopeDenominator, double y_intercept)
//takes the coordianates, slope, and intercept of a given equation and prints out the equation

{
	  if (slopeDenominator == 0)
	    cout << "x = " << x1;
	  else if (slopeNumerator == 0)
	    cout << "y = " << y1;
	  else
	    {
	      cout << "y = ";
	      if (slopeDenominator == 1)
		cout << slopeNumerator << "x";
	      else
		cout << slopeNumerator / static_cast<double>(slopeDenominator) << "x";

	      if (y_intercept > 0)
		cout << " + " << y_intercept;
	      else if (y_intercept < 0)
		cout << " - " << fabs(y_intercept);
	    }
	  cout << endl;
}

double calcIntercept(int x1, int y1, int slopeNumerator, int slopeDenominator)
//calculats the intercept using point-slope equations, accepts the point and the slope
//returns the intercept
{
  double intercept = 0.0;
  double slope = 0.0;

  slope = slopeNumerator/static_cast<double>(slopeDenominator);
  intercept = y1  - (slope * x1);
  return intercept;
}
  
