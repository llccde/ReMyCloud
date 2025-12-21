#include "Backend.h"
#include "CloudFileID.h"
#include "ServiceManager.h"
#include "FileMapping.h"
#include "RMCRelation.h"
#include <qreadwritelock.h>
#include "LocalFileService.h"
Backend::Backend() {
    // Empty constructor
}

Backend::~Backend() {
    // Empty destructor
}

void Backend::saveCloudFileFully(RMCRuntimeFileID id) {
    // Empty implementation
}
RMCRuntimeFileID Backend::loadFileFromLocal(QString path){
    return RMCRuntimeFileID::unAvailable();
}
void Backend::saveOnlyLocal(RMCRuntimeFileID id) {
    QReadLocker L(&fileBufferLock);
    auto rmc = serviceManager->getFileMapping()->getRMCFile(id);
    auto local = serviceManager->getLocalFileService()->openFile(rmc.localPath);
    serviceManager->getLocalFileService()->writeFile(local, fileBuffer[id.toString()]);
}

void Backend::writeCloudFileBuffer(RMCRuntimeFileID id, QString content) {
    if(id.available()){
        QWriteLocker L(&this->fileBufferLock);
        fileBuffer.insert(id.toString(),content);
    }
}

QString Backend::readCloudFileOnBuffer(RMCRuntimeFileID id) {
    QReadLocker L(&fileBufferLock);
    return fileBuffer[id.toString()];
}

MdHighLight Backend::getCloudHighLight(RMCRuntimeFileID id) {
    // Empty implementation
    return MdHighLight();
}

MdHtml Backend::getPreview(RMCRuntimeFileID id) {
    // Empty implementation
    return MdHtml();
}