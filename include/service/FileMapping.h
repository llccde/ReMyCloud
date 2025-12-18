#ifndef __FILEMAPPING_H__
#define __FILEMAPPING_H__
#include "I_FileMapping.h"
#include "Qvector"
#include <qcontainerfwd.h>
class FileMapping:public I_FileMapping{
    QVector<RMCRelation> mappings;
    public:
    inline FileMapping(){};
    void initMappingsFromConfig() override;
    inline ~FileMapping() override{};

};
#endif // __FILEMAPPING_H__