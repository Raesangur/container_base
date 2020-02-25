#pragma once

#include "iterator_base.h"
#include <iterator>
#include <memory>
#include <stdlib.h>
#include <string>

namespace pel
{

template<typename ItemType,
         template<typename> typename IteratorType = pel::iterator_base>
class container_base
{
    public:
    using SizeType       = typename std::size_t;
    using DifferenceType = typename std::ptrdiff_t;

    /* Element accessors */
    virtual inline ItemType&       at(const SizeType index)       = 0;
    virtual inline const ItemType& at(const SizeType index) const = 0;

    virtual inline ItemType&       front()       = 0;
    virtual inline ItemType&       back()        = 0;
    virtual inline const ItemType& front() const = 0;
    virtual inline const ItemType& back() const  = 0;


    /* Operators */
    virtual inline ItemType&       operator[](const SizeType index)       = 0;
    virtual inline const ItemType& operator[](const SizeType index) const = 0;


    /* Iterators */
    virtual inline IteratorType<ItemType>       begin() noexcept        = 0;
    virtual inline IteratorType<ItemType>       end() noexcept          = 0;
    virtual inline const IteratorType<ItemType> cbegin() const noexcept = 0;
    virtual inline const IteratorType<ItemType> cend() const noexcept   = 0;

    /* Memory */
    virtual inline SizeType length() const noexcept  = 0;
    virtual inline bool     isEmpty() const noexcept = 0;

    /* Misc */
    virtual inline std::string to_string() const = 0;
};

}        // namespace pel
