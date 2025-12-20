#ifndef __FILEID_H__
#define __FILEID_H__
#include "QString"
class IDMaker;
struct fileID {
    friend class IDMaker;
    private:
        long long int id;
    public:
    bool isValid() {
        return id > 0;
    }
    inline bool operator==(const fileID& other) const {
        return id == other.id;
    }
    inline bool operator!=(const fileID& other) const {
        return id != other.id;
    }
    inline bool operator<(const fileID& other) const {
        return id < other.id;
    }
    inline QString toString() const {
        return QString::number(id);
    }
    inline fileID(QString str){
        id = str.toLongLong();
    }
    inline fileID():id(-1){
    }
    [[deprecated("Only use on test")]]
    static fileID fromLongLong(long long int value) {
        fileID fid;
        fid.id = value;
        return fid;
    }
};
#endif // __FILEID_H__