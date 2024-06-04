#include "EventCreepDelegates.h"

void EventCreepDelegates::onCreepKilled(const std::function<void()>& listener) {
    creepKilledHandler.addListener(listener);
}

void EventCreepDelegates::onCreepReachedBase(const std::function<void()>& listener) {
    creepReachedBaseHandler.addListener(listener);
}

void EventCreepDelegates::onCreepReturnToPool(const std::function<void()>& listener) {
    creepReturnToPoolHandler.addListener(listener);
}

void EventCreepDelegates::notifyCreepKilled() {
    creepKilledHandler.notifyListeners();
}

void EventCreepDelegates::notifyCreepReachedBase() {
    creepReachedBaseHandler.notifyListeners();
}

void EventCreepDelegates::notifyCreepReturnToPool() {
    creepReturnToPoolHandler.notifyListeners();
}
