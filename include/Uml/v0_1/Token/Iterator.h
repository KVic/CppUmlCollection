/*
 * MIT License
 *
 * Copyright (c) 2018 Viktor Kireev
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include <Uml/v0_1/Token/Concept.h>
#include <Uml/v0_1/Token/Concrete.h>

#include <iterator>

namespace Uml
{
inline namespace v0_1
{
namespace Token
{
template <class T, class = void>
class Iterator
{};

template <class T>
class Iterator<T, std::enable_if_t<StrongToken<T>>>
{
public:
    using difference_type   = std::ptrdiff_t;
    using value_type        = T;
    using pointer           = value_type *;
    using reference         = value_type &;
    using iterator_category = std::forward_iterator_tag;

    Iterator() = default;
    Iterator(const Iterator&) = default;
    Iterator(T& token) noexcept
        : m_holder{token ? std::addressof(token) : nullptr}
    {}

    reference operator*() const noexcept
    { return *m_holder; }
    Iterator& operator++() noexcept
    { m_holder = nullptr; return *this; }
    Iterator  operator++(int) const noexcept
    { return Iterator{}; }

    bool operator==(const Iterator& other) const noexcept
    { return other.m_holder == m_holder; }
    bool operator!=(const Iterator& other) const noexcept
    { return !operator==(other); }

private:
    pointer m_holder{};
};

template <class T>
class Iterator<T, std::enable_if_t<WeakToken<T>>>
{
public:
    using difference_type   = std::ptrdiff_t;
    using value_type        = Token::UnifiedOptional<Trait::Value<T>>;
    using pointer           = value_type *;
    using reference         = value_type &;
    using iterator_category = std::forward_iterator_tag;

    Iterator() = default;
    Iterator(const Iterator&) = default;
    Iterator(T& token)
        : m_locker{token.lock()}
    {}

    reference operator*() noexcept
    { return m_locker; }
    reference operator*() const noexcept
    { return m_locker; }
    Iterator& operator++() noexcept
    { m_locker = nullptr; return *this; }
    Iterator  operator++(int) const noexcept
    { return Iterator{}; }

    bool operator==(const Iterator& other) const noexcept
    { return other.m_locker == m_locker; }
    bool operator!=(const Iterator& other) const noexcept
    { return !operator==(other); }

private:
    value_type m_locker{};
};
} // namespace Token
} // inline namespace v0_1
} // namespace Uml
