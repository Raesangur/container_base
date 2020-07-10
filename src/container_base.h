#ifndef CONTAINER_BASE_H_
#define CONTAINER_BASE_H_

#include "./iterator_base.h"

#include <cstddef>
#include <iterator>
#include <memory>
#include <string>

namespace pel
{
template<typename ItemType, typename IteratorType = typename pel::iterator_base<ItemType>>
class container_base
{
    /*------------------------------------*/
    /* Typenames */
    public:
    using SizeType       = std::size_t;
    using DifferenceType = std::ptrdiff_t;

    /*------------------------------------*/
    /* Constructors & Destructors */
    public:
    container_base() = default;

    container_base(const container_base& copy_) = default;
    container_base& operator=(const container_base& copy_) = default;

    container_base(container_base&& move_) noexcept = default;
    container_base& operator=(container_base&& move_) noexcept = default;

    virtual ~container_base() = default;

    /*------------------------------------*/
    /* Element accessors */
    [[nodiscard]] virtual ItemType&       at(SizeType index_)                = 0;
    [[nodiscard]] virtual const ItemType& at(SizeType index_) const          = 0;
    [[nodiscard]] virtual IteratorType     iterator_at(DifferenceType index_) const = 0;

    [[nodiscard]] virtual ItemType&       front()       = 0;
    [[nodiscard]] virtual ItemType&       back()        = 0;
    [[nodiscard]] virtual const ItemType& front() const = 0;
    [[nodiscard]] virtual const ItemType& back() const  = 0;

    /*------------------------------------*/
    /* Operators */
    [[nodiscard]] virtual ItemType&       operator[](SizeType index_)       = 0;
    [[nodiscard]] virtual const ItemType& operator[](SizeType index_) const = 0;

    /*------------------------------------*/
    /* Iterators */
    [[nodiscard]] virtual IteratorType       begin() const noexcept  = 0;
    [[nodiscard]] virtual IteratorType       end() const noexcept    = 0;
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

#endif        // CONTAINER_BASE_H_
