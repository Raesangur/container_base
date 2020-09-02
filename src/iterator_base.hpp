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

    using ReverseIteratorType = IteratorType;        // For now!

    using SizeType       = std::size_t;
    using DifferenceType = std::ptrdiff_t;

    using PointerType    = ItemType*;
    using ReferenceType  = ItemType&;
    using PointerTypeRef = PointerType&;

    using const_PointerType    = const ItemType*;
    using const_ReferenceType  = const ItemType&;
    using const_PointerTypeRef = const const_PointerType&;

    /* Types for the STL */
    using IteratorCategory  = std::random_access_iterator_tag;
    using iterator_category = IteratorCategory;
    using self_type         = IteratorType;
    using value_type        = ItemType;
    using reference         = ReferenceType;
    using pointer           = PointerType;
    using difference_type   = DifferenceType;
    using size_type         = SizeType;

    /*------------------------------------*/
    /* Constructors */
    constexpr iterator_base() noexcept = default;

    constexpr iterator_base(const iterator_base& copy_) noexcept = default;
    constexpr iterator_base& operator=(const iterator_base& copy_) noexcept;

    constexpr iterator_base(iterator_base&& move_) noexcept = default;
    constexpr iterator_base& operator=(iterator_base&& move_) noexcept = default;

    virtual ~iterator_base() = default;

    constexpr explicit iterator_base(PointerType pointer_) : m_ptr(pointer_)
    {
    }

    /*------------------------------------*/
    /* Memory operators */
    [[nodiscard]] constexpr const_ReferenceType value() const;
    [[nodiscard]] constexpr ReferenceType       value();
    [[nodiscard]] constexpr PointerType         ptr() noexcept;
    [[nodiscard]] constexpr const_PointerType   ptr() const noexcept;

    [[nodiscard]] constexpr ReferenceType       operator*();
    [[nodiscard]] constexpr const_ReferenceType operator*() const;
    [[nodiscard]] constexpr PointerType         operator->();
    [[nodiscard]] constexpr const_PointerType   operator->() const;

    [[nodiscard]] constexpr virtual ItemType& operator[](DifferenceType index) const;
    [[nodiscard]] constexpr virtual ItemType& operator[](SizeType index) const;

    /*------------------------------------*/
    /* Arithmetic operators */
    constexpr iterator_base& operator=(const_PointerType other_) noexcept;
    constexpr iterator_base& operator=(const_PointerTypeRef other_) noexcept;

    [[nodiscard]] constexpr virtual IteratorType operator+(DifferenceType rhs_) const noexcept;
    constexpr virtual IteratorType               operator++() noexcept;
    constexpr virtual const IteratorType         operator++(int) noexcept;
    constexpr virtual IteratorType               operator+=(DifferenceType rhs_) noexcept;

    [[nodiscard]] constexpr virtual IteratorType   operator-(DifferenceType rhs_) const noexcept;
    [[nodiscard]] constexpr virtual DifferenceType operator-(IteratorType rhs_) const noexcept;
    constexpr virtual IteratorType                 operator--() noexcept;
    constexpr virtual const IteratorType           operator--(int) noexcept;
    constexpr virtual IteratorType                 operator-=(DifferenceType rhs_) noexcept;

    /*------------------------------------*/
    /* Comparison operators */
    [[nodiscard]] constexpr virtual bool operator==(const_IteratorType rhs_) const noexcept;
    [[nodiscard]] constexpr virtual bool operator==(const_PointerType rhs_) const noexcept;
    [[nodiscard]] constexpr virtual bool operator!=(const_IteratorType rhs_) const noexcept;
    [[nodiscard]] constexpr virtual bool operator!=(const_PointerType rhs_) const noexcept;

    [[nodiscard]] constexpr virtual bool operator>(const_IteratorType rhs_) const noexcept;
    [[nodiscard]] constexpr virtual bool operator>(const_PointerType rhs_) const noexcept;

    [[nodiscard]] constexpr virtual bool operator>=(const_IteratorType rhs_) const noexcept;
    [[nodiscard]] constexpr virtual bool operator>=(const_PointerType rhs_) const noexcept;

    [[nodiscard]] constexpr virtual bool operator<(const_IteratorType rhs_) const noexcept;
    [[nodiscard]] constexpr virtual bool operator<(const_PointerType rhs_) const noexcept;

    [[nodiscard]] constexpr virtual bool operator<=(const_IteratorType rhs_) const noexcept;
    [[nodiscard]] constexpr virtual bool operator<=(const_PointerType rhs_) const noexcept;

