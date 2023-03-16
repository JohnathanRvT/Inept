#pragma once

#include <IneptEngine.h>

namespace IneptEngine::Core {
    class Layer {
    public:
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate(float deltaTime) {}
        virtual void OnRender() {}
        virtual void OnEvent(Events::Event* event) {}
    };
}