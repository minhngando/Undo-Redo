/*
	This is a subclass of bookCommand
	printCommand prints the phoneBook when the command is executed by the menu
*/


#include "command.h"
#include "bookCommand.h"
#include "printCommand.h"

#include "phoneBook.h"
#include "phoneBookEntry.h"

#include <iostream>
#include <string>


//constructor
printCommand::printCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream) : bookCommand(inStream, outStream), book(bookIn)
{
}

//overriding the execute function from command.h
//uses the phoneBook print (std::ostream) to display the members of the phoneBook
void printCommand::execute() {

	book.print(out);

}

