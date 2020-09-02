/**
 * \file
 * \author  Pascal-Emmanuel Lachance
 * \p       https://www.github.com/Raesangur
 * ------------------------------------------------------------------------------------------------
 * MIT License
 * Copyright (c) 2020 Pascal-Emmanuel Lachance | Ràësangür
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#pragma once


/*************************************************************************************************/
/* File includes ------------------------------------------------------------------------------- */
#include "./iterator_base.hpp"

#include <cstddef>
#include <iterator>
#include <memory>
#include <string>



namespace pel
{
template<typename ItemType,
         typename IteratorType  = typename pel::iterator_base<ItemType>,
         typename AllocatorType = std::allocator<ItemType>>
class container_base
{
    static_assert(std::is_same_v<ItemType, typename AllocatorType::value_type>,
                  "Allocator must match element type");


    /*********************************************************************************************/
    /* Type definitions ------------------------------------------------------------------------ */
public:
    using AllocatorTraits = std::allocator_traits<AllocatorType>;
    using SizeType        = std::size_t;
    using DifferenceType  = std::ptrdiff_t;
    using RIteratorType   = typename IteratorType::ReverseIteratorType;


    /*********************************************************************************************/
    /* Constructors ---------------------------------------------------------------------------- */
public:
    constexpr container_base(const AllocatorType& alloc_ = AllocatorType{}) : m_allocator{alloc_}
    {
    }

    virtual ~container_base() = default;


    /*********************************************************************************************/
    /* Element accessors ----------------------------------------------------------------------- */
    [[nodiscard]] constexpr ItemType&       at(SizeType index_);
    [[nodiscard]] constexpr const ItemType& at(SizeType index_) const;
    [[nodiscard]] constexpr IteratorType    iterator_at(DifferenceType index_) const;

    [[nodiscard]] constexpr ItemType&       front();
    [[nodiscard]] constexpr ItemType&       back();
    [[nodiscard]] constexpr const ItemType& front() const;
    [[nodiscard]] constexpr const ItemType& back() const;

    [[nodiscard]] constexpr virtual DifferenceType index_of(IteratorType iterator_) const;


    /*********************************************************************************************/
    /* Operator overloads ---------------------------------------------------------------------- */
    [[nodiscard]] constexpr virtual ItemType&       operator[](SizeType index_);
    [[nodiscard]] constexpr virtual const ItemType& operator[](SizeType index_) const;


    /*********************************************************************************************/
    /* Iterators ------------------------------------------------------------------------------- */
    [[nodiscard]] constexpr IteratorType        begin() const noexcept;
    [[nodiscard]] constexpr IteratorType        end() const noexcept;
    [[nodiscard]] constexpr const IteratorType  cbegin() const noexcept;
    [[nodiscard]] constexpr const IteratorType  cend() const noexcept;
    [[nodiscard]] constexpr RIteratorType       rbegin() const noexcept;
    [[nodiscard]] constexpr RIteratorType       rend() const noexcept;
    [[nodiscard]] constexpr const RIteratorType crbegin() const noexcept;
    [[nodiscard]] constexpr const RIteratorType crend() const noexcept;


    /*********************************************************************************************/
    /* Memory ---------------------------------------------------------------------------------- */
    [[nodiscard]] constexpr SizeType             length() const noexcept;
    [[nodiscard]] constexpr bool                 is_empty() const noexcept;
    [[nodiscard]] constexpr bool                 is_not_empty() const noexcept;
    [[nodiscard]] constexpr const AllocatorType& get_allocator() const noexcept;

    constexpr void clear();


    /*********************************************************************************************/
    /* Misc ------------------------------------------------------------------------------------ */
    [[nodiscard]] virtual std::string to_string() const = 0;


    /*********************************************************************************************/
    /* Private methods ------------------------------------------------------------------------- */
protected:
    constexpr virtual void check_if_valid(IteratorType iterator_) const;

    constexpr void add_size(SizeType addedLength_);
    constexpr void change_size(SizeType newLength_);


    /*********************************************************************************************/
    /* Variables ------------------------------------------------------------------------------- */
protected:
    IteratorType  m_beginIterator = IteratorType(nullptr);
    IteratorType  m_endIterator   = IteratorType(nullptr);
    AllocatorType m_allocator{};

    constexpr static const bool container_safeness = true;
};

/* clang-format off */
#define CONTAINER_BASE_OPERATOR_TEMPLATE_DECLARATION__                                             \
        typename ItemType,                                                                         \
        typename FirstIteratorType   = typename pel::iterator_base<ItemType>,                      \
        typename SecondIteratorType  = typename pel::iterator_base<ItemType>,                      \
        typename FirstAllocatorType  = std::allocator<ItemType>,                                   \
        typename SecondAllocatorType = std::allocator<ItemType>

#define CONTAINER_BASE_OPERATOR_TEMPLATE_DEFINITION__                                              \
        typename ItemType,                                                                         \
        typename FirstIteratorType,                                                                \
        typename SecondIteratorType,                                                               \
        typename FirstAllocatorType,                                                               \
        typename SecondAllocatorType                                         

#define CONTAINER_BASE_OPERATOR_ARGUMENTS__                                                        \
        const container_base<ItemType, FirstIteratorType, FirstAllocatorType>&   lhs_,             \
        const container_base<ItemType, SecondIteratorType, SecondAllocatorType>& rhs_
/* clang-format off */

template<CONTAINER_BASE_OPERATOR_TEMPLATE_DECLARATION__>
[[nodiscard]] constexpr bool operator==(CONTAINER_BASE_OPERATOR_ARGUMENTS__);
template<CONTAINER_BASE_OPERATOR_TEMPLATE_DECLARATION__>
[[nodiscard]] constexpr bool operator!=(CONTAINER_BASE_OPERATOR_ARGUMENTS__);
template<CONTAINER_BASE_OPERATOR_TEMPLATE_DECLARATION__>
[[nodiscard]] constexpr bool operator<(CONTAINER_BASE_OPERATOR_ARGUMENTS__);
template<CONTAINER_BASE_OPERATOR_TEMPLATE_DECLARATION__>
[[nodiscard]] constexpr bool operator>(CONTAINER_BASE_OPERATOR_ARGUMENTS__);
template<CONTAINER_BASE_OPERATOR_TEMPLATE_DECLARATION__>
[[nodiscard]] constexpr bool operator<=(CONTAINER_BASE_OPERATOR_ARGUMENTS__);
template<CONTAINER_BASE_OPERATOR_TEMPLATE_DECLARATION__>
[[nodiscard]] constexpr bool operator>=(CONTAINER_BASE_OPERATOR_ARGUMENTS__);
#ifdef __cpp_impl_three_way_comparison
template<CONTAINER_BASE_OPERATOR_TEMPLATE_DECLARATION__>
[[nodiscard]] constexpr std::strong_ordering operator<=>(CONTAINER_BASE_OPERATOR_ARGUMENTS__);
#endif


}        // namespace pel

#include "./container_base.inl"


/*************************************************************************************************/
/* Undefines ----------------------------------------------------------------------------------- */
#undef CONTAINER_BASE_OPERATOR_TEMPLATE_DECLARATION__
#undef CONTAINER_BASE_OPERATOR_TEMPLATE_DEFINITION__
#undef CONTAINER_BASE_OPERATOR_ARGUMENTS__


/*************************************************************************************************/
/* ----- END OF FILE ----- */
