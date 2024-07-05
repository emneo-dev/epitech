/*
** EPITECH PROJECT, 2021
** Sound.hpp
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include "IComponent.hpp"
#include <cstdint>
#include <memory>
#include <vector>

namespace arcade {

    namespace component {

        struct Sound : public IComponent {
            using Channel = std::vector<std::int16_t>;

            std::shared_ptr<std::vector<Channel>> channel;
            std::uint32_t sampleRate;
            float currentTime;
            float volume;
            bool loop;
        };

    }

}

#endif /* !SOUND_HPP_ */
