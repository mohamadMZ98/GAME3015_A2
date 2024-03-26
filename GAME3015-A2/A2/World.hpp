#pragma once
#include "SceneNode.hpp"
#include "Aircraft.hpp"
#include "SpriteNode.h"
#include "CommandQueue.h"


class World 
{
public:
	/// Constructor
	/// 
	/// @param (window) instance reference of a Game class for the Game Window.
	explicit World(Game* window);

	/// Update function
	/// 
	/// @param (gt) passes GameTimer for the update function.
	/// @returns no return type.
	void update(const GameTimer& gt);

	/// Draws the Scene Nodes in the World.
	/// 
	/// @param no parameters.
	/// @returns no return type.
	void draw();

	/// Builds all the nodes in the world.
	/// 
	/// @param no parameters.
	/// @returns no return type.
	void buildScene();

	/// Getter for the CommandQueue
	/// 
	/// @param no parameters.
	/// @returns no return type.
	CommandQueue& getCommandQueue();
	

private:

	/** An enum type
	 *  Enum for the different types of Layers
	 */
	enum Layer
	{
		Background, /**< enum for the Background */
		Air,		/**< enum for the air above the Background */
		LayerCount  /**< enum for Layer count */
	};


private:

	/**
	* @brief (mGame) Pointer to the Game class
	*/
	Game* mGame;

	/**
	* @brief (mSceneGraph) Pointer to Nodes of the Scene Graph.
	*/
	SceneNode* mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;

	XMFLOAT4 mWorldBounds;

	/**
	* @brief (mSpawnPosition) position where to spawn the nodes.
	*/
	XMFLOAT2 mSpawnPosition;


	// entities

	/**
	* @brief (mPlayerAircraft) Pointer to the Player Aircraft.
	*/
	Aircraft* mPlayerAircraft;

	/**
	* @brief (mBackground) pointer of Background, which is a SpriteNode.
	*/
	SpriteNode*	mBackground;

	/**
	* @brief (mEnemy) Pointer to the Enemy Aircraft.
	*/
	Aircraft* mEnemy;
	
	/**
	* @brief (mScrollSpeed) float value, Speed of the Background Scroll.
	*/
	float mScrollSpeed;

	/**
	* @brief (aircraftSize) XMFLOAT3 type. Size of the Player in the world.
	*/
	XMFLOAT3 aircraftSize;

	/**
	* @brief (enemySize) XMFLOAT3 type. Size of the Enemy in the world.
	*/
	XMFLOAT3 enemySize;

	/**
	* @brief (cQueue) Command Queue.
	*/
	CommandQueue cQueue;
};
