#include "World.hpp"
#include "Player.h"

class Game : public D3DApp
{
public:
	/// Constructor.
	/// 
	/// @param (hInstance) Instance of class
	Game(HINSTANCE hInstance);

	/// Constructor.
	/// 
	/// @param (rhs) constant pointer of A1 class
	Game(const Game& rhs) = delete;
	
	Game& operator=(const Game& rhs) = delete;

	/// Destructor.
	/// 
	/// @param no parameters
	~Game();

	/// Initialize function.
	/// 
	/// @param no parameters
	/// @returns returns a boolean value.
	virtual bool Initialize()override;
private:
	virtual void OnResize()override;

	/// Update function
	/// 
	/// @param (gt) passes GameTimer for the update function.
	/// @returns no return type.
	virtual void Update(const GameTimer& gt)override;

	/// Draw function
	/// 
	/// @param (gt) passes GameTimer.
	/// @returns no return type.
	virtual void Draw(const GameTimer& gt)override;

	virtual void OnMouseDown(WPARAM btnState, int x, int y)override;
	virtual void OnMouseUp(WPARAM btnState, int x, int y)override;
	virtual void OnMouseMove(WPARAM btnState, int x, int y)override;

	void OnKeyboardInput(const GameTimer& gt);
	void UpdateCamera(const GameTimer& gt);
	void AnimateMaterials(const GameTimer& gt);
	void UpdateObjectCBs(const GameTimer& gt);
	void UpdateMaterialCBs(const GameTimer& gt);
	void UpdateMainPassCB(const GameTimer& gt);

	/// Handles the Commands in the Game.
	/// 
	/// @param no params.
	/// @returns no return type.
	void processInput();



	//step5

	/// Load Texture
	/// 
	/// @param no params.
	/// @returns no return type.
	void LoadTextures();

	/// Build Root Signature
	/// 
	/// @param no params.
	/// @returns no return type.
	void BuildRootSignature();

	//step9

	/// Build Descriptor Heaps
	/// 
	/// @param no params.
	/// @returns no return type.
	void BuildDescriptorHeaps();

	/// Build Shaders and Input Layout.
	/// 
	/// @param no params.
	/// @returns no return type.
	void BuildShadersAndInputLayout();
	void BuildShapeGeometry();
	void BuildPSOs();
	void BuildFrameResources();
	void BuildMaterials();
	void BuildRenderItems();
	void DrawRenderItems(ID3D12GraphicsCommandList* cmdList, const std::vector<RenderItem*>& ritems);

	std::array<const CD3DX12_STATIC_SAMPLER_DESC, 6> GetStaticSamplers();

private:
	/**
	* @brief (mFrameResources) Frame Resource Array
	*/
	std::vector<std::unique_ptr<FrameResource>> mFrameResources;
	FrameResource* mCurrFrameResource = nullptr;

	/**
	* @brief (mCurrFrameResourceIndex) Frame Resource Array Index
	*/
	int mCurrFrameResourceIndex = 0;

	UINT mCbvSrvDescriptorSize = 0;

	ComPtr<ID3D12RootSignature> mRootSignature = nullptr;

	//step11
	ComPtr<ID3D12DescriptorHeap> mSrvDescriptorHeap = nullptr;

	std::unordered_map<std::string, std::unique_ptr<MeshGeometry>> mGeometries;
	std::unordered_map<std::string, std::unique_ptr<Material>> mMaterials;

	//step7
	std::unordered_map<std::string, std::unique_ptr<Texture>> mTextures;

	std::unordered_map<std::string, ComPtr<ID3DBlob>> mShaders;

	std::vector<D3D12_INPUT_ELEMENT_DESC> mInputLayout;

	ComPtr<ID3D12PipelineState> mOpaquePSO = nullptr;

	// List of all the render items.
	std::vector<std::unique_ptr<RenderItem>> mAllRitems;

	// Render items divided by PSO.
	std::vector<RenderItem*> mOpaqueRitems;

	PassConstants mMainPassCB;

	XMFLOAT3 mEyePos = { 0.0f, 0.0f, -10.0f };
	XMFLOAT4X4 mView = MathHelper::Identity4x4();
	XMFLOAT4X4 mProj = MathHelper::Identity4x4();

	float mTheta = 1.3f * XM_PI;
	float mPhi = 0.4f * XM_PI;
	float mRadius = 2.5f;

	/**
	* @brief (mLastMousePos) Lattest position of the mouse.
	*/
	POINT mLastMousePos;

	/**
	* @brief (mCamera) instance of the camera object.
	*/
	Camera mCamera;

	/**
	* @brief (mWorld) instance of the World Class object.
	*/
	World mWorld;

	/**
	* @brief (mPlayer) instance player object.
	*/
	Player mPlayer;

public:
	std::vector<std::unique_ptr<RenderItem>>& getRenderItems() { return mAllRitems; }
	std::unordered_map<std::string, std::unique_ptr<Material>>& getMaterials() { return mMaterials; }
	std::unordered_map<std::string, std::unique_ptr<MeshGeometry>>& getGeometries() { return mGeometries; }
};
