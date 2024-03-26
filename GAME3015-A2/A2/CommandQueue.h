#pragma once
#include <iostream>
#include <Queue>
#include <functional>
#include "SceneNode.hpp"
using namespace std;


	
/** A struct type
 *  Struct Type for the commands.
 */

struct Command
{
	Command() = default;

	// command name
	string name;

	// lambda function for command
	function<void(SceneNode&, const GameTimer& gt)> action;
	
	// command category
	unsigned int category;
};



class CommandQueue
{
public:

	/// Push Function
	/// 
	/// @param (newCommand) pushes the new command into the command queue
	/// @returns no return type.
	void push(const Command newCommand);

	
	/// Pop Function, that removes the command from the command queue.
	/// 
	/// @param no parameters
	/// @returns a temporary comman that is empty.
	Command pop();

	
	/// Pop Function, that removes the command from the command queue.
	/// 
	/// @param no parameters
	/// @returns a bool value. returns true if queue is empty, and false if it's not
	bool isEmpty() const;


private:
	
	/**
	* @brief (mQueue) Fifo queue that contains the commands.
	*/
	queue<Command> mQueue;



};

