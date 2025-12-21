#ifndef BACKEND_H
#define BACKEND_H

#include "I_Backend.h"
#include "QSharedPointer"
#include "QString"
#include "CloudFileID.h"
#include "MdHighLight.h"
#include "MdHTML.h"
#include "QMap"
#include <qcontainerfwd.h>
#include <qmap.h>
#include "qreadwritelock.h"
#include "QWriteLocker"
#include "qreadwritelock.h"
// Forward declarations
class I_AsyncLuncher;
class I_ServiceManager;

class Backend : public I_Backend {
public:
    // Constructor and destructor
    QReadWriteLock fileBufferLock;
    QMap<QString,QString> fileBuffer;
    Backend();
    virtual ~Backend() override;

    // Implement pure virtual methods from I_Backend
    void saveCloudFileFully(RMCRuntimeFileID id) override;
    void saveOnlyLocal(RMCRuntimeFileID id) override;
    void writeCloudFileBuffer(RMCRuntimeFileID id, QString content) override;
    RMCRuntimeFileID loadFileFromLocal(QString path) override;
    QString readCloudFileOnBuffer(RMCRuntimeFileID id) override;
    MdHighLight getCloudHighLight(RMCRuntimeFileID id) override;
    MdHtml getPreview(RMCRuntimeFileID id) override;

private:
    // Add any private members as needed
};

#endif // BACKEND_H
