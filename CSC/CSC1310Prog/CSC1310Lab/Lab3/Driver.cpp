#include "Timer.h"
#include <iostream>
#include <fstream>
#include "Timer.cpp"
using namespace std;

struct wordCount{
	string word;
	int count;
};

void insertionSort(wordCount *wordArray, int numWords);
void bubbleSortReverse(wordCount *wordArray, int numWords);
void quicksort(wordCount *wordArray, int low, int high);
int partition(wordCount *wordArray, int left, int right);

int main()
{
	wordCount* wordArray = new wordCount[150000];
	int numWords = 0;
	string temp;
	int num;
	
	ofstream outfile;
	ifstream infile;

	time_t start, end;
	char filename[50];
	cout << "\nWhich file are you opening?\n";
	cin >> filename;
	infile.open(filename);
	
	if(!infile)
	{
		cout << "\nSorry, I couldn't find that file.\n";
		return 1;
	}

	while(getline(infile, temp) && numWords != 150000)
	{
		wordArray[numWords].word = temp;
		infile >> num;
		infile.ignore();
		wordArray[numWords].count = num;
		numWords++;
	}
	cout << "you've read in " << numWords << " words.\n";

	//sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); //Starts timer.   

	//LOOK!!!!  CALL THE INSERTION SORT ALGORITHM HERE
	insertionSort(wordArray, numWords);

	end = getTime(); //Ends timer.
	outfile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();

	//sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); //Starts timer. 

	//LOOK!!!!  CALL THE REVERSE BUBBLE SORT ALGORITHM HERE
	bubbleSortReverse(wordArray, numWords);

	end = getTime(); //Ends timer.
	outfile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();

	//sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE QUICKSORT ALGORITHM HERE
	quicksort(wordArray, num, numWords);

	end = getTime(); //Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outfile.open("sortFileQuick.txt");
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();
	
	delete [] wordArray;
	return 0;
}

//LOOK!  WRITE YOUR INSERTION SORT FUNCTION HERE
void insertionSort(wordCount *wordArray, int numWords){
	for(int i = 0; i < numWords; ++i){
		int j = i;
		wordCount temp;
		while(j > 0 && wordArray[j].count < wordArray[j-1].count){
			temp = wordArray[j];
			wordArray[j] = wordArray[j-1];
			wordArray[j - 1] = temp;
			--j;
		}

	}
}


//LOOK!  WRITE YOUR REVERSE BUBBLE SORT FUNCTION HERE
void bubbleSortReverse(wordCount *wordArray, int numWords){
	wordCount temp;
	for (int i = 0; i < numWords - 1; i++) {
      for (int j = 0; j < numWords - i - 1; j++) {
         if (wordArray[j].count > wordArray[j+1].count) {
            temp = wordArray[j];
            wordArray[j] = wordArray[j + 1];
            wordArray[j + 1] = temp;
         }
      }
   }
}


//LOOK!  WRITE YOUR RECURSIVE QUICK SORT FUNCTION HERE
void quicksort(wordCount *wordArray, int low, int high){
	if (low >= high) {
      return;
   }

   int LowEnd = partition(wordArray, low, high);
   quicksort(wordArray, low, LowEnd);
   quicksort(wordArray, LowEnd+1, high);
}



int partition(wordCount *wordArray, int left, int right){
   int mid = left + (right - left) / 2;
   int pivot = wordArray[mid].count;

   bool finished = false;
   while (!finished) {
      while (wordArray[left].count < pivot) {
         left += 1;
      }
      while (pivot < wordArray[right].count) {
         right -= 1;
      }

      if (left >= right) {
         finished = true;
      }
      else {
        
         wordCount temp = wordArray[left];
         wordArray[left] = wordArray[right];
         wordArray[right] = temp;
 
        
         left += 1;
         right -= 1;
      }
   }
   return right;
}