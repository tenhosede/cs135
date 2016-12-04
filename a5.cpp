/*
Bruce Powell, Lecture Section 1003, Lab Section 1009, Assignment 5

Accepts and input file that contains in order: a string, number of readings, and temperature readings.

determins Max and Min, calculates Average, median, and std deviation for both high and low temperatures.

Prints data in the form set in "printValues"
*/

#include<string>
#include<iomanip>
#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;


const int dayspermonth = 31;
const int labelwidth = 18;
const int datawidth = 8;

void getValues();
int maximum(int values[], int numvalues);
int minumum(int values[], int numvalues);
double average(int values[], int numvalues);
double median(int values[], int numvalues);
double stdDev(double average,int values[], int numvalues);
void printValues(string month, int numReadings, int hiTemps[], int loTemps[]);
void sortNumbers(int values[], int length);
string properCase(string input);



int main()
{


  getValues();

  return 0;
}

void getValues()
{
  //gets data from file, calculates average, median, deviation of high and low, as well as max and min
  // displays values in a printed form


  ifstream inf;
  string filename = "";
  string monthName = "";
  int hiTempValues[dayspermonth];  
  int loTempValues[dayspermonth];  
  int numReadings = 0;

  cout << "Please enter the file name: ";
  cin >> filename;
  cout << endl;

  inf.open(filename.c_str());


  cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
  cout << "Bruce Powell, Lec 1003, Lab 1009, Assignment 5" << endl;
  cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl << endl;

  inf >> monthName;

  while(inf)
    {
      inf >> numReadings;
      
      for(int i = 0; i < numReadings; i++)
	{
	  inf >> hiTempValues[i];
	  inf >> loTempValues[i];

	}
      printValues(monthName, numReadings, hiTempValues, loTempValues);

      inf >> monthName;    
    }
  inf.close();
}

int maximum(int values[], int numvalues)
{
  //find the maximum integer value in an array, returns it
  int max = values[0];
  for (int i = 0; i < numvalues; i++)
    if (max < values[i])
      max = values[i];
  return max;
}

int minimum(int values[], int numvalues)
{
  // finds the minimum integer value in an array, returns it
  int min = values[0];
  for (int i = 0; i < numvalues; i++)
    if (min > values[i])
      min = values[i];
  return min;

}

double average(int values[], int numvalues)
{
  //calculates the average of values in an array, returns a double
  double average = 0.0;

  for (int i = 0; i < numvalues; i++)
    average = average + (values[i]/static_cast<double>(numvalues));

  return average;
}

double median(int values[], int numvalues)
{
  //calcuates the median of an values in an array, returns a double
  double median;
  int medianIndex;

  sortNumbers(values, numvalues);

  medianIndex = numvalues/2;

  if (numvalues % 2 == 0)
    median = (values[medianIndex] + values[medianIndex - 1])/2.;
  else
    median = values[medianIndex];

  return median;
}

double stdDev(double average, int values[], int numvalues)
{
  //calculates the standard deviation of a set of integer values in an array, returns a double
  double sum = 0.0;

  for(int i = 0;i < numvalues; i++) // calculates sigma(average - data(i)**2)
    {
      sum = sum + pow((average - values[i]),2);
    }
  sum = sum/(numvalues - 1);

  sum = sqrt(sum);
  return sum;
}

void printValues(string month, int numReadings, int hiTemps[], int loTemps[])
{
  //prints values in a structured format
  double hiAverage = 0.0;
  double loAverage = 0.0;

;
  hiAverage = average(hiTemps, numReadings);
  loAverage = average(loTemps, numReadings);

  cout << properCase(month) << " Temperature Data: ";
  cout << numReadings << " Readings Taken" << endl;

  cout << left << setw(labelwidth) << "Maximum high:" << right << setw(datawidth) << maximum(hiTemps, numReadings) << "  ";
  cout << left << setw(labelwidth) << "Minimum low:" << right << setw(datawidth) << minimum(loTemps, numReadings) << endl;
  cout << fixed << setprecision(3);
  cout << left << setw(labelwidth) << "Average high:" << right << setw(datawidth) << hiAverage << "  ";
  cout << left << setw(labelwidth) << "Average low:" << right << setw(datawidth) << loAverage << endl;
  if (numReadings % 2 == 0)
    cout << setprecision(1);
  else
    cout << setprecision(0);
  cout << left << setw(labelwidth) << "Median high:" << right << setw(datawidth) << median(hiTemps, numReadings) << "  ";  
  cout << left << setw(labelwidth) << "Meidan low:" << right << setw(datawidth) << median(loTemps, numReadings) << endl;
  cout << setprecision(3);
  cout << left << setw(labelwidth) << "Std dev of highs:" << right << setw(datawidth) << stdDev(hiAverage,hiTemps,numReadings) << "  ";  
  cout << left << setw(labelwidth) << "Std def of lows:" << right << setw(datawidth) << stdDev(loAverage,loTemps,numReadings) << endl;
  cout << endl;

}

string properCase(string input)
{
  //formats a string to proper case
  string wordtoformat = input;

  for (int i = 0; i < input.length();i++)
    {
      if (i == 0)
	wordtoformat[i] = toupper(static_cast<char>(input[i]));
      else
	wordtoformat[i] = tolower(static_cast<char>(input[i]));
    }
  return wordtoformat;
}   
void sortNumbers(int values[], int numvalues)
//sorts using a bubblesort algorithm
{
  int temp;
  bool sortdone = false;
  bool sorted = false;

  while (!sortdone)
    {
      for(int i = 0; i < numvalues - 1; i++)
	{
	  if (values[i] > values[i+1])
	    {	  
	      temp = values[i];
	      values[i] = values[i+1];
	      values[i+1] = temp;
	      sorted = true;
	    }
	}
      if (sorted)
	sortdone = false;
      else 
	sortdone = true;
      
      sorted = false;
    }

}
