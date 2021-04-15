/*
	This class will represent an entry in the phone book. It contains the name, phone number and e-mail address
*/



#ifndef PHONEBOOKENTRY_H_
#define PHONEBOOKENTRY_H_

#include <string>

class phoneBookEntry {

	private:
		std::string pbname;
		std::string pbnumber;
		std::string pbemail;
	public:

		//constructors
		phoneBookEntry();
		phoneBookEntry(const std::string &name, const std::string &number);
		phoneBookEntry(const std::string &name, const std::string &number, const std::string &email);
		phoneBookEntry(const phoneBookEntry &from);

		//accessor functions
		std::string name() const;
		std::string phoneNumber() const;
		std::string email() const;

		//mutator functions to allow updates to phoneNumber and email
		void phoneNumber(const std::string &newNumber);
		void email(const std::string &newEmail);

		//destructor
		virtual ~phoneBookEntry() {}
};

#endif