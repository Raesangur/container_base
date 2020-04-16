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

    /* Types for the STL */
    using IteratorCategory  = std::contiguous_iterator_tag;
    using iterator_category = IteratorCategory;
    using self_type         = IteratorType;
    using value_type        = ItemType;
    using reference         = ReferenceType;
    using pointer           = PointerType;
    using difference_type   = DifferenceType;
    using size_type         = SizeType;

    /*------------------------------------*/
    /* Constructors */
    iterator_base() noexcept = default;

    iterator_base(const iterator_base& copy) noexcept = default;
    iterator_base& operator                           =(const iterator_base& copy) noexcept;

    iterator_base(iterator_base&& move) noexcept = default;
    iterator_base& operator=(iterator_base&& move) noexcept = default;

    virtual ~iterator_base() = default;

    iterator_base(PointerType pointer) : m_ptr(pointer)
    {
    }

    /*------------------------------------*/
    /* Memory operators */
    [[nodiscard]] PointerType       ptr() noexcept;
    [[nodiscard]] const_PointerType ptr() const noexcept;

    [[nodiscard]] ReferenceType       operator*();
    [[nodiscard]] const_ReferenceType operator*() const;
    [[nodiscard]] PointerType         operator->();
    [[nodiscard]] const_PointerType   operator->() const;

    [[nodiscard]] virtual ItemType& operator[](DifferenceType index) const;
    [[nodiscard]] virtual ItemType& operator[](SizeType index) const;

    /*------------------------------------*/
    /* Arithmetic operators */
    iterator_base& operator=(const_PointerType other) noexcept;
    iterator_base& operator=(const_PointerTypeRef other) noexcept;

    [[nodiscard]] virtual IteratorType operator+(DifferenceType rhs) const;
    virtual IteratorType               operator++();
    virtual const IteratorType         operator++(int);
    virtual IteratorType               operator+=(DifferenceType rhs);

    [[nodiscard]] virtual IteratorType   operator-(DifferenceType rhs) const;
    [[nodiscard]] virtual DifferenceType operator-(IteratorType rhs) const;
    virtual IteratorType                 operator--();
    virtual const IteratorType           operator--(int);
    virtual IteratorType                 operator-=(DifferenceType rhs);

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
[[nodiscard]] inline typename iterator_base<ItemType>::PointerType
iterator_base<ItemType>::operator->()
{
    return m_ptr;
}

template<typename ItemType>
[[nodiscard]] inline typename iterator_base<ItemType>::const_PointerType 
iterator_base<ItemType>::operator->() const
{
    return m_ptr;
}

template<typename ItemType>
[[nodiscard]] inline ItemType&
iterator_base<ItemType>::operator[](DifferenceType index) const
{
    return m_ptr[index];
}
template<typename ItemType>
[[nodiscard]] inline ItemType&
iterator_base<ItemType>::operator[](SizeType index) const
{
    return m_ptr[index];
}

/*------------------------------------*/
/* Arithmetic operators */
template<typename ItemType>
inline iterator_base<ItemType>&
iterator_base<ItemType>::operator=(const_PointerType other) noexcept
{
    m_ptr = other;
    return *this;
}
template<typename ItemType>
inline iterator_base<ItemType>&
iterator_base<ItemType>::operator=(const_PointerTypeRef other) noexcept
{
    m_ptr = other;
    return *this;
}
template<typename ItemType>
inline iterator_base<ItemType>&
iterator_base<ItemType>::operator=(const iterator_base& copy) noexcept
{
    if(this == &copy)
    {
        return *this;
    }
    else
    {
        this->m_ptr = copy.m_ptr;
        return *this;
    }
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
    return IteratorType(*this);
}
template<typename ItemType>
inline const iterator_base<ItemType>
iterator_base<ItemType>::operator++(int)
{
    IteratorType temp = IteratorType(*this);
    m_ptr++;
    return temp;
}

template<typename ItemType>
inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator+=(DifferenceType rhs)
{
    m_ptr += rhs;
    return IteratorType(*this);
}

template<typename ItemType>
[[nodiscard]] inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator-(DifferenceType rhs) const
{
    PointerType pointer = m_ptr - rhs;
    return IteratorType(pointer);
}
template<typename ItemType>
[[nodiscard]] inline typename iterator_base<ItemType>::DifferenceType
iterator_base<ItemType>::operator-(IteratorType rhs) const
{
    DifferenceType pointer = m_ptr - rhs.m_ptr;
    return pointer;
}

template<typename ItemType>
inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator--()
{
    --m_ptr;
    return IteratorType(*this);
}
template<typename ItemType>
inline const iterator_base<ItemType>
iterator_base<ItemType>::operator--(int)
{
    const IteratorType temp = IteratorType(*this);
    m_ptr--;
    return temp;
}
template<typename ItemType>
inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator-=(DifferenceType rhs)
{
    m_ptr -= rhs;
    return IteratorType(*this);
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
