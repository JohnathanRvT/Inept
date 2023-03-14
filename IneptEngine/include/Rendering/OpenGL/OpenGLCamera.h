#pragma once

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

namespace IneptEngine::Rendering {
    class OpenGLCamera {
    public:
        OpenGLCamera() : m_position(glm::vec3(0.0f, 0.0f, 3.0f)), m_front(glm::vec3(0.0f, 0.0f, -1.0f)), m_up(glm::vec3(0.0f, 1.0f, 0.0f)),
            m_yaw(-90.0f), m_pitch(0.0f), m_fov(45.0f), m_aspect(16.0f / 9.0f), m_near(0.1f), m_far(100.0f) {
            UpdateVectors();
        }

        void SetPosition(const glm::vec3& position) {
            m_position = position;
        }

        void SetOrientation(float yaw, float pitch) {
            m_yaw = yaw;
            m_pitch = pitch;
            UpdateVectors();
        }

        void SetFOV(float fov) {
            m_fov = fov;
        }

        void SetAspectRatio(float aspect) {
            m_aspect = aspect;
        }

        void SetNearPlane(float nearPlane) {
            m_near = nearPlane;
        }

        void SetFarPlane(float farPlane) {
            m_far = farPlane;
        }

        glm::mat4 GetViewMatrix() const {
            return glm::lookAt(m_position, m_position + m_front, m_up);
        }

        glm::mat4 GetProjectionMatrix() const {
            return glm::perspective(glm::radians(m_fov), m_aspect, m_near, m_far);
        }

        void MoveForward(float distance) {
            m_position += m_front * distance;
        }

        void MoveBackward(float distance) {
            m_position -= m_front * distance;
        }

        void MoveRight(float distance) {
            m_position += m_right * distance;
        }

        void MoveLeft(float distance) {
            m_position -= m_right * distance;
        }

        void MoveUp(float distance) {
            m_position += m_up * distance;
        }

        void MoveDown(float distance) {
            m_position -= m_up * distance;
        }

        void Rotate(float yaw, float pitch) {
            m_yaw += yaw;
            m_pitch += pitch;
            if (m_pitch > 89.0f) {
                m_pitch = 89.0f;
            }
            if (m_pitch < -89.0f) {
                m_pitch = -89.0f;
            }
            UpdateVectors();
        }

    private:
        glm::vec3 m_position;
        glm::vec3 m_front;
        glm::vec3 m_up;
        glm::vec3 m_right;

        float m_yaw;
        float m_pitch;
        float m_fov;
        float m_aspect;
        float m_near;
        float m_far;

        void UpdateVectors() {
            glm::vec3 front;
            front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
            front.y = sin(glm::radians(m_pitch));
            front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
            m_front = glm::normalize(front);
            m_right = glm::normalize(glm::cross(m_front, glm::vec3(0.0f, -1.0f, 0.0f)));
            m_up = glm::normalize(glm::cross(m_right, m_front));
        }
    };
}