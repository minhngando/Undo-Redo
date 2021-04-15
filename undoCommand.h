#ifndef UNDOCOMMAND_H_
#define UNDOCOMMAND_H_

#include "command.h"
#include "undoRedo.h"

class undoCommand : public command {

private:

	undoRedo &undoRedoOb;

public:
	
	//constructor
	undoCommand(undoRedo &undoRedoObject);

	virtual void execute();
};


#endif