#ifdef __cpp_impl_three_way_comparison
    [[nodiscard]] constexpr virtual std::strong_ordering operator<=>(
      const_IteratorType rhs_) const noexcept;
    [[nodiscard]] constexpr virtual std::strong_ordering operator<=>(
      const_PointerType rhs_) const noexcept;
#endif

    /*------------------------------------*/
protected:
    PointerType m_ptr = nullptr;
};


/*************************************************************************/
/* IMPLEMENTATION OF METHODS                                             */
/*************************************************************************/
/* Memory operators */

template<typename ItemType>
[[nodiscard]] constexpr inline typename iterator_base<ItemType>::const_ReferenceType
iterator_base<ItemType>::value() const
{
    return *m_ptr;
}

template<typename ItemType>
[[nodiscard]] constexpr inline typename iterator_base<ItemType>::ReferenceType
iterator_base<ItemType>::value()
{
    return *m_ptr;
}

template<typename ItemType>
[[nodiscard]] constexpr inline typename iterator_base<ItemType>::PointerType
iterator_base<ItemType>::ptr() noexcept
{
    return m_ptr;
}
template<typename ItemType>
[[nodiscard]] constexpr inline typename iterator_base<ItemType>::const_PointerType
iterator_base<ItemType>::ptr() const noexcept
{
    return m_ptr;
}

template<typename ItemType>
[[nodiscard]] constexpr inline typename iterator_base<ItemType>::ReferenceType
iterator_base<ItemType>::operator*()
{
    return *m_ptr;
}
template<typename ItemType>
[[nodiscard]] constexpr inline typename iterator_base<ItemType>::const_ReferenceType
iterator_base<ItemType>::operator*() const
{
    return *m_ptr;
}

template<typename ItemType>
[[nodiscard]] constexpr inline typename iterator_base<ItemType>::PointerType
iterator_base<ItemType>::operator->()
{
    return m_ptr;
}

template<typename ItemType>
[[nodiscard]] constexpr inline typename iterator_base<ItemType>::const_PointerType
iterator_base<ItemType>::operator->() const
{
    return m_ptr;
}

template<typename ItemType>
[[nodiscard]] constexpr inline ItemType&
iterator_base<ItemType>::operator[](DifferenceType index_) const
{
    return m_ptr[index_];
}
template<typename ItemType>
[[nodiscard]] constexpr inline ItemType&
iterator_base<ItemType>::operator[](SizeType index_) const
{
    return m_ptr[index_];
}

/*------------------------------------*/
/* Arithmetic operators */
template<typename ItemType>
constexpr inline iterator_base<ItemType>&
iterator_base<ItemType>::operator=(const_PointerType other_) noexcept
{
    m_ptr = other_;
    return *this;
}
template<typename ItemType>
constexpr inline iterator_base<ItemType>&
iterator_base<ItemType>::operator=(const_PointerTypeRef other_) noexcept
{
    m_ptr = other_;
    return *this;
}
template<typename ItemType>
constexpr inline iterator_base<ItemType>&
iterator_base<ItemType>::operator=(const iterator_base& copy_) noexcept
{
    if(this == &copy_)
    {
        return *this;
    }
    else
    {
        this->m_ptr = copy_.m_ptr;
        return *this;
    }
}

template<typename ItemType>
[[nodiscard]] constexpr inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator+(DifferenceType rhs_) const noexcept
{
    PointerType ptr = m_ptr + rhs_;
    return IteratorType(ptr);
}

template<typename ItemType>
constexpr inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator++() noexcept
{
    ++m_ptr;
    return IteratorType(*this);
}
template<typename ItemType>
constexpr inline const iterator_base<ItemType>
iterator_base<ItemType>::operator++(int) noexcept
{
    IteratorType temp = IteratorType(*this);
    m_ptr++;
    return temp;
}

template<typename ItemType>
constexpr inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator+=(DifferenceType rhs_) noexcept
{
    m_ptr += rhs_;
    return IteratorType(*this);
}

template<typename ItemType>
[[nodiscard]] constexpr inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator-(DifferenceType rhs_) const noexcept
{
    PointerType ptr = m_ptr - rhs_;
    return IteratorType(ptr);
}
template<typename ItemType>
[[nodiscard]] constexpr inline typename iterator_base<ItemType>::DifferenceType
iterator_base<ItemType>::operator-(IteratorType rhs_) const noexcept
{
    DifferenceType ptr = m_ptr - rhs_.m_ptr;
    return ptr;
}

