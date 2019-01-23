#pragma once

#include "stdafx.h"
#include "Object.h"
#include "Vector2.h"
#include "String.h"
#include <list>

class Scene {
private:
	using ObjectList = std::list<Object>;
	ObjectList m_objects;

public:
	virtual ~Scene() = default;

private:
	friend class SceneManager;

	void Init();
	void Update();
	void Clear();

public:
	Object& FindObject(const std::tstring& name) const;
	Object& AddObject(const std::tstring& name, const Utility::Vector2 = Utility::Vector2(), const Utility::Vector2 = Utility::Vector2(1, 1), const float = 0);
};