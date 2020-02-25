#pragma once

#include <iterator>

namespace pel
{
template<typename ItemType>
class iterator_base
{
    public:
    /* Using declarations */
    using SizeType = typename pel::container_base<ItemType>::SizeType;
    using DifferenceType =
      typename pel::container_base<ItemType>::DifferenceType;

    using PointerType    = ItemType*;
    using ReferenceType  = ItemType&;
    using PointerTypeRef = PointerType&;

    /* Memory operators */
    [[nodiscard]] inline PointerTypeRef       ptr() noexcept;
    [[nodiscard]] inline const PointerTypeRef ptr() const noexcept;

    [[nodiscard]] inline ReferenceType       operator*();
    [[nodiscard]] inline const ReferenceType operator*() const;

    [[nodiscard]] inline operator PointerType() const noecept;

    /* Arithmetic operators */

    /* Comparison operators */


    private:
    PointerType m_ptr = nullptr;
};

}        // namespace pel
