#ifndef EVENT_H
#define EVENT_H

#include <vector>
#include <functional>

class Event
{
public:
    using Listener = std::function<void()>;

    void addListener(const Listener& listener);
    void removeListener(const Listener& listener);
    void notifyListeners() const;

private:
    std::vector<Listener> listeners;
 };

#endif // EVENT_H
