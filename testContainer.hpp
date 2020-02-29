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
#pragma warning(suppress : 4100)
    at(const SizeType index) override
    {
        static ItemType a = 0;
        return a;
    }
    constexpr inline const ItemType&
#pragma warning(suppress : 4100)
    at(const SizeType index) const
    {
        static ItemType a = 0;
        return a;
    }

    constexpr inline ItemType&
    front() override
    {
        static ItemType a = 0;
        return a;
    }
    constexpr inline ItemType&
    back() override
    {
        static ItemType a = 0;
        return a;
    }
    constexpr inline const ItemType&
    front() const override
    {
        static ItemType a = 0;
        return a;
    }
    constexpr inline const ItemType&
    back() const override
    {
        static ItemType a = 0;
        return a;
    }

    /* Operators */
    constexpr inline ItemType&
#pragma warning(suppress : 4100)
    operator[](const SizeType index) override
    {
        static ItemType a = 0;
        return a;
    }
    constexpr inline const ItemType&
#pragma warning(suppress : 4100)
    operator[](const SizeType index) const override
    {
        static ItemType a = 0;
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
    constexpr inline std::string
    to_string() const override
    {
        return "Hello World";
    }
};
}        // namespace pel
