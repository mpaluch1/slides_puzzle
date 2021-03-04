#include "iabletonotify.h"

IAbleToNotify::IAbleToNotify()
{

}

void IAbleToNotify::set_notification_box(std::shared_ptr<NotificationBox> box)
{
    _box = box;
}
