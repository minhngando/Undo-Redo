/*
	This is the phoneBook and contains phoneBookEntry values.
	You can add, update, and remove entries from the phoneBook and you can print the contents of the phoneBook
*/

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

#include "phoneBookEntry.h"

#include <vector>



class phoneBook {
		
		typedef std::vector<phoneBookEntry> phoneBookEntryList;
		phoneBookEntryList myPhoneBook;

	public:

		typedef phoneBookEntryList::iterator iterator;
		typedef phoneBookEntryList::const_iterator const_iterator;
		iterator begin() { return myPhoneBook.begin(); }
		iterator end() { return myPhoneBook.end(); }

		//default constructor
		phoneBook();

		//takes an existing phoneBookEntry object and adds it to the end of the phoneBook vector
		void insert(const phoneBookEntry &entry);
		//creates a new phoneBookEntry object with name, number, and email and adds it to the end of the phoneBook vector
		void insert(const std::string &name, const std::string &number, const std::string &email);
		//creates a new phoneBookEntry object with name and number and adds its to the end of the phoneBook vector
		void insert(const std::string &name, const std::string &number);

		//removes a phoneBookEntry with the associated name from the phoneBook vector
		//goes through the vector to find and erase the phoneBookEntry at index i
		//the entry at i+1 will be moved up to i and i+2 moved up to i+1, so on...
		//the last entry will be deleted since when moving up the entries and copy of the last one has been moved above it
		//returns true if a phoneBookEntry object was erased and false if it was not
		bool erase(std::string name);

		//determines if there is a phoneBookEntry object with the specified name
		//returns true if found, false if not found
		bool find(std::string name);

		//prints out the content of the phoneBook vector
		//left justified, name column has 31 characters wide, phone number column 16 characters wide, email no predetermined width
		void print() const;
		void print(std::ostream &out) const;

		//outputs the contents of the phoneBook vector
		void debug(std::ostream &out) const;

		//returns current number of entries in the phoneBook vector
		std::size_t size() const;

		//destructor
		virtual ~phoneBook() {}
};

#endif