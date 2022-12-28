#pragma once

#include <SkyrimScripting/Plugin/CallbackEventSink.h>

// TODO: support UI and BSInputDeviceManager events (and others, if any)

namespace SkyrimScripting::Plugin::EventCallback {
    template <typename EventType>
    void On(std::function<void(const EventType*)> callback) {
        RE::ScriptEventSourceHolder::GetSingleton()->AddEventSink<EventType>(
            new CallbackEventSink<EventType>(callback));
    }
}
