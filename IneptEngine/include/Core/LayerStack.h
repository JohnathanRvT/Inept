#pragma once

#include <Core/Layer.h>

namespace IneptEngine::Core {
    class LayerStack {
    public:
        LayerStack() = default;
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);

        void OnUpdate(float deltaTime);
        void OnRender();
        void OnEvent(Events::Event* event);

        std::vector<Layer*>::iterator begin() { return m_layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_layers.end(); }

    private:
        std::vector<Layer*> m_layers;
        unsigned int m_layerInsertIndex = 0;
    };

    LayerStack::~LayerStack() {
        for (Layer* layer : m_layers) {
            delete layer;
        }
    }

    void LayerStack::PushLayer(Layer* layer) {
        m_layers.emplace(m_layers.begin() + m_layerInsertIndex, layer);
        m_layerInsertIndex++;
        layer->OnAttach();
    }

    void LayerStack::PopLayer(Layer* layer) {
        auto it = std::find(m_layers.begin(), m_layers.begin() + m_layerInsertIndex, layer);
        if (it != m_layers.begin() + m_layerInsertIndex) {
            layer->OnDetach();
            m_layers.erase(it);
            m_layerInsertIndex--;
        }
        layer->OnDetach();
    }

    void LayerStack::PushOverlay(Layer* overlay) {
        m_layers.emplace_back(overlay);
        overlay->OnAttach();
    }

    void LayerStack::PopOverlay(Layer* overlay) {
        auto it = std::find(m_layers.begin() + m_layerInsertIndex, m_layers.end(), overlay);
        if (it != m_layers.end()) {
            overlay->OnDetach();
            m_layers.erase(it);
        }
    }

    void LayerStack::OnUpdate(float deltaTime) {
        for (Layer* layer : m_layers) {
            layer->OnUpdate(deltaTime);
        }
    }

    void LayerStack::OnEvent(Events::Event* event) {
        for (auto it = m_layers.rbegin(); it != m_layers.rend(); ++it) {
           // if (event->Handled) {
          //      break;
           // }
            (*it)->OnEvent(event);
        }
    }

    void LayerStack::OnRender() {
        for (Layer* layer : m_layers) {
            layer->OnRender();
        }
    }
}