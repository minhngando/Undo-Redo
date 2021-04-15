/*
	
*/
#ifndef UNDOREDO_H_
#define UNDOREDO_H_

#include "memoryLeak.h"
#include "stack.h"
#include "command.h"


class command; 
class stack;

class undoRedo {

	private:

		//everytime you use a command, a stackEntry object is made with the command and pushed onto the undoStack
		stack *undoStack;

		//everytime the undo function is called it pops off the topOfStack of undoStack and and pushes it onto the redoStack
		stack *redoStack;

	public:

		//constructor
		undoRedo();

		//destructor 
		//goes through all of the entries of the undoStack. Gets the top value, deletes it and then pops it off of the undoStack until there are no more values in the undoStack
		//goes through all of the entries of the redoStack. Gets the top value, deletes it and then pops it off of the redoStack until there are no more values in the redoStack
		virtual ~undoRedo();

		//note that undoRedo will delete the command in its destructor
		//adds a command to the undoStack 
		virtual void addCommand(command *newCommand);

		//if the undoStack is empty, do nothing 
		//if the stack has items, then undo() will get the topOfStack from the undoStack and use the unExecute function of the topOfStack's command object
		//then, pop that command from the undoStack and push it onto the redoStack
		virtual void undo();

		//if the redoStack is empty, do nothing
		//if the redoStack has items, then redo() will get the topOfStack from the redoStack and use the execute (do the command again) function of the topOfStack's command object
		//then, pop that command from the redoStack and push it onto the undoStack
		virtual void redo();
};


#endif