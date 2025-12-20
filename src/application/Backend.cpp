#include "Backend.h"
#include "CloudFileID.h"

Backend::Backend() {
    // Empty constructor
}

Backend::~Backend() {
    // Empty destructor
}

void Backend::saveCloudFileFully(RMCFileID id) {
    // Empty implementation
}

void Backend::saveCloudOnlyLocal(RMCFileID id) {
    // Empty implementation
}

void Backend::writeCloudFile(RMCFileID id, QString content) {
    // Empty implementation
}

QString Backend::readCloudFileOnBuffer(RMCFileID id) {
    // Empty implementation
    return QString();
}

MdHighLight Backend::getCloudHighLight(RMCFileID id) {
    // Empty implementation
    return MdHighLight();
}

MdHtml Backend::getPreview(RMCFileID id) {
    // Empty implementation
    return MdHtml();
}