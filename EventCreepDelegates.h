#ifndef EVENTCREEPDELEGATES_H
#define EVENTCREEPDELEGATES_H

#include "Event.h"
#include <functional>

class EventCreepDelegates {
public:
    void onCreepKilled(const std::function<void()>& listener);
    void onCreepReachedBase(const std::function<void()>& listener);
    void onCreepReturnToPool(const std::function<void()>& listener);

    void notifyCreepKilled();
    void notifyCreepReachedBase();
    void notifyCreepReturnToPool();

private:
    Event creepKilledHandler;
    Event creepReachedBaseHandler;
    Event creepReturnToPoolHandler;
};

#endif // EVENTCREEPDELEGATES_H
