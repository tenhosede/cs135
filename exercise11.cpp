B/*
B0;136;0cruce Powell, Lecture Section 1003, Lab Section 1009
Exercise 11

Program prompts for a file with words.

Formats and sorts, then outputs to a file
*/

#include<string>
#include<iomanip>
#include<fstream>
#include<iostream>
#include<cctype>
using namespace std;

void getWords(string wordArray[], int& numWords);
void formatWords(string words[], int length);
void outputWords(string formattedWords[], string largestWords[], int length);
void sortWords(string wordsToSort[], int length);
void pickLargest(string inwords[], string largestWords[], int length);

int main()
{
  string inputWords[20]; //array for input words
  string largestWords[20]; //array for largest words
  int numWords; //number of input words
  getWords(inputWords, numWords);
  formatWords(inputWords, numWords);
  outputWords(inputWords,largestWords, numWords);

}

void getWords (string wordArray[], int& numWords)
  //prompts for the input filename and places the words into the array. also gives a count of words

{
  string filename;
  string inputString;
  ifstream inputfile;
  int i = 0;
  cout << "Enter the name of the input file: ";
  cin >> filename;

  inputfile.open(filename.c_str());
  
  inputfile >> inputString;

  while (inputfile)
    {

      wordArray[i] = inputString;
      i++;
      inputfile >> inputString;
    }
  inputfile.close();
  numWords = i;
}
					    
void formatWords(string words[], int length)
// formats the words to all lower case words
{
  string wordToFormat;
  for (int i = 0; i <= length; i++)
    {  
      wordToFormat = words[i];

      for (int j = 0; j < wordToFormat.length(); j++)
	{
	  wordToFormat[j] = tolower(static_cast<char>(wordToFormat[j]));
	}

      words[i] = wordToFormat;
    }
}

void outputWords(string formattedWords[], string largestWords[], int length)
//outputs the words from the array. at the first blank entry (which should signal the start of all blanks) it will stop printing them
//also outputs the words from the array of the longest words
{
  ofstream outf;
  string filename = "powelb2.ex11";

  sortWords(formattedWords, length);
  pickLargest(formattedWords, largestWords, length);

  outf.open(filename.c_str());

  outf << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  outf << "Bruce Powell, Lec #1003, Lab #1009, Exercise 11" << endl;
  outf << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl << endl;

  outf << "Alphabetized List of Words:" << endl;

  for (int i = 0; i < length; i++)
    if (formattedWords[i] == "")
      break;
    else 
      outf << formattedWords[i] << endl;

  outf << endl;
  
  outf << "List of longest words:" << endl;
  for (int i = 0; i < length; i++)
    if (largestWords[i] == "")
      break;
    else 
      outf << largestWords[i] << endl;

  outf.close();
}

void sortWords(string wordsToSort[], int length)
//sorts using a bubblesort algorithm
{
  string temp;
  bool sortdone = false;
  bool sorted = false;

  while (!sortdone)
    {
      for(int i = 0; i < length - 1; i++)
	{
	  if (wordsToSort[i] > wordsToSort[i+1])
	    {	  
	      temp = wordsToSort[i];
	      wordsToSort[i] = wordsToSort[i+1];
	      wordsToSort[i+1] = temp;
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
void pickLargest(string inwords[], string largestWords[], int length)
//picks the longest words out of an array and places them in the second array. sorts the second array
{
  int wordlength = 0;
  int longest = 0;
  for (int i = 0; i < length; i++)
    {
      wordlength = inwords[i].length();
      if (wordlength > longest)
	longest = wordlength;
    }
  int index = 0;
  for (int i = 0; i < length; i++)
    if (inwords[i].length() == longest)
      {
      largestWords[index] = inwords[i];
      index++;
      }
  sortWords(largestWords, index);
}
