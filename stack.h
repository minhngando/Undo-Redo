/*
 * stack.h
 *
 *  The stack class is a stack data structor for command pointers. The entries that make up the stack are of
 *  type stackEntry.
 *
 *  Created on: Oct 1, 2018
 *      Author: dgv130030
 */

#ifndef STACK_H_
#define STACK_H_

#include "memoryLeak.h"

#include <vector>
#include <iostream>

class command;
class stack;

class stackEntry
{
	friend class stack;

	private:

		command *cmd;
		stackEntry *nextStackEntry;

	protected:

		//stackEntry constructor
		stackEntry(command *theCommand, stackEntry *pNext = nullptr);

		//updates the nextStackEntry to pNext
		virtual void next(stackEntry *pNext);

		//returns the stackEntry pointer (which is a pointer to the next stack entry) of the stackEntry
		virtual stackEntry* next();

		//returns the command pointer of the stackEntry
		virtual command* data();
		virtual const command* data() const;

		//destructor
		virtual ~stackEntry();
};

class stack
{
	//every stack has a pointer to the top of the stack and a size
	private:

		stackEntry *topOfStack;
		std::size_t numEntries;

	public:

		//stack constructor creates a stack with no elements
		stack();

		//explicitly deleting the copy constructor and the assignment operator 
		stack(const stack &from) = delete;
		stack& operator=(const stack &from) = delete;
		
		//returns the top stackEntry objects on top of the stack, if there isn't one then nullptr should be returned
		command* top();
		const command* top() const;

		//returns the number of items on the stack
		//not dynamically counted, needs to be an instance variable and incremented when push is called and decremented when an item is removed from the stack
		std::size_t size() const;

		//returns true if the stack is empty (contains no items)
		//returns false if the stack has at least one item
		bool empty() const;

		//adds a new command pointer to the stack
		//creates a new stackEntry and makes it the new topOfStack
		void push(command *newCommand);

		//removes the top entry from the stack and deletes the stackEntry object that is being removed
		//should not delete the command pointer
		void pop();

		//debugging
		void debug(std::ostream &out) const;
		void debug() const;

		//destructor
		//delete all the stackEntry objects but should not delete the command objects they point to
		virtual ~stack();
};

#endif /* STACK_H_ */
