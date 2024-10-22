#include "PackageFactory.h"

PackageFactory::PackageFactory(PackageObserver* observer) {
  packageObserver = observer;
}

IEntity* PackageFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("package") == 0) {
    std::cout << "Package Created" << std::endl;
    return new Package(entity, packageObserver);
  }
  return nullptr;
}
