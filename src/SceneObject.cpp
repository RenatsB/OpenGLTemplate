#include "SceneObject.h"

void SceneObject::reset()
{
  m_pos=vec3(0,0,0);
  m_rot=vec3(0,0,0);
  m_scale=vec3(1,1,1);
}

void SceneObject::changeID(const size_t _newID)
{
  m_id = _newID;
}

size_t SceneObject::getID () const
{
  return m_id;
}

void SceneObject::setGeometry(size_t _new)
{
  m_geometry = _new;
}

size_t SceneObject::getGeo() const
{
  return m_geometry;
}

size_t SceneObject::findMat() const
{
  return m_material;
}

void SceneObject::setMat(size_t _new)
{
  m_material = _new;
}
