#ifndef MARKOVLIST_H
#define MARKOVLIST_H

#include<map>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
using namespace std;

class markovList
{
	private:
		struct edge{
			string value;
			edge* nextInList;
			float weight;
			edge(string val, float wordWeight){ 
				weight = wordWeight;
				value = val;
				nextInList = NULL;
			}
		};
		int corpusSize;

		map<string, edge*> corpus;

	public:
		markovList(const char*);
		~markovList();
		
		string generate(int);
};

markovList::markovList(const char* filename)
{
	ifstream file(filename);
	stringstream parser, splitter;
	string line, index, word;
	float weight;
	edge* newEdge;
	edge* tmp;
	int i = 0;
	srand (time(0));
	
	if(file.good()) {
	file >> corpusSize;
	file.ignore(1, '\n');
	
	while(getline(file, line, '\n')) //map every word to a position in the matrix, keep the line in an array of buffers for later
	{
		parser.clear();
		parser << line;
		getline(parser, index,',');	//pulls the first word of the line, which is the node for which we're making a list of neighbors
		//initialize an empty list at the index---
		while(getline(parser, word, ','))
		{
			//allocate a new node in the edge list---
			splitter.clear();
			splitter.str(word);
			splitter >> word >> weight;
			//stick word and weight on the node you've just allocated---


			newEdge = new edge(word, weight);
			//make sure your new node is attached to the list---
			if(!corpus[index])
				corpus[index] = newEdge;
			else{
				tmp = corpus[index];
				while(tmp->nextInList)
					tmp = tmp->nextInList;
				tmp->nextInList = newEdge;


				
			}
		}
	}}
}

markovList::~markovList()// deletes all nodes inside the dictionary starting from the beginining 
{
	//write this
	edge * tmp;
	edge * nextEdge;
	for (map<string, edge*>::iterator it = corpus.begin(); it == corpus.end(); ++it)
	{
		
		tmp = it->second;
		while(tmp != NULL){
			nextEdge = tmp->nextInList;
			delete tmp;
			tmp = nextEdge;
		}

	}
}
		
string markovList::generate(int length)
{
	map<string, edge*>::iterator it = corpus.begin();
	advance(it, rand() % corpusSize);	//initialize an iterator to find a random node in the next line

	edge* tmpNode; 
	float RanWeight;
	string current = it->first;
	string Words = current;
	//this grabs a random node from your corpus as a starting point

	//checks the weight of your mom and then finds your father ;)
	for(int i = 0; i < length; i++){
		RanWeight = (float)rand()/RAND_MAX;
		tmpNode = corpus[current];

		while(tmpNode != NULL && tmpNode->weight < RanWeight){
			RanWeight -= tmpNode->weight;
			tmpNode = tmpNode->nextInList;
		}

		if(!tmpNode){
			it = corpus.begin();
			advance(it, rand() % corpusSize);
			current = it->first;
		}
		else{
			current = tmpNode->value;
			Words += " " + current;
		}
	}
	return Words;

}


#endif