#pragma once

#include <vector>

#include <Rendering/Renderable.h>

namespace IneptEngine::Rendering {
        class Polygon : public Renderable {
        public:
            Polygon(std::vector<float> vertices, std::vector<unsigned int> indices) :
                m_Vertices(vertices), m_Indices(indices) {}
            virtual ~Polygon() {}

            virtual void Bind() = 0;
            virtual void Unbind() = 0;
        protected:
            std::vector<float> m_Vertices;
            std::vector<unsigned int> m_Indices;
        };
} // namespace IneptEngine::Rendering

			/*    X      Y     Z
			std::vector<float> vertices = {
				-0.5f, -0.5f, 0.0f,
				 0.5f, -0.5f, 0.0f,
				 0.0f,  0.5f, 0.0f
			};
			
			
				 Y
			+1   |
				 |
				 |           *{0,-0.5}
				 |
			0    |
				 |
				 |  {-0.5,-0.5}     {0.5,-0.5}
				 |    *             *
			-1   |_______________________X
				 -1           0         +1
			
			std::vector<unsigned int> indices = { 0, 1, 2 };
			
				 Y
			+1   |
				 |           2
				 |           *
				 |
			0    |   counter clockwise
				 |
				 |    0             1
				 |    *             *
			-1   |_______________________X
				 -1           0         +1
			*/