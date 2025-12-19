#ifndef __BACKEND_H__
#define __BACKEND_H__

#include "I_Backend.h"
#include "QSharedPointer"
#include "QString"
#include "CloudFileID.h"
#include "MdHighLight.h"
#include "MdHTML.h"

// Forward declarations
class I_AsyncLuncher;
class I_ServiceManager;

class Backend : public I_Backend {
public:
    // Constructor and destructor
    Backend();
    virtual ~Backend() override;

    // Implement pure virtual methods from I_Backend
    void saveCloudFileFully(CloudFileID id) override;
    void saveCloudOnlyLocal(CloudFileID id) override;
    void writeCloudFile(CloudFileID id, QString content) override;
    QString readCloudFileOnBuffer(CloudFileID id) override;
    MdHighLight getCloudHighLight(CloudFileID id) override;
    MdHtml getPreview(CloudFileID id) override;

private:
    // Add any private members as needed
};

#endif // __BACKEND_H__