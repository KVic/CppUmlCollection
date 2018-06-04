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

#include <Uml/v0_1/Token/Iterator.h>

#include <Uml/v0_1/Token/Detail/Counted/Counted.h>

namespace Uml
{
inline namespace v0_1
{
namespace detail
{
namespace counted
{
template <class T, class Multiplicity>
inline Token::Iterator<shared<T, Multiplicity>>
begin(shared<T, Multiplicity>& token) noexcept (internal::IsOptional<Multiplicity>)
{ return Token::Iterator<shared<T, Multiplicity>>{token}; }

template <class T, class Multiplicity>
inline Token::Iterator<unique<T, Multiplicity>>
begin(unique<T, Multiplicity>& token) noexcept (internal::IsOptional<Multiplicity>)
{ return Token::Iterator<unique<T, Multiplicity>>{token}; }

template <class T, class Multiplicity>
inline Token::Iterator<unified<T, Multiplicity>>
begin(unified<T, Multiplicity>& token) noexcept (internal::IsOptional<Multiplicity>)
{ return Token::Iterator<unified<T, Multiplicity>>{token}; }

template <class T, class Multiplicity>
inline Token::Iterator<weak<T, Multiplicity>>
begin(weak<T, Multiplicity>& token) noexcept (internal::IsOptional<Multiplicity>)
{ return Token::Iterator<weak<T, Multiplicity>>{token}; }

template <class T, class Multiplicity>
inline Token::Iterator<shared<T, Multiplicity>>
end(shared<T, Multiplicity>&) noexcept (internal::IsOptional<Multiplicity>)
{ return Token::Iterator<shared<T, Multiplicity>>{}; }

template <class T, class Multiplicity>
inline Token::Iterator<unique<T, Multiplicity>>
end(unique<T, Multiplicity>&) noexcept (internal::IsOptional<Multiplicity>)
{ return Token::Iterator<unique<T, Multiplicity>>{}; }

template <class T, class Multiplicity>
inline Token::Iterator<unified<T, Multiplicity>>
end(unified<T, Multiplicity>&) noexcept (internal::IsOptional<Multiplicity>)
{ return Token::Iterator<unified<T, Multiplicity>>{}; }

template <class T, class Multiplicity>
inline Token::Iterator<weak<T, Multiplicity>>
end(weak<T, Multiplicity>&) noexcept (internal::IsOptional<Multiplicity>)
{ return Token::Iterator<weak<T, Multiplicity>>{}; }
} // namespace counted
} // namespace detail
} // namespace v0_1
} // namespace Uml
