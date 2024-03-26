#pragma once
#include "Entity.hpp"
#include "CommandQueue.h"

class SpriteNode : public Entity
{
public:
    /** A struct type
     *  Struct Type that makes the Background Scroll.
     */
    struct BGMover
    {
        XMFLOAT3 velocity;
    
	    BGMover(float vx, float vy, float vz) : velocity(vx, vy, vz){}
        void operator() (SceneNode& node, const GameTimer& gt) 
        {
            SpriteNode& spriteNode = static_cast<SpriteNode&>(node);
            spriteNode.move(velocity);
        }
    };

    /// Constructor
    /// 
    /// @param (game) instance reference of a Game class
	SpriteNode(Game* game);

    /// Update function
    /// 
    /// @param (gt) passes GameTimer for the update function.
    /// @returns no return type.
	void Update(const GameTimer gt);

	void UpdateWithCmd(CommandQueue& commands);

    /**
    * @brief (backgroundSpeed) float value for the Background's speed.
    */
	float backgroundSpeed;

private:
    /// Draws the Render Item during the current frame.
    /// 
    /// @param no parameters.
    /// @returns no return type.
	virtual void drawCurrent() const;

    /// Builds the Render Item for the Sprite Node.
    /// 
    /// @param no parameters
    /// @returns no return type.
	virtual void buildCurrent();
};
