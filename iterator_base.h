#pragma once
#include "container_base.h"

#include <compare>
#include <iterator>

namespace pel
{

/* Forward declaration */
template<typename ItemType>
class container_base;

template<typename ItemType>
class iterator_base
{
    public:
    /*------------------------------------*/
    /* Using declarations */
    using IteratorType = iterator_base<ItemType>;

    using SizeType = typename pel::container_base<ItemType>::SizeType;
    using DifferenceType =
      typename pel::container_base<ItemType>::DifferenceType;

    using PointerType    = ItemType*;
    using ReferenceType  = ItemType&;
    using PointerTypeRef = PointerType&;


    /*------------------------------------*/
    /* Constructors */
    iterator_base()                          = delete;
    iterator_base(iterator_base<ItemType>&)  = default;
    iterator_base(iterator_base<ItemType>&&) = default;
    virtual ~iterator_base()                 = default;

    iterator_base(PointerType pointer) : m_ptr(pointer)
    {
    }


    /*------------------------------------*/
    /* Memory operators */
    [[nodiscard]] PointerTypeRef    ptr() noexcept;
    [[nodiscard]] const PointerType ptr() const noexcept;

    [[nodiscard]] ReferenceType       operator*();
    [[nodiscard]] const ReferenceType operator*() const;

    [[nodiscard]] operator PointerType() const noexcept;

    /*------------------------------------*/
    /* Arithmetic operators */
    void operator=(const PointerType other) noexcept;
    void operator=(const PointerTypeRef other) noexcept;
    void operator=(const IteratorType& other) noexcept;

    [[nodiscard]] virtual IteratorType operator+(DifferenceType rhs) const;
    virtual IteratorType               operator++();
    virtual IteratorType               operator++(int);
    virtual IteratorType               operator+=(DifferenceType rhs);

    [[nodiscard]] virtual IteratorType operator-(DifferenceType rhs) const;
    virtual IteratorType               operator--();
    virtual IteratorType               operator--(int);
    virtual IteratorType               operator-=(DifferenceType rhs);

    /*------------------------------------*/
    /* Comparison operators */
    [[nodiscard]] virtual bool operator==(IteratorType rhs) const noexcept;
    [[nodiscard]] virtual bool operator==(PointerType rhs) const noexcept;

    [[nodiscard]] virtual bool operator!=(IteratorType rhs) const noexcept;
    [[nodiscard]] virtual bool operator!=(PointerType rhs) const noexcept;

    [[nodiscard]] virtual bool operator>(IteratorType rhs) const noexcept;
    [[nodiscard]] virtual bool operator>(PointerType rhs) const noexcept;

    [[nodiscard]] virtual bool operator>=(IteratorType rhs) const noexcept;
    [[nodiscard]] virtual bool operator>=(PointerType rhs) const noexcept;

    [[nodiscard]] virtual bool operator<(IteratorType rhs) const noexcept;
    [[nodiscard]] virtual bool operator<(PointerType rhs) const noexcept;

    [[nodiscard]] virtual bool operator<=(IteratorType rhs) const noexcept;
    [[nodiscard]] virtual bool operator<=(PointerType rhs) const noexcept;

#ifdef __cpp_impl_three_way_comparison
    virtual [[nodiscard]] std::strong_ordering operator<=>(
      IteratorType rhs) const noexcept;
    virtual [[nodiscard]] std::strong_ordering operator<=>(
      PointerType rhs) const noexcept;
#endif

