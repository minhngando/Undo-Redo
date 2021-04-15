/*
	Will be created by addUpdateCommand objects.
	They need to be created with the new operator and passed to the undoRedo object using the addCommand member function.
	The undoRedo object will be responsible for deleting these new command objects

	This is a command that will be passed onto the undoStack and redoStack
	Everytime addUpdateCommand inserts a phoneBookEntry into the phoneBook, it also creates this command and pushes it onto the undoStack of the addUpdateCommand's undoRedo object

	This command's unExecute() is the actual undo, the undo() function of the undoRedo object calls this to actually undo the command and modify the phoneBook,
	then it moves the command so that it's available to redo

	This command's execute() is the actual redo, the redo() function of the undoRedo object calls this to actually redo the command and modify the phoneBook,
	then it moves the command so that it's available to undo again
*/
#include "insertUndoRedoCommand.h"

//constructor 
//each insertUndoRedoCommand has a phoneBook reference and the phoneBook entry that was used to insert
insertUndoRedoCommand::insertUndoRedoCommand(phoneBook &book, phoneBookEntry newEntry) : theBook(book)
{
	theEntry = newEntry; 
}

//redo the insert command
void insertUndoRedoCommand::execute() {
	theBook.insert(theEntry);
}

//undo the insert command
//undoing an insert would mean to erase the entry that was inserted
void insertUndoRedoCommand::unExecute() {
	theBook.erase(theEntry.name());
}