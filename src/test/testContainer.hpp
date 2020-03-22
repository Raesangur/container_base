#pragma once
#include "src/container_base.h"

namespace pel
{
template<typename ItemType>
class container_base;

template<typename ItemType>
class testContainer : container_base<ItemType>
{
    public:
    using SizeType       = typename pel::container_base<ItemType>::SizeType;
    using DifferenceType = typename pel::container_base<ItemType>::DifferenceType;
    using IteratorType   = typename pel::container_base<ItemType>::IteratorType;

    testContainer()           = default;

    testContainer(const testContainer&) = default;
    testContainer& operator=(const testContainer&) = default;

    testContainer(testContainer&&) noexcept = default;
    testContainer& operator=(testContainer&&) noexcept = default;
    ~testContainer() override = default;

    [[nodiscard]] inline ItemType&
    at(const SizeType index) override
    {
        (void)index;
        return a;
    }
    [[nodiscard]] inline const ItemType&
    at(const SizeType index) const override
    {
        (void)index;
        return a;
    }

    [[nodiscard]] inline ItemType&
    front() override
    {
        return a;
    }
    [[nodiscard]] inline ItemType&
    back() override
    {
        return a;
    }
    [[nodiscard]] inline const ItemType&
    front() const override
    {
        return a;
    }
    [[nodiscard]] inline const ItemType&
    back() const override
    {
        return a;
    }

    /* Operators */
    [[nodiscard]] inline ItemType&
    operator[](const SizeType index) override
    {
        (void)index;
        return a;
    }
    [[nodiscard]] inline const ItemType&
    operator[](const SizeType index) const override
    {
        (void)index;
        return a;
    }

    /* Iterators */
    [[nodiscard]] inline IteratorType&
    begin() noexcept override
    {
        return m_begin;
    }
    [[nodiscard]] inline IteratorType&
    end() noexcept override
    {
        return m_end;
    }
    [[nodiscard]] inline const IteratorType&
    cbegin() const noexcept override
    {
        return m_begin;
    }
    [[nodiscard]] inline const IteratorType&
    cend() const noexcept override
    {
        return m_end;
    }

    /* Memory */
    [[nodiscard]] inline SizeType
    length() const noexcept override
    {
        return 0;
    }
    [[nodiscard]] inline bool
    is_empty() const noexcept override
    {
        return true;
    }
    [[nodiscard]] inline bool
    is_not_empty() const noexcept override
    {
        return false;
    }

    /* Misc */
    [[nodiscard]] inline std::string
    to_string() const override
    {
        return std::string("Hello World");
    }


    private:
    ItemType a = 0;
    IteratorType m_begin = IteratorType{nullptr};
    IteratorType m_end   = IteratorType{nullptr};
};
}        // namespace pel
