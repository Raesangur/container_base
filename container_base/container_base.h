#pragma once

#include "iterator_base.h"
#include <iterator>
#include <stdlib.h>
#include <string>
#include <memory>

namespace pel
{

template<typename ItemType,
         template<typename> typename IteratorType = pel::iterator_base>
class container_base
{
public:
    using SizeType = std::size_t;
    using DifferenceType = std::ptrdiff_t;

    /* Element accessors */
    virtual constexpr inline ItemType& at(const SizeType index) const = 0;
    virtual constexpr inline const ItemType& at(const SizeType index) const = 0;

    virtual constexpr inline ItemType& front() const = 0;
    virtual constexpr inline ItemType& back() const = 0;
    virtual constexpr inline const ItemType& front() const = 0;
    virtual constexpr inline const ItemType& back() const = 0;


    /* Operators */
    virtual constexpr inline ItemType& operator[](const SizeType index) const = 0;
    virtual constexpr inline const ItemType& operator[](const SizeType index) const = 0;


    /* Iterators */
    virtual constexpr inline IteratorType<ItemType> begin() const noexcept = 0;
    virtual constexpr inline IteratorType<ItemType> end()   const noexcept = 0;
    virtual constexpr inline const IteratorType<ItemType> cbegin() const noexcept = 0;
    virtual constexpr inline const IteratorType<ItemType> cend()   const noexcept = 0;
    virtual constexpr inline std::reverse_iterator<IteratorType<ItemType>> rbegin() const noexcept = 0;
    virtual constexpr inline std::reverse_iterator<IteratorType<ItemType>> rend()   const noexcept = 0;
    virtual constexpr inline const std::reverse_iterator<IteratorType<ItemType>> crbegin() const noexcept = 0;
    virtual constexpr inline const std::reverse_iterator<IteratorType<ItemType>> crend()   const noexcept = 0;

    /* Memory */
    virtual constexpr inline SizeType length() const noexcept = 0;
    virtual constexpr inline bool isEmpty() const noexcept = 0;

    /* Misc */
    virtual constexpr inline std::string to_string() const = 0;
};

}