#ifndef SMSGATEWAY_H
#define SMSGATEWAY_H

//#include <QObject>
#include <ismsgateway.h>

class smsgateway : public ISmsGateway
{
    Q_OBJECT
public:
    explicit smsgateway(QObject *parent = 0);
    ~smsgateway();

signals:

public slots:
};

#endif // SMSGATEWAY_H
