/*
	Will be created by eraseUpdateCommand objects.
	They need to be created with the new operator and passed to the undoRedo object using the addCommand member function.
	The undoRedo object will be responsible for deleting these new command objects

	This is a command that will be passed onto the undoStack and redoStack
	Everytime eraseCommand erases a phoneBookEntry from the phoneBook, it also creates this command and pushes it onto the undoStack of the eraseCommand's undoRedo object

	This command's unExecute() is the actual undo, the undo() function of the undoRedo object calls this to actually undo the command and modify the phoneBook,
	then it moves the command so that it's available to redo

	This command's execute() is the actual redo, the redo() function of the undoRedo object calls this to actually redo the command and modify the phoneBook,
	then it moves the command so that it's available to undo again
*/
#include "eraseUndoRedoCommand.h"

//constructor
eraseUndoRedoCommand::eraseUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry) : theBook(book) {
	theEntry = oldEntry;
}

//redo the command
void eraseUndoRedoCommand::execute() {
	theBook.erase(theEntry.name());
}

//undo the command
//undoing an erase from the phoneBook would mean to add back the entry it was trying to erase
void eraseUndoRedoCommand::unExecute() {
	theBook.insert(theEntry);
}