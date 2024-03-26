#pragma once
#include "CommandQueue.h"
#include "Aircraft.hpp"
#include "World.hpp"




class Player
{
    /** A struct type
     *  Struct Type that has the Aircraft Mover Command.
     */
    struct AircraftMover
    {
        XMFLOAT3 velocity;

        
        
        AircraftMover(float vx, float vy, float vz) : velocity(vx, vy, vz)
        {

        }


        void operator() (SceneNode& node, const GameTimer& gt) 
        {
            Aircraft& aircraft = static_cast<Aircraft&>(node);
            aircraft.move(velocity);
        }
        
    };
public:
    /**
    * @brief (playerSpeed) float value for the speed of Player Movement.
    */
    const float playerSpeed = 0.001f;

    /// Handle's event for the recieved command.
    /// 
    /// @param (commands) the commandQueue type that passes in the command.
    /// @returns no return type
    void handleEvent(CommandQueue& commands);

    /// Handle's event for the recieved command in the current frame.
    /// 
    /// @param (commands) the command that tells the handleEvent function what command has been pressed..
    /// @returns no return type
    void handleRealtimeInput(CommandQueue& commands);

};

