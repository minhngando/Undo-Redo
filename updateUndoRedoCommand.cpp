/*
	Will be created by addUpdateCommand objects.
	They need to be created with the new operator and passed to the undoRedo object using the addCommand member function.
	The undoRedo object will be responsible for deleting these new command objects

	This is a command that will be passed onto the undoStack and redoStack
	Every time addUpdateCommand updates the phoneBookEntry it also makes this command and pushes it onto the undoStack of the addUpdateCommand's undoRedo object

	This command's unExecute() is the actual undo, the undo() function of the undoRedo object calls this to actually undo the command and modify the phoneBook, 
	then it moves the command so that it's available to redo

	This command's execute() is the actual redo, the redo() function of the undoRedo object calls this to actually redo the command and modify the phoneBook,
	then it moves the command so that it's available to undo again
*/
#include "updateUndoRedoCommand.h"

//constructor
updateUndoRedoCommand::updateUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry, phoneBookEntry newEntry) : theBook(book) {

	theOldEntry = oldEntry;
	theNewEntry = newEntry;

}

//redo the command
void updateUndoRedoCommand::execute() {
	theBook.insert(theNewEntry);
}

//undo the command
//undoing an update would mean to switch the updated entry with the old entry
void updateUndoRedoCommand::unExecute() {
	theBook.insert(theOldEntry);
}