#ifndef __FMP_TEST_H__
#define __FMP_TEST_H__
#include "DataConfig.h"
#include "FileMapping.h"
#include "I_CloudFileService.h"
#include "I_ServiceManager.h"
#include "ServiceManager.h"
#include "qobject.h"
#include <memory>
#include <qtmetamacros.h>
#include "memory"
#include "CloudFileService.h"
#include "LocalFileService.h"
#include "I_DataConfigLoader.h"
#include "QTemporaryFile"
class Loader_t:public I_DataConfigLoader{
        std::shared_ptr<DataConfig> c  =std::shared_ptr<DataConfig>(new DataConfig);
    public:
        inline Loader_t(QString path){
            c->files.reserve(3);

            QFile f(path+"/good.txt");
            QFile f2(path+"/hello.txt");

            c->files[0].localPath = path+"/good.txt";
            c->files[0].cloudId = "";
            c->files[1].localPath = path+"/hello.txt";
            c->files[1].cloudId = "FileE";
            c->files[2].localPath = path+"/hello.txt";
            c->files[1].cloudId = "FileE"
        inline std::shared_ptr<DataConfig> loadConfig() override{
            return c;
        }
};
class FMP_test:public QObject{
    Q_OBJECT
        std::shared_ptr<I_ServiceManager> manager;
    public:
        inline FMP_test(){};
        inline ~FMP_test(){};
    private slots:
        inline void initTestCase(){
            manager = std::shared_ptr<I_ServiceManager>(new ServiceManager());
            manager->initializeServices();

            manager->setCloudFileService(std::shared_ptr<I_CloudFileService>(new CloudFileService()));
            manager->setLocalFileService(std::shared_ptr<I_LocalFileService>(new LocalFileService));

            manager->setDataConfigLoader(std::shared_ptr<I_DataConfigLoader>(new Loader_t()));
        };
        inline void cleanupTestCase(){};
        inline void init(){};
        inline void cleanup(){};

        inline void testFileLoad(){
            
        }
};
#endif // __FMP_TEST_H__