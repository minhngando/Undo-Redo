/*
	This class will represent an entry in the phone book. It contains the name, phone number and e-mail address
*/

#include "phoneBookEntry.h"

#include <string>

//default constructor
phoneBookEntry::phoneBookEntry() {
	pbname = "";
	pbnumber = "";
	pbemail = "";
}

//creates a phoneBookEntry object with name, number, and blank email
phoneBookEntry::phoneBookEntry(const std::string &name, const std::string &number) {
	pbname = name;
	pbnumber = number;
	pbemail = "";
}

//creates a phoneBookEntry object with name, number, email
phoneBookEntry::phoneBookEntry(const std::string &name, const std::string &number, const std::string &email) {
	pbname = name;
	pbnumber = number;
	pbemail = email;
}

//copy constructor
phoneBookEntry::phoneBookEntry(const phoneBookEntry &from) {
	pbname = from.pbname;
	pbnumber = from.pbnumber;
	pbemail = from.pbemail;
}

//returns name of the phoneBookEntry object
std::string phoneBookEntry::name() const {
	return pbname;
}

//returns the phoneNumber of the phoneBookEntry object
std::string phoneBookEntry::phoneNumber() const {
	return pbnumber;
}

//returns the email of the phoneBookEntry object
std::string phoneBookEntry::email() const {
	return pbemail;
}

//updates the phoneNumber of the phoneBookEntry object
void phoneBookEntry::phoneNumber(const std::string &newNumber) {
	pbnumber = newNumber;
}

//updates the email of the phoneBookEntry object
void phoneBookEntry::email(const std::string &newEmail) {
	pbemail = newEmail;
}

