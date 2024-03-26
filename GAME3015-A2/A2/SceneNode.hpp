#pragma once
#include "../../Common/d3dApp.h"
#include "../../Common/MathHelper.h"
#include "../../Common/UploadBuffer.h"
#include "../../Common/GeometryGenerator.h"
#include "../../Common/Camera.h"
#include "FrameResource.h"

using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;

#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")

// Lightweight structure stores parameters to draw a shape.  This will
// vary from app-to-app.
struct RenderItem
{
	RenderItem() = default;

	// World matrix of the shape that describes the object's local space
	// relative to the world space, which defines the position, orientation,
	// and scale of the object in the world.
	XMFLOAT4X4 World = MathHelper::Identity4x4();

	XMFLOAT4X4 TexTransform = MathHelper::Identity4x4();

	// Dirty flag indicating the object data has changed and we need to update the constant buffer.
	// Because we have an object cbuffer for each FrameResource, we have to apply the
	// update to each FrameResource.  Thus, when we modify obect data we should set 
	// NumFramesDirty = gNumFrameResources so that each frame resource gets the update.
	int NumFramesDirty = gNumFrameResources;

	// Index into GPU constant buffer corresponding to the ObjectCB for this render item.
	UINT ObjCBIndex = -1;

	Material* Mat = nullptr;
	MeshGeometry* Geo = nullptr;

	// Primitive topology.
	D3D12_PRIMITIVE_TOPOLOGY PrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	// DrawIndexedInstanced parameters.
	UINT IndexCount = 0;
	UINT StartIndexLocation = 0;
	int BaseVertexLocation = 0;
};

class Game;
struct Command;


namespace Category
{
	/** An enum type
	 *  Enum for the different types of scene nodes in the game.
	 */
	enum Type
	{
		None,
		Scene,
		BackGround,
		PlayerAircraft,
		AlliedAircraft,
		EnemyAircraft,
	};
}





class SceneNode
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;


public:
	/// Constructor
	/// 
	/// @param (game) instance reference of a Game class
	SceneNode(Game* game);

	void attachChild(Ptr child);
	Ptr	detachChild(const SceneNode& node);

	/// Update function
	/// 
	/// @param (gt) passes GameTimer for the update function.
	/// @returns no return type.
	void update(const GameTimer& gt);

	/// Draw function
	/// 
	/// @param no parameters.
	/// @returns no return type.
	void draw() const;

	/// Build function
	/// 
	/// @param no parameters.
	/// @returns no return type.
	void build();

	// Getters

	/// Gets World Position
	/// 
	/// @param no parameters.
	/// @returns Node's position as XMFLOAT3 reference
	XMFLOAT3 getWorldPosition() const;

	/// Gets Entity's Rotation
	/// 
	/// @param no parameters.
	/// @returns Node's rotation as XMFLOAT3 reference
	XMFLOAT3 getWorldRotation() const;

	/// Gets Entity's Scale
	/// 
	/// @param no parameters.
	/// @returns Node's position as XMFLOAT3 reference
	XMFLOAT3 getWorldScale() const;

	/// Gets Entity's Transformation
	/// 
	/// @param no parameters.
	/// @returns Node's transformation as XMFLOAT3 reference
	XMFLOAT4X4 getWorldTransform() const;


	XMFLOAT4X4 getTransform() const;


	// Setters

	/// Sets Entity's Rotation
	/// 
	/// @param (x) Sets Node's x rotation
	/// @param (y) Sets Node's y rotation
	/// @param (z) Sets Node's z rotation
	/// @returns no return type.
	void setWorldRotation(float x, float y, float z);

	/// Sets Entity's Position
	/// 
	/// @param (x) Sets Node's x position
	/// @param (y) Sets Node's y position
	/// @param (z) Sets Node's z position
	/// @returns no return type.
	void setPosition(float x, float y, float z);
	void setPosition(XMFLOAT3 newScale);

	/// Sets Entity's Scale
	/// 
	/// @param (x) Sets Node's x scale
	/// @param (y) Sets Node's y scale
	/// @param (z) Sets Node's z scale
	/// @returns no return type.
	void setScale(float x, float y, float z);
	void setScale(XMFLOAT3 newScale);


	/// Moves the entity
	/// 
	/// @param (x) Enitiy's movement in x direction.
	/// @param (y) Enitiy's movement in y direction.
	/// @param (z) Enitiy's movement in z direction.
	/// @returns no return type.
	void move(float x, float y, float z);
	void move(XMFLOAT3 velocity);

	/// Command Execution
	/// 
	/// @param (command) Passes in the command.
	/// @param (gt) passes GameTimer.
	/// @returns no return type.
	void onCommand(const Command& command, const GameTimer& gt);

	/// Gets Category of the commands
	/// 
	/// @param no parameters.
	/// @returns an int value from enum Type.
	virtual unsigned int getCategory() const;
	void setCategory(int c);

private:
	virtual void updateCurrent(const GameTimer& gt);
	void updateChildren(const GameTimer& gt);

	virtual void drawCurrent() const;
	void drawChildren() const;
	virtual void buildCurrent();
	void buildChildren();

protected:
	Game* game;
	RenderItem* renderer;
private:

	/**
	* @brief (mWorldPosition) Current Position of the Node, passed as XMFLOAT3.
	*/
	XMFLOAT3 mWorldPosition;

	/**
	* @brief (mWorldRotation) Current Rotation of the Node, passed as XMFLOAT3.
	*/
	XMFLOAT3 mWorldRotation;

	/**
	* @brief (mWorldScaling) Current Scale of the Node, passed as XMFLOAT3.
	*/
	XMFLOAT3 mWorldScaling;


	std::vector<Ptr> mChildren;

	/**
	* @brief (mParent) Parrent of the Scene Node.
	*/
	SceneNode* mParent;

	int mCategory;


};

