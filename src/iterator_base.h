#pragma once
#include <compare>
#include <iterator>

namespace pel
{

template<typename ItemType>
class iterator_base
{
    public:
    /*------------------------------------*/
    /* Typenames */
    using IteratorType       = iterator_base<ItemType>;
    using const_IteratorType = const iterator_base<ItemType>;

    using SizeType       = std::size_t;
    using DifferenceType = std::ptrdiff_t;

    using PointerType    = ItemType*;
    using ReferenceType  = ItemType&;
    using PointerTypeRef = PointerType&;

    using const_PointerType    = const ItemType*;
    using const_ReferenceType  = const ItemType&;
    using const_PointerTypeRef = const const_PointerType&;

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
    [[nodiscard]] PointerType       ptr() noexcept;
    [[nodiscard]] const_PointerType ptr() const noexcept;

    [[nodiscard]] ReferenceType       operator*();
    [[nodiscard]] const_ReferenceType operator*() const;

    [[nodiscard]] operator PointerType() const noexcept;

    /*------------------------------------*/
    /* Arithmetic operators */
    IteratorType& operator=(const_PointerType other) noexcept;
    IteratorType& operator=(const_PointerTypeRef other) noexcept;
    IteratorType& operator=(const_IteratorType& other) noexcept;
    IteratorType& operator=(IteratorType& other) noexcept;

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
    [[nodiscard]] virtual bool operator==(const_IteratorType rhs) const noexcept;
    [[nodiscard]] virtual bool operator==(const_PointerType rhs) const noexcept;
    [[nodiscard]] virtual bool operator!=(const_IteratorType rhs) const noexcept;
    [[nodiscard]] virtual bool operator!=(const_PointerType rhs) const noexcept;

    [[nodiscard]] virtual bool operator>(const_IteratorType rhs) const noexcept;
    [[nodiscard]] virtual bool operator>(const_PointerType rhs) const noexcept;

    [[nodiscard]] virtual bool operator>=(const_IteratorType rhs) const noexcept;
    [[nodiscard]] virtual bool operator>=(const_PointerType rhs) const noexcept;

    [[nodiscard]] virtual bool operator<(const_IteratorType rhs) const noexcept;
    [[nodiscard]] virtual bool operator<(const_PointerType rhs) const noexcept;

