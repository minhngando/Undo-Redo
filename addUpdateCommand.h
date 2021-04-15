/*
	This is a subclass of bookCommand.
	This addUpdateCommand class will add a new entry if the passed in name is not already in the phoneBook. Otherwise it will update an existing phoneBookEntry

*/

#ifndef ADDUPDATECOMMAND_H_
#define ADDUPDATECOMMAND_H_

#include "phoneBookEntry.h"
#include "phoneBook.h"

#include "command.h"
#include "bookCommand.h"

#include "undoRedo.h"
#include "eraseUndoRedoCommand.h"

//addUpdateCommand is a subclass (derived) of bookCommand
class addUpdateCommand : public bookCommand {
	private:
		phoneBook &book;
		undoRedo &undoRedoOb;

	public:

		//constructor
		addUpdateCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream, undoRedo &undoRedoObject);

		//overriding the execute command from command.h
		//uses the bookCommand member functions to prompt for name, phone number, and email
		//prompt messages will be "Enter name to add/update", "Enter phone number", "Enter e-mail address"
		//after last prompt and input --> "Adding phone book entry for NAME"
		//delegates the actual add/update to the phoneBook class
		virtual void execute() override;
};

#endif