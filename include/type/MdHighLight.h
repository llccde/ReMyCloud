#ifndef __MDHIGHLIGHT_H__
#define __MDHIGHLIGHT_H__
#include "QString"
#include "QVector"
#include <qsharedpointer.h>
using token = QString;
struct tokenLight{
    token token;
    struct{
        int r;
        int g;
        int b;
    } color;
};
using MdHighLight = QVector<tokenLight>;
#endif // __MDHIGHLIGHT_H__