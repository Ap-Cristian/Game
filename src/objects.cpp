#include "../include/objects/Objects.hpp"

int Objects::numberOfTotalObjects = 0;

Objects::Objects(/* args */)
{
    numberOfTotalObjects++;

    numberOfSpawnedObjects = 0;
    numberOfStaticObj = 0;
    numberOfTriggerObj = 0;
    numberOfDynamicObj = 0;
}


Objects::~Objects()
{
}