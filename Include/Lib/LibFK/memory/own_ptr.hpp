/*
* Own_ptr.hpp
* SPDX-Identifier-License: BSD-3-Clause
* Copyright (c) 2024 FoxBSD
*/

#pragma once

#include <Lib/LibC/stddef.h>

namespace FK{
    template <typename T>
    class own_ptr{
        private:
            T* memory_pointer;
        public:
            own_ptr() noexcept : memory_pointer(nullptr) {}
            explicit own_ptr(T* ptr) noexcept : memory_pointer(ptr) {}
            own_ptr(own_ptr&& other) noexcept : memory_pointer(other.release()) {}
            template<typename U> own_ptr(own_ptr<U>&& other) noexcept : memory_pointer(static_cast<T*>(other.release())) {}
            ~own_ptr() noexcept { delete memory_pointer; }

            explicit operator bool() const noexcept { return memory_pointer != nullptr; }

            own_ptr& operator=(own_ptr&& other) noexcept {
            if (this != &other) {
                reset(other.release());
            }
            return *this;
        }

        template<typename U>
        own_ptr& operator=(own_ptr<U>&& other) noexcept {
            if (this != static_cast<void*>(&other)) {
                reset(other.release());
            }
            return *this;
        }

        own_ptr& operator=(T* ptr) noexcept {
            if (memory_pointer != ptr) {
                reset(ptr);
            }
            return *this;
        }

        own_ptr& operator=(nullptr) noexcept {
            reset();
            return *this;
        }

        void reset(T* ptr = nullptr) noexcept {
            if (memory_pointer != ptr) {
                delete memory_pointer;
                memory_pointer = ptr;
            }
        }

        T* release() noexcept {
            T* releasedPtr = memory_pointer;
            memory_pointer = nullptr;
            return releasedPtr;
        }

        T* get() const noexcept { return memory_pointer; }

        T* operator->() const noexcept { return memory_pointer; }
        T& operator*() const noexcept { return *memory_pointer; }
    };

    template<class T, class... Args>
    own_ptr<T> make(Args&&... args) {
        return own_ptr<T>(new T(std::forward<Args>(args)...));
    }
};

using FK::own_ptr;
using FK::make;