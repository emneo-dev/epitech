/*
** EPITECH PROJECT, 2021
** LibraryLoader.cpp
** File description:
** LibraryLoader
*/

#include <stdexcept>
#include <dlfcn.h>
#include <iostream>

#include "LibraryHandler.hpp"

namespace arcade {
    namespace lib {
        LibHandler::~LibHandler()
        {
            this->m_library_delete(this->lib);
            dlclose(this->m_handle);
        }

        void LibHandler::generateInfo()
        {
            this->m_info = this->m_library_data();
        }

        void *LibHandler::loadFunction(const std::string &functionName)
        {
            void *functionPtr = dlsym(this->m_handle, functionName.c_str());
            if (!functionPtr)
                throw std::runtime_error("Could not load function '" + functionName + "' from shared library :\n" + dlerror());
            return functionPtr;
        }

        LibHandler::LibHandler(const std::string &filepath) {
            if (filepath.length() == 0)
                throw std::invalid_argument("filepath is empty");
            this->m_handle = dlopen(filepath.c_str(), RTLD_LAZY);
            if (!this->m_handle)
                throw std::runtime_error("Could not open the shared library at " + filepath + " :\n" + dlerror());

            this->m_library_create = (void *(*)())this->loadFunction("library_create");
            this->m_library_delete = (void (*)(void *))this->loadFunction("library_delete");
            this->m_library_data = (library_info_t (*)())this->loadFunction("library_get_data");

            this->generateInfo();
            this->lib = (arcade::lib::ILibrary *)m_library_create();
        }

        library_info_t LibHandler::getInfo() {
            return this->m_info;
        }
    }
}