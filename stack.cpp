#include "stack.h"

#include <iostream>

//stackEntry constructor
stackEntry::stackEntry(command *theCommand, stackEntry *pNext) {
	cmd = theCommand;
	nextStackEntry = pNext;
}

//updates the pointer nextStackEntry to pNext
void stackEntry::next(stackEntry *pNext) {
	nextStackEntry = pNext;
}

//returns the pointer nextStackEntry of the stackEntry
stackEntry* stackEntry::next() {
	return nextStackEntry;
}

//returns pointer cmd of the stackEntry
command* stackEntry::data() {
	return cmd;
}

//returns pointer cmd of the stackEntry 
const command* stackEntry::data() const {
	return cmd;
}

//stackEntry destructor
stackEntry::~stackEntry() {}

//stack constructor
stack::stack() {
	topOfStack = nullptr;
	numEntries = 0;
}

//returns the pointer cmd of the top stackEntry object, if there isn't one then nullptr should be returned
command* stack::top() {
	return topOfStack->data();
}

//returns the const pointer cmd of the top stackEntry object, if there isn't one then nullptr should be returned
const command* stack::top() const {
	return topOfStack->data();
}

//returns number of items in the stack
std::size_t stack::size() const {
	return numEntries;
}

//adds a new command pointer to the stack (basically adding a new stackEntry object to the stack, since it is a new command but the nextStackEntry is updated to the previous top)
//creates a new stackEntry and makes it the new topOfStack
void stack::push(command *newCommand) {

	//makes a new stackEntry (with the newCommand, and sets the pointer to the next stackEntry item to the previous topOfStack) the topOfStack 
	topOfStack = new stackEntry(newCommand, topOfStack);
	
	//increment numEntries every time a new stackEntry is pushed onto the stack
	numEntries++;

}

//removes the top entry from the stack and deletes the stackEntry object that is being removed
//should not delete the command pointer
void stack::pop() {

	//if the stack has items in it, then the topOfStack can be removed
	//if the stack has no items in it and pop is called then pop does nothing
	if (empty() == false) {

		
		stackEntry *newTopOfStack = nullptr;

		//check to see if the size is greater than 1 or else it gives an exception
		if (size() > 1) {
			//making a new stackEntry variable that has the topOfStack's nextStackEntry command pointer and its nextStackEntry pointer
			newTopOfStack = new stackEntry(topOfStack->next()->data(), topOfStack->next()->next());
		}
		
		//deleting the topOfStack
		//topOfStack is a stackEntry pointer
		//NOT DELETING THE COMMAND POINTER, that would be delete topOfStack->top()
		delete topOfStack;

		//the topOfStack is now the previous topOfStack's nextStackEntry 
		//if the stack has 1 or less items in it, then it deletes the topOfStack and sets the new topOfStack to nullptr (if you try to make it without checking the size then it throws an exception)
		topOfStack = newTopOfStack;

		//decrement the size of the stack every time a stackEntry is popped off the stack
		numEntries--;
	}
	
}

//returns true if the stack is empty (contains no items)
//returns false if the stack has at least one item
bool stack::empty() const{
	bool isEmpty = true;

	if (numEntries > 0) {
		isEmpty = false;
	}

	return isEmpty;
}

//debugging
void stack::debug(std::ostream &out) const {

}

//debugging
void stack::debug() const {
	debug(std::cout);
}

//deletes all the stackEntry objects in the stack, but not the command pointers they point to
stack::~stack() {

	//while the stack has items in it, pop off the top (so it deletes every item)
	while (empty() == false) {
		pop(); 
	}

}