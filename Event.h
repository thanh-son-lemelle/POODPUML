#ifndef EVENT_H
#define EVENT_H

#include <vector>
#include <functional>

class Event {
public:
    void addListener(const std::function<void()>& listener);
    void removeListener(const std::function<void()>& listener);
    void notifyListeners();

private:
    std::vector<std::function<void()>> listeners;
};

#endif // EVENT_H