template<typename ItemType>
constexpr inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator--() noexcept
{
    --m_ptr;
    return IteratorType(*this);
}
template<typename ItemType>
constexpr inline const iterator_base<ItemType>
iterator_base<ItemType>::operator--(int) noexcept
{
    const IteratorType temp = IteratorType(*this);
    m_ptr--;
    return temp;
}
template<typename ItemType>
constexpr inline typename iterator_base<ItemType>::IteratorType
iterator_base<ItemType>::operator-=(DifferenceType rhs_) noexcept
{
    m_ptr -= rhs_;
    return IteratorType(*this);
}

/*------------------------------------*/
/* Comparison operators */
template<typename ItemType>
[[nodiscard]] constexpr inline bool
iterator_base<ItemType>::operator==(const_IteratorType rhs_) const noexcept
{
    return m_ptr == rhs_.m_ptr;
}
template<typename ItemType>
[[nodiscard]] constexpr inline bool
iterator_base<ItemType>::operator==(const_PointerType rhs_) const noexcept
{
    return m_ptr == rhs_;
}
template<typename ItemType>
[[nodiscard]] constexpr inline bool
iterator_base<ItemType>::operator!=(const_IteratorType rhs_) const noexcept
{
    return m_ptr != rhs_.m_ptr;
}
template<typename ItemType>
[[nodiscard]] constexpr inline bool
iterator_base<ItemType>::operator!=(const_PointerType rhs_) const noexcept
{
    return m_ptr != rhs_;
}
template<typename ItemType>
[[nodiscard]] constexpr inline bool
iterator_base<ItemType>::operator>(const_IteratorType rhs_) const noexcept
{
    return m_ptr > rhs_.m_ptr;
}
template<typename ItemType>
[[nodiscard]] constexpr inline bool
iterator_base<ItemType>::operator>(const_PointerType rhs_) const noexcept
{
    return m_ptr > rhs_;
}
template<typename ItemType>
[[nodiscard]] constexpr inline bool
iterator_base<ItemType>::operator>=(const_IteratorType rhs_) const noexcept
{
    return m_ptr >= rhs_.m_ptr;
}
template<typename ItemType>
[[nodiscard]] constexpr inline bool
iterator_base<ItemType>::operator>=(const_PointerType rhs_) const noexcept
{
    return m_ptr >= rhs_;
}
template<typename ItemType>
[[nodiscard]] constexpr inline bool
iterator_base<ItemType>::operator<(const_IteratorType rhs_) const noexcept
{
    return m_ptr < rhs_.m_ptr;
}
template<typename ItemType>
[[nodiscard]] constexpr inline bool
iterator_base<ItemType>::operator<(const_PointerType rhs_) const noexcept
{
    return m_ptr < rhs_;
}
template<typename ItemType>
[[nodiscard]] constexpr inline bool
iterator_base<ItemType>::operator<=(const_IteratorType rhs_) const noexcept
{
    return m_ptr <= rhs_.m_ptr;
}
template<typename ItemType>
[[nodiscard]] constexpr inline bool
iterator_base<ItemType>::operator<=(const_PointerType rhs_) const noexcept
{
    return m_ptr <= rhs_;
}

#ifdef __cpp_impl_three_way_comparison
template<typename ItemType>
[[nodiscard]] constexpr inline std::strong_ordering
iterator_base<ItemType>::operator<=>(const_IteratorType rhs_) const noexcept
{
    if(m_ptr < rhs_.m_ptr)
    {
        return std::strong_ordering::greater;
    }
    if(m_ptr > rhs_.m_ptr)
    {
        return std::strong_ordering::less;
    }
    else /* m_ptr == rhs_.m_ptr */
    {
        return std::strong_ordering::equal;
    }
}
template<typename ItemType>
[[nodiscard]] constexpr inline std::strong_ordering
iterator_base<ItemType>::operator<=>(const_PointerType rhs_) const noexcept
{
    if(m_ptr < rhs_)
    {
        return std::strong_ordering::greater;
    }
    if(m_ptr > rhs_)
    {
        return std::strong_ordering::less;
    }
    else /* m_ptr == rhs_ */
    {
        return std::strong_ordering::equal;
    }
}
#endif


}        // namespace pel
