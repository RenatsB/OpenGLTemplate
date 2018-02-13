#ifndef MATERIAL_H
#define MATERIAL_H

#include <array>
#include <mat4x4.hpp>

class ShaderLib;

class Material
{
public:
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default constructor.
  //-----------------------------------------------------------------------------------------------------
  Material(ShaderLib *io_shaderLib, std::array<glm::mat4, 3>* io_matrices) :
    m_shaderLib(io_shaderLib),
    m_matrices(io_matrices)
  {}
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default copy constructor.
  //-----------------------------------------------------------------------------------------------------
  Material(const Material&) = default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default copy assignment operator.
  //-----------------------------------------------------------------------------------------------------
  Material& operator=(const Material&) = default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default move constructor.
  //-----------------------------------------------------------------------------------------------------
  Material(Material&&) = default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default move assignment operator.
  //-----------------------------------------------------------------------------------------------------
  Material& operator=(Material&&) = default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default virtual destructor.
  //-----------------------------------------------------------------------------------------------------
  virtual ~Material() = default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to intialise a passed shader, subclasses must call this base function.
  //-----------------------------------------------------------------------------------------------------
  virtual void init() = 0;

  void setShaderName(const std::string &_name);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to update shader values.
  //-----------------------------------------------------------------------------------------------------
  virtual void update() = 0;

  void apply();

  virtual const char* shaderFileName() const = 0;

protected:
  //-----------------------------------------------------------------------------------------------------
  /// @brief A pointer to the central Shader Library.
  //-----------------------------------------------------------------------------------------------------
  ShaderLib* m_shaderLib = nullptr;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Unique id of the shader within the shader library, that this material affects.
  //-----------------------------------------------------------------------------------------------------
  std::string m_shaderName;
  //-----------------------------------------------------------------------------------------------------
  /// @brief A pointer to matrices this material should use for the vertex shader.
  //-----------------------------------------------------------------------------------------------------
  std::array<glm::mat4, 3>* m_matrices = nullptr;
};

#endif // MATERIAL_H
