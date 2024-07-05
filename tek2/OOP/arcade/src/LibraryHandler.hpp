/*
** EPITECH PROJECT, 2021
** LibraryLoader.hpp
** File description:
** LibraryLoader
*/

#ifndef LIBRARY_LOADER_HPP_
#define LIBRARY_LOADER_HPP_

#include <string>
#include <memory>

#include "api.h"
#include "ILibrary.hpp"

namespace arcade {
    namespace lib {
        class LibHandler {
        public:
            arcade::lib::ILibrary *lib;

            explicit LibHandler(const std::string &filepath);
            ~LibHandler();
            void generateInfo();
            library_info_t getInfo();
        private:
            library_info_t m_info;
            void *m_handle;
            void (*m_library_delete)(void *);
            void *(*m_library_create)();
            library_info_t (*m_library_data)();
            void *loadFunction(const std::string &functionName);
        };
    }
}

#endif /* !LIBRARY_LOADER_HPP_ */
