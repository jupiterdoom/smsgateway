#ifndef ISMSGATEWAY
#define ISMSGATEWAY
#include <QObject>
#include <QStringList>

class ISmsGateway : public QObject {
    Q_OBJECT
public:
    enum SmsState {
        Queued,
        Sended,
        Delivered,
        Accepted,
        Rejected,
        Unknown
    };

public:
    ISmsGateway(const QString &gatewayId, const QString &gatewayName, QObject *parent) :
        QObject(parent), mGatewayId(gatewayId), mGatewayName(gatewayName) {}
    virtual ~ISmsGateway() {}
    virtual void sendSms(const QString &smsId, const quint16 priority, const QString &recepient, const QString &smsText, const QString &sender = QString()) = 0;
    virtual void requestBalance(const QString &phone = QString()) = 0;
    virtual bool isConnected() const = 0;
    virtual void connectToGateway() = 0;
    virtual void disconnectFromGateway() = 0;

    void addSender(const QString &sender) {mSenders.append(sender);}
    void removeSender(const QString &sender) {mSenders.removeAll(sender);}
    QStringList senders() const {return mSenders;}

    QString gatewayId() const {return mGatewayId;}
    QString gatewayName() const {return mGatewayName;}

signals:
    void incomingSms(const QString &gatewayId, const QString &from, const QString &to, const QString &smsText);
    void incomingRing(const QString &gatewayId, const QString &from, const QString &to);
    void smsStatusChanged(const QString &gatewayId, const QString smsId, ISmsGateway::SmsState state);
    void infoMessage(const QString &gatewayName, const QString &message);
    void gatewayConnected();
    void gatewayDisconnected();

private:
    const QString mGatewayId;
    const QString mGatewayName;
    QStringList mSenders;
};

#endif // ISMSGATEWAY
