/*
	This is a subclass of the command class. 
	It will implement some helper functions needed by the add/update, and erase command
*/

#ifndef BOOKCOMMAND_H_
#define BOOKCOMMAND_H_

#include "command.h"
#include <iostream>
#include <string>


class bookCommand : public command {

	protected:

		//istream object for input
		std::istream &in;
		//ostream object for output
		std::ostream &out;

		//helper function that will be used by addUpdateCommand, eraseCommand, printCommand
		//basically outputs a prompt (passed as string input) to the user
		void outo(std::string input);

		//helper function that will be used by addUpdateCommand, eraseCommand, printCommand
		//basically outputs a prompt (passed as string input) to the user, then reads in what the user says and returns it
		//returns a string of what the user input was
		std::string outo2(std::string input);

	public:
		//default constructor
		bookCommand();

		//constructor, initialization list used in cpp
		bookCommand(std::istream &in, std::ostream &out);

		//destructor
		virtual ~bookCommand() {}

};








#endif 