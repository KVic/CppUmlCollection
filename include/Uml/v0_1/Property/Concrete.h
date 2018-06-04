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

#include <Uml/v0_1/Token/Concrete.h>
#include <Uml/v0_1/Property/Tag.h>

namespace Uml
{
namespace Property
{
template <class T,
          class Aggregation = Tag::Shared,
          class Multiplicity = Tag::Single>
using Base = Token::Base<T, Aggregation, Multiplicity>;

template <class T, class Multiplicity = Tag::Single>
using Composite = Base<T, Tag::Composite, Multiplicity>;

template <class T, class Multiplicity = Tag::Single>
using Shared = Base<T, Tag::Shared, Multiplicity>;

template <class T, class Multiplicity = Tag::Single>
using Observer = Base<T, Tag::Observer, Multiplicity>;

template <class T>
using CompositeOptional = Composite<T, Tag::Optional>;

template <class T>
using SharedOptional = Shared<T, Tag::Optional>;

template <class T>
using ObserverOptional = Observer<T, Tag::Optional>;

template <class T>
using CompositeSingle = Composite<T, Tag::Single>;

template <class T>
using SharedSingle = Shared<T, Tag::Single>;

template <class T>
using ObserverSingle = Observer<T, Tag::Single>;
} // namespace Property
} // namespace Uml
