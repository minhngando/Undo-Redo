/*
	This is a subclass of bookCommand
	printCommand prints the phoneBook when the command is executed by the menu
*/

#ifndef PRINTCOMMAND_H_
#define PRINTCOMMAND_H_

#include "command.h"
#include "bookCommand.h"

#include "phoneBook.h"
#include "phoneBookEntry.h"

#include <iostream>


class printCommand : public bookCommand {

	private:
		phoneBook &book;
	public:

		//constructor
		printCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream);

		//overriding the execute function from command.h
		//uses the phoneBook print (std::ostream) to display the members of the phoneBook
		virtual void execute() override;


};


#endif
