/*
	Will be created by eraseUpdateCommand objects.
	They need to be created with the new operator and passed to the undoRedo object using the addCommand member function.
	The undoRedo object will be responsible for deleting these new command objects
*/
#ifndef ERASEUNDOREDOCOMMAND_H_
#define ERASEUNDOREDOCOMMAND_H_

#include "undoRedo.h"
#include "phoneBook.h"
#include "phoneBookEntry.h"
#include "command.h"

class eraseUndoRedoCommand : public command {

	private:

		phoneBook &theBook;
		phoneBookEntry theEntry;

	public:
		//constructor
		eraseUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry);

		//undo the command
		virtual void execute();

		//redo the command
		virtual void unExecute();

};


#endif