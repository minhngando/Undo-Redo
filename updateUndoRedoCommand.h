/*
	Will be created by addUpdateCommand objects.
	They need to be created with the new operator and passed to the undoRedo object using the addCommand member function.
	The undoRedo object will be responsible for deleting these new command objects
*/
#ifndef UPDATEUNDOREDOCOMMAND_H_
#define UPDATEUNDOREDOCOMMAND_H_

#include "undoRedo.h"
#include "phoneBook.h"
#include "phoneBookEntry.h"
#include "command.h"

class updateUndoRedoCommand : public command {

	private:

		phoneBook &theBook;

		//needed for an undo
		phoneBookEntry theOldEntry;

		//needed for a redo
		phoneBookEntry theNewEntry;

	public:

		//constructor
		updateUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry, phoneBookEntry newEntry);

		//redo the command
		virtual void execute();

		//undo the command
		virtual void unExecute();
};

#endif