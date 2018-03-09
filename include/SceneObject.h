#ifndef SCENEOBJECT_H_
#define SCENEOBJECT_H_

#include "DataContainer.h"
#include "BaseObject.h"

class SceneObject : public BaseObject
{
public :
  SceneObject(std::string _name = "SceneObject", glm::vec3 _pos=glm::vec3(0,0,0), glm::vec3 _rot=glm::vec3(0,0,0), glm::vec3 _sc=glm::vec3(1,1,1), size_t _geo=1, size_t _mat=0):
    BaseObject(_name, _pos, _rot, _sc),
    m_geometry(_geo),
    m_material(_mat)
  {}

  ~SceneObject() override = default;
  virtual void reset() override;
  virtual void changeID(const size_t _newID) override;
  virtual size_t getID() const override;
  void setGeometry(size_t _new);
  size_t getGeo() const;
  size_t findMat() const;
  void setMat(size_t _new);
private :
  size_t m_geometry;
  size_t m_material = 0;
};

#endif
