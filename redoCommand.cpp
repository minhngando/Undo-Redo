/*
	This is a command that calls redo() on an undoRedo object 

	This will be used to create a menuItem on the menuList, so that everytime the menuItem is pressed, 
	then this command executes its execute() function, calling the redo function on the undoRedo object.

*/
#include "redoCommand.h"

//constructor
redoCommand::redoCommand(undoRedo &undoRedoObject) : undoRedoOb(undoRedoObject) {

}

void redoCommand::execute() {

	undoRedoOb.redo();

}