#include <string>
#include <iostream>

#include "menuList.h"
#include "command.h"
#include "bookCommand.h"
#include "addUpdateCommand.h"
#include "eraseCommand.h"
#include "printCommand.h"

#include "phoneBook.h"
#include "phoneBookEntry.h"

#include "memoryLeak.h"
#include "stack.h"
#include "undoRedo.h"
#include "updateUndoRedoCommand.h"
#include "insertUndoRedoCommand.h"
#include "eraseCommand.h"
#include "undoCommand.h"
#include "redoCommand.h"

using namespace std;

int main() {

	//build the phoneBook 
	phoneBook yellowPages = phoneBook();
	undoRedo ur;

	//build menuList
	menuList menu("Phone book menu:");
	
	//creating commands
	addUpdateCommand auc = addUpdateCommand(yellowPages, cin, cout, ur);
	printCommand pc = printCommand(yellowPages, cin, cout);
	eraseCommand ec = eraseCommand(yellowPages, cin, cout, ur);

	undoCommand undc = undoCommand(ur);
	redoCommand redc = redoCommand(ur);


	//build menuItem objects
	menuItem addUpdate('a', "add/update", auc);
	menuItem erase('e', "erase", ec);
	menuItem print('p', "print", pc);

	menuItem undo('u', "undo", undc);
	menuItem redo('r', "redo", redc);

	//add menuItem values to menuList
	menu.add(addUpdate);
	menu.add(erase);
	menu.add(print);
	menu.add(undo);
	menu.add(redo);

	cout << "Starting the Phone Book" << endl << endl;

	//run the menu
	menu.start();

	system("pause");
	return 0;
}