#pragma once 

#include <iepch.h>

#include <Events/Event.h>
#include <Events/ApplicationEvent.h>
#include <Events/WindowEvent.h>
#include <Events/KeyboardEvent.h>
#include <Events/MouseEvent.h>

#define EVENT_SUBSCRIBE(eventType, eventHandler) \
    IneptEngine::Events::EventBus::GetInstance().Subscribe(IneptEngine::Events::EventType::eventType,std::bind(eventHandler, std::placeholders::_1))

#define EVENT_SUBSCRIBE_CATEGORY(eventCategory, eventHandler) \
    IneptEngine::Events::EventBus::GetInstance().Subscribe<IneptEngine::Events::EventCategory::eventCategory>(std::bind(eventHandler, std::placeholders::_1))

#define EVENT_PUBLISH(eventType, ...) \
    IneptEngine::Events::EventBus::GetInstance().Publish(new IneptEngine::Events::eventType(__VA_ARGS__))

#define EVENT_PUBLISH_NOW(eventType, ...) \
    IneptEngine::Events::EventBus::GetInstance().PublishNow(new IneptEngine::Events::eventType(__VA_ARGS__))

#define EVENT_PROCESS() \
    IneptEngine::Events::EventBus::GetInstance().ProcessEvents()

namespace IneptEngine::Events
{
    /**
    * @brief Represents a subscription to an event type or category
    */
    using EventHandler = std::function<void(Event*)>;
    struct Subscription {
    public:
        EventType type;
        EventCategory category;
        EventHandler handler;
        Subscription(EventType type, EventCategory category, EventHandler handler):type(type),category(category),handler(handler) {}

        bool operator==(const Subscription& other) const {
            return (type == other.type) && (category == other.category) && (handler.target<EventHandler>() == other.handler.target<EventHandler>());
        }
    };

    /**
    * @class EventBus
    * @brief Manages the delivery of events to subscribed event handlers
    *
    * The EventBus class provides an implementation of the observer pattern for events.
    * It allows event handlers to be subscribed to specific event types or categories, and then
    * publishes events to all subscribed handlers.
    *
    * The class is designed to be thread-safe, so that it can be used in a multithreaded environment.
    */

    class EventBus {
    public:
        /**
        * @brief Returns the singleton instance of the EventBus.
        * @return EventBus& - Reference to the singleton instance.
        */
        static EventBus& GetInstance() {
            static EventBus instance;
            return instance;
        }

        /**
         * @brief Subscribes a function to an event type
         *
         * This function subscribes a specified event handler function to a specific event type.
         * The handler will be called whenever an event of the specified type is published to the bus.
         *
         * @param type The event type to subscribe to
         * @param handler The event handler function
         * @return A reference to a subscription that can be used to unsubscribe the event handler
         */
        Subscription& Subscribe(EventType type, EventHandler handler);

        /**
         * @brief Subscribes a function to an event category
         *
         * This function subscribes a specified event handler function to a specific event category.
         * The handler will be called whenever an event of the specified category is published to the bus.
         *
         * @param category The event category to subscribe to
         * @param handler The event handler function
         * @return A reference to a subscription object that can be used to unsubscribe the event handler
         */
        Subscription& Subscribe(EventCategory category, EventHandler handler);

        /**
         * @brief Check if function has been subscribed to an event type
         *
         * This function will check if the specified handler function has been already subscribed to a specific event type.
         *
         * @param type The event type to check for
         * @param handler The event handler function
         * @return Boolean value indicating if handler is subscribed or not
         */
        bool IsSubscribed(EventType type, EventHandler handler);

        /**
         * @brief Unsubscribes a function from an event type or category
         *
         * This function removes the specified event handler function from the list of subscribers.
         * The function will no longer receive events of the specified type or category.
         *
         * @param subscription The subscription object to unsubscribe
         */
        void Unsubscribe(const Subscription& subscription);

        /**
         * @brief Publishes an event to the event buffer
         *
         * This function adds the specified event to the event buffer, to be processed by all subscribers at a later time.
         *
         * @param event The event to publish
         */
        void Publish(Event* event);

        /**
         * @brief Publishes an event to the subscriptions now
         *
         * This function immediately calls the subscribed event handler functions for the passed event.
         * This can be useful if you need the event handlers to be called immediately and don't want to wait for the event buffer to be processed.
         *
         * @param event The event to publish
         */
        void PublishNow(Event* event);

        /**
         * @brief Process the events in the event buffer
         *
         * This function processes all events in the event buffer, calling all subscribed event handlers for each event.
         * After processing all events, the event buffer is cleared.
         *
         */
        void ProcessEvents();
    private:
        /**
         * @brief Private constructor to prevent use oustide of singleton
         */
        EventBus() = default;

        /**
         * @brief Default destructor
         */
        ~EventBus() = default;

        std::vector<Event*> m_events;
        std::vector<Subscription*> m_subscriptions;

        std::mutex m_subscriptionsMutex;
        std::mutex m_eventsMutex;
    };
} // namespace IneptEngine::Events