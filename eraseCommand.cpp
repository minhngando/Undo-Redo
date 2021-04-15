/*
	This is a subclass of bookCommand.
	This eraseCommand class will remove a specified phoneBookEntry from the phoneBook if it exists.

*/

#include "phoneBookEntry.h"
#include "phoneBook.h"

#include "command.h"
#include "bookCommand.h"
#include "eraseCommand.h"

#include "undoRedo.h"
#include "eraseUndoRedoCommand.h"

#include <iostream>
#include <string>

//constructor
eraseCommand::eraseCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream, undoRedo &undoRedoObject) : bookCommand(inStream, outStream), book(bookIn), undoRedoOb(undoRedoObject)
{
	undoRedoOb = undoRedoObject;
}

//overriding the execute command from command.h
//uses the bookCommand member functions to prompt for name to erase
//prompt messages will be "Enter name to erase"
//after last prompt and user input, outputs either "Phone book entry NAME was erased" or "Phone book entry NAME was not erased"
//delegates the actual erase to the phoneBook class
void eraseCommand::execute() {

	//string variable called name to store user input after prompt
	std::string name;

	//prompts the user, and stores the user input into name
	name = outo2("Enter name to erase");

	phoneBookEntry theEntry; 

	//looping through the phoneBook to find the phoneBookEntry with the user inputted name
	//once the entry is found, it is stored in variable oldEntry 
	if (book.find(name)) {

		for (std::vector<phoneBookEntry>::iterator iter = book.begin(); iter != book.end(); iter++) {
			if ((*iter).name() == name) {
				theEntry = (*iter);
			}
		}

	}

	//if the entry was successfully erased then output a message saying it was erased
	//if the entry wasn't found/erased, then output a message saying it wasn't erased
	if (book.erase(name)) {

		outo("Phone book entry " + name + " was erased");

		//makes an eraseUndoRedoCmd command object to be added to the eraseCommand's undoRedo object
		eraseUndoRedoCommand *eraseCmd = new eraseUndoRedoCommand(book, theEntry);

		//adds the eraseCmd command object to the eraseCommand's undoRedo object
		undoRedoOb.addCommand(eraseCmd);


	}
	else {
		outo("Phone book entry " + name + " was not erased");
	}

}