#ifndef DATACONTAINER_H_
#define DATACONTAINER_H_
#include <vector>
#include <memory>
#include <unordered_map>
#include "BaseMesh.h"
#include "BaseMaterial.h"
//-------------------------------------------------------------------------------------------------------
/// @author Renats Bikmajevs
/// Modified from : --
/// @note A container for material and mesh data that also manages them.
//-------------------------------------------------------------------------------------------------------
class DataContainer
{
public :
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default constructor
  //-----------------------------------------------------------------------------------------------------
  DataContainer()=default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default destructor.
  //-----------------------------------------------------------------------------------------------------
  ~DataContainer()=default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Calls the update method of the material with the specified ID
  //-----------------------------------------------------------------------------------------------------
  void matUpdate(const size_t _id);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Returns the current size of the material vector
  //-----------------------------------------------------------------------------------------------------
  size_t matSize() const;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Returns the current size of the geometry vector
  //-----------------------------------------------------------------------------------------------------
  size_t geosize() const;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Returns a pointer to the geometry with the specified ID
  //-----------------------------------------------------------------------------------------------------
  BaseMesh* geoFind(const size_t _id) const;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Returns a pointer to the geometry with the specified Name
  //-----------------------------------------------------------------------------------------------------
  BaseMesh* geoFind(const std::string _name) const;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Returns a pointer to the material with the specified ID
  //-----------------------------------------------------------------------------------------------------
  BaseMaterial* matFind(const size_t _id) const;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Returns a pointer to the material with the specified Name
  //-----------------------------------------------------------------------------------------------------
  BaseMaterial* matFind(const std::string _name) const;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Adds a specified Material pointer to the material vector, using default name
  //-----------------------------------------------------------------------------------------------------
  void matPut(BaseMaterial* _new);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Adds a specified Material pointer to the material vector, using custom name
  //-----------------------------------------------------------------------------------------------------
  void matPut(BaseMaterial* _new, const std::string _name);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Adds a specified Geometry pointer to the geometry vector, using default name
  //-----------------------------------------------------------------------------------------------------
  void geoPut(BaseMesh* _new);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Adds a specified Geometry pointer to the geometry vector, using custom name
  //-----------------------------------------------------------------------------------------------------
  void geoPut(BaseMesh* _new, const std::string _name);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Removes material with the specified Name, does nothing if not found
  //-----------------------------------------------------------------------------------------------------
  void matRemove(const std::string _name);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Removes material with the specified ID, does nothing if not found
  //-----------------------------------------------------------------------------------------------------
  void matRemove(const size_t _id);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Removes geometry with the specified Name, does nothing if not found
  //-----------------------------------------------------------------------------------------------------
  void geoRemove(const std::string _name);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Removes geometry with the specified ID, does nothing if not found
  //-----------------------------------------------------------------------------------------------------
  void geoRemove(const size_t _id);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Sets the name of the mesh with specified ID to the input name value
  //-----------------------------------------------------------------------------------------------------
  void setGeoName(const size_t _id, const std::string _new);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Sets the name of the material with specified ID to the input name value
  //-----------------------------------------------------------------------------------------------------
  void setMatName(const size_t _id, const std::string _new);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Returns the Name value of the material with the specified ID
  //-----------------------------------------------------------------------------------------------------
  std::string getMatName(const size_t _id) const;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Returns the Name value of the mesh with the specified ID
  //-----------------------------------------------------------------------------------------------------
  std::string getGeoName(const size_t _id) const;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Returns a vector of all stored geometry names
  //-----------------------------------------------------------------------------------------------------
  std::vector<std::string> getGeoNames() const;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Returns a vector of all stored material names
  //-----------------------------------------------------------------------------------------------------
  std::vector<std::string> getMatNames() const;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Returns the ID value of the material with the specified Name
  //-----------------------------------------------------------------------------------------------------
  size_t getMatID(const std::string &_name) const;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Returns the ID value of the mesh with the specified Name
  //-----------------------------------------------------------------------------------------------------
  size_t getGeoID(const std::string &_name) const;
private:
  //-----------------------------------------------------------------------------------------------------
  /// @brief Checks if there are meshes or materials that share the same IDs and replaces them with new IDs if found
  //-----------------------------------------------------------------------------------------------------
  void checkIDs();
  //-----------------------------------------------------------------------------------------------------
  /// @brief Checks if there are meshes that share the same IDs and replaces them with new IDs if found
  //-----------------------------------------------------------------------------------------------------
  void checkGeoIDs();
  //-----------------------------------------------------------------------------------------------------
  /// @brief Checks if there are materials that share the same IDs and replaces them with new IDs if found
  //-----------------------------------------------------------------------------------------------------
  void checkMatIDs();
  //-----------------------------------------------------------------------------------------------------
  /// @brief Scans currenly stored meshes and returns an ID that is not in use
  //-----------------------------------------------------------------------------------------------------
  size_t getFreeGeoID() const;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Scans currenly stored materials and returns an ID that is not in use
  //-----------------------------------------------------------------------------------------------------
  size_t getFreeMatID() const;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Returns a vector of all stored geometry IDs
  //-----------------------------------------------------------------------------------------------------
  std::vector<size_t> getCurrentGeoIDs()const;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Returns a vector of all stored material IDs
  //-----------------------------------------------------------------------------------------------------
  std::vector<size_t> getCurrentMatIDs()const;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Checks if there are meshes or materials that share the same Names and replaces them with new Names if found
  //-----------------------------------------------------------------------------------------------------
  void checkNames();
  //-----------------------------------------------------------------------------------------------------
  /// @brief Checks if there are materials that share the same Names and replaces them with new Names if found
  //-----------------------------------------------------------------------------------------------------
  void checkMatNames();
  //-----------------------------------------------------------------------------------------------------
  /// @brief Checks if there are meshes that share the same Names and replaces them with new Names if found
  //-----------------------------------------------------------------------------------------------------
  void checkGeoNames();
private :
  //-----------------------------------------------------------------------------------------------------
  /// @brief A vector of geometry(mesh) data stored using pointers to the virtual interfaces
  //-----------------------------------------------------------------------------------------------------
  std::vector<std::unique_ptr<BaseMesh>> m_geo;
  //-----------------------------------------------------------------------------------------------------
  /// @brief A vector of material data stored using pointers to the virtual interfaces
  //-----------------------------------------------------------------------------------------------------
  std::vector<std::unique_ptr<BaseMaterial>> m_mat;
};
#endif //DATACONTAINER_H_