#pragma once
#include "Entity.hpp"
#include <string>





class Aircraft : public Entity
{
public:
	/** An enum type
	 *  Enum for the different types of Aircrafts.
	 */
	enum Type
	{
		Eagle,	/**< enum Eagle for enemy */
		Raptor,	/**< enum Raptor for player */
	};
	
	/// Constructor
	/// 
	/// @param (type) Type enum for the Type of Aircraft.
	/// @param (game) instance reference of a Game class
	Aircraft(Type type, Game* game);

	/// Update function
	/// 
	/// @param (gt) passes GameTimer for the update function.
	/// @returns no return type.
	void Update(const GameTimer& gt);

	/// Gets the enum Type from the Category Namespace from the SceneNode class.
	/// 
	/// @param no parameters
	/// @returns an enum type from the Category Namespace.
	unsigned int getCategory() const;

	
private:

	virtual void drawCurrent() const;

	/// Builds the Render Item for the Aircrafts.
	/// 
	/// @param no parameters
	/// @returns no return type.
	virtual void buildCurrent();

	/**
	* @brief (mType) Enum type of Aircraft.
	*/
	Type mType;

	std::string mSprite;
};