    /*------------------------------------*/
    private:
    PointerType m_ptr = nullptr;
};


/*************************************************************************/
/* IMPLEMENTATION OF METHODS                                             */
/*************************************************************************/
/* Memory operators */
template<typename ItemType>
[[nodiscard]] typename iterator_base<ItemType>::PointerTypeRef
iterator_base<ItemType>::ptr() noexcept
{
    return m_ptr;
}
template<typename ItemType>
[[nodiscard]] const typename iterator_base<ItemType>::PointerType
iterator_base<ItemType>::ptr() const noexcept
{
    return m_ptr;
}

template<typename ItemType>
[[nodiscard]] typename iterator_base<ItemType>::ReferenceType
iterator_base<ItemType>::operator*()
{
    return *ptr();
}
template<typename ItemType>
[[nodiscard]] const typename iterator_base<ItemType>::ReferenceType
iterator_base<ItemType>::operator*() const
{
    return *ptr();
}

template<typename ItemType>
[[nodiscard]] iterator_base<ItemType>::operator PointerType() const noexcept
{
    return ptr();
}


/* Arithmetic operators */
template<typename ItemType>
void
iterator_base<ItemType>::operator=(const PointerType other) noexcept
{
    ptr() = other;
}
template<typename ItemType>
void
iterator_base<ItemType>::operator=(const PointerTypeRef other) noexcept
{
    ptr() = other;
}
template<typename ItemType>
void
iterator_base<ItemType>::operator=(const IteratorType& other) noexcept
{
    ptr() = other.ptr();
}
template<typename ItemType>
[[nodiscard]] typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator+(DifferenceType rhs) const
{
    return IteratorType(ptr() + rhs);
}
template<typename ItemType>
typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator++()
{
    ++ptr();
    return *this;
}
template<typename ItemType>
typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator++(int)
{
    IteratorType temp = *this;
    ptr()++;
    return temp;
}

template<typename ItemType>
typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator+=(DifferenceType rhs)
{
    ptr() += rhs;
    return *this;
}

template<typename ItemType>
[[nodiscard]] typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator-(DifferenceType rhs) const
{
    return IteratorType(ptr() - rhs);
}
template<typename ItemType>
typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator--()
{
    --ptr();
    return *this;
}
template<typename ItemType>
typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator--(int)
{
    IteratorType temp = *this;
    ptr()--;
    return temp;
}
template<typename ItemType>
typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator-=(DifferenceType rhs)
{
    ptr() -= rhs;
    return *this;
}

/* Comparison operators */
template<typename ItemType>
[[nodiscard]] bool
iterator_base<ItemType>::operator==(IteratorType rhs) const noexcept
{
    return ptr() == rhs.ptr();
}
template<typename ItemType>
[[nodiscard]] bool
iterator_base<ItemType>::operator==(PointerType rhs) const noexcept
{
    return ptr() == rhs;
}
template<typename ItemType>
[[nodiscard]] bool
iterator_base<ItemType>::operator!=(IteratorType rhs) const noexcept
{
    return ptr() != rhs.ptr();
}
template<typename ItemType>
[[nodiscard]] bool
iterator_base<ItemType>::operator!=(PointerType rhs) const noexcept
{
    return ptr() != rhs;
}
template<typename ItemType>
[[nodiscard]] bool
iterator_base<ItemType>::operator>(IteratorType rhs) const noexcept
{
    return ptr() > rhs.ptr();
}
template<typename ItemType>
[[nodiscard]] bool
iterator_base<ItemType>::operator>(PointerType rhs) const noexcept
{
    return ptr() > rhs;
}
template<typename ItemType>
[[nodiscard]] bool
iterator_base<ItemType>::operator>=(IteratorType rhs) const noexcept
{
    return ptr() >= rhs.ptr();
}
template<typename ItemType>
[[nodiscard]] bool
iterator_base<ItemType>::operator>=(PointerType rhs) const noexcept
{
    return ptr() >= rhs;
}
template<typename ItemType>
[[nodiscard]] bool
iterator_base<ItemType>::operator<(IteratorType rhs) const noexcept
{
    return ptr() < rhs.ptr();
}
template<typename ItemType>
[[nodiscard]] bool
iterator_base<ItemType>::operator<(PointerType rhs) const noexcept
{
    return ptr() < rhs;
}
template<typename ItemType>
[[nodiscard]] bool
iterator_base<ItemType>::operator<=(IteratorType rhs) const noexcept
{
    return ptr() <= rhs.ptr();
}
template<typename ItemType>
[[nodiscard]] bool
iterator_base<ItemType>::operator<=(PointerType rhs) const noexcept
{
    return ptr() <= rhs;
}

#ifdef __cpp_impl_three_way_comparison
template<typename ItemType>
[[nodiscard]] std::strong_ordering
iterator_base<ItemType>::operator<=>(IteratorType rhs) const noexcept
{
    if(ptr() < rhs.ptr())
    {
        return std::strong_ordering::greater;
    }
    if(ptr() > rhs.ptr())
    {
        return std::strong_ordering::less;
    }
    else /* ptr() == rhs.ptr() */
    {
        return std::strong_ordering::equal;
    }
}
template<typename ItemType>
[[nodiscard]] std::strong_ordering
iterator_base<ItemType>::operator<=>(PointerType rhs) const noexcept
{
    if(ptr() < rhs)
    {
        return std::strong_ordering::greater;
    }
    if(ptr() > rhs)
    {
        return std::strong_ordering::less;
    }
    else /* ptr() == rhs */
    {
        return std::strong_ordering::equal;
    }
}
#endif


}        // namespace pel
