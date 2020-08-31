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
 * \brief       Return the index of an iterator from the start of the vector.
 *
 * \param       iterator_: Iterator in the vector to get the index of.
 *
 * \retval      SizeType: index of the iterator.
 *************************************************************************************************/
template<CONTAINER_BASE_TEMPLATE_DECLARATION__>
[[nodiscard]] inline typename CONTAINER_BASE_CLASS_SCOPE__::DifferenceType
CONTAINER_BASE_CLASS_SCOPE__::index_of(IteratorType iterator_) const
{
    if constexpr(vector_safeness == true)
    {
        check_if_valid(iterator_);
    }

    return iterator_ - begin();
}


/*************************************************************************************************/
/* OPERATOR OVERLOADS -------------------------------------------------------------------------- */
/*************************************************************************************************/


/*************************************************************************************************/
/* ITERATORS ----------------------------------------------------------------------------------- */
/*************************************************************************************************/


/*************************************************************************************************/
/* MEMORY -------------------------------------------------------------------------------------- */
/*************************************************************************************************/


/*************************************************************************************************/
/* MISC ---------------------------------------------------------------------------------------- */
/*************************************************************************************************/


/*************************************************************************************************/
/* PRIVATE METHODS ----------------------------------------------------------------------------- */
/*************************************************************************************************/
/**
 **************************************************************************************************
 * \brief       Check if an iterator is located within the vector's bounds.
 *              If it is not, throw an exception.
 *
 * \param       iterator_: Iterator to check.
 *
 * \throws      std::invalid_argument("Invalid iterator"):
 *              If the iterator does not belong in the vector's boundaries.
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
}        // namespace pel


/*************************************************************************************************/
/* Undefines ----------------------------------------------------------------------------------- */
#undef CONTAINER_BASE_TEMPLATE_DECLARATION__
#undef CONTAINER_BASE_CLASS_SCOPE__


/*************************************************************************************************/
/* END OF FILE --------------------------------------------------------------------------------- */
/*************************************************************************************************/
