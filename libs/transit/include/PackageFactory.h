#ifndef PACKAGE_FACTORY_H_
#define PACKAGE_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "Package.h"
#include "PackageObserver.h"

/**
 *@brief Package Factory to produce Package class.
 **/
class PackageFactory : public IEntityFactory {
 public:
  /**
   * @brief PackageFactories are created with a package observer
   * @param observer PackageObserver object to subscribe to 
   * the packages being produced
   */
  PackageFactory(PackageObserver* observer);

  /**
   * @brief Destructor for PackageFactory class.
   **/
  virtual ~PackageFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity);

 private:
    PackageObserver* packageObserver;
};

#endif
