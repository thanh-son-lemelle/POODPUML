#include "Event.h"
#include <algorithm>

void Event::addListener(const Listener& listener) {
    listeners.push_back(listener);
}

void Event::removeListener(const Listener& listener) {
    listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
}

void Event::notifyListeners() const {
    for (const auto& listener : listeners) {
        listener();
    }
}
