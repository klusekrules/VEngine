#pragma once

#include "PhysicalObject.h"
#include "Engine/Physic/RayIntersection.h"
#include "Engine/Octree.h"

namespace vengine {

class PlayerController : public PhysicalObject {
public:
	PlayerController(const std::string& name = "Player");
	PlayerController(const PlayerController& source);

	virtual ~PlayerController();

	virtual GameObject* Clone();

	void SetCamera(CameraFPP* camera);
	void SetOctree(Octree* octree);

	float speed = 5.0f;
	float runModifier = 2.0f;
	float jumpForce = 20.0f;
	float digDistance = 5.0f;
private:
	CameraFPP* _camera;
	Voxel::Type _activeItem;
	Lines _voxLines;
	Octree* _octree;
	RayIntersection rayInfo;

	virtual void OnUpdate();
	virtual void OnLateUpdate();
	virtual void OnInit();
	virtual void OnDraw(Renderer* renderer);
	bool grounded = false;

	void Move();
	void ChangeBlocks();
};


inline
PlayerController::PlayerController(const std::string& name) : PhysicalObject(name)
{
	_camera = nullptr;
	_octree = nullptr;
	_mass = 2.0f;
	_bounciness = 0.0f;
}

inline
PlayerController::PlayerController(const PlayerController& source) : PhysicalObject(source)
{
	speed = source.speed;
	runModifier = source.runModifier;

	_camera = source._camera;
	_octree = source._octree;
}

inline
PlayerController::~PlayerController()
{
	delete _camera;
}

inline GameObject*
PlayerController::Clone()
{
	return new PlayerController(*this);
}

inline void 
PlayerController::SetCamera(CameraFPP* camera)
{
	_camera = camera;
}

inline void 
PlayerController::SetOctree(Octree* octree)
{
	_octree = octree;
}

}