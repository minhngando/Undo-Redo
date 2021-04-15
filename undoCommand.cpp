/*
	This is a command that calls undo() on an undoRedo object

	This will be used to create a menuItem on the menuList, so that everytime the menuItem is pressed,
	then this command executes its execute() function, calling the undo function on the undoRedo object.

*/
#include "undoCommand.h"

//constructor
undoCommand::undoCommand(undoRedo &undoRedoObject) : undoRedoOb(undoRedoObject) {

}

void undoCommand::execute() {

	undoRedoOb.undo();

}