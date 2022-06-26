#pragma once

#include "Object.hpp"
#include <vector> 
#include <string>

class Objects
{
private:
    static int numberOfTotalObjects;

    int numberOfSpawnedObjects;
    int numberOfStaticObj;
    int numberOfTriggerObj;
    int numberOfDynamicObj;

public:
    Objects(/* args */);
    void addStaticObj(Object obj);
    void addTriggerObj(Object obj);
    void addDynamicObj(Object obj);

    std::vector<Object> getStaticObjVector();
    std::vector<Object> getTriggerObjVector();
    std::vector<Object> getDynamicObjVector();

    void removeStaticObj(int indexOfObj);
    void removeTriggerObj(int indexOfObj);
    void removeDynamicObj(int indexOfObj);
    ~Objects(); 
};


