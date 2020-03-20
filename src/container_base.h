#pragma once

#include "src/iterator_base.h"

#include <iterator>
#include <memory>
#include <string>

namespace pel
{

template<typename ItemType>
class container_base
{
    /*------------------------------------*/
    /* Typenames */
    public:
    using SizeType       = typename std::size_t;
    using DifferenceType = typename std::ptrdiff_t;
    using IteratorType   = typename pel::iterator_base<ItemType>;

    /*------------------------------------*/
    /* Constructors & Destructors */
    protected:
    virtual ~container_base()                           = default;

    /*------------------------------------*/
    /* Element accessors */
    [[nodiscard]] virtual ItemType&       at(const SizeType index)       = 0;
    [[nodiscard]] virtual const ItemType& at(const SizeType index) const = 0;

    [[nodiscard]] virtual ItemType&       front()       = 0;
    [[nodiscard]] virtual ItemType&       back()        = 0;
    [[nodiscard]] virtual const ItemType& front() const = 0;
    [[nodiscard]] virtual const ItemType& back() const  = 0;

    /*------------------------------------*/
    /* Operators */
    [[nodiscard]] virtual ItemType&       operator[](const SizeType index)       = 0;
    [[nodiscard]] virtual const ItemType& operator[](const SizeType index) const = 0;

    /*------------------------------------*/
    /* Iterators */
    [[nodiscard]] virtual IteratorType       begin() noexcept        = 0;
    [[nodiscard]] virtual IteratorType       end() noexcept          = 0;
    [[nodiscard]] virtual const IteratorType cbegin() const noexcept = 0;
    [[nodiscard]] virtual const IteratorType cend() const noexcept   = 0;

    /*------------------------------------*/
    /* Memory */
    [[nodiscard]] virtual SizeType length() const noexcept       = 0;
    [[nodiscard]] virtual bool     is_empty() const noexcept     = 0;
    [[nodiscard]] virtual bool     is_not_empty() const noexcept = 0;

    /*------------------------------------*/
    /* Misc */
    [[nodiscard]] virtual std::string to_string() const = 0;
};

}        // namespace pel
