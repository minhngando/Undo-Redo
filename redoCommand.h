#ifndef REDOCOMMAND_H_
#define REDOCOMMAND_H_

#include "command.h"
#include "undoRedo.h"

class redoCommand : public command {

private:

	undoRedo &undoRedoOb;

public:

	//constructor
	redoCommand(undoRedo &undoRedoObject);

	virtual void execute();
};


#endif