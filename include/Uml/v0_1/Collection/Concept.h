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

#include <range/v3/range_traits.hpp>

namespace Uml
{
namespace
{
template <class C, class T = void>
UML_CONCEPT_SPECIFIER bool AnyCollection =
    ranges::Range<C>::value
    && AnyToken<ranges::range_value_type_t<C>, T>;

template <class C, class T = void>
UML_CONCEPT_SPECIFIER bool StrongCollection =
    ranges::Range<C>::value
    && StrongToken<ranges::range_value_type_t<C>, T>;

template <class C, class T = void>
UML_CONCEPT_SPECIFIER bool WeakCollection =
    ranges::Range<C>::value
    && WeakToken<ranges::range_value_type_t<C>, T>;

template <class C, class T = void>
UML_CONCEPT_SPECIFIER bool UnifiedCollection =
    ranges::Range<C>::value
    && UnifiedToken<ranges::range_value_type_t<C>, T>;

template <class C, class T = void>
UML_CONCEPT_SPECIFIER bool StrictCollection =
    ranges::Range<C>::value
    && StrictToken<ranges::range_value_type_t<C>, T>;

template <class C, class T = void>
UML_CONCEPT_SPECIFIER bool UniqueCollection =
    ranges::Range<C>::value
    && UniqueToken<ranges::range_value_type_t<C>, T>;

template <class C, class T = void>
UML_CONCEPT_SPECIFIER bool SharedCollection =
    ranges::Range<C>::value
    && SharedToken<ranges::range_value_type_t<C>, T>;
} // namespace
} // namespace Uml
