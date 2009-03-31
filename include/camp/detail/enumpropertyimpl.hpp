// <insert copyright>

#ifndef CAMP_DETAIL_ENUMPROPERTYIMPL_HPP
#define CAMP_DETAIL_ENUMPROPERTYIMPL_HPP


#include <camp/enumproperty.hpp>
#include <camp/invalidaccess.hpp>


namespace camp
{
namespace detail
{
/**
 * \brief Typed implementation of EnumProperty
 *
 * EnumPropertyImpl is a template implementation of EnumProperty, which is strongly typed
 * in order to keep track of the true underlying C++ types involved in the property.
 *
 * The template parameter A is an abstract helper to access the actual C++ property.
 *
 * \sa EnumProperty
 */
template <typename A>
class EnumPropertyImpl : public EnumProperty
{
public:

    /**
     * \brief Construct the property from its accessors
     *
     * \param name Name of the property
     * \param accessor Object used to access the actual C++ property
     */
    EnumPropertyImpl(const std::string& name, const A& accessor);

protected:

    /**
     * \see Property::isReadable
     */
    virtual bool isReadable() const;

    /**
     * \see Property::isWritable
     */
    virtual bool isWritable() const;

    /**
     * \see Property::getValue
     */
    virtual Value getValue(const UserObject& object) const;

    /**
     * \see Property::setValue
     */
    virtual void setValue(const UserObject& object, const Value& value) const;

private:

    A m_accessor; ///< Object used to access the actual C++ property
};

} // namespace detail

} // namespace camp

#include <camp/detail/enumpropertyimpl.inl>


#endif // CAMP_DETAIL_ENUMPROPERTYIMPL_HPP