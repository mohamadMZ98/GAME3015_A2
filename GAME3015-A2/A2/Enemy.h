#pragma once
#include "Entity.hpp"
#include <string>
using namespace std;

class Enemy : public Entity
{
public:
	/** An enum type
	 *  Enum for the different types of the Enemy Aircraft.
	 */
	enum Type
	{
		Eagle,	/**< enum Eagle  */
		Raptor,	/**< enum Raptor */
	};

	/// Constructor
	/// 
	/// @param (type) Type enum for the Type of Aircraft.
	/// @param (game) instance reference of a Game class
	Enemy(Type type, Game* game);


private:

	virtual void drawCurrent() const;

	/// Builds the Render Item for the Enemy.
	/// 
	/// @param no parameters
	/// @returns no return type.
	virtual void buildCurrent();

	/**
	* @brief (mType) Enum type of Enemy.
	*/
	Type mType;

	string mSprite;



};

