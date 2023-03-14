#pragma once

#include <Rendering/OpenGL/OpenGLPolygon.h>

#include <glm.hpp>

namespace IneptEngine::Rendering {
    class Square {
    public:
        Square(glm::vec2 position, float size) {
            // Create a square with vertices centered at (x, y) and with sides of length size
            float halfSize = size / 2.0f;

            std::vector<float> vertices = {
                position.x - halfSize, position.y - halfSize, 0.0f,
                position.x + halfSize, position.y - halfSize, 0.0f,
                position.x + halfSize, position.y + halfSize, 0.0f,
                position.x - halfSize, position.y + halfSize, 0.0f
            };

            std::vector<unsigned int> indices = {
                0, 1, 2,
                2, 3, 0
            };

            m_polygon = new OpenGLPolygon(vertices, indices);
        }

        virtual ~Square() {}

        virtual OpenGLShader* GetShader() { return m_polygon->GetShader(); }

        virtual void Bind() { m_polygon->Bind(); }
        virtual void Unbind() { m_polygon->Unbind(); }
        virtual void Render() { m_polygon->Render(); }
    private:
        OpenGLPolygon* m_polygon;
    };
} // namespace IneptEngine::Rendering
