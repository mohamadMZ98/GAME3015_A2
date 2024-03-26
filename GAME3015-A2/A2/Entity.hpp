#pragma once
#include "SceneNode.hpp"

// 2D Entity
class Entity : public SceneNode
{
public:

	/// Constructor
	/// 
	/// @param (game) instance reference of a Game class
	Entity(Game* game);

	//void setVelocity(XMFLOAT2 velocity);

	/// Sets Entity velocity.
	/// 
	/// @param (x) Set the entity's x direction.
	/// @param (y) Set the entity's y direction.
	/// @returns no return type
	void setVelocity(float vx, float vy);

	/// Gets Entity velocity.
	/// 
	/// @param no parameters
	/// @returns returns the velocity of the Entity, as a XMFLOAT2 reference.
	XMFLOAT2 getVelocity() const;

	/// Recieves the updated velocity of the Entity.
	/// 
	/// @param (gt) passes in the game timer to update the Entity.
	/// @returns no return type
	virtual	void updateCurrent(const GameTimer& gt);

public:
	/**
	* @brief (mVelocity) Current Velocity of the Entity passed as XMFLOAT2
	*/
	XMFLOAT2 mVelocity;
};

