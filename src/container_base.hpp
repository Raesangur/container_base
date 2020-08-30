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
    container_base() = default;

    container_base(const container_base& copy_) = default;
    container_base& operator=(const container_base& copy_) = default;

    container_base(container_base&& move_) noexcept = default;
    container_base& operator=(container_base&& move_) noexcept = default;

    virtual ~container_base() = default;


    /*********************************************************************************************/
    /* Element accessors ----------------------------------------------------------------------- */
    [[nodiscard]] virtual ItemType&       at(SizeType index_)                      = 0;
    [[nodiscard]] virtual const ItemType& at(SizeType index_) const                = 0;
    [[nodiscard]] virtual IteratorType    iterator_at(DifferenceType index_) const = 0;

    [[nodiscard]] virtual ItemType&       front()       = 0;
    [[nodiscard]] virtual ItemType&       back()        = 0;
    [[nodiscard]] virtual const ItemType& front() const = 0;
    [[nodiscard]] virtual const ItemType& back() const  = 0;

    [[nodiscard]] virtual DifferenceType index_of(IteratorType iterator_) const = 0;


    /*********************************************************************************************/
    /* Operator overloads ---------------------------------------------------------------------- */
    [[nodiscard]] virtual ItemType&       operator[](SizeType index_)       = 0;
    [[nodiscard]] virtual const ItemType& operator[](SizeType index_) const = 0;

    [[nodiscard]] virtual bool operator==(const container_base& other_) const = 0;
    [[nodiscard]] virtual bool operator!=(const container_base& other_) const = 0;
    [[nodiscard]] virtual bool operator<(const container_base& other_) const  = 0;
    [[nodiscard]] virtual bool operator>(const container_base& other_) const  = 0;
    [[nodiscard]] virtual bool operator<=(const container_base& other_) const = 0;
    [[nodiscard]] virtual bool operator>=(const container_base& other_) const = 0;
#ifdef __cpp_impl_three_way_comparison
    [[nodiscard]] virtual std::strong_ordering operator<=>(const container_base& other_) const = 0;
#endif


    /*********************************************************************************************/
    /* Iterators ------------------------------------------------------------------------------- */
    [[nodiscard]] virtual IteratorType        begin() const noexcept   = 0;
    [[nodiscard]] virtual IteratorType        end() const noexcept     = 0;
    [[nodiscard]] virtual const IteratorType  cbegin() const noexcept  = 0;
    [[nodiscard]] virtual const IteratorType  cend() const noexcept    = 0;
    [[nodiscard]] virtual RIteratorType       rbegin() const noexcept  = 0;
    [[nodiscard]] virtual RIteratorType       rend() const noexcept    = 0;
    [[nodiscard]] virtual const RIteratorType crbegin() const noexcept = 0;
    [[nodiscard]] virtual const RIteratorType crend() const noexcept   = 0;


    /*********************************************************************************************/
    /* Memory ---------------------------------------------------------------------------------- */
    [[nodiscard]] virtual SizeType             length() const noexcept        = 0;
    [[nodiscard]] virtual bool                 is_empty() const noexcept      = 0;
    [[nodiscard]] virtual bool                 is_not_empty() const noexcept  = 0;
    [[nodiscard]] virtual const AllocatorType& get_allocator() const noexcept = 0;

    virtual void clear() = 0;


    /*********************************************************************************************/
    /* Misc ------------------------------------------------------------------------------------ */
    [[nodiscard]] virtual std::string to_string() const = 0;


    /*********************************************************************************************/
    /* Variables ------------------------------------------------------------------------------- */
    protected:
    IteratorType  m_beginIterator = IteratorType(nullptr);
    IteratorType  m_endIterator   = IteratorType(nullptr);
    AllocatorType m_allocator {};
};

}        // namespace pel
