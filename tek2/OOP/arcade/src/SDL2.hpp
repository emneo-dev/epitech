/*
** EPITECH PROJECT, 2021
** SDL2.hpp
** File description:
** SDL2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include <SDL2/SDL.h>
#include "IGraphic.hpp"

namespace arcade {

    namespace lib {

        class SDL2 : public IGraphic {
            public:
                SDL2();
                ~SDL2();

                void init(IScene &scene) override;
                void update(IScene &scene, float dt) override;
                void end(IScene &scene) override;
                bool quitRequested() const override;

            protected:
            private:
                std::size_t m_width;
                std::size_t m_height;
                SDL_Renderer *m_renderer;
                SDL_Window *m_window;
                SDL_Texture *m_texture;
                SDL_Event m_event;
                Uint64 m_start;
                Uint64 m_end;
                bool m_quit;
        };
    }

}

#endif /* !SDL2_HPP_ */