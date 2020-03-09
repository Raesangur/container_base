#pragma once
#include "container_base.h"

namespace pel
{
template<typename ItemType>
class container_base;

template<typename ItemType>
class testContainer : container_base<ItemType>
{
    public:
    using SizeType       = typename pel::container_base<ItemType>::SizeType;
    using DifferenceType = typename container_base<ItemType>::DifferenceType;
    using IteratorType   = typename pel::iterator_base<ItemType>;

    testContainer()
    {}
    ~testContainer() override
    {

    }

    constexpr inline ItemType&
    at(const SizeType index) override
    {
        (void)index;
        return a;
    }
    constexpr inline const ItemType&
    at(const SizeType index) const override
    {
        (void)index;
        return a;
    }

    constexpr inline ItemType&
    front() override
    {
        return a;
    }
    constexpr inline ItemType&
    back() override
    {
        return a;
    }
    constexpr inline const ItemType&
    front() const override
    {
        return a;
    }
    constexpr inline const ItemType&
    back() const override
    {
        return a;
    }

    /* Operators */
    constexpr inline ItemType&
    operator[](const SizeType index) override
    {
        (void)index;
        return a;
    }
    constexpr inline const ItemType&
    operator[](const SizeType index) const override
    {
        (void)index;
        return a;
    }

    /* Iterators */
    constexpr inline IteratorType
    begin() noexcept override
    {
        return IteratorType(0);
    }
    constexpr inline IteratorType
    end() noexcept override
    {
        return IteratorType(0);
    }
    constexpr inline const IteratorType
    cbegin() const noexcept override
    {
        return IteratorType(0);
    }
    constexpr inline const IteratorType
    cend() const noexcept override
    {
        return IteratorType(0);
    }

    /* Memory */
    constexpr inline SizeType
    length() const noexcept override
    {
        return 0;
    }
    constexpr inline bool
    is_empty() const noexcept override
    {
        return true;
    }
    constexpr inline bool
    is_not_empty() const noexcept override
    {
        return false;
    }

    /* Misc */
    inline std::string
    to_string() const override
    {
        return std::string("Hello World");
    }


    private:
    ItemType a = 0;
};
}        // namespace pel
