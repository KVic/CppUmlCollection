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

#include <Uml/v0_1/Token/Tag.h>
#include <Uml/v0_1/Token/Trait.h>

#include <type_traits>

#if defined (__cpp_concepts)
#define UML_CONCEPT_SPECIFIER concept
#else
#define UML_CONCEPT_SPECIFIER inline constexpr
#endif

namespace Uml
{
inline namespace v0_1
{
namespace Internal
{
namespace
{
template <class P, class T>
UML_CONCEPT_SPECIFIER bool TokenOfValue =
    std::is_same_v<T, void>
    || std::is_base_of_v<T, Trait::Value<P>>;

template <class P>
UML_CONCEPT_SPECIFIER bool BaseToken =
    std::is_base_of_v<Token::Tag::Internal::Base, Trait::Ownership<P>>;

template <class P, class Ownership>
UML_CONCEPT_SPECIFIER bool OwnershipToken =
    std::is_base_of_v<Ownership, Trait::Ownership<P>>;

template <class P, class Multiplicity>
UML_CONCEPT_SPECIFIER bool MultiplicityToken =
    std::is_base_of_v<Multiplicity, Trait::Multiplicity<P>>;
} // namespace
} // namespace Internal

namespace
{
template <class P, class Ownership, class Multiplicity>
UML_CONCEPT_SPECIFIER bool BaseToken =
    (  (  std::is_same_v<Ownership, Token::Tag::Any>
       && Internal::BaseToken<P>)
    || Internal::OwnershipToken<P, Ownership>)
    && (  std::is_same_v<Multiplicity, Token::Tag::Any>
       || Internal::MultiplicityToken<P, Multiplicity>);

template <class P, class T = void>
UML_CONCEPT_SPECIFIER bool AnyToken =
    Internal::BaseToken<P>
    && Internal::TokenOfValue<P, T>;

template <class P, class T = void>
UML_CONCEPT_SPECIFIER bool StrongToken =
    Internal::OwnershipToken<P, Token::Tag::Internal::Strong>
    && Internal::TokenOfValue<P, T>;

template <class P, class T = void>
UML_CONCEPT_SPECIFIER bool WeakToken =
    Internal::OwnershipToken<P, Token::Tag::Internal::Weak>
    && Internal::TokenOfValue<P, T>;

template <class P, class T = void>
UML_CONCEPT_SPECIFIER bool UnifiedToken =
    Internal::OwnershipToken<P, Token::Tag::Unified>
    && Internal::TokenOfValue<P, T>;

template <class P, class T = void>
UML_CONCEPT_SPECIFIER bool StrictToken =
    Internal::OwnershipToken<P, Token::Tag::Internal::Strict>
    && Internal::TokenOfValue<P, T>;

template <class P, class T = void>
UML_CONCEPT_SPECIFIER bool UniqueToken =
    Internal::OwnershipToken<P, Token::Tag::Unique>
    && Internal::TokenOfValue<P, T>;

template <class P, class T = void>
UML_CONCEPT_SPECIFIER bool SharedToken =
    Internal::OwnershipToken<P, Token::Tag::Shared>
    && Internal::TokenOfValue<P, T>;

template <class P, class T = void>
UML_CONCEPT_SPECIFIER bool OptionalToken =
    Internal::BaseToken<P>
    && Internal::MultiplicityToken<P, Token::Tag::Optional>
    && Internal::TokenOfValue<P, T>;

template <class P, class T = void>
UML_CONCEPT_SPECIFIER bool SingleToken =
    Internal::BaseToken<P>
    && Internal::MultiplicityToken<P, Token::Tag::Single>
    && Internal::TokenOfValue<P, T>;
} // namespace
} // inline namespace v0_1
} // namespace Uml
