#ifndef CONTAINER_BASE_H_
#define CONTAINER_BASE_H_

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
    public:
    container_base() = default;

    container_base(const container_base&) = default;
    container_base& operator=(const container_base&) = default;

    container_base(const container_base&&) noexcept = default;
    container_base& operator=(container_base&&) noexcept = default;

    virtual ~container_base() = default;

    /*------------------------------------*/
    /* Element accessors */
    [[nodiscard]] virtual ItemType&       at(SizeType index)       = 0;
    [[nodiscard]] virtual const ItemType& at(SizeType index) const = 0;

    [[nodiscard]] virtual ItemType&       front()       = 0;
    [[nodiscard]] virtual ItemType&       back()        = 0;
    [[nodiscard]] virtual const ItemType& front() const = 0;
    [[nodiscard]] virtual const ItemType& back() const  = 0;

    /*------------------------------------*/
    /* Operators */
    [[nodiscard]] virtual ItemType&       operator[](SizeType index)       = 0;
    [[nodiscard]] virtual const ItemType& operator[](SizeType index) const = 0;

    /*------------------------------------*/
    /* Iterators */
    [[nodiscard]] virtual IteratorType&       begin() noexcept        = 0;
    [[nodiscard]] virtual IteratorType&       end() noexcept          = 0;
    [[nodiscard]] virtual const IteratorType& cbegin() const noexcept = 0;
    [[nodiscard]] virtual const IteratorType& cend() const noexcept   = 0;

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

#endif        // CONTAINER_BASE_H_
