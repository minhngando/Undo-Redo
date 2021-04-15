/*
	This is a subclass of the command class.
	It will implement some helper functions needed by the add/update, and erase command
*/


#include "command.h"
#include "bookCommand.h"

#include <iostream>
#include <string>

//no code in body of constructor, used initialization list
bookCommand::bookCommand(std::istream &in, std::ostream &out) : in(in), out(out)
{
}

//helper function that will be used by addUpdateCommand, eraseCommand, printCommand
void bookCommand::outo(std::string input) {

	//takes the string input parameter and outputs it/displays it to the ostream protected reference
	out << input << std::endl;

}

//helper function that will be used by addUpdateCommand, eraseCommand, printCommand
//returns a string
std::string bookCommand::outo2(std::string input) {

	//this is a prompt to the user (asking the user to input)
	//takes the string input that was passed in and outputs it to the ostream object passed to the bookCommand constructor
	out << input << std::endl;

	//creating a string variable called into
	std::string into;

	//in is the istream object from the constructor/protected member
	//whenever bookCommand is constructed and this is called, whatever the user input is will be put into 
	//the string variable into
	getline(in, into);

	//this function call returns whatever the user input was that was passed into the arguments after the prompt
	return into;

}