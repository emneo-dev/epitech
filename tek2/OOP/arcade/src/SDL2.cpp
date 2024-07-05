/*
** EPITECH PROJECT, 2021
** SDL2.cpp
** File description:
** SDL2
*/

#include <iostream>
#include "SDL2.hpp"
#include "api.h"

static const char *lib_name = "libSDL2";

static const char *lib_desc = "Graphics library made by Arcaac using SDL2";

extern "C" {

    void *library_create(void)
    {
        auto *lib = new arcade::lib::SDL2();

        return lib;
    }

    void library_delete(void *library)
    {
        delete (arcade::lib::SDL2 *)library;
    }

    library_info_t library_get_data(void)
    {
        library_info_t info;

        info.desc = lib_desc;
        info.date = time(nullptr);
        info.name = lib_name;
        info.type = library_info::GRAPHIC;
        return info;
    }

}

namespace arcade {

    namespace lib {

        SDL2::SDL2()
        {
            this->m_width = 640;
            this->m_height = 480;
            this->m_renderer = nullptr;
            this->m_window = nullptr;
            this->m_texture = nullptr;
            this->m_quit = false;
        }

        SDL2::~SDL2()
        {
        }

        void SDL2::init(IScene &scene)
        {
            std::cout << "Initialization of the SDL2 attributes" << std::endl;
            this->m_window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, this->m_width, this->m_height, 0);
            if (!this->m_window) {
                std::cerr << "Failed to create " << this->m_width << " x " << this->m_height << " window: " << SDL_GetError() << std::endl;
                return;
            }
            this->m_renderer = SDL_CreateRenderer(this->m_window, -1, SDL_RENDERER_ACCELERATED);
            if (!this->m_renderer) {
                std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
                return;
            }
            this->m_texture = SDL_CreateTexture(this->m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1024, 768);
            if (!this->m_texture) {
                std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
                return;
            }
            // this->m_start = SDL_GetPerformanceCounter();
        }

        void SDL2::update(IScene &scene, float dt)
        {
            // std::cout << "SDL2::update" << std::endl;
        
            while (SDL_PollEvent(&this->m_event))
                if (this->m_event.type == SDL_QUIT)
                    this->m_quit = true;
            SDL_RenderClear(this->m_renderer);
            SDL_RenderCopy(this->m_renderer, this->m_texture, nullptr, nullptr);
            SDL_RenderPresent(this->m_renderer);
            // this->m_end = SDL_GetPerformanceCounter();
            // SDL_Delay(floor(dt - ( (this->m_end - this->m_start) / (float)SDL_GetPerformanceFrequency() * 1000.0f)));
        }

        void SDL2::end(IScene &scene)
        {
            std::cout << "SDL2::end" << std::endl;
            SDL_DestroyTexture(this->m_texture);
            SDL_DestroyRenderer(this->m_renderer);
            SDL_DestroyWindow(this->m_window);
        }

        bool SDL2::quitRequested() const
        {
            return m_quit;
        }
    }

}