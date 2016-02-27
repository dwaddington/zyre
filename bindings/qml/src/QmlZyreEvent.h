/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#ifndef QML_ZYRE_EVENT_H
#define QML_ZYRE_EVENT_H

#include <QtQml>

#include <zyre.h>
#include "qml_zyre_plugin.h"


class QmlZyreEvent : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isNULL READ isNULL)
    
public:
    zyre_event_t *self;
    
    QmlZyreEvent() { self = NULL; }
    bool isNULL() { return self == NULL; }
    
    static QObject* qmlAttachedProperties(QObject* object); // defined in QmlZyreEvent.cpp
    
public slots:
    //  Returns event type, as printable uppercase string
    const QString type ();

    //  Return the sending peer's uuid as a string
    const QString peerUuid ();

    //  Return the sending peer's public name as a string
    const QString peerName ();

    //  Return the sending peer's ipaddress as a string
    const QString peerAddr ();

    //  Returns the event headers, or NULL if there are none
    zhash_t *headers ();

    //  Returns value of a header from the message headers   
    //  obtained by ENTER. Return NULL if no value was found.
    const QString header (const QString &name);

    //  Returns the group name that a SHOUT event was sent to
    const QString group ();

    //  Returns the incoming message payload
    zmsg_t *msg ();

    //  Print event to zsys log
    void print ();
};

class QmlZyreEventAttached : public QObject
{
    Q_OBJECT
    QObject* m_attached;
    
public:
    QmlZyreEventAttached (QObject* attached) {
        Q_UNUSED (attached);
    };
    
public slots:
    //  Self test of this class.
    void test (bool verbose);

    //  Constructor: receive an event from the zyre node, wraps zyre_recv.
    //  The event may be a control message (ENTER, EXIT, JOIN, LEAVE) or  
    //  data (WHISPER, SHOUT).                                            
    QmlZyreEvent *construct (QmlZyre *node);

    //  Destructor; destroys an event instance
    void destruct (QmlZyreEvent *qmlSelf);
};


QML_DECLARE_TYPEINFO(QmlZyreEvent, QML_HAS_ATTACHED_PROPERTIES)

#endif
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
