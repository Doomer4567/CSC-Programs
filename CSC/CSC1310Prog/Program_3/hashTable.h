#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
using std::string;

class hashTable
{
	private:
		class entry;
		int tableSize;
		entry** hashArray;
		//add the attributes you need for the class---------------------------------------------------------

		int hash(string);
		entry* getEntry(string);
	public:
		//add all the functions you need--------------------------------------------------------------------
		hashTable(int);
		~hashTable();
		string generateSalt();
		string getSalt(string);
		void addEntry(string,string,string);
		bool validateLogin(string,string);
		bool removeUser(string,string);

};

class hashTable::entry
{
	private:
		string uname;
		string salt;
		string passHash;
	public:
		entry* next = NULL;
		// creates the entry 'struct' to store data
		entry(string un,string st,string ph){
			this->uname = un;
			this->salt = st;
			this->passHash = ph;
			this->next = NULL;
		}
		//grabs the username stored in private
		string getUsername(){
			return uname;
		}
		//grabs the salt stored in private
		string getSalt(){
			return salt;
		}
		//grabs the hashed password stored in private
		string getHashedpwd(){
			return passHash;
		}

};

#endif