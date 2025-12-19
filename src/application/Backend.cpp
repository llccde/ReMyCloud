#include "Backend.h"

Backend::Backend() {
    // Empty constructor
}

Backend::~Backend() {
    // Empty destructor
}

void Backend::saveCloudFileFully(CloudFileID id) {
    // Empty implementation
}

void Backend::saveCloudOnlyLocal(CloudFileID id) {
    // Empty implementation
}

void Backend::writeCloudFile(CloudFileID id, QString content) {
    // Empty implementation
}

QString Backend::readCloudFileOnBuffer(CloudFileID id) {
    // Empty implementation
    return QString();
}

MdHighLight Backend::getCloudHighLight(CloudFileID id) {
    // Empty implementation
    return MdHighLight();
}

MdHtml Backend::getPreview(CloudFileID id) {
    // Empty implementation
    return MdHtml();
}