    [[nodiscard]] virtual bool operator<=(const_IteratorType rhs) const noexcept;
    [[nodiscard]] virtual bool operator<=(const_PointerType rhs) const noexcept;

#ifdef __cpp_impl_three_way_comparison
    [[nodiscard]] virtual std::strong_ordering operator<=>(const_IteratorType rhs) const noexcept;
    [[nodiscard]] virtual std::strong_ordering operator<=>(const_PointerType rhs) const noexcept;
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
[[nodiscard]] inline typename iterator_base<ItemType>::PointerType
iterator_base<ItemType>::ptr() noexcept
{
    return m_ptr;
}
template<typename ItemType>
[[nodiscard]] inline typename iterator_base<ItemType>::const_PointerType
iterator_base<ItemType>::ptr() const noexcept
{
    return m_ptr;
}

template<typename ItemType>
[[nodiscard]] inline typename iterator_base<ItemType>::ReferenceType
iterator_base<ItemType>::operator*()
{
    return *m_ptr;
}
template<typename ItemType>
[[nodiscard]] inline typename iterator_base<ItemType>::const_ReferenceType
iterator_base<ItemType>::operator*() const
{
    return *m_ptr;
}

template<typename ItemType>
[[nodiscard]] inline iterator_base<ItemType>::operator PointerType() const noexcept
{
    return m_ptr;
}

/*------------------------------------*/
/* Arithmetic operators */
template<typename ItemType>
inline typename iterator_base<ItemType>::IteratorType&
iterator_base<ItemType>::operator=(const_PointerType other) noexcept
{
    return *this;
}
template<typename ItemType>
inline typename iterator_base<ItemType>::IteratorType&
iterator_base<ItemType>::operator=(const_PointerTypeRef other) noexcept
{
    m_ptr = other;
    return *this;
}
template<typename ItemType>
inline typename iterator_base<ItemType>::IteratorType&
iterator_base<ItemType>::operator=(IteratorType& other) noexcept
{
    m_ptr = other.m_ptr;
    return *this;
}
template<typename ItemType>
[[nodiscard]] inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator+(DifferenceType rhs) const
{
    PointerType pointer = m_ptr + rhs;
    return IteratorType(pointer);
}

template<typename ItemType>
inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator++()
{
    ++m_ptr;
    return *this;
}
template<typename ItemType>
inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator++(int)
{
    IteratorType temp = *this;
    m_ptr++;
    return temp;
}

template<typename ItemType>
inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator+=(DifferenceType rhs)
{
    m_ptr += rhs;
    return *this;
}

template<typename ItemType>
[[nodiscard]] inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator-(DifferenceType rhs) const
{
    PointerType pointer = m_ptr - rhs;
    return IteratorType(pointer);
}

template<typename ItemType>
inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator--()
{
    --m_ptr;
    return *this;
}
template<typename ItemType>
inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator--(int)
{
    IteratorType temp = *this;
    m_ptr--;
    return temp;
}
template<typename ItemType>
inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator-=(DifferenceType rhs)
{
    m_ptr -= rhs;
    return *this;
}

/*------------------------------------*/
/* Comparison operators */
template<typename ItemType>
[[nodiscard]] inline bool
iterator_base<ItemType>::operator==(const_IteratorType rhs) const noexcept
{
    return m_ptr == rhs.m_ptr;
}
template<typename ItemType>
[[nodiscard]] inline bool
iterator_base<ItemType>::operator==(const_PointerType rhs) const noexcept
{
    return m_ptr == rhs;
}
template<typename ItemType>
[[nodiscard]] inline bool
iterator_base<ItemType>::operator!=(const_IteratorType rhs) const noexcept
{
    return m_ptr != rhs.m_ptr;
}
template<typename ItemType>
[[nodiscard]] inline bool
iterator_base<ItemType>::operator!=(const_PointerType rhs) const noexcept
{
    return m_ptr != rhs;
}
template<typename ItemType>
[[nodiscard]] inline bool
iterator_base<ItemType>::operator>(const_IteratorType rhs) const noexcept
{
    return m_ptr > rhs.m_ptr;
}
template<typename ItemType>
[[nodiscard]] inline bool
iterator_base<ItemType>::operator>(const_PointerType rhs) const noexcept
{
    return m_ptr > rhs;
}
template<typename ItemType>
[[nodiscard]] inline bool
iterator_base<ItemType>::operator>=(const_IteratorType rhs) const noexcept
{
    return m_ptr >= rhs.m_ptr;
}
template<typename ItemType>
[[nodiscard]] inline bool
iterator_base<ItemType>::operator>=(const_PointerType rhs) const noexcept
{
    return m_ptr >= rhs;
}
template<typename ItemType>
[[nodiscard]] inline bool
iterator_base<ItemType>::operator<(const_IteratorType rhs) const noexcept
{
    return m_ptr < rhs.m_ptr;
}
template<typename ItemType>
[[nodiscard]] inline bool
iterator_base<ItemType>::operator<(const_PointerType rhs) const noexcept
{
    return m_ptr < rhs;
}
template<typename ItemType>
[[nodiscard]] inline bool
iterator_base<ItemType>::operator<=(const_IteratorType rhs) const noexcept
{
    return m_ptr <= rhs.m_ptr;
}
template<typename ItemType>
[[nodiscard]] inline bool
iterator_base<ItemType>::operator<=(const_PointerType rhs) const noexcept
{
    return m_ptr <= rhs;
}

#ifdef __cpp_impl_three_way_comparison
template<typename ItemType>
[[nodiscard]] inline std::strong_ordering
iterator_base<ItemType>::operator<=>(const_IteratorType rhs) const noexcept
{
    if(m_ptr < rhs.m_ptr)
    {
        return std::strong_ordering::greater;
    }
    if(m_ptr > rhs.m_ptr)
    {
        return std::strong_ordering::less;
    }
    else /* m_ptr == rhs.m_ptr */
    {
        return std::strong_ordering::equal;
    }
}
template<typename ItemType>
[[nodiscard]] inline std::strong_ordering
iterator_base<ItemType>::operator<=>(const_PointerType rhs) const noexcept
{
    if(m_ptr < rhs)
    {
        return std::strong_ordering::greater;
    }
    if(m_ptr > rhs)
    {
        return std::strong_ordering::less;
    }
    else /* m_ptr == rhs */
    {
        return std::strong_ordering::equal;
    }
}
#endif


}        // namespace pel
