#include "BaseMaterial.h"

void BaseMaterial::apply()
{
  return;
}

void BaseMaterial::setShaderName(const std::string &_name)
{
  return;
}

void BaseMaterial::setName(std::string _new)
{
  m_name = _new;
}

std::string BaseMaterial::getName() const
{
  return m_name;
}

void BaseMaterial::setID(size_t _new)
{
  m_id = _new;
}

size_t BaseMaterial::getID() const
{
  return m_id;
}
