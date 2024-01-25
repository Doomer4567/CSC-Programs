#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "hashTable.h"
#include "sha256.h"
using std::string;
using std::cout;

hashTable::hashTable(int size)
{
	//you need to add everything else that belongs in the constructor--------------------------------------
	tableSize = size;
	hashArray = new entry*[tableSize];
	for(int i=0; i<tableSize; i++)
		hashArray[i] = NULL;
	srand (time(0));	//this needs to be in the constructor, otherwise every user gets the same salt
}

hashTable::~hashTable(){

	for(int i=0; i < tableSize; i++){
		delete hashArray[i];		
	}
	delete [] hashArray;
}

//don't touch this!
int hashTable::hash(string key)
{
	int sum = 0;
	for(int i = 0; i < key.size(); i++)
		sum += key[i];
	
	return sum % tableSize;
}
//don't touch this!
string hashTable::generateSalt()
{
	string s = "";
	
	for(int i = 0; i < tableSize; i++)
		s = s + char('!' + (rand() % 93));
	return s;
}
//grabs a entry from the bucket of the hashtable. (called by validatelogin and removeuser)
hashTable:: entry* hashTable::getEntry(string username){
			int bucket = hash(username);
			entry* temp = hashArray[bucket];
			while(temp && temp->getUsername() != username){
				temp = temp->next;
			}
			if(temp && temp->getUsername() == username){
				return temp;
			}
			return NULL;
}

string hashTable::getSalt(string username){
	entry* temp = getEntry(username);
	string salt = temp->getSalt();
	return salt;

}
//using data given from the driver  file, adds a new entry into a bucket made by the hash function
void hashTable::addEntry(string username,string salt, string pwd){

	string saltyPwd = pwd + salt;
	string hashedPwd = sha256(saltyPwd);
	entry* newEntry = new entry(username,salt,hashedPwd);
	int bucket = hash(username);
	entry* travel = hashArray[bucket];

	if(hashArray[bucket] == NULL){
		hashArray[bucket] = newEntry;
	} else {

		while(travel && travel->next != NULL)
			travel = travel->next;
		
			if(username == travel->getUsername()){
				std::cout << "User already exists" << std::endl;
				return;
			}
		travel->next = newEntry;
		travel = travel->next;
		travel->next = NULL;
		
	}
}
//using the username to find the right entry and bucket, it compares the password hashed given by taking the salt used when the account was created and comparing it to the password hashed stored in the entry node
bool hashTable::validateLogin(string userName, string pass){
    int bucket = hash(userName);
    entry* validate = hashArray[bucket];
	
    while (validate && validate->getUsername() != userName)
		validate = validate->next; //traverses list looking for your mom
	if(!validate) 
		return false;    
    string hashedPassedPass = sha256(pass + validate->getSalt());
    if (hashedPassedPass == validate->getHashedpwd()) // check if password is there
        return true;
    return false;
}
//similar to validatelogin, it compares using the username then stores it temporarly, it then grabs the next nodes in the list and throws them back in to put them in line and then deletes the stored node
bool hashTable::removeUser(string username, string hashedPwd){
	int bucket = hash(username);
	entry* travel = hashArray[bucket];
	entry* tempDel = hashArray[bucket];
	entry* swap;
	while(travel && username != travel->getUsername())
		travel = travel->next; 

	if(!travel)
		return false;

	tempDel = travel;
	
	do{
		swap = travel->next;
		travel = NULL;
		hashArray[bucket] = swap;
	}while(travel != NULL);

	delete tempDel;
	travel = NULL;
	
		
	return true;
}
