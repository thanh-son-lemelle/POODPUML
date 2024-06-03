#include "Event.h"
#include <algorithm>

void Event::addListener(const std::function<void()>& listener) {
    listeners.push_back(listener);
}

void Event::removeListener(const std::function<void()>& listener) {
    auto it = std::remove_if(listeners.begin(), listeners.end(),
                             [&listener](const std::function<void()>& l) {
                                 // Compare the target function pointers
                                 return l.target<void()>() == listener.target<void()>();
                             });
    if (it != listeners.end()) {
        listeners.erase(it, listeners.end());
    }
}

void Event::notifyListeners() {
    for (const auto& listener : listeners) {
        listener();
    }
}
