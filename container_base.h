#pragma once

#include "iterator_base.h"

#include <iterator>
#include <memory>
#include <stdlib.h>
#include <string>

namespace pel
{

/* Forward declaration */
template<typename ItemType>
class iterator_base;

template<typename ItemType>
class container_base
{
    protected:
    container_base()                           = default;
    container_base(container_base<ItemType>&)  = default;
    container_base(container_base<ItemType>&&) = default;
    virtual ~container_base()                  = default;

    public:
    using SizeType       = typename std::size_t;
    using DifferenceType = typename std::ptrdiff_t;
    using IteratorType   = typename pel::iterator_base<ItemType>;

    /* Element accessors */
    virtual ItemType&       at(const SizeType index)       = 0;
    virtual const ItemType& at(const SizeType index) const = 0;

    virtual ItemType&       front()       = 0;
    virtual ItemType&       back()        = 0;
    virtual const ItemType& front() const = 0;
    virtual const ItemType& back() const  = 0;


    /* Operators */
    virtual ItemType&       operator[](const SizeType index)       = 0;
    virtual const ItemType& operator[](const SizeType index) const = 0;


    /* Iterators */
    virtual IteratorType       begin() noexcept        = 0;
    virtual IteratorType       end() noexcept          = 0;
    virtual const IteratorType cbegin() const noexcept = 0;
    virtual const IteratorType cend() const noexcept   = 0;

    /* Memory */
    virtual SizeType length() const noexcept       = 0;
    virtual bool     is_empty() const noexcept     = 0;
    virtual bool     is_not_empty() const noexcept = 0;

    /* Misc */
    virtual std::string to_string() const = 0;
};

}        // namespace pel
