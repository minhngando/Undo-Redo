/*
	This is the phoneBook and contains phoneBookEntry values.
	You can add, update, and remove entries from the phoneBook and you can print the contents of the phoneBook
*/

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

#include "phoneBook.h"
#include "phoneBookEntry.h"


//default constructor
//nothing in it because already created a vector in the class declaration with a identifier, basically the vector already initialized/created
phoneBook::phoneBook() {}


//takes an existing phoneBookEntry object and adds it to the end of the phoneBook vector
void phoneBook::insert(const phoneBookEntry &entry) {

	phoneBook::iterator iter;

	//instead of using an integer to iterate through the loop, just used the vector iterator
	for (iter = myPhoneBook.begin(); iter != myPhoneBook.end(); iter++) {

		//I am using the operator[] to access the vector's member functions so i made an index variable
		//that is the distance from the beginning index of the myPhoneBook vector up until the iter
		int index = std::distance(myPhoneBook.begin(), iter);

		//checks to see if theres already an entry in the phonebook with the same name as the passed entry's name
		//if there is already an entry with the same name then it updates the phoneNumber and email
		if ((*iter).name() == entry.name()) {

			myPhoneBook[index].phoneNumber(entry.phoneNumber());
			myPhoneBook[index].email(entry.email());

		}

	}

	//if the passed myPhoneBook entry isn't found (isn't already in the phoneBook vector)
	if (find(entry.name()) == false) {

		//then add the entry to the end of the phoneBook vector
		myPhoneBook.push_back(entry);

	}


}

//creates a new phoneBookEntry object with name, number, and email and adds it to the end of the phoneBook vector
void phoneBook::insert(const std::string &name, const std::string &number, const std::string &email) {

	//makes a new phoneBookEntry item with the passed name,number,email
	phoneBookEntry newEntry = phoneBookEntry(name, number, email);
	
	phoneBook::iterator iter;

	//if the entry isn't already in the phoneBook, then add it to the end of the phoneBook
	if (find(newEntry.name()) == false) {
		myPhoneBook.push_back(newEntry);

	}

	//if the entry is in the phoneBook (has same name) then update its phoneNumber and email
	else {

		//using vector iterator to iterate through the phoneBook vector
		for (iter = myPhoneBook.begin(); iter != myPhoneBook.end(); iter++) {

			//this is so that i can access member functions with the operator[] 
			int index = std::distance(myPhoneBook.begin(), iter);

			//updating phoneNumber and email
			if ((*iter).name() == newEntry.name()) {
				myPhoneBook[index].phoneNumber(newEntry.phoneNumber());
				myPhoneBook[index].email(newEntry.email());
			}

		}

	}

}

//creates a new phoneBookEntry object with name and number and adds its to the end of the phoneBook vector
void phoneBook::insert(const std::string &name, const std::string &number) {

	//creates a phoneBookEntry with the passed name and number, email is default ""
	phoneBookEntry newEntry = phoneBookEntry(name, number);

	phoneBook::iterator iter;

	//if the entry doesn't already exist then adds the newEntry to the end of the list
	if (find(newEntry.name()) == false) {
		myPhoneBook.push_back(newEntry);

	}

	//if the entry already exists
	else {


		for (iter = myPhoneBook.begin(); iter != myPhoneBook.end(); iter++) {

			//again, this is so that i can use the operator[] to access the member functions of phoneBook to update the phoneNumber and email
			int index = std::distance(myPhoneBook.begin(), iter);

			//updates phoneNumber and email of the current iteration if the current iteration has the same name as the entry
			if ((*iter).name() == newEntry.name()) {
				myPhoneBook[index].phoneNumber(newEntry.phoneNumber());
				myPhoneBook[index].email(newEntry.email());
			}

		}

	}

}

//determines if there is a phoneBookEntry object with the specified name
//returns true if found, false if not found
bool phoneBook::find(std::string name) {


	phoneBook::const_iterator iter;

	//preset found to false
	bool found = false;

	//goes through the phoneBook vector 
	for (iter = myPhoneBook.begin(); iter != myPhoneBook.end(); iter++) {

		//checks to see if the current iteration's name matches the passed name
		//if yes, the sets found to true
		if ((*iter).name() == name) {
			found = true;
		}

	}

	//returning found, if the name wasn't found then found stays false
	//if the name was found then found was set to true
	return found;

}

