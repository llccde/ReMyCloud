#ifndef BACKEND_H
#define BACKEND_H

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
    void saveCloudFileFully(RMCFileID id) override;
    void saveCloudOnlyLocal(RMCFileID id) override;
    void writeCloudFile(RMCFileID id, QString content) override;
    QString readCloudFileOnBuffer(RMCFileID id) override;
    MdHighLight getCloudHighLight(RMCFileID id) override;
    MdHtml getPreview(RMCFileID id) override;

private:
    // Add any private members as needed
};

#endif // BACKEND_H
