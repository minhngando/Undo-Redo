/*
	an undoRedo object contains an undoStack and a redoStack 
	addUpdateCommand and eraseCommand use the addCommand function to pop insertUndoRedoCommand, updateUndoRedoCommand, eraseUndoRedoCommand onto its undoRedo object's undoStack
	the undo function pops the command off the undoStack and pushes it to the redoStack (undoes the command)
	the redo function pops the command off the redoStack and pushes it to the undoStack (redoes an undone command)
*/

#include "undoRedo.h"

//constructor
undoRedo::undoRedo() {

	undoStack = new stack();
	redoStack = new stack();

}

//adds a command to the undoStack
void undoRedo::addCommand(command *newCommand) {
	undoStack->push(newCommand);
}


//destructor
//deletes the command pointer 
undoRedo::~undoRedo() {

	//while the undoStack has items in it
	while (undoStack->empty() == false) {

		//delete the command pointer of the topOfStack of the undoStack
		delete undoStack->top();

		//pops off the topOfStack of the undoStack (deleting the stackEntry)
		undoStack->pop();
	}

	//while the redoStack has items in it
	while (redoStack->empty() == false) {

		//delete the command pointer of the topOfStack of the redoStack
		delete redoStack->top();

		//pops off the topOfStack stackEntry of the redoStack 
		redoStack->pop();
	}

}

//if the undoStack is empty, do nothing 
//if the stack has items, then undo() will get the topOfStack from the undoStack and use the unExecute function of the topOfStack's command object
//then, pop that command from the undoStack and push it onto the redoStack
//this implements the "undo movement", the actual undoing is implemented in its unExecute()
void undoRedo::undo() {

	//if the undoStack has items in it
	if (undoStack->empty() == false) {

		//store the command pointer of the topOfStack of the undoStack into a variable called topOfUndo
		command *topOfUndo = undoStack->top();

		//pushes this command into the redoStack
		redoStack->push(topOfUndo);

		//unExecute the command 
		//this is the real "undoing" of the command, implemented in unExecute()
		topOfUndo->unExecute();

		//pop it off the undoStack
		undoStack->pop();

	}

}

//if the redoStack is empty, do nothing
//if the redoStack has items, then redo() will get the topOfStack from the redoStack and use the execute (do the command again) function of the topOfStack's command object
//then, pop that command from the redoStack and push it onto the undoStack
//this implements the "redo movement", the actual redoing of the command is implemented in its the execute()
void undoRedo::redo() {

	//if the redoStack has items in it
	if (redoStack->empty() == false) {

		//store the command pointer of the topOfStack of the redoStack into a variable called topOfRedo
		command *topOfRedo = redoStack->top();

		//execute the command again
		//this is the real "redoing" of the command implemented in execute()
		topOfRedo->execute(); 

		//popping the command off the redoStack and pushing it back into the undoStack
		redoStack->pop();
		undoStack->push(topOfRedo);
	}

}