#pragma once

#include <array>

namespace jlm
{
    class vec2
    {
        public:
            explicit constexpr vec2(float x, float y);

            constexpr float x() const;
            constexpr float y() const;           

        private:
            static constexpr uint32_t Dimension {2};
            union
            {
                struct
                {
                    float mX, mY;
                    /* data */
                };

                std::array<float, Dimension> Scalars {0.0f, 0.0f};
                
                /* data */
            };
            
    };
}