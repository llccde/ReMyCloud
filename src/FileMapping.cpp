#include "FileMapping.h"
#include "I_DataConfigLoader.h"
#include "DataConfig.h"
void FileMapping::initMappingsFromConfig(){
    
    auto configLoaderPtr = configLoader.lock();
    if(!configLoaderPtr){
        return;
    }
    
    auto config = configLoaderPtr->loadConfig();

    mappings.clear();
    for(const auto& relationRaw:config->relations){
        RMCRelation relation;
        relation.theName = relationRaw.theName;
        mappings.append(relation);
    }
}