/*
Bruce Powell @ UNLV
Lecture Section 1003
Lab Section 1009
This program accepts a file with a data set, prints out the set,
gives the number of non-zero values, their sum and average.
Output will be a form with rows of data including the set number,
count, sum, average, largest value, and factors.
Also outputs number of non-zero values, sum of non-zeros,
and the average of all of the non-zero numbers.
*/

#include<iostream>
#include<iomanip>
using namespace std;

//constants used for form column width
const int setColumn = 4;
const int countColumn = 10;
const int sumColumn = 10;
const int averageColumn = 12;
const int largestColumn = 12;
const int factorsColumn = 10;
const int formWidth = (setColumn + countColumn + sumColumn + averageColumn + largestColumn + factorsColumn);

int main()
{
  int input = 0; //input value will be stored here for processing
  int dataSet = 1; //this is the row number for the table
  int countValues = 0; // number of values in the set
  double sumValues = 0.0; // sum of values in the set
  double averageSet = 0.0; //
  int largestValue = 0;
  int factorSet = 0;
  int nonZeros = 0;
  int totalSum = 0.0;
  double totalAverage = 0.0;


  cout << endl << endl << endl; //form starts here
  cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << "Bruce Powell, Lecture Section 1003, Lab Section 1009, Assignment 3" << endl;
  cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << endl << endl;
  cout << left << setw(setColumn + countColumn + sumColumn + averageColumn + largestColumn);
  cout << "Data" << right;
  cout << setw(factorsColumn) << "Largest #" << endl;
  cout << setw(setColumn) << "Set#" << setw(countColumn) << "Count" << setw(sumColumn) << "Sum";
  cout << setw(averageColumn) << "Average" << setw(largestColumn) << "Largest #" << setw(factorsColumn);
  cout << "Factors" << endl;
  cout << setfill('=') << setw(formWidth) << "=" << endl;
  cout << right << setfill(' ');
  cout << fixed << setprecision(3);
  cin >> input;
  while (cin)
    {
	  while (input != 0)
	    {
	      countValues++; 
	      sumValues = sumValues + input;
	      if (input > largestValue)
		{
		  largestValue = input;
		}
	      //cout << input << " "; //these are debug lines
	      //cout << "debug message 1 " << endl;
	      //cout << countValues << endl;
	      //cout << sumValues << endl;
	      // cout << largestValue << endl;
	      cin >> input;
	      if (cin.eof())
		break;
	    }
	  cout << setw(setColumn) << dataSet;
	  cout << setw(countColumn) << countValues;
	  cout << setw(sumColumn) << sumValues;
	  if (countValues == 0)
	    {
	      cout << setw(averageColumn) << " ";
	    }	    
	  else
	    {
	      cout << setw(averageColumn) << sumValues/countValues;
	    }	      
	  cout << setw(largestColumn) << largestValue;
	  for (int i = 1; i < (largestValue + 1); i++)
	    {
	      if (largestValue % i == 0)
		{
		  factorSet++;
		}
	    }
	  cout << setw(factorsColumn) << factorSet << endl;
	  dataSet++;
	  nonZeros = nonZeros + countValues;
	  countValues = 0;
	  totalSum = totalSum + sumValues;
	  totalAverage = totalSum/static_cast<double>(nonZeros);
	  sumValues = 0;
	  largestValue = 0;
	  factorSet = 0;
	  cin >> input;
    }

  cout << setfill('=') << setw(formWidth) << "=" << endl;
  cout << endl << endl;
  cout << "Count of all non-zero #s: " << nonZeros << endl;
  cout << "Sum of all non-zero #s: " << totalSum << endl;
  cout << "Average of all non-zero #s: " << totalAverage << endl;
}



