/*
	This is a subclass of bookCommand.
	This eraseCommand class will remove a specified phoneBookEntry from the phoneBook if it exists.

*/

#ifndef ERASECOMMAND_H_
#define ERASECOMMAND_H_

#include "phoneBookEntry.h"
#include "phoneBook.h"

#include "command.h"
#include "bookCommand.h"

#include "undoRedo.h"
#include "eraseUndoRedoCommand.h"

class eraseCommand : public bookCommand {

	private:
		phoneBook &book;
		undoRedo &undoRedoOb;

	public:

		//constructor
		eraseCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream, undoRedo &undoRedoObject);

		//overriding the execute command from command.h
		//uses the bookCommand member functions to prompt for name to erase
		//prompt messages will be "Enter name to erase"
		//after last prompt and user input, outputs either "Phone book entry NAME was erased" or "Phone book entry NAME was not erased"
		//delegates the actual erase to the phoneBook class
		virtual void execute() override;


};



#endif