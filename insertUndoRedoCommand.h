/*
	Will be created by addUpdateCommand objects. 
	They need to be created with the new operator and passed to the undoRedo object using the addCommand member function. 
	The undoRedo object will be responsible for deleting these new command objects
*/
#ifndef INSERTUNDOREDOCOMMAND_H_
#define INSERTUNDOREDOCOMMAND_H_

#include "undoRedo.h"
#include "phoneBook.h"
#include "phoneBookEntry.h"
#include "command.h"

class insertUndoRedoCommand : public command {

	private:

		phoneBook &theBook;
		phoneBookEntry theEntry;

	public:

		//constructor
		insertUndoRedoCommand(phoneBook &book, phoneBookEntry newEntry);

		//redo the command
		virtual void execute();

		//undo the command
		virtual void unExecute();
};


#endif