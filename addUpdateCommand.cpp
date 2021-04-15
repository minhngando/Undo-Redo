/*
	This is a subclass of bookCommand.
	This addUpdateCommand class will add a new entry if the passed in name is not already in the phoneBook. Otherwise it will update an existing phoneBookEntry

*/

#include "phoneBookEntry.h"
#include "phoneBook.h"

#include "command.h"
#include "bookCommand.h"
#include "addUpdateCommand.h"

#include "undoRedo.h"
#include "insertUndoRedoCommand.h"
#include "updateUndoRedoCommand.h"

#include <iostream>
#include <string>


//constructor
addUpdateCommand::addUpdateCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream, undoRedo &undoRedoObject) : bookCommand(inStream, outStream), book(bookIn), undoRedoOb(undoRedoObject)
{
}

//overriding the execute command from command.h
//uses the bookCommand member function outo2 to prompt for name, phone number, and email then store the user input into variables
//prompt messages will be "Enter name to add/update", "Enter phone number", "Enter e-mail address"
//after last prompt and input --> "Adding phone book entry for NAME" or "Updating phone book entry for NAME" --> this uses outo not outo2 because don't need to store any inputs, just prompts
//delegates the actual add/update to the phoneBook class
void addUpdateCommand::execute() {

	std::string name, phoneNumber, email;

	//prompts the user, then stores the user input into string variables name, phoneNumber, and email
	name = outo2("Enter name to add/update");
	phoneNumber = outo2("Enter phone number");
	email = outo2("Enter e-mail address");

	//phoneBookEntry variable to store the phoneBookEntry to be added or updated
	phoneBookEntry newEntry = phoneBookEntry(name, phoneNumber, email);

	//a phoneBookEntry variable to store the phoneBookEntry data before the new entry was added or updated
	phoneBookEntry oldEntry;

	//looping through the phoneBook to find the phoneBookEntry with the user inputted name
	//once the entry is found, it is stored in variable oldEntry 
	if (book.find(name)) {

		for (std::vector<phoneBookEntry>::iterator iter = book.begin(); iter != book.end(); iter++) {
			if ((*iter).name() == name) {
				oldEntry = (*iter);
			}
		}

	}

	//using the information from the user input to add or update an entry in the phoneBook
	if (book.find(name)) {

		outo("Updating phone book entry for " + name);
		book.insert(newEntry);

		//makes an updateUndoRedoCommand command object to be added to the undoRedo object 
		updateUndoRedoCommand *updateCommand = new updateUndoRedoCommand(book, oldEntry, newEntry);

		//adds the updateUndoRedoCommand to the addUpdateCommand's undoRedo object
		//this updateCommand is used to make a stackEntry and added to the undoStack
		//later, the undoRedo object can call undo() which calls the command's unExecute() or redo() which calls the command's execute()
		undoRedoOb.addCommand(updateCommand);

	}
	else {

		outo("Adding phone book entry for " + name);
		book.insert(newEntry);
		
		//makes an insertUndoRedoCommand command object to be added to the undoRedo object
		insertUndoRedoCommand *insertCommand = new insertUndoRedoCommand(book, newEntry);

		//adds the insertUndoRedoCommand to the addUpdateCommand's undoRedo object
		undoRedoOb.addCommand(insertCommand);
	}


}
