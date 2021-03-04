#ifndef IABLETONOTIFY_H
#define IABLETONOTIFY_H

#include <memory>

#include <notificationbox.h>

class IAbleToNotify
{
public:
    IAbleToNotify();

    void set_notification_box(std::shared_ptr<NotificationBox> box);

protected:
    std::shared_ptr<NotificationBox> _box;
};

#endif // IABLETONOTIFY_H
