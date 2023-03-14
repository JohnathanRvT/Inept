#pragma once

#include <Rendering/Polygon.h>
#include <Rendering/OpenGl/OpenGLShader.h>

#include <vector>
#include <glad/glad.h>

namespace IneptEngine::Rendering {
    class OpenGLPolygon : public Polygon {
    public:
        OpenGLPolygon(std::vector<float> vertices, std::vector<unsigned int> indices) : Polygon(vertices, indices) {
            m_shader = new OpenGLShader();
            if (m_shader->LoadShader("shaders\\OpenGL\\vert.shader", "shaders\\OpenGL\\frag.shader")) {
                LOG_DEBUG("Shaders compiled and linked");
            }
        }
        virtual ~OpenGLPolygon() {}

        virtual OpenGLShader* GetShader() { return m_shader; }

        virtual void Bind() override;
        virtual void Unbind() override;
        virtual void Render() override;
    private:
        GLuint m_VertexArray, m_VertexBuffer, m_IndexBuffer;

        OpenGLShader* m_shader; // Move to renderable as shader(base)
    };

    inline void OpenGLPolygon::Bind() {
        m_shader->Bind();

        // Vertex array
        glGenVertexArrays(1, &m_VertexArray);
        glBindVertexArray(m_VertexArray);

        // Vertex buffer
        glGenBuffers(1, &m_VertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

        glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(float), m_Vertices.data(), GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);

        // Index buffer
        glGenBuffers(1, &m_IndexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(unsigned int), m_Indices.data(), GL_STATIC_DRAW);
    }

    inline  void OpenGLPolygon::Unbind() {
        m_shader->Unbind();
        // TODO: Unbind vertex buffer and index buffer
    }

    inline void OpenGLPolygon::Render() {
        glBindVertexArray(m_VertexArray);
        glDrawElements(GL_TRIANGLES, m_Indices.size(), GL_UNSIGNED_INT, nullptr);
    }

} // namespace IneptEngine::Rendering
