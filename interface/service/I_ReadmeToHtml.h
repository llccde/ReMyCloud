#ifndef __I_READMETOHTML_H__
#define __I_READMETOHTML_H__
#include <QString>
class I_ReadmeToHtml
{
public:
    virtual ~I_ReadmeToHtml() = default;
    virtual QString convertMarkdownToHtml(const QString& markdownContent) = 0;


};



#endif // __I_READMETOHTML_H__