//removes a phoneBookEntry with the associated name from the phoneBook vector
//goes through the vector to find and erase the phoneBookEntry at index i
//the entry at i+1 will be moved up to i and i+2 moved up to i+1, so on...
//the last entry will be deleted since when moving up the entries and copy of the last one has been moved above it
//returns true if a phoneBookEntry object was erased and false if it was not
bool phoneBook::erase(std::string name) {

	phoneBook::iterator iter;

	bool erased;

	//loops through the phoneBook once with the find function to check if the passed name is an existing entry
	if (find(name)) {

		//looping through again to access the phoneBook entry if the entry was found 
		for (iter = myPhoneBook.begin(); iter != myPhoneBook.end(); iter++) {

			//if the current iteration has the same name as the passed 
			if ((*iter).name() == name) {

				//erases the current iteration 
				//vector's erase function already does the shifting for you
				myPhoneBook.erase(iter);

			
				//sets erased to true
				erased = true;

				//then exits so the loop doesn't continue and go out of bounds
				//you have to put the return statement here or else the iterator goes out of bound after erasing (since it changes the size)
				return erased;
			}

		}

	}

	//modifies nothing if the entry you're trying to erase doesn't exist in the phoneBook
	//sets erased to false 
	else {
		erased = false;
	}



	return erased;
}


//prints out the content of the phoneBook vector to cout
//left justified, name column has 31 characters wide, phone number column 16 characters wide, email no predetermined width
void phoneBook::print() const {

	if (myPhoneBook.size() == 0) {
		std::cout << "The phone book is empty" << std::endl;
	}

	else {


		phoneBook::const_iterator iter;

		//left justify
		std::cout << std::left;

		//sets Name: column to 31 characters and Phone Number: column to 16 characters
		//this is the column titles
		std::cout << std::setw(31) << "Name:" << std::setw(16) << "Phone Number:" << "E-Mail:" << std::endl;

		//loops through the phoneBook
		for (iter = myPhoneBook.begin(); iter != myPhoneBook.end(); iter++) {

			//left justifies 
			std::cout << std::left;

			//formatting the actual contents of phoneBook
			//each entry's name in the phoneBook falls under the Name: column and has 31 characters wide
			//each entry's phoneNumber in the phoneBook falls under the Phone Number: column and has 16 characters wide
			//the entry's email does not need to be modified/formatted because its at the end
			std::cout << std::setw(31) << (*iter).name() << std::setw(16) << (*iter).phoneNumber() << (*iter).email() << std::endl;

		}
	}
}

//prints out the content of the phoneBook vector to passed ostream object, out (by reference)
//left justified, name column has 31 characters wide, phone number column 16 characters wide, email no predetermined width
void phoneBook::print(std::ostream &out) const {

	if (myPhoneBook.size() == 0) {
		out << "The phone book is empty" << std::endl;
	}
	else {

		phoneBook::const_iterator iter;

		//left justifies
		out << std::left;

		//sets Name: column to 31 characters and Phone Number: column to 16 characters
		//this is the column titles
		out << std::setw(31) << "Name:" << std::setw(16) << "Phone Number:" << "E-Mail:" << std::endl;

		//loops through phoneBook
		for (iter = myPhoneBook.begin(); iter != myPhoneBook.end(); iter++) {

			//left justify
			out << std::left;

			//formatting the actual contents of phoneBook
			//each entry's name in the phoneBook falls under the Name: column and has 31 characters wide
			//each entry's phoneNumber in the phoneBook falls under the Phone Number: column and has 16 characters wide
			//the entry's email does not need to be modified/formatted because its at the end
			out << std::setw(31) << (*iter).name() << std::setw(16) << (*iter).phoneNumber() << (*iter).email() << std::endl;

		}
	}

}

//outputs the contents of the phoneBook vector
void phoneBook::debug(std::ostream &out) const {

	phoneBook::const_iterator iter;

	//loops through the phoneBook
	for (iter = myPhoneBook.begin(); iter != myPhoneBook.end(); iter++) {

		//prints out the contents of the phoneBook, separated by a space
		//not formatted
		out << (*iter).name() << " " << (*iter).phoneNumber() << " " << (*iter).email() << std::endl;

	}


}

//returns current number of entries in the phoneBook vector
std::size_t phoneBook::size() const {

	return myPhoneBook.size();

}