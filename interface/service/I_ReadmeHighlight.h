#ifndef __I_READMEHIGHLIGHT_H__
#define __I_READMEHIGHLIGHT_H__
#include <qcontainerfwd.h>
class I_ReadmeHighlight
{
public:
    virtual ~I_ReadmeHighlight() = default;
    virtual QString highlightCode(const QString& codeContent, const QString& language) = 0;
};

#endif // __I_READMEHIGHLIGHT_H__