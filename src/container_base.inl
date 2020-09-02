/**
 * \file
 * \author  Pascal-Emmanuel Lachance
 * \p       https://www.github.com/Raesangur
 * ------------------------------------------------------------------------------------------------
 * MIT License
 * Copyright (c) 2020 Pascal-Emmanuel Lachance | Ràësangür
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#pragma once
#include "./container_base.hpp"


/*************************************************************************************************/
/* Defines ------------------------------------------------------------------------------------- */
/* clang-format off */
#define CONTAINER_BASE_TEMPLATE_DECLARATION__   typename ItemType,                                 \
                                                typename IteratorType,                             \
                                                typename AllocatorType

#define CONTAINER_BASE_CLASS_SCOPE__            container_base<ItemType,                           \
                                                               IteratorType,                       \
                                                               AllocatorType>
/* clang-format on */


namespace pel
{
/*************************************************************************************************/
/* CONSTRUCTORS & DESTRUCTORS ------------------------------------------------------------------ */
/*************************************************************************************************/


/*************************************************************************************************/
/* ELEMENT ACCESSORS --------------------------------------------------------------------------- */
/*************************************************************************************************/

/**
 **************************************************************************************************
 * \brief       Obtain a reference to the element at a specified index in the container.
 *
 * \param       index_: Index of the element to get.
 *
 * \retval      ItemType&: Reference to the item at the specified index.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline ItemType&
CONTAINER_BASE_CLASS_SCOPE__::at(SizeType index_)
{
    return this->operator[](index_);
}


/**
 **************************************************************************************************
 * \brief       Obtain a constant reference to the element at a specified index in the container.
 *
 * \param       index_: Index of the element to get.
 *
 * \retval      ItemType&: Const reference to the item at the specified index.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline const ItemType&
CONTAINER_BASE_CLASS_SCOPE__::at(SizeType index_) const
{
    return this->operator[](index_);
}


/**
**************************************************************************************************
* \brief       Obtain the iterator to the element at the specified index.
*
* \param       index_: Index of the element to get.
*
* \retval      IteratorType: Iterator to the item at the specified index.
*************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline IteratorType
CONTAINER_BASE_CLASS_SCOPE__::iterator_at(DifferenceType index_) const
{
    return cbegin() + index_;
}


/**
 **************************************************************************************************
 * \brief       Get the element at the front of the container.
 *
 * \retval      ItemType&: Element at the front of the container.
 *
 * \throw       std::length_error
 *              If there was no memory allocated for the elements, accessing even just the first
 *              element would cause errors.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline ItemType&
CONTAINER_BASE_CLASS_SCOPE__::front()
{
    if constexpr(container_safeness == true)
    {
        if(length() == 0)
        {
            throw std::length_error("Could not access element - No memory allocated");
        }
    }
    return *begin();
}


/**
 **************************************************************************************************
 * \brief       Get the element at the back of the container.
 *
 * \retval      ItemType&: Element at the back of the container.
 *
 * \throw       std::length_error
 *              If there was no memory allocated for the elements, accessing even just the first
 *              element would cause errors.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline ItemType&
CONTAINER_BASE_CLASS_SCOPE__::back()
{
    if constexpr(container_safeness == true)
    {
        if(length() == 0)
        {
            throw std::length_error("Could not access element - No memory allocated");
        }
    }
    return *(end() - 1);
}


/**
 **************************************************************************************************
 * \brief       Get the const element at the front of the container.
 *
 * \retval      ItemType&: Const element at the front of the container.
 *
 * \throw       std::length_error
 *              If there was no memory allocated for the elements, accessing even just the first
 *              element would cause errors.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline const ItemType&
CONTAINER_BASE_CLASS_SCOPE__::front() const
{
    if constexpr(container_safeness == true)
    {
        if(length() == 0)
        {
            throw std::length_error("Could not access element - No memory allocated");
        }
    }
    return *cbegin();
}


/**
 **************************************************************************************************
 * \brief       Get the const element at the back of the container.
 *
 * \retval      ItemType&: Const element at the back of the container.
 *
 * \throw       std::length_error
 *              If there was no memory allocated for the elements, accessing even just the first
 *              element would cause errors.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline const ItemType&
CONTAINER_BASE_CLASS_SCOPE__::back() const
{
    if constexpr(container_safeness == true)
    {
        if(length() == 0)
        {
            throw std::length_error("Could not access element - No memory allocated");
        }
    }
    return *(end() - 1);
}


/**
 **************************************************************************************************
 * \brief       Return the index of an iterator from the start of the container.
 *
 * \param       iterator_: Iterator in the container to get the index of.
 *
 * \retval      SizeType: index of the iterator.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline typename CONTAINER_BASE_CLASS_SCOPE__::DifferenceType
CONTAINER_BASE_CLASS_SCOPE__::index_of(IteratorType iterator_) const
{
    if constexpr(container_safeness == true)
    {
        check_if_valid(iterator_);
    }

    return iterator_ - begin();
}


/*************************************************************************************************/
/* OPERATOR OVERLOADS -------------------------------------------------------------------------- */
/*************************************************************************************************/


/**
 **************************************************************************************************
 * \brief       Overload of the brackets[] operator to access an element at a specific index.
 *
 * \param       index_: Index of the element to access.
 *
 * \retval      ItemType&: Reference to the element at the index.
 *
 * \throws      std::length_error("Index out of range")
 *              If the index is out of the container's length.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline ItemType&
CONTAINER_BASE_CLASS_SCOPE__::operator[](SizeType index_)
{
    if constexpr(container_safeness == true)
    {
        if(index_ >= length())
        {
            throw std::length_error("Index out of range");
        }
    }

    return begin()[index_];
}


/**
 **************************************************************************************************
 * \brief       Overload of the brackets[] operator to access a const element at a specific index.
 *
 * \param       index_: Index of the element to access.
 *
 * \retval      ItemType&: Const reference to the element at the index.
 *
 * \throws      std::length_error("Index out of range")
 *              If the index is out of the container's length.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline const ItemType&
CONTAINER_BASE_CLASS_SCOPE__::operator[](SizeType index_) const
{
    if constexpr(container_safeness == true)
    {
        if(index_ >= length())
        {
            throw std::length_error("Index out of range!");
        }
    }

    return begin()[index_];
}


/**
 **************************************************************************************************
 * \brief       Overload of the equality == operator to compare the values of two containers.
 *
 * \param       lhs: The container on the left side of the operator
 * \param       rhs: The container on the right side of the operator
 *
 * \retval      true if all the values within both containers are equal
 *************************************************************************************************/
template<CONTAINER_BASE_OPERATOR_TEMPLATE_DEFINITION__>
[[nodiscard]] inline bool operator==(CONTAINER_BASE_OPERATOR_ARGUMENTS__)
{
    bool isSameLength = lhs_.length() == rhs_.length();
    if(isSameLength == true)
    {
        bool isEqual = std::equal(lhs_.begin(), lhs_.end(), rhs_.begin());
        return isEqual;
    }
}


/**
 **************************************************************************************************
 * \brief       Overload of the inequality != operator to compare the values of two containers.
 *
 * \param       lhs: The container on the left side of the operator
 * \param       rhs: The container on the right side of the operator
 *
 * \retval      true if any value is different between the containers or if their size differ.
 *************************************************************************************************/
template<CONTAINER_BASE_OPERATOR_TEMPLATE_DEFINITION__>
[[nodiscard]] inline bool operator!=(CONTAINER_BASE_OPERATOR_ARGUMENTS__)
{
    return !(lhs_ == rhs_);
}

/**
 **************************************************************************************************
 * \brief       Overload of the less-than < operator to compare the values of two containers.
 *              Uses lexicographical comparison to compare the values of the containers.
 *
 * \param       lhs: The container on the left side of the operator
 * \param       rhs: The container on the right side of the operator
 *
 * \retval      true if this container is lexicographically less than the other.
 *************************************************************************************************/
template<CONTAINER_BASE_OPERATOR_TEMPLATE_DEFINITION__>
[[nodiscard]] inline bool operator<(CONTAINER_BASE_OPERATOR_ARGUMENTS__)
{
    bool isLess = std::lexicographical_compare(lhs_.begin(), lhs_.end(), rhs_.begin(), rhs_.end());
    return isLess;
}

/**
 **************************************************************************************************
 * \brief       Overload of the more-than > operator to compare the values of two containers.
 *              Uses lexicographical comparison to compare the values of the containers.
 *
 * \param       lhs: The container on the left side of the operator
 * \param       rhs: The container on the right side of the operator
 *
 * \retval      true if this container is lexicographically more than the other.
 *************************************************************************************************/
template<CONTAINER_BASE_OPERATOR_TEMPLATE_DEFINITION__>
[[nodiscard]] inline bool operator>(CONTAINER_BASE_OPERATOR_ARGUMENTS__)
{
    return rhs_ < lhs_;
}

/**
 **************************************************************************************************
 * \brief       Overload of the less-or-equal <= operator to compare the values of two containers.
 *              Uses lexicographical comparison to compare the values of the containers.
 *
 * \param       lhs: The container on the left side of the operator
 * \param       rhs: The container on the right side of the operator
 *
 * \retval      true if this container is lexicographically less or equal to the other.
 *************************************************************************************************/
template<CONTAINER_BASE_OPERATOR_TEMPLATE_DEFINITION__>
[[nodiscard]] inline bool operator<=(CONTAINER_BASE_OPERATOR_ARGUMENTS__)
{
    return !(rhs_ < lhs_);
}

/**
 **************************************************************************************************
 * \brief       Overload of the more-or-equal >= operator to compare the values of two containers.
 *              Uses lexicographical comparison to compare the values of the containers.
 *
 * \param       lhs: The container on the left side of the operator
 * \param       rhs: The container on the right side of the operator
 *
 * \retval      true if this container is lexicographically more or equal to the other.
 *************************************************************************************************/
template<CONTAINER_BASE_OPERATOR_TEMPLATE_DEFINITION__>
[[nodiscard]] inline bool operator>=(CONTAINER_BASE_OPERATOR_ARGUMENTS__)
{
    return !(lhs_ < rhs_);
}


/**
 **************************************************************************************************
 * \brief       Overload of the three-way-comparison <=> operator to compare the values of two
 *              containers.
 *              Uses lexicographical comparison to compare the values of the containers.
 *
 * \param       lhs: The container on the left side of the operator
 * \param       rhs: The container on the right side of the operator
 *
 * \retval      greater: if this container is lexicographically greater than the other
 *              less:    if this container is lexicographically less than the other
 *              equal:   if the items of both containers are equals
 *************************************************************************************************/
#ifdef __cpp_impl_three_way_comparison
template<CONTAINER_BASE_OPERATOR_TEMPLATE_DEFINITION__>
[[nodiscard]] inline std::strong_ordering operator<=>(CONTAINER_BASE_OPERATOR_ARGUMENTS__)
{
    if(lhs_ < rhs_)
    {
        return std::strong_ordering::greater;
    }
    if(lhs_ > rhs_)
    {
        return std::strong_ordering::less;
    }
    else /* lhs_ == rhs_ */
    {
        return std::strong_ordering::equal;
    }
}
#endif


/*************************************************************************************************/
/* ITERATORS ----------------------------------------------------------------------------------- */
/*************************************************************************************************/


/**
 **************************************************************************************************
 * \brief       Returns an iterator to the beginning of the allocated data.
 *
 * \retval      IteratorType: Iterator to the start of the vector's memory.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline IteratorType
CONTAINER_BASE_CLASS_SCOPE__::begin() const noexcept
{
    return m_beginIterator;
}


/**
 **************************************************************************************************
 * \brief       Returns an iterator to the end of the allocated data.
 *
 * \retval      IteratorType: Iterator to the end of the vector's memory.
 *
 * \note        This iterator does not point directly to the end of the memory, but to one element
 *              after the end of the memory.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline IteratorType
CONTAINER_BASE_CLASS_SCOPE__::end() const noexcept
{
    return m_endIterator;
}


/**
 **************************************************************************************************
 * \brief       Returns a const iterator to the beginning of the allocated data.
 *
 * \retval      IteratorType: Const iterator to the start of the vector's memory.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline const IteratorType
CONTAINER_BASE_CLASS_SCOPE__::cbegin() const noexcept
{
    return m_beginIterator;
}


/**
 **************************************************************************************************
 * \brief       Returns a const iterator to the end of the allocated data.
 *
 * \retval      IteratorType: Const iterator to the end of the vector's memory.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline const IteratorType
CONTAINER_BASE_CLASS_SCOPE__::cend() const noexcept
{
    return m_endIterator;
}


/**
 **************************************************************************************************
 * \brief       Returns a reverse iterator to the reversed beginning of the allocated data.
 *
 * \retval      IteratorType: Iterator to the reversed start of the vector's memory.
 *                            (end - 1)
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline typename CONTAINER_BASE_CLASS_SCOPE__::RIteratorType
CONTAINER_BASE_CLASS_SCOPE__::rbegin() const noexcept
{
    return RIteratorType(end());
}


/**
 **************************************************************************************************
 * \brief       Returns a reverse iterator to the reversed end of the allocated data.
 *
 * \retval      IteratorType: Iterator to the reversed of the vector's memory.
 *                            (begin - 1)
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline typename CONTAINER_BASE_CLASS_SCOPE__::RIteratorType
CONTAINER_BASE_CLASS_SCOPE__::rend() const noexcept
{
    return RIteratorType(begin());
}


/**
 **************************************************************************************************
 * \brief       Returns a const reverse iterator to the reversed beginning of the allocated data.
 *
 * \retval      IteratorType: Const iterator to the reversed start of the vector's memory.
 *                            (end - 1)
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline const typename CONTAINER_BASE_CLASS_SCOPE__::RIteratorType
CONTAINER_BASE_CLASS_SCOPE__::crbegin() const noexcept
{
    return RIteratorType(end());
}


/**
 **************************************************************************************************
 * \brief       Returns a const reverse iterator to the reversed end of the allocated data.
 *
 * \retval      IteratorType: Const iterator to the reversed of the vector's memory.
 *                            (begin - 1)
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline const typename CONTAINER_BASE_CLASS_SCOPE__::RIteratorType
CONTAINER_BASE_CLASS_SCOPE__::crend() const noexcept
{
    return RIteratorType(begin());
}


/*************************************************************************************************/
/* MEMORY -------------------------------------------------------------------------------------- */
/*************************************************************************************************/

/**
 **************************************************************************************************
 * \brief       Simple accessor, return the length (number of elements) of the container.
 *
 * \retval      SizeType: Number of elements of the container.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline typename CONTAINER_BASE_CLASS_SCOPE__::SizeType
CONTAINER_BASE_CLASS_SCOPE__::length() const noexcept
{
    DifferenceType diff = end() - begin();
    return static_cast<SizeType>(diff);
}


/**
 **************************************************************************************************
 * \brief       Simple accessor, returns true if there are no elements in the container.
 *
 * \retval      bool: True if there are no elements in the container.
 *                    False if there are elements in the container.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline bool
CONTAINER_BASE_CLASS_SCOPE__::is_empty() const noexcept
{
    return length() == 0;
}


/**
 **************************************************************************************************
 * \brief       Simple accessor, returns true if there are elements in the container.
 *
 * \retval      bool: True if there are elements in the container.
 *                    False if there are not elements in the container.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline bool
CONTAINER_BASE_CLASS_SCOPE__::is_not_empty() const noexcept
{
    return !is_empty();
}

/**
 **************************************************************************************************
 * \brief       Simple accessor, returns a const reference to the container's allocator.
 *
 * \retval      AllocatorType&: The container's allocator
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] const AllocatorType&
CONTAINER_BASE_CLASS_SCOPE__::get_allocator() const noexcept
{
    return m_allocator;
}


/**
 **************************************************************************************************
 * \brief       Destroy all elements currently in the container and set its length to 0.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
inline void
CONTAINER_BASE_CLASS_SCOPE__::clear()
{
    std::destroy(begin(), end());

    m_endIterator = cbegin();
}


/*************************************************************************************************/
/* MISC ---------------------------------------------------------------------------------------- */
/*************************************************************************************************/


/*************************************************************************************************/
/* PRIVATE METHODS ----------------------------------------------------------------------------- */
/*************************************************************************************************/
/**
 **************************************************************************************************
 * \brief       Check if an iterator is located within the container's bounds.
 *              If it is not, throw an exception.
 *
 * \param       iterator_: Iterator to check.
 *
 * \throws      std::invalid_argument("Invalid iterator"):
 *              If the iterator does not belong in the container's boundaries.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
constexpr inline void
CONTAINER_BASE_CLASS_SCOPE__::check_if_valid(IteratorType iterator_) const
{
    if constexpr(vector_safeness == true)
    {
        if((iterator_ < cbegin()) || (iterator_ > cend()))
        {
            throw std::invalid_argument("Invalid iterator");
        }
    }
}


/**
 **************************************************************************************************
 * \brief       Add a number of elements to the current length of the vector.
 *
 * \param       addedLength_: Numbers of elements to add to the current length.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
constexpr inline void
CONTAINER_BASE_CLASS_SCOPE__::add_size(SizeType addedLength_)
{
    change_size(length() + addedLength_);
}


/**
 **************************************************************************************************
 * \brief       Change the current length (in elements) of the container.
 *
 * \param       newLength_: New length (in elements) of the container.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
constexpr inline void
CONTAINER_BASE_CLASS_SCOPE__::change_size(SizeType newLength_)
{
    m_endIterator = IteratorType(&(begin()[newLength_]));
}


/*************************************************************************************************/
/* Undefines ----------------------------------------------------------------------------------- */
#undef CONTAINER_BASE_TEMPLATE_DECLARATION__
#undef CONTAINER_BASE_CLASS_SCOPE__


}        // namespace pel

         
/*************************************************************************************************/
/* END OF FILE --------------------------------------------------------------------------------- */
/*************************************************************************************************/
