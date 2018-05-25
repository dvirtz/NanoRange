// nanorange.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_HPP_INCLUDED
#define NANORANGE_HPP_INCLUDED

// nanorange/concepts.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_HPP_INCLUDED
#define NANORANGE_ALGORITHM_HPP_INCLUDED

// Algorithms reimplemented in Nanorange
// nanorange/algorithm/adjacent_find.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_ADJACENT_FIND_HPP_INCLUDED
#define NANORANGE_ALGORITHM_ADJACENT_FIND_HPP_INCLUDED

// nanorange/range.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_RANGE_HPP_INCLUDED
#define NANORANGE_RANGE_HPP_INCLUDED

// nanorange/detail/range/access.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_RANGE_ACCESS_HPP_INCLUDED
#define NANORANGE_DETAIL_RANGE_ACCESS_HPP_INCLUDED

// nanorange/detail/functional/decay_copy.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_FUNCTIONAL_DECAY_COPY_HPP_INCLUDED
#define NANORANGE_DETAIL_FUNCTIONAL_DECAY_COPY_HPP_INCLUDED

// nanorange/detail/macros.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_MACROS_HPP_INCLUDED
#define NANORANGE_DETAIL_MACROS_HPP_INCLUDED

#if (__cplusplus >= 201703) || (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L)
#define NANO_HAVE_CPP17
#endif

#if defined(NANO_HAVE_CPP17) || defined(__cpp_inline_variables)
#define NANO_HAVE_INLINE_VARS
#endif

#ifdef NANORANGE_NO_DEPRECATION_WARNINGS
#define NANO_DEPRECATED
#define NANO_DEPRECATED_FOR(x)
#else
#define NANO_DEPRECATED [[deprecated]]
#define NANO_DEPRECATED_FOR(x) [[deprecated(x)]]
#endif

#ifdef NANO_HAVE_CPP17
#define NANO_NODISCARD [[nodiscard]]
#else
#define NANO_NODISCARD
#endif

#if defined(NANO_HAVE_CPP17) || defined(__cpp_deduction_guides)
#define NANO_HAVE_DEDUCTION_GUIDES
#endif

#define NANO_CONCEPT constexpr bool

#define NANO_BEGIN_NAMESPACE                                                   \
    \
namespace nano                                                                 \
    {                                                                          \
        \
inline namespace ranges                                                        \
        {

#define NANO_END_NAMESPACE                                                     \
    }                                                                          \
    }

#ifdef NANO_HAVE_INLINE_VARS
#define NANO_INLINE_VAR(type, name)                                            \
    inline namespace function_objects {                                        \
    inline constexpr type name{};                                              \
    }

#else
#define NANO_INLINE_VAR(type, name)                                            \
    inline namespace function_objects {                                        \
    inline namespace {                                                         \
    constexpr const auto& name =                                               \
        ::nano::ranges::detail::static_const_<type>::value;                    \
    }                                                                          \
    }
#endif

NANO_BEGIN_NAMESPACE

namespace detail {

template <typename T>
struct static_const_ {
    static constexpr T value{};
};

template <typename T>
constexpr T static_const_<T>::value;

} // namespace detail

NANO_END_NAMESPACE

#endif


#include <functional>
#include <type_traits>

NANO_BEGIN_NAMESPACE

namespace detail {

template <typename T>
constexpr std::decay_t<T> decay_copy(T &&t) noexcept(
    noexcept(static_cast<std::decay_t<T>>(std::forward<T>(t))))
{
    return std::forward<T>(t);
}

} // namespace detail

NANO_END_NAMESPACE

#endif

// nanorange/detail/iterator/concepts.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_ITERATOR_CONCEPTS_HPP_INCLUDED
#define NANORANGE_DETAIL_ITERATOR_CONCEPTS_HPP_INCLUDED

// nanorange/detail/concepts/object.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_CONCEPTS_OBJECT_HPP_INCLUDED
#define NANORANGE_DETAIL_CONCEPTS_OBJECT_HPP_INCLUDED

// nanorange/detail/concepts/comparison.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_CONCEPTS_COMPARISON_HPP_INCLUDED
#define NANORANGE_DETAIL_CONCEPTS_COMPARISON_HPP_INCLUDED

// nanorange/detail/concepts/core.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_CONCEPTS_CORE_HPP_INCLUDED
#define NANORANGE_DETAIL_CONCEPTS_CORE_HPP_INCLUDED


// nanorange/type_traits.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_TYPE_TRAITS_HPP_INCLUDED
#define NANORANGE_TYPE_TRAITS_HPP_INCLUDED

// nanorange/detail/common_reference.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_COMMON_REFERENCE_HPP_INCLUDED
#define NANORANGE_DETAIL_COMMON_REFERENCE_HPP_INCLUDED


// nanorange/detail/type_traits.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_TYPE_TRAITS_HPP_INCLUDED
#define NANORANGE_DETAIL_TYPE_TRAITS_HPP_INCLUDED



#include <type_traits>

NANO_BEGIN_NAMESPACE

namespace detail {

template <typename T>
using lref_t = std::add_lvalue_reference_t<T>;

template <typename T>
using clref_t = std::add_lvalue_reference_t<std::add_const_t<T>>;

template <typename T>
using rref_t = std::add_rvalue_reference_t<T>;

template <typename T>
using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;

template <typename...>
using void_t = void;

template <typename... T>
void valid_expr(T&&...);

struct error_t {
    error_t() = delete;
    error_t(error_t const&) = delete;
    error_t& operator=(const error_t&) = delete;
    ~error_t() = delete;
};

template <typename Void, template <class...> class Trait, typename... Args>
struct test_ {
    using type = error_t;
};

template <template <class...> class Trait, typename... Args>
struct test_<void_t<Trait<Args...>>, Trait, Args...> {
    using type = Trait<Args...>;
};

template <template <class...> class Trait, typename... Args>
using test_t = typename test_<void, Trait, Args...>::type;

template <typename Void, template <class...> class AliasT, typename... Args>
constexpr bool exists_helper_v = false;

template <template <class...> class AliasT, typename... Args>
constexpr bool exists_helper_v<void_t<AliasT<Args...>>, AliasT, Args...> = true;

template <template <class...> class AliasT, typename... Args>
constexpr bool exists_v = exists_helper_v<void, AliasT, Args...>;

template <typename R, typename... Args,
          typename = decltype(&R::template requires_<Args...>)>
auto test_requires(R&) -> void;

template <typename R, typename... Args>
using test_requires_t = decltype(test_requires<R, Args...>(std::declval<R&>()));

template <typename R, typename... Args>
constexpr bool requires_ = exists_v<test_requires_t, R, Args...>;

template <bool Expr>
using requires_expr = std::enable_if_t<Expr, int>;

template <std::size_t I>
struct priority_tag : priority_tag<I - 1> {
};
template <>
struct priority_tag<0> {
};

} // namespace detail

NANO_END_NAMESPACE

#endif


NANO_BEGIN_NAMESPACE

namespace detail {

template <typename T, typename U>
struct copy_cv {
    using type = U;
};

template <typename T, typename U>
struct copy_cv<const T, U> {
    using type = std::add_const_t<U>;
};

template <typename T, typename U>
struct copy_cv<volatile T, U> {
    using type = std::add_volatile_t<U>;
};

template <typename T, typename U>
struct copy_cv<const volatile T, U> {
    using type = std::add_cv_t<U>;
};

template <typename T, typename U>
using copy_cv_t = typename copy_cv<T, U>::type;

template <typename T>
using cref_t = std::add_lvalue_reference_t<const std::remove_reference_t<T>>;

template <typename T>
using uncvref_t = std::remove_cv_t<std::remove_reference_t<T>>;

template <typename T>
struct rref_res {
    using type = T;
};

template <typename T>
struct rref_res<T&> {
    using type = std::remove_reference_t<T>&&;
};

template <typename T>
using rref_res_t = typename rref_res<T>::type;

template <typename T, typename U>
using cond_res_t = decltype(std::declval<bool>() ? std::declval<T (&)()>()()
                                                 : std::declval<U (&)()>()());

// For some value of "simple"
template <typename T, typename U>
struct simple_common_reference {
};

template <typename T, typename U,
          typename C = test_t<cond_res_t, copy_cv_t<T, U>&, copy_cv_t<U, T>&>>
struct lvalue_simple_common_reference
    : std::enable_if<std::is_reference<C>::value, C> {
};

template <typename T, typename U>
using lvalue_scr_t = typename lvalue_simple_common_reference<T, U>::type;

template <typename T, typename U>
struct simple_common_reference<T&, U&> : lvalue_simple_common_reference<T, U> {
};

template <typename T, typename U, typename LCR = test_t<lvalue_scr_t, T, U>,
          typename C = rref_res_t<LCR>>
struct rvalue_simple_common_reference
    : std::enable_if<std::is_convertible<T&&, C>::value &&
                         std::is_convertible<U&&, C>::value,
                     C> {
};

template <typename T, typename U>
struct simple_common_reference<T&&, U&&>
    : rvalue_simple_common_reference<T, U> {
};

template <typename A, typename B, typename C = test_t<lvalue_scr_t, A, const B>>
struct mixed_simple_common_reference
    : std::enable_if<std::is_convertible<B&&, C>::value, C> {
};

template <typename A, typename B>
struct simple_common_reference<A&, B&&> : mixed_simple_common_reference<A, B> {
};

template <typename A, typename B>
struct simple_common_reference<A&&, B&> : simple_common_reference<B&, A&&> {
};

template <typename T, typename U>
using simple_common_reference_t = typename simple_common_reference<T, U>::type;

} // namespace detail

template <class T, class U, template <class> class TQual,
          template <class> class UQual>
struct basic_common_reference {
};

template <typename...>
struct common_reference;

template <typename... Ts>
using common_reference_t = typename common_reference<Ts...>::type;

template <>
struct common_reference<> {
};

template <typename T0>
struct common_reference<T0> {
    using type = T0;
};

namespace detail {

template <typename T, typename U>
constexpr bool has_simple_common_ref_v =
    exists_v<simple_common_reference_t, T, U>;

template <typename T>
T common_ref_test_func();

template <typename T, typename U,
          typename C = decltype(false ? common_ref_test_func<T>()
                                      : common_ref_test_func<U>())>
struct function_common_ref {
    using type = C;
};

template <typename T, typename U>
using function_common_ref_t = typename function_common_ref<T, U>::type;

template <typename T, typename U>
constexpr bool has_function_common_ref_v =
    exists_v<function_common_ref_t, T, U>;

template <typename T, typename U, typename = void>
struct binary_common_ref : std::common_type<T, U> {
};

template <typename T, typename U>
struct binary_common_ref<T, U, std::enable_if_t<has_simple_common_ref_v<T, U>>>
    : simple_common_reference<T, U> {
};

template <typename T, typename U>
struct binary_common_ref<T, U,
                         std::enable_if_t<has_function_common_ref_v<T, U> &&
                                          !has_simple_common_ref_v<T, U>>>
    : function_common_ref<T, U> {
};

} // namespace detail

// FIXME: Handle basic_common_reference
template <typename T1, typename T2>
struct common_reference<T1, T2> : detail::binary_common_ref<T1, T2> {
};

namespace detail {

template <typename Void, typename T1, typename T2, typename... Rest>
struct multiple_common_reference {
};

template <typename T1, typename T2, typename... Rest>
struct multiple_common_reference<void_t<common_reference_t<T1, T2>>, T1, T2,
                                 Rest...>
    : common_reference<common_reference_t<T1, T2>, Rest...> {
};

} // namespace detail

template <typename T1, typename T2, typename... Rest>
struct common_reference<T1, T2, Rest...>
    : detail::multiple_common_reference<void, T1, T2, Rest...> {
};

namespace detail {

template <typename... T>
using checked_common_ref_t = test_t<common_reference_t, T...>;
}

NANO_END_NAMESPACE

#endif

NANO_BEGIN_NAMESPACE

using std::common_type;
using std::common_type_t;

namespace detail {

template <typename... T>
using checked_common_type_t = test_t<common_type_t, T...>;
}

NANO_END_NAMESPACE

#endif


#include <functional>

NANO_BEGIN_NAMESPACE

// [concepts.lib.corelang.same]
template <typename T, typename U>
NANO_CONCEPT Same = std::is_same<T, U>::value;

// [concepts.lib.corelang.derived]

// FIXME: Spec doesn't use remove_reference_t here, not sure if it should
template <typename Derived, typename Base>
NANO_CONCEPT DerivedFrom = std::is_base_of<Base, Derived>::value&&
    std::is_convertible<const volatile std::remove_reference_t<Derived>*,
                        const volatile std::remove_reference_t<Base>*>::value;

// [concepts.lib.corelang.convertibleto]
namespace detail {

struct ConvertibleTo_req {
    template <typename From, typename To>
    auto requires_(From (&f)()) -> decltype(static_cast<To>(f()));
};

} // namespace detail

// [concepts.lib.corelang.convertibleto]
template <typename From, typename To>
NANO_CONCEPT ConvertibleTo = std::is_convertible<From, To>::value&&
    detail::requires_<detail::ConvertibleTo_req, From, To>;

// [concepts.lib.corelang.commonref]
template <typename T, typename U>
NANO_CONCEPT CommonReference = Same<detail::checked_common_ref_t<T, U>,
                                    detail::checked_common_ref_t<U, T>>&&
    ConvertibleTo<T, detail::checked_common_ref_t<T, U>>&&
        ConvertibleTo<U, detail::checked_common_ref_t<T, U>>;

// [concepts.lib.corelang.common]
template <typename T, typename U>
NANO_CONCEPT Common = Same<detail::checked_common_type_t<T, U>,
                           detail::checked_common_type_t<U, T>>&&
    ConvertibleTo<T, detail::checked_common_type_t<T, U>>&& ConvertibleTo<
        U, detail::checked_common_type_t<
               T, U>>&& CommonReference<std::add_lvalue_reference_t<const T>,
                                        std::add_lvalue_reference_t<const U>>&&
        CommonReference<
            std::add_lvalue_reference_t<detail::checked_common_type_t<T, U>>,
            detail::checked_common_ref_t<std::add_lvalue_reference_t<const T>,
                                         std::add_lvalue_reference_t<const U>>>;

// [concepts.lib.corelang.integral]
template <typename T>
NANO_CONCEPT Integral = std::is_integral<T>::value;

// [concepts.lib.corelang.signedintegral]
template <typename T>
NANO_CONCEPT SignedIntegral = Integral<T>&& std::is_signed<T>::value;

// [concepts.lib.corelang.unsignedintegral]
template <typename T>
NANO_CONCEPT UnsignedIntegral = Integral<T> && !SignedIntegral<T>;

// [concepts.lib.corelang.assignable]

namespace detail {

struct Assignable_req {
    template <typename LHS, typename RHS>
    auto requires_(LHS lhs, RHS&& rhs) -> decltype(valid_expr(
        lhs = std::forward<RHS>(rhs),
        requires_expr<Same<decltype(lhs = std::forward<RHS>(rhs)), LHS>>{}));
};

} // namespace detail

template <typename LHS, typename RHS>
NANO_CONCEPT Assignable = std::is_lvalue_reference<LHS>::value&&
    CommonReference<detail::clref_t<std::remove_reference_t<LHS>>,
                    detail::clref_t<std::remove_reference_t<RHS>>>&&
        detail::requires_<detail::Assignable_req, LHS, RHS>;

// [concepts.lib.corelang.destructible]
template <typename T>
NANO_CONCEPT Destructible = std::is_nothrow_destructible<T>::value;

// [concepts.lib.corelang.constructible]
template <typename T, typename... Args>
NANO_CONCEPT Constructible =
    Destructible<T>&& std::is_constructible<T, Args...>::value;

// [concepts.lib.corelang.defaultconstructible]
template <typename T>
NANO_CONCEPT DefaultConstructible = Constructible<T>;

// [concepts.lib.corelang.moveconstructible]
template <typename T>
NANO_CONCEPT MoveConstructible = Constructible<T, T>&& ConvertibleTo<T, T>;

// [concepts.lib.corelang.copyconstructible]
template <typename T>
NANO_CONCEPT CopyConstructible = MoveConstructible<T>&& Constructible<
    T, detail::lref_t<T>>&& ConvertibleTo<detail::lref_t<T>, T>&&
    Constructible<T, detail::lref_t<T>>&& ConvertibleTo<detail::clref_t<T>, T>&&
        Constructible<T, const T>&& ConvertibleTo<const T, T>;

NANO_END_NAMESPACE

#endif

// nanorange/detail/concepts/movable.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_CONCEPTS_MOVABLE_HPP
#define NANORANGE_DETAIL_CONCEPTS_MOVABLE_HPP


// nanorange/detail/concepts/swappable.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_CONCEPTS_SWAPPABLE_HPP_INCLUDED
#define NANORANGE_DETAIL_CONCEPTS_SWAPPABLE_HPP_INCLUDED


// nanorange/detail/swap.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_SWAP_HPP_INCLUDED
#define NANORANGE_DETAIL_SWAP_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

// [range.swap]

namespace detail {
namespace swap_ {

#ifndef MSVC_NO_POISON_PILLS
template <typename T>
void swap(T&, T&) = delete;

template <typename T, std::size_t N>
void swap(T (&)[N], T (&)[N]) = delete;
#endif

struct fn {
private:
    template <typename T, typename U>
    static constexpr auto impl(T&& t, U&& u, priority_tag<2>) noexcept(
        noexcept(swap(std::forward<T>(t), std::forward<U>(u))))
        -> decltype(static_cast<void>(swap(std::forward<T>(t),
                                           std::forward<U>(u))))
    {
        (void) swap(std::forward<T>(t), std::forward<U>(u));
    }

    template <typename T, typename U, std::size_t N, typename F = fn>
    static constexpr auto
        impl(T (&t)[N], U (&u)[N],
             priority_tag<1>) noexcept(noexcept(std::declval<F&>()(*t, *u)))
            -> decltype(std::declval<F&>()(*t, *u))
    {
        for (std::size_t i = 0; i < N; ++i) {
            fn::impl(t[i], u[i], priority_tag<2>{});
        }
    }

    template <typename T>
    static constexpr auto impl(T& a, T& b, priority_tag<0>) noexcept(
        std::is_nothrow_move_constructible<T>::value&&
            std::is_nothrow_assignable<T&, T>::value)
        -> std::enable_if_t<MoveConstructible<T> && Assignable<T&, T>>
    {
        T temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }

public:
    template <typename T, typename U>
    constexpr auto operator()(T&& t, U&& u) const
        noexcept(noexcept(fn::impl(std::forward<T>(t), std::forward<U>(u),
                                   priority_tag<2>{})))
            -> decltype(fn::impl(std::forward<T>(t), std::forward<U>(u),
                                 priority_tag<2>{}))
    {
        return fn::impl(std::forward<T>(t), std::forward<U>(u),
                        priority_tag<2>{});
    }
};

} // end namespace swap_
} // end namespace detail

NANO_INLINE_VAR(detail::swap_::fn, swap)

NANO_END_NAMESPACE

#endif


NANO_BEGIN_NAMESPACE

namespace detail {

// Implement the Swappable concepts now we have swap()

struct Swappable_req {
    template <typename T>
    auto requires_(T& a, T& b) -> decltype(ranges::swap(a, b));
};

struct SwappableWith_req {
    template <typename T, typename U>
    auto requires_(T&& t, U&& u)
        -> decltype(ranges::swap(std::forward<T>(t), std::forward<T>(t)),
                    ranges::swap(std::forward<U>(u), std::forward<U>(u)),
                    ranges::swap(std::forward<T>(t), std::forward<U>(u)),
                    ranges::swap(std::forward<U>(u), std::forward<T>(t)));
};

} // namespace detail

template <typename T>
NANO_CONCEPT Swappable = detail::requires_<detail::Swappable_req, T>;

template <typename T, typename U>
NANO_CONCEPT SwappableWith = detail::requires_<detail::SwappableWith_req, T, U>;

NANO_END_NAMESPACE

#endif


// Movable is listed as an object concept, but is required for the definition
// of Boolean, so we treat it specially

NANO_BEGIN_NAMESPACE

template <typename T>
NANO_CONCEPT Movable = std::is_object<T>::value&& MoveConstructible<T>&&
    Assignable<detail::lref_t<T>, T>&& Swappable<T>;

NANO_END_NAMESPACE

#endif



NANO_BEGIN_NAMESPACE

// [concepts.lib.compare.boolean]

namespace detail {

struct Boolean_req {
    template <typename B>
    auto requires_(const std::remove_reference_t<B>& b1,
                   const std::remove_reference_t<B>& b2, const bool a)
        -> decltype(valid_expr(
            requires_expr<
                ConvertibleTo<const std::remove_reference_t<B&>, bool>>{},
            !b1, requires_expr<ConvertibleTo<decltype(!b1), bool>>{}, b1&& a,
            requires_expr<Same<decltype(b1 && a), bool>>{}, b1 || a,
            requires_expr<Same<decltype(b1 || a), bool>>{}, b1&& b2,
            requires_expr<Same<decltype(b1 && b2), bool>>{}, a&& b2,
            requires_expr<Same<decltype(a && b2), bool>>{}, b1 || b2,
            requires_expr<Same<decltype(b1 || b2), bool>>{}, a || b2,
            requires_expr<Same<decltype(a || b2), bool>>{}, b1 == b2,
            requires_expr<ConvertibleTo<decltype(b1 == b2), bool>>{}, b1 == a,
            requires_expr<ConvertibleTo<decltype(b1 == a), bool>>{}, a == b2,
            requires_expr<ConvertibleTo<decltype(a == b2), bool>>{}, b1 != b2,
            requires_expr<ConvertibleTo<decltype(b1 != b2), bool>>{}, b1 != a,
            requires_expr<ConvertibleTo<decltype(b1 != a), bool>>{}, a != b2,
            requires_expr<ConvertibleTo<decltype(a != b2), bool>>{}));
};

} // namespace detail

template <typename B>
NANO_CONCEPT Boolean = Movable<detail::remove_cvref_t<B>>&&
    detail::requires_<detail::Boolean_req, B>;

// [concepts.lib.compare.equalitycomparable]

namespace detail {

struct WeaklyEqualityComparableWith_req {
    template <typename T, typename U>
    auto requires_(const std::remove_reference_t<T>& t,
                   const std::remove_reference_t<U>& u)
        -> decltype(
            valid_expr(t == u, requires_expr<Boolean<decltype(t == u)>>{},
                       t != u, requires_expr<Boolean<decltype(t != u)>>{},
                       u == t, requires_expr<Boolean<decltype(u == t)>>{},
                       u != t, requires_expr<Boolean<decltype(u != t)>>{}));
};

template <typename T, typename U>
NANO_CONCEPT WeaklyEqualityComparableWith =
    requires_<WeaklyEqualityComparableWith_req, T, U>;

} // namespace detail

template <typename T>
NANO_CONCEPT EqualityComparable = detail::WeaklyEqualityComparableWith<T, T>;

template <typename T, typename U>
NANO_CONCEPT EqualityComparableWith =
    EqualityComparable<T>&& EqualityComparable<U>&&
        CommonReference<detail::clref_t<std::remove_reference_t<T>>,
                        detail::clref_t<std::remove_reference_t<U>>>&&
            EqualityComparable<detail::checked_common_ref_t<
                detail::clref_t<std::remove_reference_t<T>>,
                detail::clref_t<std::remove_reference_t<U>>>>&&
                detail::WeaklyEqualityComparableWith<T, U>;

// [concepts.lib.compare.stricttotallyordered]

namespace detail {

struct StrictTotallyOrdered_req {
    template <typename T>
    auto requires_(const std::remove_reference_t<T>& a,
                   const std::remove_reference_t<T>& b)
        -> decltype(
            valid_expr(a<b, requires_expr<Boolean<decltype(a < b)>>{}, a> b,
                       requires_expr<Boolean<decltype(a > b)>>{}, a <= b,
                       requires_expr<Boolean<decltype(a <= b)>>{}, a >= b,
                       requires_expr<Boolean<decltype(a >= b)>>{}));
};

} // namespace detail

template <typename T>
NANO_CONCEPT StrictTotallyOrdered = EqualityComparable<T>&&
    detail::requires_<detail::StrictTotallyOrdered_req, T>;

namespace detail {

struct StrictTotallyOrderedWith_req {
    template <typename T, typename U>
    auto requires_(const std::remove_reference_t<T>& t,
                   const std::remove_reference_t<U>& u)
        -> decltype(
            valid_expr(t<u, requires_expr<Boolean<decltype(t < u)>>{}, t> u,
                       requires_expr<Boolean<decltype(t > u)>>{}, t <= u,
                       requires_expr<Boolean<decltype(t <= u)>>{}, t >= u,
                       requires_expr<Boolean<decltype(t >= u)>>{},
                       u<t, requires_expr<Boolean<decltype(u < t)>>{}, u> t,
                       requires_expr<Boolean<decltype(u > t)>>{}, u <= t,
                       requires_expr<Boolean<decltype(u <= t)>>{}, u >= t,
                       requires_expr<Boolean<decltype(u >= t)>>{}));
};

} // namespace detail

template <typename T, typename U>
NANO_CONCEPT StrictTotallyOrderedWith =
    StrictTotallyOrdered<T>&& StrictTotallyOrdered<U>&&
        CommonReference<detail::clref_t<std::remove_reference_t<T>>,
                        detail::clref_t<std::remove_reference_t<U>>>&&
            StrictTotallyOrdered<detail::checked_common_ref_t<
                detail::clref_t<std::remove_reference_t<T>>,
                detail::clref_t<std::remove_reference_t<T>>>>&&
                EqualityComparableWith<T, U>&& detail::requires_<
                    detail::StrictTotallyOrderedWith_req, T, U>;

NANO_END_NAMESPACE

#endif



// nanorange/detail/functional/invoke.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_FUNCTIONAL_INVOKE_HPP_INCLUDED
#define NANORANGE_DETAIL_FUNCTIONAL_INVOKE_HPP_INCLUDED

#include <functional>




NANO_BEGIN_NAMESPACE

namespace detail {

// This is a reimplementation of std::invoke, which for some stupid
// reason is not constexpr in C++17
inline namespace invoke_ {

template <typename>
constexpr bool is_reference_wrapper_v = false;

template <typename T>
constexpr bool is_reference_wrapper_v<std::reference_wrapper<T>> = true;

struct fn {
private:
    template <class Base, class T, class Derived, class... Args>
    static constexpr auto
    impl(T Base::*pmf, Derived&& ref,
         Args&&... args) noexcept(noexcept((std::forward<Derived>(ref).*
                                            pmf)(std::forward<Args>(args)...)))
        -> std::enable_if_t<
            std::is_function<T>::value &&
                std::is_base_of<Base, std::decay_t<Derived>>::value,
            decltype((std::forward<Derived>(ref).*
                      pmf)(std::forward<Args>(args)...))>
    {
        return (std::forward<Derived>(ref).*pmf)(std::forward<Args>(args)...);
    }

    template <class Base, class T, class RefWrap, class... Args>
    static constexpr auto
    impl(T Base::*pmf, RefWrap&& ref, Args&&... args) noexcept(
        noexcept((ref.get().*pmf)(std::forward<Args>(args)...)))
        -> std::enable_if_t<std::is_function<T>::value &&
                                is_reference_wrapper_v<std::decay_t<RefWrap>>,
                            decltype((ref.get().*
                                      pmf)(std::forward<Args>(args)...))>
    {
        return (ref.get().*pmf)(std::forward<Args>(args)...);
    }

    template <class Base, class T, class Pointer, class... Args>
    static constexpr auto
    impl(T Base::*pmf, Pointer&& ptr,
         Args&&... args) noexcept(noexcept(((*std::forward<Pointer>(ptr)).*
                                            pmf)(std::forward<Args>(args)...)))
        -> std::enable_if_t<
            std::is_function<T>::value &&
                !is_reference_wrapper_v<std::decay_t<Pointer>> &&
                !std::is_base_of<Base, std::decay_t<Pointer>>::value,
            decltype(((*std::forward<Pointer>(ptr)).*
                      pmf)(std::forward<Args>(args)...))>
    {
        return ((*std::forward<Pointer>(ptr)).*
                pmf)(std::forward<Args>(args)...);
    }

    template <class Base, class T, class Derived>
    static constexpr auto
    impl(T Base::*pmd,
         Derived&& ref) noexcept(noexcept(std::forward<Derived>(ref).*pmd))
        -> std::enable_if_t<
            !std::is_function<T>::value &&
                std::is_base_of<Base, std::decay_t<Derived>>::value,
            decltype(std::forward<Derived>(ref).*pmd)>
    {
        return std::forward<Derived>(ref).*pmd;
    }

    template <class Base, class T, class RefWrap>
    static constexpr auto impl(T Base::*pmd,
                               RefWrap&& ref) noexcept(noexcept(ref.get().*pmd))
        -> std::enable_if_t<!std::is_function<T>::value &&
                                is_reference_wrapper_v<std::decay_t<RefWrap>>,
                            decltype(ref.get().*pmd)>
    {
        return ref.get().*pmd;
    }

    template <class Base, class T, class Pointer>
    static constexpr auto
    impl(T Base::*pmd,
         Pointer&& ptr) noexcept(noexcept((*std::forward<Pointer>(ptr)).*pmd))
        -> std::enable_if_t<
            !std::is_function<T>::value &&
                !is_reference_wrapper_v<std::decay_t<Pointer>> &&
                !std::is_base_of<Base, std::decay_t<Pointer>>::value,
            decltype((*std::forward<Pointer>(ptr)).*pmd)>
    {
        return (*std::forward<Pointer>(ptr)).*pmd;
    }

    template <class F, class... Args>
    static constexpr auto impl(F&& f, Args&&... args) noexcept(
        noexcept(std::forward<F>(f)(std::forward<Args>(args)...)))
        -> std::enable_if_t<
            !std::is_member_pointer<std::decay_t<F>>::value,
            decltype(std::forward<F>(f)(std::forward<Args>(args)...))>
    {
        return std::forward<F>(f)(std::forward<Args>(args)...);
    }

public:
    template <typename F, typename... Args>
    constexpr auto operator()(F&& f, Args&&... args) const noexcept(
        noexcept(fn::impl(std::forward<F>(f), std::forward<Args>(args)...)))
        -> decltype(fn::impl(std::forward<F>(f), std::forward<Args>(args)...))
    {
        return fn::impl(std::forward<F>(f), std::forward<Args>(args)...);
    }
};

} // namespace invoke_
} // namespace detail

NANO_INLINE_VAR(nano::detail::invoke_::fn, invoke)

namespace detail {

template <typename Void, typename, typename...>
struct invoke_result_helper {
};

template <typename F, typename... Args>
struct invoke_result_helper<
    void_t<decltype(nano::invoke(std::declval<F>(), std::declval<Args>()...))>,
    F, Args...> {
    using type =
        decltype(nano::invoke(std::declval<F>(), std::declval<Args>()...));
};

} // namespace detail

template <typename F, typename... Args>
struct invoke_result : detail::invoke_result_helper<void, F, Args...> {
};

template <typename F, typename... Args>
using invoke_result_t = typename invoke_result<F, Args...>::type;

namespace detail {

template <typename F, typename... Args>
using checked_invoke_result_t = test_t<invoke_result_t, F, Args...>;
}

NANO_END_NAMESPACE

#endif


NANO_BEGIN_NAMESPACE

// [concepts.lib.object.copyable]
template <typename T>
NANO_CONCEPT Copyable = CopyConstructible<T>&& Movable<T>&&
    Assignable<detail::lref_t<T>, detail::clref_t<T>>;

// [concepts.lib.object.semiregular]
template <typename T>
NANO_CONCEPT Semiregular = Copyable<T>&& DefaultConstructible<T>;

// [concepts.lib.object.regular]
template <typename T>
NANO_CONCEPT Regular = Semiregular<T>&& EqualityComparable<T>;

namespace detail {

struct Invocable_req {
    /*template <typename F, typename... Args>
    auto requires_(F&& f, Args&&... args) -> decltype(
        nano::invoke(std::forward<F>(f), std::forward<Args>(args)...)
    );*/
    // FIXME: Clang really doesn't like the above, work out why
    template <typename F, typename... Args>
    auto requires_(F&& f, Args&&... args) -> invoke_result_t<F, Args...>;
};

} // namespace detail

template <typename F, typename... Args>
NANO_CONCEPT Invocable = detail::requires_<detail::Invocable_req, F, Args...>;

template <typename F, typename... Args>
NANO_CONCEPT RegularInvocable = Invocable<F, Args...>;

template <typename F, typename... Args>
NANO_CONCEPT Predicate = RegularInvocable<F, Args...>&&
    Boolean<detail::checked_invoke_result_t<F, Args...>>;

template <typename R, typename T, typename U>
NANO_CONCEPT Relation = Predicate<R, T, T>&& Predicate<R, U, U>&&
    CommonReference<detail::clref_t<std::remove_reference_t<T>>,
                    detail::clref_t<std::remove_reference_t<U>>>&&
        Predicate<R,
                  detail::checked_common_ref_t<
                      detail::clref_t<std::remove_reference_t<T>>,
                      detail::clref_t<std::remove_reference_t<U>>>,
                  detail::checked_common_ref_t<
                      detail::clref_t<std::remove_reference_t<T>>,
                      detail::clref_t<std::remove_reference_t<U>>>>&&
            Predicate<R, T, U>&& Predicate<R, U, T>;

template <typename R, typename T, typename U>
NANO_CONCEPT StrictWeakOrder = Relation<R, T, U>;

NANO_END_NAMESPACE

#endif

// nanorange/detail/iterator/associated_types.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_ITERATOR_ASSOCIATED_TYPES_HPP_INCLUDED
#define NANORANGE_DETAIL_ITERATOR_ASSOCIATED_TYPES_HPP_INCLUDED




NANO_BEGIN_NAMESPACE

template <typename>
struct difference_type;

namespace detail {

template <typename, typename = void>
struct difference_type_ {
};

template <typename T>
struct difference_type_<T*>
    : std::enable_if<std::is_object<T>::value, std::ptrdiff_t> {
};

template <class I>
struct difference_type_<const I> : difference_type<std::decay_t<I>> {
};

template <typename, typename = void>
constexpr bool has_member_difference_type_v = false;

template <typename T>
constexpr bool
    has_member_difference_type_v<T, void_t<typename T::difference_type>> = true;

template <typename T>
struct difference_type_<T, std::enable_if_t<has_member_difference_type_v<T>>> {
    using type = typename T::difference_type;
};

template <typename T>
struct difference_type_<
    T, std::enable_if_t<!std::is_pointer<T>::value &&
                        !has_member_difference_type_v<T> &&
                        Integral<decltype(std::declval<const T&>() -
                                          std::declval<const T&>())>>>
    : std::make_signed<decltype(std::declval<T>() - std::declval<T>())> {
};

} // namespace detail

template <typename T>
struct difference_type : detail::difference_type_<T> {
};

template <typename T>
using difference_type_t = typename difference_type<T>::type;

// [range.iterator.assoc.types.value_type]

template <typename>
struct value_type;

namespace detail {

template <typename, typename = void>
struct value_type_helper {
};

template <typename T>
struct value_type_helper<T*>
    : std::enable_if<std::is_object<T>::value, std::remove_cv_t<T>> {
};

template <typename T>
struct value_type_helper<T, std::enable_if_t<std::is_array<T>::value>>
    : value_type<std::decay_t<T>> {
};

template <typename I>
struct value_type_helper<const I, std::enable_if_t<!std::is_array<I>::value>>
    : value_type<std::decay_t<I>> {
};

template <typename T, typename V = typename T::value_type>
struct member_value_type : std::enable_if<std::is_object<V>::value, V> {
};

template <typename T, typename E = typename T::element_type>
struct member_element_type : std::enable_if<std::is_object<E>::value, E> {
};

template <typename T>
using member_value_type_t = typename T::value_type;

template <typename T>
constexpr bool has_member_value_type_v = exists_v<member_value_type_t, T>;

template <typename T>
using member_element_type_t = typename T::element_type;

template <typename T>
constexpr bool has_member_element_type_v = exists_v<member_element_type_t, T>;

template <typename T>
struct value_type_helper<T, std::enable_if_t<has_member_value_type_v<T>>>
    : member_value_type<T> {
};

template <typename T>
struct value_type_helper<T, std::enable_if_t<has_member_element_type_v<T>>>
    : member_element_type<T> {
};

} // namespace detail

template <typename T>
struct value_type : detail::value_type_helper<T> {
};

template <typename T>
using value_type_t = typename value_type<T>::type;

NANO_END_NAMESPACE

#endif

// nanorange/detail/iterator/traits.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_ITERATOR_TRAITS_HPP_INCLUDED
#define NANORANGE_DETAIL_ITERATOR_TRAITS_HPP_INCLUDED

// nanorange/detail/iterator/dereferenceable.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_ITERATOR_DEREFERENCABLE_HPP_INCLUDED
#define NANORANGE_DETAIL_ITERATOR_DEREFERENCABLE_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

namespace detail {

template <typename T>
auto not_void(T &&) -> int;

struct Dereferenceable_req {
    template <typename T>
    auto requires_(T& t) -> decltype(valid_expr(not_void(*t)));
};

template <typename T>
NANO_CONCEPT Dereferenceable = requires_<Dereferenceable_req, T>;

} // namespace detail

NANO_END_NAMESPACE

#endif

// nanorange/detail/iterator/iter_move.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_ITERATOR_ITER_MOVE_HPP_INCLUDED
#define NANORANGE_DETAIL_ITERATOR_ITER_MOVE_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

namespace detail {
namespace iter_move_ {

void iter_move();

struct fn {
private:
    template <typename T>
    static constexpr auto impl(T&& t, priority_tag<2>) noexcept(
        noexcept(static_cast<decltype(iter_move(t))>(iter_move(t))))
        -> decltype(static_cast<decltype(iter_move(t))>(iter_move(t)))
    {
        return static_cast<decltype(iter_move(t))>(iter_move(t));
    }

    template <typename T>
    static constexpr auto impl(T& t, priority_tag<1>) noexcept(
        noexcept(std::move(*std::declval<T&>()))) -> decltype(std::move(*t))
    {
        return std::move(*t);
    }

    template <typename T>
    static constexpr auto
    impl(T&& t,
         priority_tag<0>) noexcept(noexcept(static_cast<decltype(*t)>(*t)))
        -> decltype(static_cast<decltype(*t)>(*t))
    {
        return static_cast<decltype(*t)>(*t);
    }

public:
    template <typename T>
    constexpr auto operator()(T&& t) const
        noexcept(noexcept(fn::impl(std::forward<T>(t), priority_tag<2>{})))
            -> decltype(fn::impl(std::forward<T>(t), priority_tag<2>{}))
    {
        return fn::impl(std::forward<T>(t), priority_tag<2>{});
    }
};

} // namespace iter_move_
} // namespace detail

NANO_INLINE_VAR(detail::iter_move_::fn, iter_move)

NANO_END_NAMESPACE

#endif


#include <iterator>

NANO_BEGIN_NAMESPACE

// [range.iterator.assoc.types.iterator_category]
// FIXME: Not to spec -- do we want to duplicate all the iterator tags, or just
// use the std:: ones?

using std::bidirectional_iterator_tag;
using std::forward_iterator_tag;
using std::input_iterator_tag;
using std::output_iterator_tag;
using std::random_access_iterator_tag;

template <typename T>
struct iterator_category;

namespace detail {

template <typename T, typename = void>
struct iterator_category_ {
};

template <typename T>
struct iterator_category_<T*>
    : std::enable_if<std::is_object<T>::value, random_access_iterator_tag> {
};

template <typename T>
struct iterator_category_<const T> : iterator_category<T> {
};

template <typename T>
struct iterator_category_<T, void_t<typename T::iterator_category>> {
    using type = typename T::iterator_category;
};

} // namespace detail

template <typename T>
struct iterator_category : detail::iterator_category_<T> {
};

template <typename T>
using iterator_category_t = typename iterator_category<T>::type;

namespace detail {

template <typename, typename = void>
struct reference_helper {
};

template <typename T>
struct reference_helper<T, std::enable_if_t<Dereferenceable<T>>> {
    using type = decltype(*std::declval<T&>());
};

} // namespace detail

template <typename T>
using reference_t = typename detail::reference_helper<T>::type;

template <typename T>
using rvalue_reference_t = decltype(ranges::iter_move(std::declval<T&>()));

namespace detail {

template <typename T>
using checked_difference_type_t = test_t<difference_type_t, T>;

template <typename T>
using checked_value_type_t = test_t<value_type_t, T>;

template <typename T>
using checked_iterator_category_t = test_t<iterator_category_t, T>;

template <typename T>
using checked_reference_t = test_t<reference_t, T>;

template <typename T>
using checked_rvalue_ref_t = test_t<rvalue_reference_t, T>;

} // namespace detail

NANO_END_NAMESPACE

#endif


NANO_BEGIN_NAMESPACE

// [range.iterators.readable]
namespace detail {

struct Readable_req {
    template <typename In>
    auto requires_()
        -> decltype(valid_expr(std::declval<value_type_t<In>>(),
                               std::declval<reference_t<In>>(),
                               std::declval<rvalue_reference_t<In>>()));
};

} // namespace detail

template <typename In>
NANO_CONCEPT Readable =
    detail::requires_<detail::Readable_req, In>&& CommonReference<
        detail::checked_reference_t<In>&&, detail::checked_value_type_t<In>&>&&
        CommonReference<detail::checked_reference_t<In>&&,
                        detail::checked_rvalue_ref_t<In>&>&&
            CommonReference<detail::checked_rvalue_ref_t<In>&&,
                            const detail::checked_value_type_t<In>&>;

// [range.iterators.writable]
namespace detail {

struct Writable_req {
    template <typename Out, typename T>
    auto requires_(Out&& o, T&& t) -> decltype(valid_expr(
        *o = std::forward<T>(t), *std::forward<Out>(o) = std::forward<T>(t),
        const_cast<const reference_t<Out>&&>(*o) = std::forward<T>(t),
        const_cast<const reference_t<Out>&&>(*std::forward<Out>(o)) =
            std::forward<T>(t)));
};

} // namespace detail

template <typename Out, typename T>
NANO_CONCEPT Writable = detail::requires_<detail::Writable_req, Out, T>;

// [range.iterators.weaklyincrementable]

namespace detail {

template <typename T, typename Deduced>
auto same_lv(Deduced&) -> std::enable_if_t<Same<T, Deduced>, int>;

template <typename T, typename Deduced>
auto same_rv(Deduced &&) -> std::enable_if_t<Same<T, Deduced>, int>;

struct WeaklyIncrementable_req {
    template <typename I>
    auto requires_(I i) -> decltype(
        valid_expr(std::declval<difference_type_t<I>>(),
                   requires_expr<SignedIntegral<difference_type_t<I>>>{},
                   same_lv<I>(++i), i++));
};

} // namespace detail

template <typename I>
NANO_CONCEPT WeaklyIncrementable =
    Semiregular<I>&& detail::requires_<detail::WeaklyIncrementable_req, I>;

// [range.iterators.incrementable]

namespace detail {

struct Incrementable_req {
    template <typename I>
    auto requires_(I i) -> decltype(valid_expr(same_rv<I>(i++)));
};

} // namespace detail

template <typename I>
NANO_CONCEPT Incrementable = Regular<I>&& WeaklyIncrementable<I>&&
    detail::requires_<detail::Incrementable_req, I>;

// [range.iterators.iterator]

namespace detail {

struct Iterator_req {
    template <typename I>
    auto requires_(I i) -> decltype(valid_expr(not_void(*i)));
};

} // namespace detail

template <typename I>
NANO_CONCEPT Iterator =
    detail::requires_<detail::Iterator_req, I>&& WeaklyIncrementable<I>;

// [range.iterators.sentinel]

template <typename S, typename I>
NANO_CONCEPT Sentinel =
    Semiregular<S>&& Iterator<I>&& detail::WeaklyEqualityComparableWith<S, I>;

// [range.iterators.sizedsentinel]

template <typename S, typename I>
constexpr bool disable_sized_sentinel = false;

namespace detail {

struct SizedSentinel_req {
    template <typename S, typename I>
    auto requires_(const S& s, const I& i)
        -> decltype(valid_expr(same_rv<difference_type_t<I>>(s - i),
                               same_rv<difference_type_t<I>>(i - s)));
};

} // namespace detail

template <typename S, typename I>
NANO_CONCEPT SizedSentinel =
    Sentinel<S, I> &&
    !disable_sized_sentinel<std::remove_cv_t<S>, std::remove_cv_t<I>> &&
    detail::requires_<detail::SizedSentinel_req, S, I>;

// [range.iterators.input]

template <typename I>
NANO_CONCEPT InputIterator =
    Iterator<I>&& Readable<I>&& detail::exists_v<iterator_category_t, I>&&
        DerivedFrom<detail::checked_iterator_category_t<I>, input_iterator_tag>;

// [ranges.iterator.output]

namespace detail {

struct OutputIterator_req {
    template <typename I, typename T>
    auto requires_(I i, T&& t)
        -> decltype(valid_expr(*i++ = std::forward<T>(t)));
};

} // namespace detail

template <typename I, typename T>
NANO_CONCEPT OutputIterator = Iterator<I>&& Writable<I, T>&&
    detail::requires_<detail::OutputIterator_req, I, T>;

// [ranges.iterators.forward]

template <typename I>
NANO_CONCEPT ForwardIterator = InputIterator<I>&&
    DerivedFrom<detail::checked_iterator_category_t<I>, forward_iterator_tag>&&
        Incrementable<I>&& Sentinel<I, I>;

// [ranges.iterators.bidirectional]

namespace detail {

struct BidirectionalIterator_req {
    template <typename I>
    auto requires_(I i)
        -> decltype(valid_expr(same_lv<I>(--i), same_rv<I>(i--)));
};

} // namespace detail

template <typename I>
NANO_CONCEPT BidirectionalIterator =
    ForwardIterator<I>&& DerivedFrom<detail::checked_iterator_category_t<I>,
                                     bidirectional_iterator_tag>&&
        detail::requires_<detail::BidirectionalIterator_req, I>;

// [ranges.iterators.random.access]

namespace detail {

struct RandomAccessIterator_req {
    template <typename I>
    auto requires_(I i, const I j, const difference_type_t<I> n) -> decltype(
        valid_expr(same_lv<I>(i += n), same_rv<I>(j + n),
                   n + j, // same_rv<I>(n + j) -- FIXME: MSVC doesn't like this
                          // with I = int*, find out why
                   same_lv<I>(i -= n), same_rv<I>(j - n), j[n],
                   requires_expr<Same<decltype(j[n]), reference_t<I>>>{}));
};

} // namespace detail

template <typename I>
NANO_CONCEPT RandomAccessIterator = BidirectionalIterator<I>&& DerivedFrom<
    detail::checked_iterator_category_t<I>, random_access_iterator_tag>&&
    StrictTotallyOrdered<I>&& SizedSentinel<I, I>&&
        detail::requires_<detail::RandomAccessIterator_req, I>;


// Extension: used for constraining iterators for existing STL algos

namespace detail {

template <typename I,
          typename T = std::iterator_traits<I>,
          typename = typename T::value_type,
          typename = typename T::difference_type,
          typename = typename T::reference,
          typename = typename T::pointer,
          typename = typename T::iterator_category>
using legacy_iterator_traits_t = void;

template <typename I>
NANO_CONCEPT Cpp98Iterator = Iterator<I> && exists_v<legacy_iterator_traits_t, I>;

}

NANO_END_NAMESPACE

#endif


#include <iterator> // for make_reverse_iterator

NANO_BEGIN_NAMESPACE

// [range.access.begin]

namespace detail {
namespace begin_ {

// MSVC doesn't mind this for some reason
template <typename T>
void begin(T&&) = delete;

template <typename T>
void begin(std::initializer_list<T>&&) = delete;

struct fn {
private:
    template <typename T, std::size_t N>
    static constexpr auto impl(T (&t)[N], priority_tag<2>) noexcept
        -> decltype((t) + 0)
    {
        return (t) + 0;
    }

    template <typename T>
    static constexpr auto
    impl(T& t, priority_tag<1>) noexcept(noexcept(decay_copy(t.begin())))
        -> std::enable_if_t<Iterator<decltype(decay_copy(t.begin()))>,
                            decltype(decay_copy(t.begin()))>
    {
        return decay_copy(t.begin());
    }

    template <typename T>
    static constexpr auto impl(T&& t, priority_tag<0>) noexcept(
        noexcept(decay_copy(begin(std::forward<T>(t)))))
        -> std::enable_if_t<
            Iterator<decltype(decay_copy(begin(std::forward<T>(t))))>,
            decltype(decay_copy(begin(std::forward<T>(t))))>
    {
        return decay_copy(begin(t));
    }

public:
    template <typename T>
    constexpr auto operator()(T&& t) const
        noexcept(noexcept(fn::impl(std::forward<T>(t), priority_tag<2>{})))
            -> decltype(fn::impl(std::forward<T>(t), priority_tag<2>{}))
    {
        return fn::impl(std::forward<T>(t), priority_tag<2>{});
    }
};

} // namespace begin_
} // namespace detail

NANO_INLINE_VAR(detail::begin_::fn, begin)

namespace detail {
namespace end_ {

template <typename T>
void end(T&&) = delete;

template <typename T>
void end(std::initializer_list<T>&&) = delete;

struct fn {
private:
    template <typename T, std::size_t N>
    static constexpr auto impl(T (&t)[N], priority_tag<2>) noexcept
        -> decltype(t + N)
    {
        return t + N;
    }

    template <typename T,
              typename S = decltype(decay_copy(std::declval<T&>().end())),
              typename I = decltype(ranges::begin(std::declval<T&>()))>
    static constexpr auto
    impl(T& t, priority_tag<1>) noexcept(noexcept(decay_copy(t.end())))
        -> std::enable_if_t<Sentinel<S, I>, decltype(decay_copy(t.end()))>
    {
        return decay_copy(t.end());
    }

    template <typename T,
              typename S = decltype(decay_copy(end(std::declval<T>()))),
              typename I = decltype(ranges::begin(std::declval<T>()))>
    static constexpr auto impl(T&& t, priority_tag<0>) noexcept(
        noexcept(decay_copy(end(std::forward<T>(t)))))
        -> std::enable_if_t<Sentinel<S, I>, S>
    {
        return decay_copy(end(std::forward<T>(t)));
    }

public:
    template <typename T>
    constexpr auto operator()(T&& t) const
        noexcept(noexcept(fn::impl(std::forward<T>(t), priority_tag<2>{})))
            -> decltype(fn::impl(std::forward<T>(t), priority_tag<2>{}))
    {
        return fn::impl(std::forward<T>(t), priority_tag<2>{});
    }
};

} // namespace end_
} // namespace detail

NANO_INLINE_VAR(detail::end_::fn, end)

// [range.access.cbegin]

namespace detail {
namespace cbegin_ {

struct fn {

    template <typename T>
    constexpr auto operator()(const T& t) const
        noexcept(noexcept(ranges::begin(t))) -> decltype(ranges::begin(t))
    {
        return ranges::begin(t);
    }

    template <typename T>
    constexpr auto operator()(const T&& t) const
        noexcept(noexcept(ranges::begin(static_cast<const T&&>(t))))
            -> decltype(ranges::begin(static_cast<const T&&>(t)))
    {
        return ranges::begin(static_cast<const T&&>(t));
    }
};

} // namespace cbegin_
} // namespace detail

NANO_INLINE_VAR(detail::cbegin_::fn, cbegin)

// [ranges.access.cend]

namespace detail {
namespace cend_ {

struct fn {

    template <typename T>
    constexpr auto operator()(const T& t) const
        noexcept(noexcept(ranges::end(t))) -> decltype(ranges::end(t))
    {
        return ranges::end(t);
    }

    template <typename T>
    constexpr auto operator()(const T&& t) const
        noexcept(noexcept(ranges::end(static_cast<const T&&>(t))))
            -> decltype(ranges::end(static_cast<const T&&>(t)))
    {
        return ranges::end(static_cast<const T&&>(t));
    }
};

} // namespace cend_
} // namespace detail

NANO_INLINE_VAR(detail::cend_::fn, cend)

namespace detail {
namespace rbegin_ {

template <typename T>
void rbegin(T&&) = delete;

// second poison pill needed for MSVC
template <typename T>
void rbegin(const T&&) = delete;

struct fn {
private:
    template <typename T,
              typename I = decltype(decay_copy(std::declval<T&>().rbegin()))>
    static constexpr auto
    impl(T& t, priority_tag<2>) noexcept(noexcept(decay_copy(t.rbegin())))
        -> std::enable_if_t<Iterator<I>, I>
    {
        return t.rbegin();
    }

    template <typename T,
              typename I = decltype(decay_copy(rbegin(std::declval<T&&>())))>
    static constexpr auto impl(T&& t, priority_tag<1>) noexcept(
        noexcept(decay_copy(rbegin(std::forward<T>(t)))))
        -> std::enable_if_t<Iterator<I>, I>
    {
        return rbegin(std::forward<T>(t));
    }

    template <typename T,
              typename I = decltype(ranges::begin(std::declval<T&&>())),
              typename S = decltype(ranges::end(std::declval<T&&>()))>
    static constexpr auto impl(T&& t, priority_tag<0>) noexcept(
        noexcept(std::make_reverse_iterator(ranges::end(std::forward<T>(t)))))
        -> std::enable_if_t<Same<I, S> && BidirectionalIterator<I>,
                            decltype(std::make_reverse_iterator(
                                ranges::end(std::forward<T>(t))))>
    {
        return std::make_reverse_iterator(ranges::end(std::forward<T>(t)));
    }

public:
    template <typename T>
    constexpr auto operator()(T&& t) const
        noexcept(noexcept(fn::impl(std::forward<T>(t), priority_tag<2>{})))
            -> decltype(fn::impl(std::forward<T>(t), priority_tag<2>{}))
    {
        return fn::impl(std::forward<T>(t), priority_tag<2>{});
    }
};

} // namespace rbegin_
} // namespace detail

NANO_INLINE_VAR(detail::rbegin_::fn, rbegin)

namespace detail {
namespace rend_ {

template <typename T>
void rend(T&&) = delete;

template <typename T>
void rend(const T&&) = delete;

struct fn {
private:
    template <typename T,
              typename I = decltype(ranges::begin(std::declval<T&>())),
              typename S = decltype(decay_copy(std::declval<T&>().rend()))>
    static constexpr auto
    impl(T& t, priority_tag<2>) noexcept(noexcept(decay_copy(t.rend())))
        -> std::enable_if_t<Sentinel<S, I>, S>
    {
        return t.rend();
    }

    template <typename T,
              typename I = decltype(ranges::begin(std::declval<T&&>())),
              typename S = decltype(decay_copy(rend(std::declval<T&&>())))>
    static constexpr auto impl(T&& t, priority_tag<1>) noexcept(
        noexcept(decay_copy(rend(std::forward<T>(t)))))
        -> std::enable_if_t<Sentinel<S, I>, S>
    {
        return rend(std::forward<T>(t));
    }

    template <typename T,
              typename I = decltype(ranges::begin(std::declval<T&&>())),
              typename S = decltype(ranges::end(std::declval<T&&>()))>
    static constexpr auto impl(T&& t, priority_tag<0>) noexcept(
        noexcept(std::make_reverse_iterator(ranges::begin(std::forward<T>(t)))))
        -> std::enable_if_t<Same<I, S> && BidirectionalIterator<I>,
                            decltype(std::make_reverse_iterator(
                                ranges::begin(std::forward<T>(t))))>
    {
        return std::make_reverse_iterator(ranges::begin(std::forward<T>(t)));
    }

public:
    template <typename T>
    constexpr auto operator()(T&& t) const
        noexcept(noexcept(fn::impl(std::forward<T>(t), priority_tag<2>{})))
            -> decltype(fn::impl(std::forward<T>(t), priority_tag<2>{}))
    {
        return fn::impl(std::forward<T>(t), priority_tag<2>{});
    }
};

} // namespace rend_
} // namespace detail

NANO_INLINE_VAR(detail::rend_::fn, rend)

namespace detail {
namespace crbegin_ {

struct fn {
    template <typename T>
    constexpr auto operator()(const T& t) const
        noexcept(noexcept(ranges::rbegin(t))) -> decltype(ranges::rbegin(t))
    {
        return ranges::rbegin(t);
    }

    template <typename T>
    constexpr auto operator()(const T&& t) const
        noexcept(noexcept(ranges::rbegin(static_cast<const T&&>(t))))
            -> decltype(ranges::rbegin(static_cast<const T&&>(t)))
    {
        return ranges::rbegin(static_cast<const T&&>(t));
    }
};

} // namespace crbegin_
} // namespace detail

NANO_INLINE_VAR(detail::crbegin_::fn, crbegin)

namespace detail {
namespace crend_ {

struct fn {
    template <typename T>
    constexpr auto operator()(const T& t) const
        noexcept(noexcept(ranges::rend(t))) -> decltype(ranges::rend(t))
    {
        return ranges::rend(t);
    }

    template <typename T>
    constexpr auto operator()(const T&& t) const
        noexcept(noexcept(ranges::rend(static_cast<const T&&>(t))))
            -> decltype(ranges::rend(static_cast<const T&&>(t)))
    {
        return ranges::rend(static_cast<const T&&>(t));
    }
};

} // namespace crend_
} // namespace detail

NANO_INLINE_VAR(detail::crend_::fn, crend)

NANO_END_NAMESPACE

#endif

// nanorange/detail/range/concepts.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_RANGE_CONCEPTS_HPP_INCLUDED
#define NANORANGE_DETAIL_RANGE_CONCEPTS_HPP_INCLUDED


// nanorange/detail/range/primitives.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_RANGE_PRIMITIVES_HPP_INCLUDED
#define NANORANGE_DETAIL_RANGE_PRIMITIVES_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

// [range.primitives.size]

template <typename T>
constexpr bool disable_sized_range = false;

namespace detail {
namespace size_ {

template <typename T>
void size(T&&) = delete;

// For some reason MSVC doesn't mind poison pills,
// as long as there are two
template <typename T>
void size(T&) = delete;

struct fn {
private:
    template <typename T, std::size_t N>
    static constexpr std::size_t impl(const T(&&)[N], priority_tag<3>) noexcept
    {
        return N;
    }

    template <typename T, std::size_t N>
    static constexpr std::size_t impl(const T (&)[N], priority_tag<3>) noexcept
    {
        return N;
    }

    template <typename T,
              typename I = decltype(decay_copy(std::declval<T>().size()))>
    static constexpr auto impl(T&& t, priority_tag<2>) noexcept(
        noexcept(decay_copy(std::forward<T>(t).size())))
        -> std::enable_if_t<
            Integral<I> && !disable_sized_range<remove_cvref_t<T>>, I>
    {
        return decay_copy(std::forward<T>(t).size());
    }

    template <typename T,
              typename I = decltype(decay_copy(size(std::declval<T>())))>
    static constexpr auto impl(T&& t, priority_tag<1>) noexcept(
        noexcept(decay_copy(size(std::forward<T>(t)))))
        -> std::enable_if_t<
            Integral<I> && !disable_sized_range<remove_cvref_t<T>>, I>
    {
        return decay_copy(size(std::forward<T>(t)));
    }

    template <typename T,
              typename I = decltype(ranges::begin(std::declval<T>())),
              typename S = decltype(ranges::end(std::declval<T>())),
              typename D = decltype(decay_copy(std::declval<S>() -
                                               std::declval<I>()))>
    static constexpr auto impl(T&& t, priority_tag<0>) noexcept(
        noexcept(decay_copy(ranges::end(t) - ranges::begin(t))))
        -> std::enable_if_t<
            !std::is_array<remove_cvref_t<T>>::value && // MSVC sillyness?
                SizedSentinel<S, I> && ForwardIterator<I>,
            D>
    {
        return decay_copy(ranges::end(t) - ranges::begin(t));
    }

public:
    template <typename T>
    constexpr auto operator()(T&& t) const
        noexcept(noexcept(fn::impl(std::forward<T>(t), priority_tag<3>{})))
            -> decltype(fn::impl(std::forward<T>(t), priority_tag<3>{}))
    {
        return fn::impl(std::forward<T>(t), priority_tag<3>{});
    }
};

} // namespace size_
} // namespace detail

NANO_INLINE_VAR(detail::size_::fn, size)

// [range.primitives.empty]

namespace detail {
namespace empty_ {

struct fn {
private:
    template <typename T>
    static constexpr auto
    impl(T&& t,
         priority_tag<2>) noexcept(noexcept((bool(std::forward<T>(t).empty()))))
        -> decltype((bool(std::forward<T>(t).empty())))
    {
        return bool((std::forward<T>(t).empty()));
    }

    template <typename T>
    static constexpr auto impl(T&& t, priority_tag<1>) noexcept(
        noexcept(ranges::size(std::forward<T>(t)) == 0))
        -> decltype(ranges::size(std::forward<T>(t)) == 0)
    {
        return ranges::size(std::forward<T>(t)) == 0;
    }

    template <typename T,
              typename I = decltype(ranges::begin(std::declval<T>()))>
    static constexpr auto
    impl(T&& t,
         priority_tag<0>) noexcept(noexcept(ranges::begin(t) == ranges::end(t)))
        -> std::enable_if_t<ForwardIterator<I>,
                            decltype(ranges::begin(t) == ranges::end(t))>
    {
        return ranges::begin(t) == ranges::end(t);
    }

public:
    template <typename T>
    constexpr auto operator()(T&& t) const
        noexcept(noexcept(fn::impl(std::forward<T>(t), priority_tag<2>{})))
            -> decltype(fn::impl(std::forward<T>(t), priority_tag<2>{}))
    {
        return fn::impl(std::forward<T>(t), priority_tag<2>{});
    }
};

} // namespace empty_
} // namespace detail

NANO_INLINE_VAR(detail::empty_::fn, empty)

namespace detail {

template <typename P>
constexpr bool is_object_pointer_v =
    std::is_pointer<P>::value && std::is_object<checked_value_type_t<P>>::value;

namespace data_ {

struct fn {
private:
    template <typename T, typename D = decltype(decay_copy(std::declval<T&>().data()))>
    static constexpr auto
    impl(T& t, priority_tag<1>) noexcept(noexcept(decay_copy(t.data())))
        -> std::enable_if_t<is_object_pointer_v<D>, D>
    {
        return t.data();
    }

    template <typename T>
    static constexpr auto
    impl(T&& t,
         priority_tag<0>) noexcept(noexcept(ranges::begin(std::forward<T>(t))))
        -> std::enable_if_t<
            is_object_pointer_v<decltype(ranges::begin(std::forward<T>(t)))>,
            decltype(ranges::begin(std::forward<T>(t)))>
    {
        return ranges::begin(std::forward<T>(t));
    }

public:
    template <typename T>
    constexpr auto operator()(T&& t) const
        noexcept(noexcept(fn::impl(std::forward<T>(t), priority_tag<1>{})))
            -> decltype(fn::impl(std::forward<T>(t), priority_tag<1>{}))
    {
        return fn::impl(std::forward<T>(t), priority_tag<1>{});
    }
};

} // namespace data_
} // namespace detail

NANO_INLINE_VAR(detail::data_::fn, data)

NANO_END_NAMESPACE

#endif

// These are, sadly, needed for view-predicate specialisations,
// because we're not allowed to forward-declare std classes

#include <initializer_list>
#include <set>
#include <unordered_set>

NANO_BEGIN_NAMESPACE

template <typename T>
using iterator_t = decltype(ranges::begin(std::declval<T&>()));

template <typename T>
using sentinel_t = decltype(ranges::end(std::declval<T&>()));

namespace detail {

template <typename T>
using checked_iterator_t = test_t<iterator_t, T>;

template <typename T>
using checked_sentinel_t = test_t<sentinel_t, T>;

} // namespace detail

template <typename T>
struct enable_view {
};

struct view_base {
};

// [range.range]

namespace detail {

struct Range_req {
    template <typename T>
    auto requires_(T&& t)
        -> decltype(valid_expr(ranges::begin(t), ranges::end(t)));
};

} // namespace detail

template <typename T>
NANO_CONCEPT Range = detail::requires_<detail::Range_req, T>;

// [range.sized]

namespace detail {

template <typename T, typename Deduced>
auto convertible_to_helper(Deduced)
    -> std::enable_if_t<ConvertibleTo<Deduced, T>, int>;

struct SizedRange_req {
    template <typename T>
    auto requires_(T& t) -> decltype(
        valid_expr(convertible_to_helper<difference_type_t<iterator_t<T>>>(
            ranges::size(t))));
};

} // namespace detail

template <typename T>
NANO_CONCEPT SizedRange =
    Range<T> &&
    !disable_sized_range<std::remove_cv_t<std::remove_reference_t<T>>> &&
    detail::requires_<detail::SizedRange_req, T>;

// [range.view]

namespace detail {

template <typename, typename = void>
constexpr bool view_predicate = true;

template <typename T>
using enable_view_t = typename enable_view<T>::type;

template <typename T>
constexpr bool has_enable_view_v = exists_v<enable_view_t, T>;

template <typename T>
constexpr bool view_predicate<T, std::enable_if_t<has_enable_view_v<T>>> =
    enable_view<T>::type::value;

template <typename T>
constexpr bool view_predicate<
    T, std::enable_if_t<!has_enable_view_v<T> && DerivedFrom<T, view_base>>> =
    true;

template <typename T>
constexpr bool view_predicate<std::initializer_list<T>> = false;

template <typename K, typename C, typename A>
constexpr bool view_predicate<std::set<K, C, A>> = false;

template <typename K, typename C, typename A>
constexpr bool view_predicate<std::multiset<K, C, A>> = false;

template <typename K, typename H, typename E, typename A>
constexpr bool view_predicate<std::unordered_set<K, H, E, A>> = false;

template <typename K, typename H, typename E, typename A>
constexpr bool view_predicate<std::unordered_multiset<K, H, E, A>> = false;

template <typename T>
constexpr bool view_predicate_helper =
    !has_enable_view_v<T> && !DerivedFrom<T, view_base> && Range<T> &&
    Range<const T> &&
    !Same<checked_reference_t<checked_iterator_t<T>>,
          checked_reference_t<checked_iterator_t<const T>>>;

template <typename T>
constexpr bool view_predicate<T, std::enable_if_t<view_predicate_helper<T>>> =
    false;

} // namespace detail

template <typename T>
NANO_CONCEPT View = Range<T>&& Semiregular<T>&& detail::view_predicate<T>;

// [range.common]

template <typename T>
NANO_CONCEPT CommonRange = Range<T>&&
    Same<detail::checked_iterator_t<T>, detail::checked_sentinel_t<T>>;

// [ranges.viewable]

template <typename T>
NANO_CONCEPT ViewableRange = Range<T> && (std::is_lvalue_reference<T>::value ||
                                          View<std::decay_t<T>>);

// [range.input]

template <typename T>
NANO_CONCEPT InputRange =
    Range<T>&& InputIterator<detail::checked_iterator_t<T>>;

template <typename R, typename T>
NANO_CONCEPT OutputRange =
    Range<R>&& OutputIterator<detail::checked_iterator_t<R>, T>;

template <typename T>
NANO_CONCEPT ForwardRange =
    InputRange<T>&& ForwardIterator<detail::checked_iterator_t<T>>;

template <typename T>
NANO_CONCEPT BidirectionalRange =
    ForwardRange<T>&& BidirectionalIterator<detail::checked_iterator_t<T>>;

template <typename T>
NANO_CONCEPT RandomAccessRange =
    BidirectionalRange<T>&& RandomAccessIterator<detail::checked_iterator_t<T>>;

NANO_END_NAMESPACE

#endif

// nanorange/detail/range/dangling.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_RANGE_DANGLING_HPP_INCLUDED
#define NANORANGE_DETAIL_RANGE_DANGLING_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

// [range.dangling.wrap]

template <typename T>
struct dangling {
    static_assert(CopyConstructible<T>,
                  "Argument to dangling<T> must satisfy CopyConstructible<T>");

    template <typename U = T, std::enable_if_t<DefaultConstructible<U>>>
    dangling() : value_{}
    {}

    dangling(T t) : value_(std::move(t)) {}

    T get_unsafe() { return value_; }

private:
    T value_;
};

namespace detail {

template <typename R, typename = void_t<iterator_t<R>>>
struct safe_iterator_helper {
    using type = dangling<iterator_t<R>>;
};

template <typename R>
struct safe_iterator_helper<
    R, void_t<decltype(ranges::begin(std::declval<R>()))>> {
    using type = iterator_t<R>;
};

} // namespace detail

template <typename Range>
using safe_iterator_t = typename detail::safe_iterator_helper<Range>::type;

NANO_END_NAMESPACE

#endif


// nanorange/iterator.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ITERATOR_HPP_INCLUDED
#define NANORANGE_ITERATOR_HPP_INCLUDED

// nanorange/detail/iterator/algorithm_requirements.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_ITERATOR_ALGORITHM_REQUIREMENTS_HPP_INCLUDED
#define NANORANGE_DETAIL_ITERATOR_ALGORITHM_REQUIREMENTS_HPP_INCLUDED

// nanorange/detail/functional/comparisons.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_FUNCTIONAL_COMPARISONS_HPP_INCLUDED
#define NANORANGE_DETAIL_FUNCTIONAL_COMPARISONS_HPP_INCLUDED




#include <functional>

NANO_BEGIN_NAMESPACE

// [range.comparisons]

namespace detail {

template <typename = void, typename = void>
struct equal_to_helper;

template <>
struct equal_to_helper<void> {
    template <typename T, typename U>
    constexpr auto operator()(T&& t, U&& u) const
        noexcept(noexcept(std::equal_to<>{}(std::forward<T>(t),
                                            std::forward<U>(u))))
            -> std::enable_if_t<EqualityComparableWith<T, U>, bool>
    {
        return std::equal_to<>{}(std::forward<T>(t), std::forward<U>(u));
    }

    using is_transparent = std::true_type;
};

template <typename T>
struct equal_to_helper<T, std::enable_if_t<EqualityComparable<T>>> {
    constexpr bool operator()(const T& t, const T& u) const
        noexcept(noexcept(equal_to_helper<>{}(t, u)))
    {
        return equal_to_helper<>{}(t, u);
    }
};

template <typename, typename = void>
struct not_equal_to_helper;

template <>
struct not_equal_to_helper<void> {
    template <typename T, typename U>
    constexpr auto operator()(T&& t, U&& u) const
        noexcept(noexcept(!equal_to_helper<>{}(std::forward<T>(t),
                                               std::forward<U>(u))))
            -> std::enable_if_t<EqualityComparableWith<T, U>, bool>
    {
        return !equal_to_helper<>{}(std::forward<T>(t), std::forward<U>(u));
    }

    using is_transparent = std::true_type;
};

template <typename T>
struct not_equal_to_helper<T, std::enable_if_t<EqualityComparable<T>>> {
    constexpr bool operator()(const T& t, const T& u) const
        noexcept(noexcept(!equal_to_helper<>{}(t, u)))
    {
        return !equal_to_helper<>{}(t, u);
    }
};

template <typename = void, typename = void>
struct less_helper;

template <>
struct less_helper<void> {
    template <typename T, typename U>
    constexpr auto operator()(T&& t, U&& u) const
        noexcept(noexcept(std::less<>(std::forward<T>(t), std::forward<U>(u))))
            -> std::enable_if_t<StrictTotallyOrderedWith<T, U>, bool>
    {
        return std::less<>(std::forward<T>(t), std::forward<U>(u));
    }

    using is_transparent = std::true_type;
};

template <typename T>
struct less_helper<T, std::enable_if_t<StrictTotallyOrdered<T>>> {
    constexpr bool operator()(const T& t, const T& u) const
        noexcept(noexcept(less_helper<>{}(t, u)))
    {
        return less_helper<>{}(t, u);
    }
};

template <typename, typename = void>
struct greater_helper;

template <>
struct greater_helper<void> {
    template <typename T, typename U>
    constexpr auto operator()(T&& t, U&& u) const
        noexcept(noexcept(less_helper<>{}(std::forward<T>(t),
                                          std::forward<U>(u))))
            -> std::enable_if_t<StrictTotallyOrderedWith<T, U>, bool>
    {
        return less_helper<>{}(std::forward<U>(u), std::forward<T>(t));
    }

    using is_transparent = std::true_type;
};

template <typename T>
struct greater_helper<T, std::enable_if_t<StrictTotallyOrdered<T>>> {
    constexpr bool operator()(const T& t, const T& u) const
        noexcept(noexcept(less_helper<>{}(u, t)))
    {
        return less_helper<>{}(u, t);
    }
};

template <typename, typename = void>
struct less_equal_helper;

template <>
struct less_equal_helper<void> {
    template <typename T, typename U>
    constexpr auto operator()(T&& t, U&& u) const
        noexcept(noexcept(!less_helper<>{}(std::forward<U>(u),
                                           std::forward<T>(t))))
            -> std::enable_if_t<StrictTotallyOrderedWith<T, U>, bool>
    {
        return !less_helper<>{}(std::forward<U>(u), std::forward<T>(t));
    }

    using is_transparent = std::true_type;
};

template <typename T>
struct less_equal_helper<T, std::enable_if_t<StrictTotallyOrdered<T>>> {
    constexpr bool operator()(const T& t, const T& u) const
        noexcept(noexcept(!less_helper<>{}(u, t)))
    {
        return !less_helper<>{}(u, t);
    }
};

template <typename, typename = void>
struct greater_equal_helper;

template <>
struct greater_equal_helper<void> {
    template <typename T, typename U>
    constexpr auto operator()(T&& t, U&& u) const
        noexcept(noexcept(less_helper<>{}(std::forward<T>(t),
                                          std::forward<U>(u))))
            -> std::enable_if_t<StrictTotallyOrderedWith<T, U>, bool>
    {
        return !less_helper<>{}(std::forward<T>(t), std::forward<U>(u));
    }

    using is_transparent = std::true_type;
};

template <typename T>
struct greater_equal_helper<T, std::enable_if_t<StrictTotallyOrdered<T>>> {
    constexpr bool operator()(const T& t, const T& u) const
        noexcept(noexcept(!less_helper<>{}(t, u)))
    {
        return !less_helper<>{}(t, u);
    }
};

} // namespace detail

template <typename T = void>
struct equal_to : detail::equal_to_helper<T> {
};

template <typename T = void>
struct not_equal_to : detail::not_equal_to_helper<T> {
};

template <typename T = void>
struct less : detail::less_helper<T> {
};

template <typename T = void>
struct greater : detail::greater_helper<T> {
};

template <typename T = void>
struct greater_equal : detail::greater_equal_helper<T> {
};

template <typename T = void>
struct less_equal : detail::less_equal_helper<T> {
};

NANO_END_NAMESPACE

#endif
// nanorange/detail/functional/identity.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_FUNCTIONAL_IDENTITY_HPP_INCLUDED
#define NANORANGE_DETAIL_FUNCTIONAL_IDENTITY_HPP_INCLUDED



#include <functional>
#include <type_traits>

NANO_BEGIN_NAMESPACE

struct identity {
    template <typename T>
    constexpr T&& operator()(T&& t) const noexcept
    {
        return std::forward<T>(t);
    }

    using is_transparent = std::true_type;
};

NANO_END_NAMESPACE

#endif

// nanorange/detail/iterator/indirect_callable_concepts.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_ITERATOR_INDIRECT_CALLABLE_CONCEPTS_HPP_INCLUDED
#define NANORANGE_DETAIL_ITERATOR_INDIRECT_CALLABLE_CONCEPTS_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

// [range.indirectcallable.indirectinvocable]

namespace detail {

template <typename, typename = void>
struct iter_common_ref_helper {
};

template <typename T>
struct iter_common_ref_helper<T, std::enable_if_t<Readable<T>>> {
    using type = common_reference_t<reference_t<T>, value_type_t<T>&>;
};

} // namespace detail

template <typename I>
using iter_common_reference_t =
    typename detail::iter_common_ref_helper<I>::type;

namespace detail {

template <typename I>
using checked_iter_common_ref_t = test_t<iter_common_reference_t, I>;
}

template <typename F, typename I>
NANO_CONCEPT IndirectUnaryInvocable = Readable<I>&& CopyConstructible<F>&&
    Invocable<detail::lref_t<F>, detail::checked_value_type_t<I>&>&&
        Invocable<detail::lref_t<F>, detail::checked_reference_t<I>&>&&
            Invocable<detail::lref_t<F>, detail::checked_iter_common_ref_t<I>>&&
                CommonReference<
                    detail::checked_invoke_result_t<
                        detail::lref_t<F>, detail::checked_value_type_t<I>&>,
                    detail::checked_invoke_result_t<
                        detail::lref_t<F>, detail::checked_reference_t<I>>>;

template <typename F, typename I>
NANO_CONCEPT IndirectRegularUnaryInvocable = Readable<I>&& CopyConstructible<
    F>&& RegularInvocable<detail::lref_t<F>, detail::checked_value_type_t<I>&>&&
    RegularInvocable<detail::lref_t<F>, detail::checked_reference_t<I>&>&&
        RegularInvocable<detail::lref_t<F>,
                         detail::checked_iter_common_ref_t<I>>&&
            CommonReference<
                detail::checked_invoke_result_t<
                    detail::lref_t<F>, detail::checked_value_type_t<I>&>,
                detail::checked_invoke_result_t<
                    detail::lref_t<F>, detail::checked_reference_t<I>>>;

template <typename F, typename I>
NANO_CONCEPT IndirectUnaryPredicate = Readable<I>&& CopyConstructible<F>&&
    Predicate<detail::lref_t<F>, detail::checked_value_type_t<I>&>&&
        Predicate<detail::lref_t<F>, detail::checked_reference_t<I>>&&
            Predicate<detail::lref_t<F>, detail::checked_iter_common_ref_t<I>>;

template <typename F, typename I1, typename I2 = I1>
NANO_CONCEPT IndirectRelation =
    Readable<I1>&& Readable<I2>&& CopyConstructible<F>&&
        Relation<detail::lref_t<F>, detail::checked_value_type_t<I1>&,
                 detail::checked_value_type_t<I2>&>&&
            Relation<detail::lref_t<F>, detail::checked_value_type_t<I1>&,
                     detail::checked_reference_t<I2>>&&
                Relation<detail::lref_t<F>, detail::checked_reference_t<I1>,
                         detail::checked_value_type_t<I2>&>&&
                    Relation<detail::lref_t<F>, detail::checked_reference_t<I1>,
                             detail::checked_reference_t<I2>>&&
                        Relation<detail::lref_t<F>,
                                 detail::checked_iter_common_ref_t<I1>,
                                 detail::checked_iter_common_ref_t<I2>>;

template <typename F, typename I1, typename I2 = I1>
NANO_CONCEPT IndirectStrictWeakOrder =
    Readable<I1>&& Readable<I2>&& CopyConstructible<F>&& StrictWeakOrder<
        detail::lref_t<F>, detail::checked_value_type_t<I1>&,
        detail::checked_value_type_t<I2>&>&&
        StrictWeakOrder<detail::lref_t<F>, detail::checked_value_type_t<I1>&,
                        detail::checked_reference_t<I2>>&&
            StrictWeakOrder<detail::lref_t<F>, detail::checked_reference_t<I1>,
                            detail::checked_value_type_t<I2>&>&&
                StrictWeakOrder<detail::lref_t<F>,
                                detail::checked_reference_t<I1>,
                                detail::checked_reference_t<I2>>&&
                    StrictWeakOrder<detail::lref_t<F>,
                                    detail::checked_iter_common_ref_t<I1>,
                                    detail::checked_iter_common_ref_t<I2>>;

template <typename, typename...>
struct indirect_result;

namespace detail {

template <typename Void, typename, typename...>
struct indirect_result_helper {
};

template <bool...>
struct all_readable_helper;

template <>
struct all_readable_helper<> : std::true_type {
};

template <bool First, bool... Rest>
struct all_readable_helper<First, Rest...>
    : std::conditional_t<First, all_readable_helper<Rest...>, std::false_type> {
};

template <typename... Is>
constexpr bool all_readable = all_readable_helper<Readable<Is>...>::value;

template <typename F, typename... Is>
struct indirect_result_helper<
    std::enable_if_t<all_readable<Is...> && Invocable<F, reference_t<Is>...>>,
    F, Is...> : invoke_result<F, reference_t<Is>...> {
    using type = invoke_result_t<F, reference_t<Is>...>;
};

} // namespace detail

template <typename F, typename... Is>
struct indirect_result : detail::indirect_result_helper<void, F, Is...> {
};

template <typename F, typename... Is>
using indirect_result_t = typename indirect_result<F, Is...>::type;

namespace detail {

template <typename F, typename... Is>
using checked_indirect_result_t = test_t<indirect_result_t, F, Is...>;
}

// range.commonalgoreq.indirectlymovable]

template <typename In, typename Out>
NANO_CONCEPT IndirectlyMovable =
    Readable<In>&& Writable<Out, detail::checked_rvalue_ref_t<In>>;

template <typename In, typename Out>
NANO_CONCEPT IndirectlyMovableStorable = IndirectlyMovable<In, Out>&&
    Writable<Out, detail::checked_value_type_t<In>>&&
        Movable<detail::checked_value_type_t<In>>&&
            Constructible<detail::checked_value_type_t<In>,
                          detail::checked_rvalue_ref_t<In>>&&
                Assignable<detail::checked_value_type_t<In>&,
                           detail::checked_rvalue_ref_t<In>>;

// range.commonalgoreq.indirectlycopyable

template <typename In, typename Out>
NANO_CONCEPT IndirectlyCopyable =
    Readable<In>&& Writable<Out, detail::checked_reference_t<Out>>;

template <typename In, typename Out>
NANO_CONCEPT IndirectlyCopyableStorable = IndirectlyCopyable<In, Out>&&
    Writable<Out, const detail::checked_value_type_t<In>&>&&
        Copyable<detail::checked_value_type_t<In>>&&
            Constructible<detail::checked_value_type_t<In>,
                          detail::checked_rvalue_ref_t<In>>&&
                Assignable<detail::checked_value_type_t<In>&,
                           detail::checked_reference_t<In>>;

NANO_END_NAMESPACE

#endif

// nanorange/detail/iterator/iter_swap.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_ITERATOR_ITER_SWAP_HPP_INCLUDED
#define NANORANGE_DETAIL_ITERATOR_ITER_SWAP_HPP_INCLUDED




NANO_BEGIN_NAMESPACE

namespace detail {
namespace iter_swap_ {

// ADL "poison pill"
template <typename I1, typename I2>
void iter_swap(I1, I2) = delete;

// FIXME MSVC: add a second (redundant) poison pill
template <typename I>
void iter_swap(I, I) = delete;

struct fn {
private:
    template <typename T1, typename T2>
    static constexpr bool iter_exchange_move_noexcept =
        std::is_nothrow_constructible<value_type_t<T1>,
                                      rvalue_reference_t<T1>>::value&&
            std::is_nothrow_assignable<value_type_t<T1>&,
                                       rvalue_reference_t<T1>>::value&&
                std::is_nothrow_assignable<reference_t<T1>,
                                           rvalue_reference_t<T2>>::value&&
                    std::is_nothrow_assignable<reference_t<T1>,
                                               value_type_t<T2>>::value&&
                        std::is_nothrow_move_constructible<value_type_t<T1>>::
                            value&& noexcept(
                                ranges::iter_move(std::declval<T1&>()));

    template <typename X, typename Y>
    static constexpr value_type_t<std::remove_reference_t<X>>
    iter_exchange_move(X&& x, Y&& y) noexcept(
        iter_exchange_move_noexcept<std::remove_reference_t<X>,
                                    std::remove_reference_t<Y>>&&
            iter_exchange_move_noexcept<std::remove_reference_t<Y>,
                                        std::remove_reference_t<X>>)
    {
        value_type_t<std::remove_reference_t<X>> old_value(
            ranges::iter_move(x));
        *x = ranges::iter_move(y);
        return old_value;
    }

    template <typename T, typename U>
    static constexpr auto impl(T&& t, U&& u, priority_tag<2>) noexcept(
        noexcept((void) (iter_swap(std::forward<T>(t), std::forward<U>(u)))))
        -> decltype((void) (iter_swap(std::forward<T>(t), std::forward<U>(u))))
    {
        (void) iter_swap(std::forward<T>(t), std::forward<U>(u));
    }

    template <typename T, typename U>
    static constexpr auto impl(T&& t, U&& u, priority_tag<1>) noexcept(
        noexcept(ranges::swap(*std::forward<T>(t), *std::forward<U>(u))))
        -> std::enable_if_t<Readable<std::remove_reference_t<T>> &&
                            Readable<std::remove_reference_t<U>> &&
                            SwappableWith<reference_t<T>, reference_t<U>>>
    {
        ranges::swap(*std::forward<T>(t), *std::forward<U>(u));
    }

    template <typename T, typename U>
    static constexpr auto impl(T&& t, U&& u, priority_tag<0>) noexcept(noexcept(
        *t = fn::iter_exchange_move(std::forward<U>(u), std::forward<T>(t))))
        -> std::enable_if_t<IndirectlyMovableStorable<T, U> &&
                            IndirectlyMovableStorable<U, T>>
    {
        return *t = fn::iter_exchange_move(std::forward<U>(u),
                                           std::forward<T>(t));
    }

public:
    template <typename T, typename U>
    constexpr auto operator()(T&& t, U&& u) const
        noexcept(noexcept(fn::impl(std::forward<T>(t), std::forward<U>(u),
                                   priority_tag<2>{})))
            -> decltype(fn::impl(std::forward<T>(t), std::forward<U>(u),
                                 priority_tag<2>{}))
    {
        return fn::impl(std::forward<T>(t), std::forward<U>(u),
                        priority_tag<2>{});
    }
};
}
} // namespace detail

NANO_INLINE_VAR(detail::iter_swap_::fn, iter_swap)

NANO_END_NAMESPACE

#endif

// nanorange/detail/iterator/projected.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_ITERATOR_PROJECTED_HPP_INCLUDED
#define NANORANGE_DETAIL_ITERATOR_PROJECTED_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

// [range.projected]

template <typename I, typename Proj>
struct projected;

namespace detail {

template <typename, typename, typename = void>
struct projected_helper {
};

template <typename I, typename Proj>
struct projected_helper<
    I, Proj,
    std::enable_if_t<Readable<I> && IndirectRegularUnaryInvocable<Proj, I>>> {
    using value_type =
        std::remove_cv_t<std::remove_reference_t<indirect_result_t<Proj&, I>>>;

    // We shouldn't need to define this, as we only need its return type,
    // but GCC gets stroppy sometimes.
    indirect_result_t<Proj&, I> operator*() const { throw 0; };
};

} // namespace detail

template <typename I, typename Proj>
struct projected : detail::projected_helper<I, Proj> {
};

NANO_END_NAMESPACE

#endif

NANO_BEGIN_NAMESPACE

namespace detail {

struct IndirectlySwappable_req {
    template <typename I1, typename I2>
    auto requires_(I1&& i1, I2&& i2) -> decltype(
        ranges::iter_swap(std::forward<I1>(i1), std::forward<I2>(i2)),
        ranges::iter_swap(std::forward<I2>(i2), std::forward<I1>(i1)),
        ranges::iter_swap(std::forward<I1>(i1), std::forward<I1>(i1)),
        ranges::iter_swap(std::forward<I2>(i2), std::forward<I2>(i2)));
};

} // namespace detail

template <typename I1, typename I2 = I1>
NANO_CONCEPT IndirectlySwappable = Readable<I1>&& Readable<I2>&&
    detail::requires_<detail::IndirectlySwappable_req, I1, I2>;

// [range.commonalgoreq.indirectlycomparable]

template <typename I1, typename I2, typename R = equal_to<>,
          typename P1 = identity, typename P2 = identity>
NANO_CONCEPT IndirectlyComparable =
    IndirectRelation<R, projected<I1, P1>, projected<I2, P2>>;

// [range.commonalgoreq.permutable]

template <typename I>
NANO_CONCEPT Permutable = ForwardIterator<I>&& IndirectlyMovableStorable<I, I>&&
    IndirectlySwappable<I, I>;

// [range.commonalgoreq.mergeable]

template <typename I1, typename I2, typename Out, typename R = less<>,
          typename P1 = identity, typename P2 = identity>
NANO_CONCEPT Mergeable =
    InputIterator<I1>&& InputIterator<I2>&& WeaklyIncrementable<Out>&&
        IndirectlyCopyable<I1, Out>&& IndirectlyCopyable<I2, Out>&&
            IndirectStrictWeakOrder<R, projected<I1, P1>, projected<I2, P2>>;

// [range.commonalgoreq.sortable]

template <typename I, typename R = std::less<>, typename P = identity>
NANO_CONCEPT Sortable =
    Permutable<I>&& IndirectStrictWeakOrder<R, projected<I, P>>;

NANO_END_NAMESPACE

#endif







// nanorange/iterator/back_insert_iterator.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ITERATOR_BACK_INSERT_ITERATOR_HPP_INCLUDED
#define NANORANGE_ITERATOR_BACK_INSERT_ITERATOR_HPP_INCLUDED



#include <iterator>

NANO_BEGIN_NAMESPACE

template <typename Container>
struct back_insert_iterator {
    using container_type = Container;
    using difference_type = std::ptrdiff_t;

    constexpr back_insert_iterator() = default;

    explicit back_insert_iterator(Container& x) : cont_(std::addressof(x)) {}

    back_insert_iterator& operator=(const value_type_t<Container>& value)
    {
        cont_->push_back(value);
        return *this;
    }

    back_insert_iterator& operator=(value_type_t<Container>&& value)
    {
        cont_->push_back(std::move(value));
        return *this;
    }

    back_insert_iterator& operator*() { return *this; }
    back_insert_iterator& operator++() { return *this; }
    back_insert_iterator& operator++(int) { return *this; }

private:
    container_type* cont_ = nullptr;
};

template <typename Container>
back_insert_iterator<Container> back_inserter(Container& x)
{
    return back_insert_iterator<Container>(x);
}

NANO_END_NAMESPACE

namespace std {

template <typename Cont>
struct pointer_traits<::nano::back_insert_iterator<Cont>> {
    using value_type = void;
    using difference_type = ptrdiff_t;
    using reference = void;
    using pointer = void;
    using iterator_category = std::output_iterator_tag;
};

} // namespace std

#endif

// nanorange/iterator/common_iterator.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ITERATOR_COMMON_ITERATOR_HPP_INCLUDED
#define NANORANGE_ITERATOR_COMMON_ITERATOR_HPP_INCLUDED

// nanorange/iterator/concepts.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ITERATOR_CONCEPTS_HPP_INCLUDED
#define NANORANGE_ITERATOR_CONCEPTS_HPP_INCLUDED





#endif


NANO_BEGIN_NAMESPACE

// [range.iterators.common]

namespace common_iterator_ {

template <typename I, typename S>
class common_iterator {
    static_assert(Iterator<I>, "");
    static_assert(Sentinel<S, I>, "");
    static_assert(!Same<I, S>, "");

    template <typename II, typename SS>
    friend class common_iterator;

    class op_arrow_proxy {
        value_type_t<I> keep_;

        constexpr op_arrow_proxy(reference_t<I>&& x) : keep_(std::move(x)) {}

    public:
        constexpr const value_type_t<I>* operator->() const
        {
            return std::addressof(keep_);
        }
    };

    template <typename II>
    using op_arrow_t = decltype(std::declval<const II&>().operator->());

    template <typename II>
    static constexpr auto do_op_arrow(const II& i, detail::priority_tag<2>)
        -> std::enable_if_t<
            std::is_pointer<II>::value || detail::exists_v<op_arrow_t, II>, I>
    {
        return i;
    }

    template <typename II>
    static constexpr auto do_op_arrow(const II& i, detail::priority_tag<1>)
        -> std::enable_if_t<std::is_reference<reference_t<const II>>::value,
                            std::add_pointer_t<reference_t<const II>>>
    {
        auto&& tmp = *i;
        return std::addressof(tmp);
    }

    template <typename II>
    static constexpr auto do_op_arrow(const II& i, detail::priority_tag<0>)
        -> op_arrow_proxy
    {
        return {i};
    }

public:
    using difference_type = difference_type_t<I>;

    constexpr common_iterator() : is_sentinel_{false}, iter_{} {}

    constexpr common_iterator(I i) : is_sentinel_{false}, iter_(i) {}

    constexpr common_iterator(S s) : is_sentinel_{true}, sentinel_{s} {}

    template <
        typename II, typename SS,
        std::enable_if_t<ConvertibleTo<II, I> && ConvertibleTo<SS, S>, int> = 0>
    constexpr common_iterator(const common_iterator<II, SS>& other)
        : is_sentinel_{other.is_sentinel_},
          iter_(other.iter_),
          sentinel_(other.sentinel_)
    {}

    template <typename II, typename SS>
    constexpr std::enable_if_t<ConvertibleTo<II, I> && ConvertibleTo<SS, S>,
                               common_iterator&>
    operator=(const common_iterator<II, SS>& other)
    {
        is_sentinel_ = other.is_sentinel_;
        iter_ = other.iter_;
        sentinel_ = other.sentinel_;
        return *this;
    }

    constexpr decltype(auto) operator*() { return *iter_; }

    template <typename II = I,
              std::enable_if_t<detail::Dereferenceable<const I>, int> = 0>
    constexpr decltype(auto) operator*() const
    {
        return *iter_;
    }

    template <typename II = I>
    constexpr auto operator-> () const
        -> decltype(common_iterator::do_op_arrow(std::declval<const II&>(),
                                                 detail::priority_tag<2>{}))
    {
        return do_op_arrow(iter_, detail::priority_tag<2>{});
    }

    constexpr common_iterator& operator++()
    {
        ++iter_;
        return *this;
    }

    template <typename II = I, std::enable_if_t<!ForwardIterator<II>, int> = 0>
    constexpr  decltype(auto) operator++(int)
    {
        return iter_++;
    }

    template <typename II = I, std::enable_if_t<ForwardIterator<II>, int> = 0>
    constexpr common_iterator operator++(int)
    {
        common_iterator tmp = *this;
        ++iter_;
        return tmp;
    }

    friend constexpr rvalue_reference_t<I> iter_move(const common_iterator& i)
    {
        return ranges::iter_move(i.iter_);
    }

    template <typename I2, typename S2>
    friend constexpr std::enable_if_t<IndirectlySwappable<I2, I>>
    iter_swap(const common_iterator& x, const common_iterator<I2, S2>& y)
    {
        return ranges::iter_swap(x.iter_, y.iter_);
    }

    // private:
    // TODO: Some sort of variant-like union
    bool is_sentinel_{};
    I iter_{};
    S sentinel_{};
};

template <typename I1, typename I2, typename S1, typename S2,
          std::enable_if_t<!EqualityComparableWith<I1, I2>, int> = 0>
constexpr bool operator==(const common_iterator<I1, S1>& x,
                          const common_iterator<I2, S2>& y)
{
    return x.is_sentinel_ ? (y.is_sentinel_ || y.iter_ == x.sentinel_)
                          : (!y.is_sentinel_ || x.iter_ == y.sentinel_);
}

template <typename I1, typename I2, typename S1, typename S2,
          std::enable_if_t<EqualityComparableWith<I1, I2>, int> = 0>
constexpr bool operator==(const common_iterator<I1, S1>& x,
                          const common_iterator<I2, S2>& y)
{
    return x.is_sentinel_
               ? (y.is_sentinel_ || y.iter_ == x.sentinel_)
               : (y.is_sentinel_ ? x.iter_ == y.sentinel_ : x.iter_ == y.iter_);
}

template <typename I1, typename I2, typename S1, typename S2>
constexpr bool operator!=(const common_iterator<I1, S1>& x,
                          const common_iterator<I2, S2>& y)
{
    return !(x == y);
}

template <typename I2, typename I1, typename S1, typename S2>
constexpr
std::enable_if_t<SizedSentinel<I1, I2> && SizedSentinel<S1, I2> &&
                     SizedSentinel<S2, I2>,
                 difference_type_t<I2>>
operator-(const common_iterator<I1, S1>& x, const common_iterator<I2, S2>& y)
{
    return x.is_sentinel_
               ? (y.is_sentinel_ ? 0 : x.sentinel_ - y.iter_)
               : (y.is_sentinel_ ? x.iter_ - y.sentinel_ : x.iter_ - y.iter_);
}

} // namespace common_iterator_

using common_iterator_::common_iterator;

template <typename I, typename S>
struct value_type<common_iterator<I, S>> {
    using type = value_type_t<I>;
};

template <typename I, typename S>
struct iterator_category<common_iterator<I, S>>
    : std::conditional<ForwardIterator<I>, forward_iterator_tag,
                       input_iterator_tag> {
};

NANO_END_NAMESPACE

namespace std {

template <typename I, typename S>
struct iterator_traits<::nano::common_iterator<I, S>> {
    using difference_type =
        ::nano::difference_type_t<::nano::common_iterator<I, S>>;
    using value_type = ::nano::value_type_t<::nano::common_iterator<I, S>>;
    using pointer =
        std::add_pointer_t<::nano::reference_t<::nano::common_iterator<I, S>>>;
    using reference = ::nano::reference_t<::nano::common_iterator<I, S>>;
    using iterator_category =
        std::conditional_t<::nano::ForwardIterator<I>,
                           std::forward_iterator_tag,
                           std::input_iterator_tag>;
};

} // namespace std

#endif


// nanorange/iterator/counted_iterator.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ITERATOR_COUNTED_ITERATOR_HPP_INCLUDED
#define NANORANGE_ITERATOR_COUNTED_ITERATOR_HPP_INCLUDED


// nanorange/iterator/default_sentinel.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ITERATOR_DEFAULT_SENTINEL_HPP_INCLUDED
#define NANORANGE_ITERATOR_DEFAULT_SENTINEL_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

class default_sentinel {};

NANO_END_NAMESPACE

#endif


NANO_BEGIN_NAMESPACE

template <typename I>
class counted_iterator {
    static_assert(Iterator<I>, "");

    template <typename I2>
    friend class counted_iterator;

public:
    using iterator = I;
    using difference_type = difference_type_t<I>;

    constexpr counted_iterator() = default;

    constexpr counted_iterator(I x, difference_type_t<I> n)
        : current_(x), cnt_(n)
    {}

    template <typename I2, std::enable_if_t<ConvertibleTo<I2, I>, int> = 0>
    constexpr counted_iterator(const counted_iterator<I2>& i)
        : current_(i.current_), cnt_(i.cnt_)
    {}

    template <typename I2>
    constexpr auto operator=(const counted_iterator<I2>& i)
        -> std::enable_if_t<ConvertibleTo<I2, I>, counted_iterator&>
    {
        current_ = i.current_;
        cnt_ = i.cnt_;
        return *this;
    }

    constexpr I base() const { return current_; }

    constexpr difference_type_t<I> count() const { return cnt_; }

    constexpr decltype(auto) operator*() { return *current_; }

    template <typename II = I,
              std::enable_if_t<detail::Dereferenceable<const II>, int> = 0>
    constexpr decltype(auto) operator*() const
    {
        return *current_;
    }

    constexpr counted_iterator& operator++()
    {
        ++current_;
        --cnt_;
        return *this;
    }

    template <typename II = I, std::enable_if_t<!ForwardIterator<II>, int> = 0>
    decltype(auto) operator++(int)
    {
        --cnt_;
        try {
            return current_++;
        } catch (...) {
            ++cnt_;
            throw;
        }
    }

    template <typename II = I>
    constexpr auto
    operator++(int) -> std::enable_if_t<ForwardIterator<II>, counted_iterator>
    {
        auto tmp = *this;
        ++*this;
        return tmp;
    }

    template <typename II = I>
    constexpr auto operator--()
        -> std::enable_if_t<BidirectionalIterator<II>, counted_iterator&>
    {
        --current_;
        ++cnt_;
        return *this;
    }

    template <typename II = I>
    constexpr auto operator--(int)
        -> std::enable_if_t<BidirectionalIterator<II>, counted_iterator>
    {
        auto tmp = *this;
        --*this;
        return tmp;
    }

    template <typename II = I>
    constexpr auto operator+(difference_type n) const
        -> std::enable_if_t<RandomAccessIterator<II>, counted_iterator>
    {
        return counted_iterator(current_ + n, cnt_ - n);
    }

    template <typename II = I>
    constexpr auto operator+=(difference_type n)
        -> std::enable_if_t<RandomAccessIterator<II>, counted_iterator&>
    {
        current_ += n;
        cnt_ -= n;
        return *this;
    }

    template <typename II = I>
    constexpr auto operator-(difference_type n) const
        -> std::enable_if_t<RandomAccessIterator<II>, counted_iterator>
    {
        return counted_iterator(current_ - n, cnt_ + n);
    }

    template <typename II = I>
    constexpr auto operator-=(difference_type n)
        -> std::enable_if_t<RandomAccessIterator<II>, counted_iterator&>
    {
        current_ -= n;
        cnt_ += n;
        return *this;
    }

    template <typename II = I,
              std::enable_if_t<RandomAccessIterator<II>, int> = 0>
    constexpr decltype(auto) operator[](difference_type n) const
    {
        return current_[n];
    }

    template <typename II = I, std::enable_if_t<InputIterator<II>, int> = 0>
    friend constexpr rvalue_reference_t<I>
    iter_move(const counted_iterator& i) noexcept(
        noexcept(ranges::iter_move(i.current_)))
    {
        return ranges::iter_move(i.current_);
    }

    template <typename I2>
    friend constexpr auto iter_swap(
        const counted_iterator<I>& x,
        const counted_iterator<I2>&
            y) noexcept(noexcept(ranges::iter_swap(x.current_, y.current_)))
        -> std::enable_if_t<IndirectlySwappable<I2, I>>
    {
        ranges::iter_swap(x.current_, y.current_);
    }

private:
    I current_{};
    difference_type_t<I> cnt_{0};
};

namespace detail {

template <typename I, typename = void>
struct counted_iterator_value_type_helper {
};

template <typename I>
struct counted_iterator_value_type_helper<I, std::enable_if_t<Readable<I>>> {
    using type = value_type_t<I>;
};

template <typename I, typename = void>
struct counted_iterator_category_helper {
};

template <typename I>
struct counted_iterator_category_helper<I, std::enable_if_t<InputIterator<I>>> {
    using type = iterator_category_t<I>;
};

} // namespace detail

template <typename I>
struct value_type<counted_iterator<I>>
    : detail::counted_iterator_value_type_helper<I> {
};

template <typename I>
struct iterator_category<counted_iterator<I>>
    : detail::counted_iterator_category_helper<I> {
};

template <typename I1, typename I2>
constexpr auto operator==(const counted_iterator<I1>& x,
                          const counted_iterator<I2>& y)
    -> std::enable_if_t<Common<I1, I2>, bool>
{
    return x.count() == y.count();
}

template <typename I>
constexpr bool operator==(const counted_iterator<I>& x, default_sentinel)
{
    return x.count() == 0;
}

template <typename I>
constexpr bool operator==(default_sentinel, const counted_iterator<I>& x)
{
    return x.count() == 0;
}

template <typename I1, typename I2>
constexpr auto operator!=(const counted_iterator<I1>& x,
                          const counted_iterator<I2>& y)
    -> std::enable_if_t<Common<I1, I2>, bool>
{
    return !(x == y);
}

template <typename I>
constexpr bool operator!=(const counted_iterator<I>& x, default_sentinel y)
{
    return !(x == y);
}

template <typename I>
constexpr bool operator!=(default_sentinel x, const counted_iterator<I>& y)
{
    return !(x == y);
}

template <typename I1, typename I2>
constexpr auto operator<(const counted_iterator<I1>& x,
                         const counted_iterator<I2>& y)
    -> std::enable_if_t<Common<I1, I2>, bool>
{
    return y.count() < x.count();
}

template <typename I1, typename I2>
constexpr auto operator<=(const counted_iterator<I1>& x,
                          const counted_iterator<I2>& y)
    -> std::enable_if_t<Common<I1, I2>, bool>
{
    return !(y < x);
}

template <typename I1, typename I2>
constexpr auto operator>(const counted_iterator<I1>& x,
                         const counted_iterator<I2>& y)
    -> std::enable_if_t<Common<I1, I2>, bool>
{
    return y < x;
}

template <typename I1, typename I2>
constexpr auto operator>=(const counted_iterator<I1>& x,
                          const counted_iterator<I2>& y)
    -> std::enable_if_t<Common<I1, I2>, bool>
{
    return !(x < y);
}

template <typename I1, typename I2>
constexpr auto operator-(const counted_iterator<I1>& x,
                         const counted_iterator<I2>& y)
    -> std::enable_if_t<Common<I1, I2>, difference_type_t<I2>>
{
    return y.count() - x.count();
}

template <typename I>
constexpr difference_type_t<I> operator-(const counted_iterator<I>& x,
                                         default_sentinel)
{
    return -x.count();
}

template <typename I>
constexpr difference_type_t<I> operator-(default_sentinel,
                                         const counted_iterator<I>& y)
{
    return y.count();
}

template <typename I>
constexpr auto operator+(difference_type_t<I> n, const counted_iterator<I>& x)
    -> std::enable_if_t<RandomAccessIterator<I>, counted_iterator<I>>
{
    return x + n;
}

template <typename I>
constexpr auto make_counted_iterator(I i, difference_type_t<I> n)
    -> std::enable_if_t<Iterator<I>, counted_iterator<I>>
{
    return counted_iterator<I>(std::move(i), n);
}

NANO_END_NAMESPACE

#endif


// nanorange/iterator/front_insert_iterator.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ITERATOR_FRONT_INSERT_ITERATOR_HPP_INCLUDED
#define NANORANGE_ITERATOR_FRONT_INSERT_ITERATOR_HPP_INCLUDED



#include <iterator>

NANO_BEGIN_NAMESPACE

template <typename Container>
struct front_insert_iterator {
    using container_type = Container;
    using difference_type = std::ptrdiff_t;

    constexpr front_insert_iterator() = default;

    explicit front_insert_iterator(Container& x) : cont_(std::addressof(x)) {}

    front_insert_iterator& operator=(const value_type_t<Container>& value)
    {
        cont_->push_front(value);
        return *this;
    }

    front_insert_iterator& operator=(value_type_t<Container>&& value)
    {
        cont_->front_back(std::move(value));
        return *this;
    }

    front_insert_iterator& operator*() { return *this; }
    front_insert_iterator& operator++() { return *this; }
    front_insert_iterator& operator++(int) { return *this; }

private:
    container_type* cont_ = nullptr;
};

template <typename Container>
front_insert_iterator<Container> front_inserter(Container& x)
{
    return front_insert_iterator<Container>(x);
}

NANO_END_NAMESPACE

namespace std {

template <typename Cont>
struct iterator_traits<::nano::front_insert_iterator<Cont>> {
    using value_type = void;
    using difference_type = ptrdiff_t;
    using reference = void;
    using pointer = void;
    using iterator_category = output_iterator_tag;
};

} // namespace std

#endif

// nanorange/iterator/insert_iterator.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ITERATOR_INSERT_ITERATOR_HPP_INCLUDED
#define NANORANGE_ITERATOR_INSERT_ITERATOR_HPP_INCLUDED



#include <iterator>

NANO_BEGIN_NAMESPACE

template <typename Container>
struct insert_iterator {
    using container_type = Container;
    using difference_type = std::ptrdiff_t;

    constexpr insert_iterator() = default;

    explicit insert_iterator(Container& x, iterator_t<Container> i)
        : cont_(std::addressof(x)), it_(i)
    {}

    insert_iterator& operator=(const value_type_t<Container>& value)
    {
        cont_->insert(it_, value);
        ++it_;
        return *this;
    }

    insert_iterator& operator=(value_type_t<Container>&& value)
    {
        cont_->push_back(it_, std::move(value));
        ++it_;
        return *this;
    }

    insert_iterator& operator*() { return *this; }
    insert_iterator& operator++() { return *this; }
    insert_iterator& operator++(int) { return *this; }

private:
    container_type* cont_ = nullptr;
    iterator_t<container_type> it_{};
};

template <typename Container>
insert_iterator<Container> inserter(Container& x)
{
    return back_insert_iterator<Container>(x);
}

NANO_END_NAMESPACE

namespace std {

template <typename Container>
struct iterator_traits<::nano::insert_iterator<Container>> {
    using value_type = void;
    using difference_type = ptrdiff_t;
    using reference = void;
    using pointer = void;
    using iterator_category = output_iterator_tag;
};

} // namespace std

#endif
// nanorange/iterator/operations.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ITERATOR_OPERATIONS_HPP_INCLUDED
#define NANORANGE_ITERATOR_OPERATIONS_HPP_INCLUDED






NANO_BEGIN_NAMESPACE

namespace detail {
namespace advance_ {

struct fn {
private:
    template <typename T>
    static constexpr T abs(T t)
    {
        if (t < T{0}) {
            return -t;
        }
        return t;
    }

    template <typename R>
    static constexpr auto impl(R& r, difference_type_t<R> n)
        -> std::enable_if_t<RandomAccessIterator<R>>
    {
        r += n;
    }

    template <typename I>
    static constexpr auto impl(I& i, difference_type_t<I> n)
        -> std::enable_if_t<BidirectionalIterator<I> &&
                            !RandomAccessIterator<I>>
    {
        constexpr auto zero = difference_type_t<I>{0};

        if (n > zero) {
            while (n-- > zero) {
                ++i;
            }
        } else {
            while (n++ < zero) {
                --i;
            }
        }
    }

    template <typename I>
    static constexpr auto impl(I& i, difference_type_t<I> n)
        -> std::enable_if_t<!BidirectionalIterator<I>>
    {
        while (n-- > difference_type_t<I>{0}) {
            ++i;
        }
    }

    template <typename I, typename S>
    static constexpr auto impl(I& i, S bound, priority_tag<2>)
        -> std::enable_if_t<Assignable<I&, S>>
    {
        i = std::move(bound);
    }

    template <typename I, typename S>
    static constexpr auto impl(I& i, S bound, priority_tag<1>)
        -> std::enable_if_t<SizedSentinel<S, I>>
    {
        fn::impl(i, bound - i);
    }

    template <typename I, typename S>
    static constexpr void impl(I& i, S bound, priority_tag<0>)
    {
        while (i != bound) {
            ++i;
        }
    }

    template <typename I, typename S>
    static constexpr auto impl(I& i, difference_type_t<I> n, S bound)
        -> std::enable_if_t<SizedSentinel<S, I>, difference_type_t<I>>
    {
        if (fn::abs(n) >= fn::abs(bound - i)) {
            auto dist = bound - i;
            fn::impl(i, bound, priority_tag<2>{});
            return dist;
        } else {
            fn::impl(i, n);
            return n;
        }
    }

    template <typename I, typename S>
    static constexpr auto impl(I& i, difference_type_t<I> n, S bound)
        -> std::enable_if_t<BidirectionalIterator<I> && !SizedSentinel<S, I>,
                            difference_type_t<I>>
    {
        constexpr difference_type_t<I> zero{0};
        difference_type_t<I> counter{0};

        if (n < zero) {
            do {
                --i;
                --counter; // Yes, really
            } while (++n < zero && i != bound);
        } else {
            while (n-- > zero && i != bound) {
                ++i;
                ++counter;
            }
        }

        return counter;
    }

    template <typename I, typename S>
    static constexpr auto impl(I& i, difference_type_t<I> n, S bound)
        -> std::enable_if_t<!BidirectionalIterator<I> && !SizedSentinel<S, I>,
                            difference_type_t<I>>
    {
        constexpr difference_type_t<I> zero{0};
        difference_type_t<I> counter{0};

        while (n-- > zero && i != bound) {
            ++i;
            ++counter;
        }

        return counter;
    }

public:
    template <typename I>
    constexpr auto operator()(I& i, difference_type_t<I> n) const
        -> std::enable_if_t<Iterator<I>>
    {
        fn::impl(i, n);
    }

    template <typename I, typename S>
    constexpr auto operator()(I& i, S bound) const
        -> std::enable_if_t<Iterator<I> && Sentinel<S, I>>
    {
        fn::impl(i, bound, priority_tag<2>{});
    }

    template <typename I, typename S>
    constexpr auto operator()(I& i, difference_type_t<I> n, S bound) const
        -> std::enable_if_t<Iterator<I> && Sentinel<S, I>, difference_type_t<I>>
    {
        return n - fn::impl(i, n, bound);
    }
};

} // namespace advance_
} // namespace detail

NANO_INLINE_VAR(detail::advance_::fn, advance)

namespace detail {
namespace distance_ {

struct fn {
private:
    template <typename I, typename S>
    static constexpr auto impl(I i, S s)
        -> std::enable_if_t<SizedSentinel<S, I>, difference_type_t<I>>
    {
        return s - i;
    }

    template <typename I, typename S>
    static constexpr auto impl(I i, S s)
        -> std::enable_if_t<!SizedSentinel<S, I>, difference_type_t<I>>
    {
        difference_type_t<I> counter{0};
        while (i != s) {
            ++i;
            ++counter;
        }
        return counter;
    }

    template <typename R>
    static constexpr auto impl(R&& r)
        -> std::enable_if_t<SizedRange<R>, difference_type_t<iterator_t<R>>>
    {
        return ranges::size(r);
    }

    template <typename R>
    static constexpr auto impl(R&& r)
        -> std::enable_if_t<!SizedRange<R>, difference_type_t<iterator_t<R>>>
    {
        return fn::impl(ranges::begin(r), ranges::end(r));
    }

public:
    template <typename I, typename S>
    constexpr auto operator()(I first, S last) const
        -> std::enable_if_t<Iterator<I> && Sentinel<S, I>, difference_type_t<I>>
    {
        return fn::impl(std::move(first), std::move(last));
    }

    template <typename R>
    constexpr auto operator()(R&& r) const
        -> std::enable_if_t<Range<R>, difference_type_t<iterator_t<R>>>
    {
        return fn::impl(std::forward<R>(r));
    }
};

} // namespace distance_
} // namespace detail

NANO_INLINE_VAR(detail::distance_::fn, distance)

namespace detail {
namespace next_ {

struct fn {
    template <typename I>
    constexpr auto operator()(I x) const -> std::enable_if_t<Iterator<I>, I>
    {
        ++x;
        return x;
    }

    template <typename I>
    constexpr auto operator()(I x, difference_type_t<I> n) const
        -> std::enable_if_t<Iterator<I>, I>
    {
        ranges::advance(x, n);
        return x;
    }

    template <typename I, typename S>
    constexpr auto operator()(I x, S bound) const
        -> std::enable_if_t<Iterator<I> && Sentinel<S, I>, I>
    {
        ranges::advance(x, bound);
        return x;
    }

    template <typename I, typename S>
    constexpr auto operator()(I x, difference_type_t<I> n, S bound) const
        -> std::enable_if_t<Iterator<I> && Sentinel<S, I>, I>
    {
        ranges::advance(x, n, bound);
        return x;
    }
};

} // namespace next_
} // namespace detail

NANO_INLINE_VAR(detail::next_::fn, next)

namespace detail {
namespace prev_ {

struct fn {
    template <typename I>
    constexpr auto operator()(I x) const
        -> std::enable_if_t<BidirectionalIterator<I>, I>
    {
        --x;
        return x;
    }

    template <typename I>
    constexpr auto operator()(I x, difference_type_t<I> n) const
        -> std::enable_if_t<BidirectionalIterator<I>, I>
    {
        ranges::advance(x, -n);
        return x;
    }

    template <typename I, typename S>
    constexpr auto operator()(I x, difference_type_t<I> n, S bound) const
        -> std::enable_if_t<BidirectionalIterator<I> && Sentinel<S, I>, I>
    {
        ranges::advance(x, -n, bound);
        return x;
    }
};

} // namespace prev_
} // namespace detail

NANO_INLINE_VAR(detail::prev_::fn, prev)

NANO_END_NAMESPACE

#endif

// nanorange/iterator/ostream_iterator.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ITERATOR_OSTREAM_ITERATOR_HPP_INCLUDED
#define NANORANGE_ITERATOR_OSTREAM_ITERATOR_HPP_INCLUDED



#include <string> // for char_traits

NANO_BEGIN_NAMESPACE

template <typename T, typename CharT = char, typename Traits = std::char_traits<CharT>>
struct ostream_iterator
{
    using char_type = CharT;
    using traits_type = Traits;
    using ostream_type = std::basic_ostream<CharT, Traits>;
    using difference_type = std::ptrdiff_t;

    constexpr ostream_iterator() noexcept = default;

    ostream_iterator(ostream_type& os, const CharT* delim = nullptr) noexcept
            : os_(std::addressof(os)), delim_(delim)
    {}

    ostream_iterator& operator=(const T& value)
    {
        *os_ << value;
        if (delim_) {
            *os_ << delim_;
        }
        return *this;
    }

    ostream_iterator& operator*() { return *this; }
    ostream_iterator& operator++() { return *this; }
    ostream_iterator& operator++(int) { return *this; }

private:
    ostream_type* os_ = nullptr;
    const char_type* delim_ = nullptr;
};

NANO_END_NAMESPACE

namespace std {

template <typename T, typename C, typename Tr>
struct iterator_traits<::nano::ranges::ostream_iterator<T, C, Tr>> {
    using value_type = void;
    using difference_type = ptrdiff_t;
    using reference = void;
    using pointer = void;
    using iterator_category = std::output_iterator_tag;
};

}

#endif
// nanorange/iterator/ostreambuf_iterator.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ITERATOR_OSTREAMBUF_ITERATOR_HPP_INCLUDED
#define NANORANGE_ITERATOR_OSTREAMBUF_ITERATOR_HPP_INCLUDED



#include <iosfwd> // for basic_streambuf
#include <string> // for char_traits

NANO_BEGIN_NAMESPACE

template <typename CharT, typename Traits = std::char_traits<CharT>>
struct ostreambuf_iterator {

    using char_type = CharT;
    using traits = Traits;
    using difference_type = std::ptrdiff_t;
    using streambuf_type = std::basic_streambuf<CharT, Traits>;
    using ostream_type = std::basic_ostream<CharT, Traits>;

    constexpr ostreambuf_iterator() = default;

    ostreambuf_iterator(ostream_type& s) noexcept : sbuf_(s.rdbuf()) {}

    ostreambuf_iterator(streambuf_type* s) noexcept : sbuf_(s) {}

    ostreambuf_iterator& operator=(char_type c)
    {
        if (!failed()) {
            failed_ = (sbuf_->sputc(c) == traits::eof());
        }
        return *this;
    }

    ostreambuf_iterator& operator*() { return *this; }
    ostreambuf_iterator& operator++() { return *this; }
    ostreambuf_iterator& operator++(int) { return *this; }

    bool failed() const noexcept { return failed_; }

private:
    streambuf_type* sbuf_ = nullptr;
    bool failed_ = false;
};

NANO_END_NAMESPACE

namespace std {

template <typename C, typename T>
struct iterator_traits<::nano::ranges::ostreambuf_iterator<C, T>> {
    using value_type = void;
    using difference_type = ptrdiff_t;
    using reference = void;
    using pointer = void;
    using iterator_category = output_iterator_tag;
};

} // namespace std

#endif

// nanorange/iterator/unreachable.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ITERATOR_UNREACHABLE_HPP_INCLUDED
#define NANORANGE_ITERATOR_UNREACHABLE_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

// [range.unreachable.sentinels]

class unreachable {
};

template <typename I>
constexpr std::enable_if_t<Iterator<I>, bool> operator==(const I&,
                                                         unreachable) noexcept
{
    return false;
}

template <typename I>
constexpr std::enable_if_t<Iterator<I>, bool> operator==(unreachable,
                                                         const I&) noexcept
{
    return false;
}

template <typename I>
constexpr std::enable_if_t<Iterator<I>, bool> operator!=(const I&,
                                                         unreachable) noexcept
{
    return true;
}

template <typename I>
constexpr std::enable_if_t<Iterator<I>, bool> operator!=(unreachable,
                                                         const I&) noexcept
{
    return true;
}

NANO_END_NAMESPACE

#endif


#endif

// nanorange/functional.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_FUNCTIONAL_HPP_INCLUDED
#define NANORANGE_FUNCTIONAL_HPP_INCLUDED





#endif


#endif

NANO_BEGIN_NAMESPACE

// [range.alg.adjacent.find]

namespace detail {

struct adjacent_find_fn {
private:
    template <typename I, typename S, typename Proj, typename Pred>
    static constexpr I impl(I first, S last, Pred pred, Proj proj)
    {
        if (first == last) {
            return first;
        }

        I next = first;
        ++next;

        while (next != last) {
            if (nano::invoke(pred, nano::invoke(proj, *first),
                             nano::invoke(proj, *next))) {
                return first;
            }
            ++first;
            ++next;
        }

        return first;
    }

public:
    template <typename I, typename S, typename Proj = identity,
              typename Pred = equal_to<>>
    constexpr std::enable_if_t<ForwardIterator<I> && Sentinel<S, I> &&
                                   IndirectRelation<Pred, projected<I, Proj>>,
                               I>
    operator()(I first, S last, Pred pred = Pred{}, Proj proj = Proj{}) const
    {
        return adjacent_find_fn::impl(std::move(first), std::move(last),
                                      std::move(pred), std::move(proj));
    }

    template <typename Rng, typename Proj = identity,
              typename Pred = equal_to<>>
    constexpr std::enable_if_t<
        ForwardRange<Rng> &&
            IndirectRelation<Pred, projected<iterator_t<Rng>, Proj>>,
        safe_iterator_t<Rng>>
    operator()(Rng&& rng, Pred pred = Pred{}, Proj proj = Proj{}) const
    {
        return adjacent_find_fn::impl(nano::begin(rng), nano::end(rng),
                                      std::move(pred), std::move(proj));
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::adjacent_find_fn, adjacent_find)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/all_of.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_ALL_OF_HPP_INCLUDED
#define NANORANGE_ALGORITHM_ALL_OF_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

// [range.alg.all_of]

namespace detail {

struct all_of_fn {
private:
    template <typename I, typename S, typename Proj, typename Pred>
    static constexpr bool impl(I first, S last, Pred pred, Proj proj)
    {
        while (first != last) {
            if (!nano::invoke(pred, nano::invoke(proj, *first))) {
                return false;
            }
            ++first;
        }
        return true;
    }

public:
    template <typename I, typename S, typename Proj = identity, typename Pred>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> &&
            IndirectUnaryPredicate<Pred, projected<I, Proj>>,
        bool>
    operator()(I first, S last, Pred pred, Proj proj = Proj{}) const
    {
        return all_of_fn::impl(std::move(first), std::move(last),
                               std::move(pred), std::move(proj));
    }

    template <typename Rng, typename Proj = identity, typename Pred>
    constexpr std::enable_if_t<
        InputRange<Rng> &&
            IndirectUnaryPredicate<Pred, projected<iterator_t<Rng>, Proj>>,
        bool>
    operator()(Rng&& rng, Pred pred, Proj proj = Proj{}) const
    {
        return all_of_fn::impl(nano::begin(rng), nano::end(rng),
                               std::move(pred), std::move(proj));
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::all_of_fn, all_of)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/any_of.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_ANY_OF_HPP_INCLUDED
#define NANORANGE_ALGORITHM_ANY_OF_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

// [ranges.alg.any_of]

namespace detail {

struct any_of_fn {
private:
    // Allow none_of to use this implementation
    friend struct none_of_fn;

    template <typename I, typename S, typename Proj, typename Pred>
    static constexpr bool impl(I first, S last, Pred pred, Proj proj)
    {
        while (first != last) {
            if (nano::invoke(pred, nano::invoke(proj, *first)) == true) {
                return true;
            }
            ++first;
        }
        return false;
    }

public:
    template <typename I, typename S, typename Proj = identity, typename Pred>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> &&
            IndirectUnaryPredicate<Pred, projected<I, Proj>>,
        bool>
    operator()(I first, S last, Pred pred, Proj proj = Proj{}) const
    {
        return any_of_fn::impl(std::move(first), std::move(last),
                               std::move(pred), std::move(proj));
    }

    template <typename Rng, typename Proj = identity, typename Pred>
    constexpr std::enable_if_t<
        InputRange<Rng> &&
            IndirectUnaryPredicate<Pred, projected<iterator_t<Rng>, Proj>>,
        bool>
    operator()(Rng&& rng, Pred pred, Proj proj = Proj{}) const
    {
        return any_of_fn::impl(nano::begin(rng), nano::end(rng),
                               std::move(pred), std::move(proj));
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::any_of_fn, any_of)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/copy.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_COPY_HPP_INCLUDED
#define NANORANGE_ALGORITHM_COPY_HPP_INCLUDED




NANO_BEGIN_NAMESPACE

namespace detail {

struct copy_fn {
private:
    // FIXME: Use tagged_pair

    // If we know the distance between first and last, we can use that
    // information to (potentially) allow better codegen
    template <typename I, typename S, typename O>
    static constexpr std::enable_if_t<SizedSentinel<S, I>, std::pair<I, O>>
    impl(I first, S last, O result, priority_tag<1>)
    {
        const auto dist = last - first;

        for (difference_type_t<I> i = 0; i < dist; ++i) {
            *result = *first;
            ++first;
            ++result;
        }

        return {std::move(first), std::move(result)};
    }

    template <typename I, typename S, typename O>
    static constexpr std::pair<I, O> impl(I first, S last, O result,
                                          priority_tag<0>)
    {
        while (first != last) {
            *result = *first;
            ++first;
            ++result;
        }

        return {std::move(first), std::move(result)};
    }

public:
    template <typename I, typename S, typename O>
    constexpr std::enable_if_t<InputIterator<I> && Sentinel<S, I> &&
                                   WeaklyIncrementable<O> &&
                                   IndirectlyCopyable<I, O>,
                               std::pair<I, O>>
    operator()(I first, S last, O result) const
    {
        return copy_fn::impl(std::move(first), std::move(last),
                             std::move(result), priority_tag<1>{});
    }

    template <typename Rng, typename O>
    constexpr std::enable_if_t<InputRange<Rng> && WeaklyIncrementable<O> &&
                                   IndirectlyComparable<iterator_t<Rng>, O>,
                               std::pair<safe_iterator_t<Rng>, O>>
    operator()(Rng&& rng, O result) const
    {
        return copy_fn::impl(nano::begin(rng), nano::end(rng),
                             std::move(result), priority_tag<1>{});
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::copy_fn, copy)

namespace detail {

struct copy_n_fn {
    template <typename I, typename O>
    constexpr std::enable_if_t<InputIterator<I> && WeaklyIncrementable<O> &&
                                   IndirectlyCopyable<I, O>,
                               std::pair<I, O>>
    operator()(I first, difference_type_t<I> n, O result) const
    {
        for (difference_type_t<I> i{}; i < n; i++) {
            *result = *first;
            ++first;
            ++result;
        }

        return {std::move(first), std::move(result)};
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::copy_n_fn, copy_n)

namespace detail {

struct copy_if_fn {
private:
    template <typename I, typename S, typename O, typename Pred, typename Proj>
    static constexpr std::pair<I, O> impl(I first, S last, O result, Pred pred,
                                          Proj proj)
    {
        while (first != last) {
            if (nano::invoke(pred, nano::invoke(proj, *first))) {
                *result = *first;
                ++result;
            }
            ++first;
        }

        return {std::move(first), std::move(result)};
    }

public:
    template <typename I, typename S, typename O, typename Proj = identity,
              typename Pred>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> && WeaklyIncrementable<O> &&
            IndirectUnaryPredicate<Pred, projected<I, Proj>> &&
            IndirectlyCopyable<I, O>,
        std::pair<I, O>>
    operator()(I first, S last, O result, Pred pred, Proj proj = Proj{}) const
    {
        return copy_if_fn::impl(std::move(first), std::move(last),
                                std::move(result), std::move(pred),
                                std::move(proj));
    }

    template <typename Rng, typename O, typename Proj = identity, typename Pred>
    constexpr std::enable_if_t<
        InputRange<Rng> && WeaklyIncrementable<O> &&
            IndirectUnaryPredicate<Pred, projected<iterator_t<Rng>, Proj>>,
        std::pair<safe_iterator_t<Rng>, O>>
    operator()(Rng&& rng, O result, Pred pred, Proj proj = Proj{}) const
    {
        return copy_if_fn::impl(nano::begin(rng), nano::end(rng),
                                std::move(result), std::move(pred),
                                std::move(proj));
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::copy_if_fn, copy_if)

namespace detail {

struct copy_backward_fn {
private:
    template <typename I1, typename S1, typename I2>
    static constexpr std::pair<I1, I2> impl(I1 first, S1 last, I2 result)
    {
        I1 last_it = nano::next(first, std::move(last));
        I1 it = last_it;

        while (it != first) {
            *--result = *--it;
        }

        return {std::move(last_it), std::move(result)};
    }

public:
    template <typename I1, typename S1, typename I2>
    constexpr std::enable_if_t<BidirectionalIterator<I1> && Sentinel<S1, I1> &&
                                   BidirectionalIterator<I2> &&
                                   IndirectlyCopyable<I1, I2>,
                               std::pair<I1, I2>>
    operator()(I1 first, S1 last, I2 result) const
    {
        return copy_backward_fn::impl(std::move(first), std::move(last),
                                      std::move(result));
    }

    template <typename Rng, typename I>
    constexpr std::enable_if_t<BidirectionalRange<Rng> &&
                                   BidirectionalIterator<I> &&
                                   IndirectlyCopyable<iterator_t<Rng>, I>,
                               std::pair<safe_iterator_t<Rng>, I>>
    operator()(Rng&& rng, I result) const
    {
        return copy_backward_fn::impl(nano::begin(rng), nano::end(rng),
                                      std::move(result));
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::copy_backward_fn, copy_backward)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/count.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_COUNT_HPP_INCLUDED
#define NANORANGE_ALGORITHM_COUNT_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

// [rng.alg.count]

namespace detail {

struct count_if_fn {
private:
    friend struct count_fn;

    template <typename I, typename S, typename Proj, typename Pred>
    static constexpr difference_type_t<I> impl(I first, S last, Pred pred,
                                               Proj proj)
    {
        difference_type_t<I> counter = 0;

        for (; first != last; ++first) {
            if (nano::invoke(pred, nano::invoke(proj, *first))) {
                ++counter;
            }
        }

        return counter;
    }

public:
    template <typename I, typename S, typename Proj = identity, typename Pred>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> &&
            IndirectUnaryPredicate<Pred, projected<I, Proj>>,
        difference_type_t<I>>
    operator()(I first, S last, Pred pred, Proj proj = Proj{}) const
    {
        return count_if_fn::impl(std::move(first), std::move(last),
                                 std::move(pred), std::move(proj));
    }

    template <typename Rng, typename Proj = identity, typename Pred>
    constexpr std::enable_if_t<
        InputRange<Rng> &&
            IndirectUnaryPredicate<Pred, projected<iterator_t<Rng>, Proj>>,
        difference_type_t<iterator_t<Rng>>>
    operator()(Rng&& rng, Pred pred, Proj proj = Proj{}) const
    {
        return count_if_fn::impl(nano::begin(rng), nano::end(rng),
                                 std::move(pred), std::move(proj));
    }
};
} // namespace detail

NANO_INLINE_VAR(detail::count_if_fn, count_if)

namespace detail {

struct count_fn {
private:
    template <typename ValueType>
    struct equal_to_pred {
        const ValueType& val;

        template <typename T>
        constexpr bool operator()(const T& t) const
        {
            return t == val;
        }
    };

public:
    template <typename I, typename S, typename T, typename Proj = identity>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> &&
            IndirectRelation<equal_to<>, projected<I, Proj>, const T*>,
        difference_type_t<I>>
    operator()(I first, S last, const T& value, Proj proj = Proj{}) const
    {
        return count_if_fn::impl(std::move(first), std::move(last),
                                 equal_to_pred<T>{value}, std::move(proj));
    }

    template <typename Rng, typename T, typename Proj = identity>
    constexpr std::enable_if_t<
        InputRange<Rng> &&
            IndirectRelation<equal_to<>, projected<iterator_t<Rng>, Proj>,
                             const T*>,
        difference_type_t<iterator_t<Rng>>>
    operator()(Rng&& rng, const T& value, Proj proj = Proj{}) const
    {
        return count_if_fn::impl(nano::begin(rng), nano::end(rng),
                                 equal_to_pred<T>{value}, std::move(proj));
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::count_fn, count)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/equal.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_EQUAL_HPP_INCLUDED
#define NANORANGE_ALGORITHM_EQUAL_HPP_INCLUDED




NANO_BEGIN_NAMESPACE

namespace detail {

struct equal_fn {
private:
    template <typename I1, typename S1, typename I2, typename S2, typename Pred,
              typename Proj1, typename Proj2>
    static constexpr bool impl4(I1 first1, S1 last1, I2 first2, S2 last2,
                                Pred pred, Proj1 proj1, Proj2 proj2)
    {
        while (first1 != last1 && first2 != last2) {
            if (!nano::invoke(pred, nano::invoke(proj1, *first1),
                              nano::invoke(proj2, *first2))) {
                return false;
            }
            ++first1;
            ++first2;
        }

        return first1 == last1 && first2 == last2;
    }

    template <typename I1, typename S1, typename I2, typename Pred,
              typename Proj1, typename Proj2>
    static constexpr bool impl3(I1 first1, S1 last1, I2 first2, Pred pred,
                                Proj1 proj1, Proj2 proj2)
    {
        while (first1 != last1) {
            if (!nano::invoke(pred, nano::invoke(proj1, *first1),
                              nano::invoke(proj2, *first2))) {
                return false;
            }
            ++first1;
            ++first2;
        }

        return true;
    }

public:
    // Four-legged, sized sentinels
    template <typename I1, typename S1, typename I2, typename S2,
              typename Pred = equal_to<>, typename Proj1 = identity,
              typename Proj2 = identity>
    constexpr std::enable_if_t<
        InputIterator<I1> && Sentinel<S1, I1> && InputIterator<I2> &&
            Sentinel<S2, I2> &&
            IndirectlyComparable<I1, I2, Pred, Proj1, Proj2> &&
            SizedSentinel<S1, I1> && SizedSentinel<S2, I2>,
        bool>
    operator()(I1 first1, S1 last1, I2 first2, S2 last2, Pred pred = Pred{},
               Proj1 proj1 = Proj1{}, Proj2 proj2 = Proj2{}) const
    {
        if (last1 - first1 != last2 - first2) {
            return false;
        }

        // Ranges are the same size, so call the 3-legged version
        // and save ourselves a comparison
        return equal_fn::impl3(std::move(first1), std::move(last1),
                               std::move(first2), std::move(pred),
                               std::move(proj1), std::move(proj2));
    }

    // Four-legged, unsized sentinels
    template <typename I1, typename S1, typename I2, typename S2,
              typename Pred = equal_to<>, typename Proj1 = identity,
              typename Proj2 = identity>
    constexpr std::enable_if_t<
        InputIterator<I1> && Sentinel<S1, I1> && InputIterator<I2> &&
            Sentinel<S2, I2> &&
            IndirectlyComparable<I1, I2, Pred, Proj1, Proj2> &&
            !(SizedSentinel<S1, I1> && SizedSentinel<S2, I2>),
        bool>
    operator()(I1 first1, S1 last1, I2 first2, S2 last2, Pred pred = Pred{},
               Proj1 proj1 = Proj1{}, Proj2 proj2 = Proj2{}) const
    {
        return equal_fn::impl4(std::move(first1), std::move(last1),
                               std::move(first2), std::move(last2),
                               std::move(pred), std::move(proj1),
                               std::move(proj2));
    }

    // Three legged
    template <typename I1, typename S1, typename I2, typename Pred = equal_to<>,
              typename Proj1 = identity, typename Proj2 = identity>
    NANO_DEPRECATED constexpr std::enable_if_t<
        InputIterator<I1> && Sentinel<S1, I1> && InputIterator<I2> &&
            IndirectlyComparable<I1, I2, Pred, Proj1, Proj2>,
        bool>
    operator()(I1 first1, S1 last1, I2 first2, Pred pred = Pred{},
               Proj1 proj1 = Proj1{}, Proj2 proj2 = Proj2{}) const
    {
        return equal_fn::impl3(std::move(first1), std::move(last1),
                               std::move(first2), std::move(pred),
                               std::move(proj1), std::move(proj2));
    }

    // Two ranges, both sized
    template <typename Rng1, typename Rng2, typename Pred = equal_to<>,
              typename Proj1 = identity, typename Proj2 = identity>
    constexpr std::enable_if_t<
        InputRange<Rng1> && InputRange<Rng2> &&
            IndirectlyComparable<iterator_t<Rng1>, iterator_t<Rng2>, Pred,
                                 Proj1, Proj2> &&
            SizedRange<Rng1> && SizedRange<Rng2>,
        bool>
    operator()(Rng1&& rng1, Rng2&& rng2, Pred pred = Pred{},
               Proj1 proj1 = Proj1{}, Proj2 proj2 = Proj2{}) const
    {
        if (nano::distance(rng1) != nano::distance(rng2)) {
            return false;
        }

        return equal_fn::impl3(nano::begin(rng1), nano::end(rng1),
                               nano::begin(rng2), std::move(pred),
                               std::move(proj1), std::move(proj2));
    }

    // Two ranges, not both sized
    template <typename Rng1, typename Rng2, typename Pred = equal_to<>,
              typename Proj1 = identity, typename Proj2 = identity>
    constexpr std::enable_if_t<
        InputRange<Rng1> && InputRange<Rng2> &&
            IndirectlyComparable<iterator_t<Rng1>, iterator_t<Rng2>, Pred,
                                 Proj1, Proj2> &&
            !(SizedRange<Rng1> && SizedRange<Rng2>),
        bool>
    operator()(Rng1&& rng1, Rng2&& rng2, Pred pred = Pred{},
               Proj1 proj1 = Proj1{}, Proj2 proj2 = Proj2{}) const
    {
        return equal_fn::impl4(nano::begin(rng1), nano::end(rng1),
                               nano::begin(rng2), nano::end(rng2),
                               std::move(pred), std::move(proj1),
                               std::move(proj2));
    }

    // Range and a half
    template <typename Rng1, typename I2, typename Pred = equal_to<>,
              typename Proj1 = identity, typename Proj2 = identity>
    NANO_DEPRECATED constexpr std::enable_if_t<
        InputRange<Rng1> && InputIterator<I2> &&
            IndirectlyComparable<iterator_t<Rng1>, I2, Pred, Proj1, Proj2>,
        bool>
    operator()(Rng1&& rng1, I2 first2, Pred pred = Pred{},
               Proj1 proj1 = Proj1{}, Proj2 proj2 = Proj2{}) const
    {
        return equal_fn::impl3(nano::begin(rng1), nano::end(rng1),
                               std::move(first2), std::move(pred),
                               std::move(proj1), std::move(proj2));
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::equal_fn, equal)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/fill.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_FILL_HPP_INCLUDED
#define NANORANGE_ALGORITHM_FILL_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

namespace detail {

struct fill_fn {
private:
    template <typename T, typename O, typename S>
    static constexpr O impl(O first, S last, const T& value)
    {
        while (first != last) {
            *first = value;
            ++first;
        }

        return first;
    }

public:
    template <typename T, typename O, typename S>
    constexpr std::enable_if_t<OutputIterator<O, const T&> && Sentinel<S, O>, O>
    operator()(O first, S last, const T& value) const
    {
        return fill_fn::impl(std::move(first), std::move(last), value);
    }

    template <typename T, typename Rng>
    constexpr std::enable_if_t<OutputRange<Rng, const T&>, safe_iterator_t<Rng>>
    operator()(Rng&& rng, const T& value) const
    {
        return fill_fn::impl(nano::begin(rng), nano::end(rng), value);
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::fill_fn, fill)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/fill_n.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_FILL_N_HPP_INCLUDED
#define NANORANGE_ALGORITHM_FILL_N_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

namespace detail {

struct fill_n_fn {
    template <typename T, typename O>
    constexpr std::enable_if_t<OutputIterator<O, const T&>, O>
    operator()(O first, difference_type_t<O> n, const T& value) const
    {
        for (difference_type_t<O> i{0}; i < n; ++i, ++first) {
            *first = value;
        }
        return first;
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::fill_n_fn, fill_n)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/find.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_FIND_HPP_INCLUDED
#define NANORANGE_ALGORITHM_FIND_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

// [ranges.alg.find]

namespace detail {

struct find_if_fn {
private:
    friend struct find_fn;
    friend struct find_if_not_fn;

    template <typename I, typename S, typename Pred, typename Proj>
    static constexpr I impl(I first, S last, Pred pred, Proj proj)
    {
        while (first != last) {
            if (nano::invoke(pred, nano::invoke(proj, *first))) {
                return first;
            }
            ++first;
        }
        return first;
    }

public:
    template <typename I, typename S, typename Proj = identity, typename Pred>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> &&
            IndirectUnaryPredicate<Pred, projected<I, Proj>>,
        I>
    operator()(I first, S last, Pred pred, Proj proj = Proj{}) const
    {
        return find_if_fn::impl(std::move(first), std::move(last),
                                std::move(pred), std::move(proj));
    }

    template <typename Rng, typename Proj = identity, typename Pred>
    constexpr std::enable_if_t<
        InputRange<Rng> &&
            IndirectUnaryPredicate<Pred, projected<iterator_t<Rng>, Proj>>,
        safe_iterator_t<Rng>>
    operator()(Rng&& rng, Pred pred, Proj proj = Proj{}) const
    {
        return find_if_fn::impl(nano::begin(rng), nano::end(rng),
                                std::move(pred), std::move(proj));
    }
};
} // namespace detail

NANO_INLINE_VAR(detail::find_if_fn, find_if)

namespace detail {

struct find_fn {
private:
    template <typename ValueType>
    struct equal_to_pred {
        const ValueType& val;

        template <typename T>
        constexpr bool operator()(const T& t) const
        {
            return t == val;
        }
    };

public:
    template <typename I, typename S, typename T, typename Proj = identity>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> &&
            IndirectRelation<equal_to<>, projected<I, Proj>, const T*>,
        I>
    operator()(I first, S last, const T& value, Proj proj = Proj{}) const
    {
        return find_if_fn::impl(std::move(first), std::move(last),
                                equal_to_pred<T>{value}, std::move(proj));
    }

    template <typename Rng, typename T, typename Proj = identity>
    constexpr std::enable_if_t<
        InputRange<Rng> &&
            IndirectRelation<equal_to<>, projected<iterator_t<Rng>, Proj>,
                             const T*>,
        safe_iterator_t<Rng>>
    operator()(Rng&& rng, const T& value, Proj proj = Proj{}) const
    {
        return find_if_fn::impl(nano::begin(rng), nano::end(rng),
                                equal_to_pred<T>{value}, std::move(proj));
    }
};
} // namespace detail

NANO_INLINE_VAR(detail::find_fn, find)

namespace detail {

struct find_if_not_fn {
private:
    template <typename Pred>
    struct not_pred {
        Pred& p;

        template <typename T>
        constexpr bool operator()(T&& t) const
        {
            return !nano::invoke(p, std::forward<T>(t));
        }
    };

public:
    template <typename I, typename S, typename Proj = identity, typename Pred>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> &&
            IndirectUnaryPredicate<Pred, projected<I, Proj>>,
        I>
    operator()(I first, S last, Pred pred, Proj proj = Proj{}) const
    {
        return find_if_fn::impl(std::move(first), std::move(last),
                                not_pred<Pred>{pred}, std::move(proj));
    }

    template <typename Rng, typename Proj = identity, typename Pred>
    constexpr std::enable_if_t<
        InputRange<Rng> &&
            IndirectUnaryPredicate<Pred, projected<iterator_t<Rng>, Proj>>,
        safe_iterator_t<Rng>>
    operator()(Rng&& rng, Pred pred, Proj proj = Proj{}) const
    {
        return find_if_fn::impl(nano::begin(rng), nano::end(rng),
                                not_pred<Pred>{pred}, std::move(proj));
    }
};
} // namespace detail

NANO_INLINE_VAR(detail::find_if_not_fn, find_if_not)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/find_first_of.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_FIND_FIRST_OF_HPP_INCLUDED
#define NANORANGE_ALGORITHM_FIND_FIRST_OF_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

// [range.alg.find.first.of]

namespace detail {

struct find_first_of_fn {
private:
    template <typename I1, typename S1, typename I2, typename S2, typename Pred,
              typename Proj1, typename Proj2>
    static constexpr I1 impl(I1 first1, S1 last1, I2 first2, S2 last2,
                             Pred pred, Proj1 proj1, Proj2 proj2)
    {
        for (; first1 != last1; ++first1) {
            for (I2 it = first2; it != last2; ++it) {
                if (nano::invoke(pred, nano::invoke(proj1, *first1),
                                 nano::invoke(proj2, *it))) {
                    return first1;
                }
            }
        }

        return first1;
    }

public:
    template <typename I1, typename S1, typename I2, typename S2,
              typename Proj1 = identity, typename Proj2 = identity,
              typename Pred = equal_to<>>
    constexpr std::enable_if_t<
        InputIterator<I1> && Sentinel<S1, I1> && ForwardIterator<I2> &&
            Sentinel<S2, I2> &&
            IndirectRelation<Pred, projected<I1, Proj1>, projected<I2, Proj2>>,
        I1>
    operator()(I1 first1, S1 last1, I2 first2, S2 last2, Pred pred = Pred{},
               Proj1 proj1 = Proj1{}, Proj2 proj2 = Proj2{}) const
    {
        return find_first_of_fn::impl(std::move(first1), std::move(last1),
                                      std::move(first2), std::move(last2),
                                      std::move(pred), std::move(proj1),
                                      std::move(proj2));
    }

    template <typename Rng1, typename Rng2, typename Proj1 = identity,
              typename Proj2 = identity, typename Pred = equal_to<>>
    constexpr std::enable_if_t<
        InputRange<Rng1> && ForwardRange<Rng2> &&
            IndirectRelation<Pred, projected<iterator_t<Rng1>, Proj1>,
                             projected<iterator_t<Rng2>, Proj2>>,
        safe_iterator_t<Rng1>>
    operator()(Rng1&& rng1, Rng2&& rng2, Pred pred = Pred{},
               Proj1 proj1 = Proj1{}, Proj2 proj2 = Proj2{}) const
    {
        return find_first_of_fn::impl(nano::begin(rng1), nano::end(rng1),
                                      nano::begin(rng2), nano::end(rng2),
                                      std::move(pred), std::move(proj1),
                                      std::move(proj2));
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::find_first_of_fn, find_first_of)

NANO_END_NAMESPACE

#endif
// nanorange/algorithm/for_each.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_FOR_EACH_HPP_INCLUDED
#define NANORANGE_ALGORITHM_FOR_EACH_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

// [range.alg.foreach]

namespace detail {

struct for_each_fn {
private:
    template <typename I, typename S, typename Proj, typename Fun>
    static constexpr std::pair<I, Fun> // FIXME: Used tagged pair
    impl(I first, S last, Fun fun, Proj proj)
    {
        while (first != last) {
            nano::invoke(fun, nano::invoke(proj, *first));
            ++first;
        }
        return {last, std::move(fun)};
    }

public:
    template <typename I, typename S, typename Proj = identity, typename Fun>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> &&
            IndirectUnaryInvocable<Fun, projected<I, Proj>>,
        std::pair<I, Fun>> // FIXME: use tagged_pair
    operator()(I first, S last, Fun fun, Proj proj = Proj{}) const
    {
        return for_each_fn::impl(std::move(first), std::move(last),
                                 std::move(fun), std::move(proj));
    }

    template <typename Rng, typename Proj = identity, typename Fun>
    constexpr std::enable_if_t<
        InputRange<Rng> &&
            IndirectUnaryInvocable<Fun, projected<iterator_t<Rng>, Proj>>,
        std::pair<safe_iterator_t<Rng>, Fun>>
    operator()(Rng&& rng, Fun fun, Proj proj = Proj{}) const
    {
        return for_each_fn::impl(nano::begin(rng), nano::end(rng),
                                 std::move(fun), std::move(proj));
    }
};
} // namespace detail

NANO_INLINE_VAR(detail::for_each_fn, for_each)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/generate.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_GENERATE_HPP_INCLUDED
#define NANORANGE_ALGORITHM_GENERATE_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

namespace detail {

struct generate_fn {
private:
    template <typename O, typename S, typename F>
    static constexpr O impl(O first, S last, F& gen)
    {
        while (first != last) {
            *first = gen();
            ++first;
        }

        return first;
    }

public:
    template <typename O, typename S, typename F>
    constexpr std::enable_if_t<Iterator<O> && Sentinel<S, O> &&
                                   CopyConstructible<F> && Invocable<F&> &&
                                   Writable<O, invoke_result_t<F&>>,
                               O>
    operator()(O first, S last, F gen) const
    {
        return generate_fn::impl(std::move(first), std::move(last), gen);
    }

    template <typename Rng, typename F>
    constexpr std::enable_if_t<Invocable<F&> &&
                                   OutputRange<Rng, invoke_result_t<F&>>,
                               safe_iterator_t<Rng>>
    operator()(Rng&& rng, F gen) const
    {
        return generate_fn::impl(nano::begin(rng), nano::end(rng), gen);
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::generate_fn, generate)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/generate_n.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_GENERATE_N_HPP_INCLUDED
#define NANORANGE_ALGORITHM_GENERATE_N_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

namespace detail {

struct generate_n_fn {
    template <typename O, typename F>
    constexpr std::enable_if_t<Iterator<O> && CopyConstructible<F> &&
                                   Invocable<F&> &&
                                   Writable<O, invoke_result_t<F&>>,
                               O>
    operator()(O first, difference_type_t<O> n, F gen) const
    {
        for (difference_type_t<O> i{0}; i < n; ++i, ++first) {
            *first = gen();
        }

        return first;
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::generate_n_fn, generate_n)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/mismatch.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_MISMATCH_HPP_INCLUDED
#define NANORANGE_ALGORITHM_MISMATCH_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

// [range.mismatch]

namespace detail {

// FIXME: Use tagged pair
struct mismatch_fn {
private:
    template <typename I1, typename S1, typename I2, typename Proj1,
              typename Proj2, typename Pred>
    static constexpr std::pair<I1, I2>
    impl3(I1 first1, S1 last1, I2 first2, Pred pred, Proj1 proj1, Proj2 proj2)
    {
        while (first1 != last1 &&
               nano::invoke(pred, nano::invoke(proj1, *first1),
                            nano::invoke(proj2, *first2))) {
            ++first1;
            ++first2;
        }

        return {first1, first2};
    }

    template <typename I1, typename S1, typename I2, typename S2,
              typename Proj1, typename Proj2, typename Pred>
    static constexpr std::pair<I1, I2> impl4(I1 first1, S1 last1, I2 first2,
                                             S2 last2, Pred pred, Proj1 proj1,
                                             Proj2 proj2)
    {
        while (first1 != last1 && first2 != last2 &&
               nano::invoke(pred, nano::invoke(proj1, *first1),
                            nano::invoke(proj2, *first2))) {
            ++first1;
            ++first2;
        }

        return {first1, first2};
    }

public:
    template <typename I1, typename S1, typename I2, typename Proj1 = identity,
              typename Proj2 = identity, typename Pred = equal_to<>>
    NANO_DEPRECATED constexpr std::enable_if_t<
        InputIterator<I1> && Sentinel<S1, I1> && InputIterator<I2> &&
            IndirectRelation<Pred, projected<I1, Proj1>, projected<I2, Proj2>>,
        std::pair<I1, I2>>
    operator()(I1 first1, S1 last1, I2 first2, Pred pred = Pred{},
               Proj1 proj1 = Proj1{}, Proj2 proj2 = Proj2{}) const
    {
        return mismatch_fn::impl3(std::move(first1), std::move(last1),
                                  std::move(first2), std::move(pred),
                                  std::move(proj1), std::move(proj2));
    }

    template <typename Rng1, typename I2, typename Proj1 = identity,
              typename Proj2 = identity, typename Pred = equal_to<>>
    NANO_DEPRECATED constexpr std::enable_if_t<
        InputRange<Rng1> && InputIterator<I2> &&
            IndirectRelation<Pred, projected<iterator_t<Rng1>, Proj1>,
                             projected<I2, Proj2>>,
        std::pair<safe_iterator_t<Rng1>, I2>>
    operator()(Rng1&& rng1, I2 first2, Pred pred = Pred{},
               Proj1 proj1 = Proj1{}, Proj2 proj2 = Proj2{}) const
    {
        return mismatch_fn::impl3(nano::begin(rng1), nano::end(rng1),
                                  std::move(first2), std::move(pred),
                                  std::move(proj1), std::move(proj2));
    }

    template <typename I1, typename S1, typename I2, typename S2,
              typename Proj1 = identity, typename Proj2 = identity,
              typename Pred = equal_to<>>
    constexpr std::enable_if_t<
        InputIterator<I1> && Sentinel<S1, I1> && InputIterator<I2> &&
            Sentinel<S2, I2> &&
            IndirectRelation<Pred, projected<I1, Proj1>, projected<I2, Proj2>>,
        std::pair<I1, I2>>
    operator()(I1 first1, S1 last1, I2 first2, S2 last2, Pred pred = Pred{},
               Proj1 proj1 = Proj1{}, Proj2 proj2 = Proj2{}) const
    {
        return mismatch_fn::impl4(std::move(first1), std::move(last1),
                                  std::move(first2), std::move(last2),
                                  std::move(pred), std::move(proj1),
                                  std::move(proj2));
    }

    template <typename Rng1, typename Rng2, typename Proj1 = identity,
              typename Proj2 = identity, typename Pred = equal_to<>>
    constexpr std::enable_if_t<
        InputRange<Rng1> && InputRange<Rng2> &&
            IndirectRelation<Pred, projected<iterator_t<Rng1>, Proj1>,
                             projected<iterator_t<Rng2>, Proj2>>,
        std::pair<safe_iterator_t<Rng1>, safe_iterator_t<Rng2>>>
    operator()(Rng1&& rng1, Rng2&& rng2, Pred pred = Pred{},
               Proj1 proj1 = Proj1{}, Proj2 proj2 = Proj2{}) const
    {
        return mismatch_fn::impl4(nano::begin(rng1), nano::end(rng1),
                                  nano::begin(rng2), nano::end(rng2),
                                  std::move(pred), std::move(proj1),
                                  std::move(proj2));
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::mismatch_fn, mismatch)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/move.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_MOVE_HPP_INCLUDED
#define NANORANGE_ALGORITHM_MOVE_HPP_INCLUDED




NANO_BEGIN_NAMESPACE

namespace detail {

struct move_fn {
private:
    // FIXME: Use tagged_pair
    template <typename I, typename S, typename O>
    static constexpr std::enable_if_t<SizedSentinel<S, I>, std::pair<I, O>>
    impl(I first, S last, O result, priority_tag<1>)
    {
        const auto dist = last - first;

        for (difference_type_t<I> i{0}; i < dist; i++) {
            *result = nano::iter_move(first);
            ++first;
            ++result;
        }

        return {std::move(first), std::move(result)};
    }

    template <typename I, typename S, typename O>
    static constexpr std::pair<I, O> impl(I first, S last, O result,
                                          priority_tag<0>)
    {
        while (first != last) {
            *result = nano::iter_move(first);
            ++first;
            ++result;
        }

        return {std::move(first), std::move(result)};
    }

public:
    template <typename I, typename S, typename O>
    constexpr std::enable_if_t<InputIterator<I> && Sentinel<S, I> &&
                                   WeaklyIncrementable<O> &&
                                   IndirectlyMovable<I, O>,
                               std::pair<I, O>>
    operator()(I first, S last, O result) const
    {
        return move_fn::impl(std::move(first), std::move(last),
                             std::move(result), priority_tag<1>{});
    }

    template <typename Rng, typename O>
    constexpr std::enable_if_t<InputRange<Rng> && WeaklyIncrementable<O> &&
                                   IndirectlyMovable<iterator_t<Rng>, O>,
                               std::pair<safe_iterator_t<Rng>, O>>
    operator()(Rng&& rng, O result) const
    {
        return move_fn::impl(nano::begin(rng), nano::end(rng),
                             std::move(result), priority_tag<1>{});
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::move_fn, move)

namespace detail {

struct move_backward_fn {
private:
    template <typename I, typename S, typename O>
    static constexpr std::pair<I, O> impl(I first, S sent, O result)
    {
        auto last = nano::next(first, std::move(sent));
        auto it = last;

        while (it != first) {
            *--result = nano::iter_move(--it);
        }

        return {std::move(last), std::move(result)};
    }

public:
    template <typename I, typename S, typename O>
    constexpr std::enable_if_t<BidirectionalIterator<I> && Sentinel<S, I> &&
                                   BidirectionalIterator<O> &&
                                   IndirectlyMovable<I, O>,
                               std::pair<I, O>>
    operator()(I first, S last, O result) const
    {
        return move_backward_fn::impl(std::move(first), std::move(last),
                                      std::move(result));
    }

    template <typename Rng, typename O>
    constexpr std::enable_if_t<BidirectionalRange<Rng> &&
                                   BidirectionalIterator<O> &&
                                   IndirectlyMovable<iterator_t<Rng>, O>,
                               std::pair<safe_iterator_t<Rng>, O>>
    operator()(Rng&& rng, O result) const
    {
        return move_backward_fn::impl(nano::begin(rng), nano::end(rng),
                                      std::move(result));
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::move_backward_fn, move_backward)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/none_of.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_NONE_OF_HPP_INCLUDED
#define NANORANGE_ALGORITHM_NONE_OF_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

// [ranges.alg.none_of]

namespace detail {

struct none_of_fn {

    template <typename I, typename S, typename Proj = identity, typename Pred>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> &&
            IndirectUnaryPredicate<Pred, projected<I, Proj>>,
        bool>
    operator()(I first, S last, Pred pred, Proj proj = Proj{}) const
    {
        return !any_of_fn::impl(first, last, std::move(pred), std::move(proj));
    }

    template <typename Rng, typename Proj = identity, typename Pred>
    constexpr std::enable_if_t<
        InputRange<Rng> &&
            IndirectUnaryPredicate<Pred, projected<iterator_t<Rng>, Proj>>,
        bool>
    operator()(Rng&& rng, Pred pred, Proj proj = Proj{}) const
    {
        return !any_of_fn::impl(nano::begin(rng), nano::end(rng),
                                std::move(pred), std::move(proj));
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::none_of_fn, none_of)

NANO_END_NAMESPACE

#endif
// nanorange/algorithm/remove.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_REMOVE_HPP_INCLUDED
#define NANORANGE_ALGORITHM_REMOVE_HPP_INCLUDED





NANO_BEGIN_NAMESPACE

namespace detail {

struct remove_fn {
private:
    template <typename I, typename S, typename T, typename Proj>
    static constexpr I impl(I first, S last, const T& value, Proj& proj)
    {
        first = nano::find(std::move(first), last, value, proj);

        if (first == last) {
            return first;
        }

        for (auto i = next(first); i != last; ++i) {
            if (!(nano::invoke(proj, *i) == value)) {
                *first = nano::iter_move(i);
                ++first;
            }
        }

        return first;
    }

public:
    template <typename I, typename S, typename T, typename Proj = identity>
    constexpr std::enable_if_t<
        ForwardIterator<I> && Sentinel<S, I> && Permutable<I> &&
            IndirectRelation<equal_to<>, projected<I, Proj>, const T*>,
        I>
    operator()(I first, S last, const T& value, Proj proj = Proj{}) const
    {
        return remove_fn::impl(std::move(first), std::move(last), value, proj);
    }

    template <typename Rng, typename T, typename Proj = identity>
    constexpr std::enable_if_t<
        ForwardRange<Rng> && Permutable<iterator_t<Rng>> &&
            IndirectRelation<equal_to<>, projected<iterator_t<Rng>, Proj>,
                             const T*>,
        safe_iterator_t<Rng>>
    operator()(Rng&& rng, const T& value, Proj proj = Proj{}) const
    {
        return remove_fn::impl(nano::begin(rng), nano::end(rng), value, proj);
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::remove_fn, remove)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/remove_copy.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_REMOVE_COPY_HPP_INCLUDED
#define NANORANGE_ALGORITHM_REMOVE_COPY_HPP_INCLUDED





NANO_BEGIN_NAMESPACE

namespace detail {

// FIXME: Use tagged_pair
struct remove_copy_fn {
private:
    template <typename I, typename S, typename O, typename T, typename Proj>
    static constexpr std::pair<I, O> impl(I first, S last, O result,
                                          const T& value, Proj& proj)
    {
        while (first != last) {
            auto&& ref = *first;
            if (!(nano::invoke(proj, ref) == value)) {
                *result = std::forward<decltype(ref)>(ref);
                ++result;
            }
            ++first;
        }
        return {std::move(first), std::move(result)};
    }

public:
    template <typename I, typename S, typename O, typename T,
              typename Proj = identity>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> && WeaklyIncrementable<O> &&
            IndirectlyCopyable<I, O> &&
            IndirectRelation<equal_to<>, projected<I, Proj>, const T*>,
        std::pair<I, O>>
    operator()(I first, S last, O result, const T& value,
               Proj proj = Proj{}) const
    {
        return remove_copy_fn::impl(std::move(first), std::move(last),
                                    std::move(result), value, proj);
    }

    template <typename Rng, typename O, typename T, typename Proj = identity>
    constexpr std::enable_if_t<
        InputRange<Rng> && WeaklyIncrementable<O> &&
            IndirectlyCopyable<iterator_t<Rng>, O> &&
            IndirectRelation<equal_to<>, projected<iterator_t<Rng>, Proj>,
                             const T*>,
        std::pair<safe_iterator_t<Rng>, O>>
    operator()(Rng&& rng, O result, const T& value, Proj proj = Proj{}) const
    {
        return remove_copy_fn::impl(nano::begin(rng), nano::end(rng),
                               std::move(result), value, proj);
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::remove_copy_fn, remove_copy)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/remove_copy_if.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_REMOVE_COPY_IF_HPP_INCLUDED
#define NANORANGE_ALGORITHM_REMOVE_COPY_IF_HPP_INCLUDED





NANO_BEGIN_NAMESPACE

namespace detail {

// FIXME: Use tagged_pair
struct remove_copy_if_fn {
private:
    template <typename I, typename S, typename O, typename Pred, typename Proj>
    static constexpr std::pair<I, O> impl(I first, S last, O result,
                                          Pred& pred, Proj& proj)
    {
        while (first != last) {
            auto&& ref = *first;
            if (!nano::invoke(pred, nano::invoke(proj, ref))) {
                *result = std::forward<decltype(ref)>(ref);
                ++result;
            }
            ++first;
        }
        return {std::move(first), std::move(result)};
    }

public:
    template <typename I, typename S, typename O, typename Pred,
              typename Proj = identity>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> && WeaklyIncrementable<O> &&
            IndirectlyCopyable<I, O> &&
            IndirectUnaryPredicate<Pred, projected<I, Proj>>,
        std::pair<I, O>>
    operator()(I first, S last, O result, Pred pred,
               Proj proj = Proj{}) const
    {
        return remove_copy_if_fn::impl(std::move(first), std::move(last),
                                    std::move(result), pred, proj);
    }

    template <typename Rng, typename O, typename Pred, typename Proj = identity>
    constexpr std::enable_if_t<
        InputRange<Rng> && WeaklyIncrementable<O> &&
            IndirectlyCopyable<iterator_t<Rng>, O> &&
            IndirectUnaryPredicate<Pred, projected<iterator_t<Rng>, Proj>>,
        std::pair<safe_iterator_t<Rng>, O>>
    operator()(Rng&& rng, O result, Pred pred, Proj proj = Proj{}) const
    {
        return remove_copy_if_fn::impl(nano::begin(rng), nano::end(rng),
                                       std::move(result), pred, proj);
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::remove_copy_if_fn, remove_copy_if)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/remove_if.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_REMOVE_IF_HPP_INCLUDED
#define NANORANGE_ALGORITHM_REMOVE_IF_HPP_INCLUDED





NANO_BEGIN_NAMESPACE

namespace detail {

struct remove_if_fn {
private:
    template <typename I, typename S, typename Pred, typename Proj>
    static constexpr I impl(I first, S last, Pred& pred, Proj& proj)
    {
        first = nano::find_if(std::move(first), last, pred, proj);

        if (first == last) {
            return first;
        }

        for (auto i = next(first); i != last; ++i) {
            if (!nano::invoke(pred, nano::invoke(proj, *i))) {
                *first = nano::iter_move(i);
                ++first;
            }
        }

        return first;
    }

public:
    template <typename I, typename S, typename Pred, typename Proj = identity>
    constexpr std::enable_if_t<
        ForwardIterator<I> && Sentinel<S, I> && Permutable<I> &&
            IndirectUnaryPredicate<Pred, projected<I, Proj>>,
        I>
    operator()(I first, S last, Pred pred, Proj proj = Proj{}) const
    {
        return remove_if_fn::impl(std::move(first), std::move(last), pred, proj);
    }

    template <typename Rng, typename Pred, typename Proj = identity>
    constexpr std::enable_if_t<
        ForwardRange<Rng> && Permutable<iterator_t<Rng>> &&
            IndirectUnaryPredicate<Pred, projected<iterator_t<Rng>, Proj>>,
        safe_iterator_t<Rng>>
    operator()(Rng&& rng, Pred pred, Proj proj = Proj{}) const
    {
        return remove_if_fn::impl(nano::begin(rng), nano::end(rng), pred, proj);
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::remove_if_fn, remove_if)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/replace.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_REPLACE_HPP_INCLUDED
#define NANORANGE_ALGORITHM_REPLACE_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

namespace detail {

struct replace_fn {
private:
    template <typename I, typename S, typename T1, typename T2, typename Proj>
    static constexpr I impl(I first, S last, const T1& old_value,
                            const T2& new_value, Proj& proj)
    {
        while (first != last) {
            if (nano::invoke(proj, *first) == old_value) {
                *first = new_value;
            }
            ++first;
        }

        return std::move(first);
    }

public:
    template <typename I, typename S, typename T1, typename T2,
              typename Proj = identity>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> && Writable<I, const T2&> &&
            IndirectRelation<equal_to<>, projected<I, Proj>, const T1*>,
        I>
    operator()(I first, S last, const T1& old_value, const T2& new_value,
               Proj proj = Proj{}) const
    {
        return replace_fn::impl(std::move(first), std::move(last), old_value,
                                new_value, proj);
    }

    template <typename Rng, typename T1, typename T2, typename Proj = identity>
    constexpr std::enable_if_t<
        InputRange<Rng> && Writable<iterator_t<Rng>, const T2&> &&
            IndirectRelation<equal_to<>, projected<iterator_t<Rng>, Proj>,
                             const T1*>,
        safe_iterator_t<Rng>>
    operator()(Rng&& rng, const T1& old_value, const T2& new_value,
               Proj proj = Proj{}) const
    {
        return replace_fn::impl(nano::begin(rng), nano::end(rng), old_value,
                                new_value, proj);
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::replace_fn, replace)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/replace_copy.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_REPLACE_COPY_HPP_INCLUDED
#define NANORANGE_ALGORITHM_REPLACE_COPY_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

namespace detail {

// FIXME: Use tagged pair
struct replace_copy_fn {
private:
    template <typename I, typename S, typename O, typename T1, typename T2,
              typename Proj>
    static constexpr std::pair<I, O> impl(I first, S last, O result,
                                          const T1& old_value,
                                          const T2& new_value, Proj& proj)
    {
        // FIXME: wrong for input iters
        while (first != last) {
            if (nano::invoke(proj, *first) == old_value) {
                *result = new_value;
            } else {
                *result = *first;
            }
            ++first;
            ++result;
        }

        return {std::move(first), std::move(result)};
    }

public:
    template <typename I, typename S, typename O, typename T1, typename T2,
              typename Proj = identity>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> && OutputIterator<O, const T2&> &&
            IndirectlyCopyable<I, O> &&
            IndirectRelation<equal_to<>, projected<I, Proj>, const T1*>,
        std::pair<I, O>>
    operator()(I first, S last, O result, const T1& old_value,
               const T2& new_value, Proj proj = Proj{}) const
    {
        return replace_copy_fn::impl(std::move(first), std::move(last),
                                     std::move(result), old_value, new_value,
                                     proj);
    }

    template <typename Rng, typename O, typename T1, typename T2,
              typename Proj = identity>
    constexpr std::enable_if_t<
        InputRange<Rng> && OutputIterator<O, const T2&> &&
            IndirectlyCopyable<iterator_t<Rng>, O> &&
            IndirectRelation<equal_to<>, projected<iterator_t<Rng>, Proj>,
                             const T1*>,
        std::pair<safe_iterator_t<Rng>, O>>
    operator()(Rng&& rng, O result, const T1& old_value, const T2& new_value,
               Proj proj = Proj{}) const
    {
        return replace_copy_fn::impl(nano::begin(rng), nano::end(rng),
                                     std::move(result), old_value, new_value,
                                     proj);
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::replace_copy_fn, replace_copy)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/replace_copy_if.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_REPLACE_COPY_IF_HPP_INCLUDED
#define NANORANGE_ALGORITHM_REPLACE_COPY_IF_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

namespace detail {

// FIXME: Use tagged pair
struct replace_copy_if_fn {
private:
    template <typename I, typename S, typename O, typename Pred, typename T,
              typename Proj>
    static constexpr std::pair<I, O> impl(I first, S last, O result, Pred& pred,
                                          const T& new_value, Proj& proj)
    {
        // FIXME: wrong for input iters
        while (first != last) {
            if (nano::invoke(pred, nano::invoke(proj, *first))) {
                *result = new_value;
            } else {
                *result = *first;
            }
            ++first;
            ++result;
        }

        return {std::move(first), std::move(result)};
    }

public:
    template <typename I, typename S, typename O, typename Pred, typename T,
              typename Proj = identity>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> && OutputIterator<O, const T&> &&
            IndirectlyCopyable<I, O> &&
            IndirectUnaryPredicate<Pred, projected<I, Proj>>,
        std::pair<I, O>>
    operator()(I first, S last, O result, Pred pred, const T& new_value,
               Proj proj = Proj{}) const
    {
        return replace_copy_if_fn::impl(std::move(first), std::move(last),
                                        std::move(result), pred, new_value,
                                        proj);
    }

    template <typename Rng, typename O, typename Pred, typename T,
              typename Proj = identity>
    constexpr std::enable_if_t<
        InputRange<Rng> && OutputIterator<O, const T&> &&
            IndirectlyCopyable<iterator_t<Rng>, O> &&
            IndirectUnaryPredicate<Pred, projected<iterator_t<Rng>, Proj>>,
        std::pair<safe_iterator_t<Rng>, O>>
    operator()(Rng&& rng, O result, Pred pred, const T& new_value,
               Proj proj = Proj{}) const
    {
        return replace_copy_if_fn::impl(nano::begin(rng), nano::end(rng),
                                        std::move(result), pred, new_value,
                                        proj);
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::replace_copy_if_fn, replace_copy_if)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/replace_if.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_REPLACE_IF_HPP_INCLUDED
#define NANORANGE_ALGORITHM_REPLACE_IF_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

namespace detail {

struct replace_if_fn {
private:
    template <typename I, typename S, typename Pred, typename T, typename Proj>
    static constexpr I impl(I first, S last, Pred& pred, const T& new_value,
                            Proj& proj)
    {
        while (first != last) {
            if (nano::invoke(pred, nano::invoke(proj, *first))) {
                *first = new_value;
            }
            ++first;
        }

        return std::move(first);
    }

public:
    template <typename I, typename S, typename T, typename Pred,
              typename Proj = identity>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> && Writable<I, const T&> &&
            IndirectUnaryPredicate<Pred, projected<I, Proj>>,
        I>
    operator()(I first, S last, Pred pred, const T& new_value,
               Proj proj = Proj{}) const
    {
        return replace_if_fn::impl(std::move(first), std::move(last), pred,
                                   new_value, proj);
    }

    template <typename Rng, typename Pred, typename T2,
              typename Proj = identity>
    constexpr std::enable_if_t<
        InputRange<Rng> && Writable<iterator_t<Rng>, const T2&> &&
            IndirectUnaryPredicate<Pred, projected<iterator_t<Rng>, Proj>>,
        safe_iterator_t<Rng>>
    operator()(Rng&& rng, Pred pred, const T2& new_value,
               Proj proj = Proj{}) const
    {
        return replace_if_fn::impl(nano::begin(rng), nano::end(rng), pred,
                                   new_value, proj);
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::replace_if_fn, replace_if)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/search.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_SEARCH_HPP_INCLUDED
#define NANORANGE_ALGORITHM_SEARCH_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

namespace detail {

struct search_fn {
    template <typename I1, typename S1, typename I2, typename S2,
              typename Pred, typename Proj1, typename Proj2>
    static constexpr I1 impl(I1 first1, S1 last1, I2 first2, S2 last2,
                             Pred pred, Proj1 proj1, Proj2 proj2)
    {
        while (true) {
            auto it1 = first1;
            auto it2 = first2;

            while (true) {
                if (it2 == last2) {
                    return first1;
                }
                if (it1 == last1) {
                    return it1;
                }
                if (!nano::invoke(pred, nano::invoke(proj1, *it1), nano::invoke(proj2, *it2))) {
                    break;
                }
                ++it1; ++it2;
            }


            ++first1;
        }
    }

public:
    template <typename I1, typename S1, typename I2, typename S2,
              typename Pred = equal_to<>, typename Proj1 = identity,
              typename Proj2 = identity>
    constexpr std::enable_if_t<
         ForwardIterator<I1> &&
         Sentinel<S1, I1> &&
         ForwardIterator<I2> &&
         Sentinel<S2, I2> &&
         IndirectlyComparable<I1, I2, Pred, Proj1, Proj2>, I1>
    operator()(I1 first1, S1 last1, I2 first2, S2 last2,
               Pred pred = Pred{}, Proj1 proj1 = Proj1{}, Proj2 proj2 = Proj2{}) const
    {
        return search_fn::impl(std::move(first1), std::move(last1),
                               std::move(first2), std::move(last2),
                               std::move(pred), std::move(proj1),
                               std::move(proj2));
    }

    template <typename Rng1, typename Rng2,
              typename Pred = equal_to<>, typename Proj1 = identity,
              typename Proj2 = identity>
    constexpr std::enable_if_t<
            ForwardRange<Rng1> &&
            ForwardRange<Rng2> &&
            IndirectlyComparable<iterator_t<Rng1>, iterator_t<Rng2>, Pred, Proj1, Proj2>,
            safe_iterator_t<Rng1>>
    operator()(Rng1&& rng1, Rng2&& rng2, Pred pred = Pred{},
               Proj1 proj1 = Proj1{}, Proj2 proj2 = Proj2{}) const
    {
        return search_fn::impl(nano::begin(rng1), nano::end(rng1),
                               nano::begin(rng2), nano::end(rng2),
                               std::move(pred), std::move(proj1),
                               std::move(proj2));
    }
};

}

NANO_INLINE_VAR(detail::search_fn, search)

NANO_END_NAMESPACE

#endif
// nanorange/algorithm/search_n.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_SEARCH_N_HPP_INCLUDED
#define NANORANGE_ALGORITHM_SEARCH_N_HPP_INCLUDED



NANO_BEGIN_NAMESPACE


namespace detail {

struct search_n_fn {
private:
    template <typename I, typename S, typename T, typename Pred, typename Proj>
    static constexpr I impl(I first, S last, difference_type_t<I> count,
                            const T& value, Pred pred, Proj& proj)
    {
        if (count == difference_type_t<I>{0}) {
            return first;
        }

        for (; first != last; ++first) {
            if (!nano::invoke(pred, nano::invoke(proj, *first), value)) {
                continue;
            }

            I save = first;
            difference_type_t<I> running_count{1};

            while (true) {
                if (running_count++ == count) {
                    // Success
                    return save;
                }

                if (++first == last) {
                    // We have run out of elements
                    return first;
                }

                if (!nano::invoke(pred, nano::invoke(proj, *first), value)) {
                    break;
                }
            }
        }

        return first;
    }

public:
    template <typename I, typename S, typename T, typename Pred = equal_to<>,
        typename Proj = identity>
    constexpr auto operator()(I first, S last, difference_type_t<I> count,
                              const T& value, Pred pred = Pred{},
                              Proj proj = Proj{}) const
    -> std::enable_if_t<ForwardIterator<I> && Sentinel<S, I> &&
                        IndirectlyComparable<I, const T*, Pred, Proj>,
        I>
    {
        return search_n_fn::impl(std::move(first), std::move(last), count,
                                 value, pred, proj);
    }

    template <typename Rng, typename T, typename Pred = equal_to<>,
        typename Proj = identity>
    constexpr auto
    operator()(Rng&& rng, difference_type_t<iterator_t<Rng>> count,
               const T& value, Pred pred = Pred{}, Proj proj = Proj{}) const
    -> std::enable_if_t<
        ForwardRange<Rng> &&
        IndirectlyComparable<iterator_t<Rng>, const T*, Pred, Proj>,
        safe_iterator_t<Rng>>
    {
        return search_n_fn::impl(nano::begin(rng), nano::end(rng), count, value, pred,
                                 proj);
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::search_n_fn, search_n)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/swap_ranges.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_SWAP_RANGES_HPP_INCLUDED
#define NANORANGE_ALGORITHM_SWAP_RANGES_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

namespace detail {

// FIXME: Use tagged pair
struct swap_ranges_fn {
    template <typename I1, typename S1, typename I2, typename S2>
    static constexpr std::pair<I1, I2> impl4(I1 first1 ,S1 last1, I2 first2, S2 last2)
    {
        while (first1 != last1 && first2 != last2) {
            nano::iter_swap(first1, first2);
            ++first1; ++first2;
        }
        return {std::move(first1), std::move(first2)};
    }

    template <typename I1, typename S1, typename I2>
    static constexpr std::pair<I1, I2> impl3(I1 first1, S1 last1, I2 first2)
    {
        while (first1 != last1) {
            nano::iter_swap(first1, first2);
            ++first1; ++first2;
        }
        return {std::move(first1), std::move(first2)};
    }

public:
    template <typename I1, typename S1, typename I2, typename S2>
    constexpr std::enable_if_t<
        ForwardIterator<I1> &&
        Sentinel<S1, I1> &&
        ForwardIterator<I2> &&
        Sentinel<S2, I2> &&
        IndirectlySwappable<I1, I2>,
        std::pair<I1, I2>>
    operator()(I1 first1 ,S1 last1, I2 first2, S2 last2) const
    {
        return swap_ranges_fn::impl4(std::move(first1), std::move(last1),
                                     std::move(first2), std::move(last2));
    }

    template <typename I1, typename S1, typename I2>
    NANO_DEPRECATED
    constexpr std::enable_if_t<
            ForwardIterator<I1> &&
            Sentinel<S1, I1> &&
            ForwardIterator<I2> &&
            IndirectlySwappable<I1, I2>,
            std::pair<I1, I2>>
    operator()(I1 first1 ,S1 last1, I2 first2) const
    {
        return swap_ranges_fn::impl3(std::move(first1), std::move(last1),
                                     std::move(first2));
    }

    template <typename Rng1, typename Rng2>
    constexpr std::enable_if_t<
            ForwardRange<Rng1> &&
            ForwardRange<Rng2> &&
            IndirectlySwappable<iterator_t<Rng1>, iterator_t<Rng2>>,
            std::pair<safe_iterator_t<Rng1>, safe_iterator_t<Rng2>>>
    operator()(Rng1&& rng1, Rng2&& rng2) const
    {
        return swap_ranges_fn::impl4(nano::begin(rng1), nano::end(rng1),
                                     nano::begin(rng2), nano::end(rng2));
    }

    template <typename Rng1, typename I2>
    NANO_DEPRECATED
    constexpr std::enable_if_t<
            ForwardRange<Rng1> &&
            ForwardIterator<I2> &&
            IndirectlySwappable<iterator_t<Rng1>, I2>,
            std::pair<safe_iterator_t<Rng1>, I2>>
    operator()(Rng1&& rng1, I2 first2) const
    {
        return swap_ranges_fn::impl3(nano::begin(rng1), nano::end(rng1),
                                     std::move(first2));
    }
};

}

NANO_INLINE_VAR(detail::swap_ranges_fn, swap_ranges)

NANO_END_NAMESPACE

#endif

// nanorange/algorithm/transform.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_ALGORITHM_TRANSFORM_HPP_INCLUDED
#define NANORANGE_ALGORITHM_TRANSFORM_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

namespace detail {

// FIXME: Use tagged_pair
struct transform_fn {
private:
    template <typename I, typename S, typename O, typename F, typename Proj>
    static constexpr std::pair<I, O> unary_impl(I first, S last, O result,
                                                F& op, Proj& proj)
    {
        while (first != last) {
            *result = nano::invoke(op, nano::invoke(proj, *first));
            ++first;
            ++result;
        }

        return {std::move(first), std::move(result)};
    }

    template <typename I1, typename S1, typename I2, typename O, typename F,
              typename Proj1, typename Proj2>
    static constexpr std::tuple<I1, I2, O>
    binary_impl3(I1 first1, S1 last1, I2 first2, O result, F& op, Proj1& proj1,
                 Proj2& proj2)
    {
        while (first1 != last1) {
            *result = nano::invoke(op, nano::invoke(proj1, *first1),
                                   nano::invoke(proj2, *first2));
            ++first1;
            ++first2;
            ++result;
        }

        return {std::move(first1), std::move(first2), std::move(result)};
    }

    template <typename I1, typename S1, typename I2, typename S2, typename O,
              typename F, typename Proj1, typename Proj2>
    static constexpr std::tuple<I1, I2, O>
    binary_impl4(I1 first1, S1 last1, I2 first2, S2 last2, O result, F& op,
                 Proj1& proj1, Proj2& proj2)
    {
        while (first1 != last1 && first2 != last2) {
            *result = nano::invoke(op, nano::invoke(proj1, *first1),
                                   nano::invoke(proj2, *first2));
            ++first1;
            ++first2;
            ++result;
        }

        return {std::move(first1), std::move(first2), std::move(result)};
    }

public:
    // Unary op, iterators
    template <typename I, typename S, typename O, typename F,
              typename Proj = identity>
    constexpr std::enable_if_t<
        InputIterator<I> && Sentinel<S, I> && WeaklyIncrementable<O> &&
            CopyConstructible<F> &&
            Writable<O, indirect_result_t<F&, projected<I, Proj>>>,
        std::pair<I, O>>
    operator()(I first, S last, O result, F op, Proj proj = Proj{}) const
    {
        return transform_fn::unary_impl(std::move(first), std::move(last),
                                        std::move(result), op, proj);
    }

    // Unary op, range
    template <typename Rng, typename O, typename F, typename Proj = identity>
    constexpr std::enable_if_t<
        InputRange<Rng> && WeaklyIncrementable<O> && CopyConstructible<F> &&
            Writable<O,
                     indirect_result_t<F&, projected<iterator_t<Rng>, Proj>>>,
        std::pair<safe_iterator_t<Rng>, O>>
    operator()(Rng&& rng, O result, F op, Proj proj = Proj{}) const
    {
        return transform_fn::unary_impl(nano::begin(rng), nano::end(rng),
                                        std::move(result), op, proj);
    }

    // Binary op, four-legged
    template <typename I1, typename S1, typename I2, typename S2, typename O,
              typename F, typename Proj1 = identity, typename Proj2 = identity>
    constexpr std::enable_if_t<
        InputIterator<I1> && Sentinel<S1, I1> && InputIterator<I2> &&
            Sentinel<S2, I2> && WeaklyIncrementable<O> &&
            CopyConstructible<F> &&
            Writable<O, indirect_result_t<F&, projected<I1, Proj1>,
                                          projected<I2, Proj2>>>,
        std::tuple<I1, I2, O>>
    operator()(I1 first1, S1 last1, I2 first2, S2 last2, O result, F op,
               Proj1 proj1 = Proj1{}, Proj2 proj2 = Proj2{}) const
    {
        return transform_fn::binary_impl4(std::move(first1), std::move(last1),
                                          std::move(first2), std::move(last2),
                                          std::move(result), op, proj1, proj2);
    }

    // Binary op, two ranges
    template <typename Rng1, typename Rng2, typename O, typename F,
              typename Proj1 = identity, typename Proj2 = identity>
    constexpr std::enable_if_t<
        InputRange<Rng1> && InputRange<Rng2> && WeaklyIncrementable<O> &&
            CopyConstructible<F> &&
            Writable<O,
                     indirect_result_t<F&, projected<iterator_t<Rng1>, Proj1>,
                                       projected<iterator_t<Rng2>, Proj2>>>,
        std::tuple<safe_iterator_t<Rng1>, safe_iterator_t<Rng2>, O>>
    operator()(Rng1&& rng1, Rng2&& rng2, O result, F op, Proj1 proj1 = Proj1{},
               Proj2 proj2 = Proj2{}) const
    {
        return transform_fn::binary_impl4(nano::begin(rng1), nano::end(rng1),
                                          nano::begin(rng2), nano::end(rng2),
                                          std::move(result), op, proj1, proj2);
    }

    // Binary op, three-legged
    template <typename I1, typename S1, typename I2, typename O, typename F,
              typename Proj1 = identity, typename Proj2 = identity>
    NANO_DEPRECATED constexpr std::enable_if_t<
        InputIterator<I1> && Sentinel<S1, I1> && InputIterator<I2> &&
            WeaklyIncrementable<O> && CopyConstructible<F> &&
            Writable<O, indirect_result_t<F&, projected<I1, Proj1>,
                                          projected<I2, Proj2>>>,
        std::tuple<I1, I2, O>>
    operator()(I1 first1, S1 last1, I2 first2, O result, F op,
               Proj1 proj1 = Proj1{}, Proj2 proj2 = Proj2{}) const
    {
        return transform_fn::binary_impl3(std::move(first1), std::move(last1),
                                          std::move(first2), std::move(result),
                                          op, proj1, proj2);
    }

    // binary op, range-and-a-half
    template <typename Rng1, typename I2, typename O, typename F,
              typename Proj1 = identity, typename Proj2 = identity>
    NANO_DEPRECATED constexpr std::enable_if_t<
        InputRange<Rng1> && InputIterator<I2> && WeaklyIncrementable<O> &&
            CopyConstructible<F> &&
            Writable<O,
                     indirect_result_t<F&, projected<iterator_t<Rng1>, Proj1>,
                                       projected<I2, Proj2>>>,
        std::tuple<safe_iterator_t<Rng1>, I2, O>>
    operator()(Rng1&& rng1, I2 first2, O result, F op, Proj1 proj1 = Proj1{},
               Proj2 proj2 = Proj2{}) const
    {
        return transform_fn::binary_impl3(nano::begin(rng1), nano::end(rng1),
                                          std::move(first2), std::move(result),
                                          op, proj1, proj2);
    }
};

} // namespace detail

NANO_INLINE_VAR(detail::transform_fn, transform)

NANO_END_NAMESPACE

#endif


// Algorithms which reuse the STL implementation
// nanorange/detail/algorithm/stl/find_end.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_DETAIL_ALGORITHM_STL_FIND_END_HPP_INCLUDED
#define NANORANGE_DETAIL_ALGORITHM_STL_FIND_END_HPP_INCLUDED



#include <algorithm>

NANO_BEGIN_NAMESPACE

// [ranges.alg.find.end]

template <typename I1, typename I2, typename Pred = equal_to<>>
std::enable_if_t<ForwardIterator<I1> && ForwardIterator<I2> &&
                 detail::Cpp98Iterator<I1> &&
                 detail::Cpp98Iterator<I2> &&
                 IndirectRelation<Pred, I2, I1>,
                 I1>
find_end(I1 first1, I1 last1, I2 first2, I2 last2, Pred pred = Pred{})
{
    return std::find_end(std::move(first1), std::move(last1), std::move(first2),
                         std::move(last2), std::move(pred));
}

template <typename Rng1, typename Rng2, typename Pred = equal_to<>>
std::enable_if_t<ForwardRange<Rng1> && ForwardRange<Rng2> &&
                 CommonRange<Rng1> && CommonRange<Rng2> &&
                 detail::Cpp98Iterator<iterator_t<Rng1>> &&
                 detail::Cpp98Iterator<iterator_t<Rng2>> &&
                 IndirectRelation<Pred, iterator_t<Rng2>, iterator_t<Rng1>>,
                 safe_iterator_t<Rng1>>
find_end(Rng1&& rng1, Rng2&& rng2, Pred pred = Pred{})
{
    return std::find_end(nano::begin(rng1), nano::end(rng1), nano::begin(rng2),
                         nano::end(rng2), std::move(pred));
}

NANO_END_NAMESPACE

#endif


#endif

// nanorange/concepts.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_CONCEPTS_HPP_INCLUDED
#define NANORANGE_CONCEPTS_HPP_INCLUDED






#endif



// nanorange/random.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_RANDOM_HPP_INCLUDED
#define NANORANGE_RANDOM_HPP_INCLUDED



NANO_BEGIN_NAMESPACE

//  [rand.req.urng]

namespace detail {

struct UniformRandomBitGenerator_req {
    template <typename G>
    auto requires_() -> decltype(valid_expr(
        G::min(),
        requires_expr<Same<decltype(G::min()), invoke_result_t<G&>>>{},
        G::max(),
        requires_expr<Same<decltype(G::max()), invoke_result_t<G&>>>{}));
};

} // namespace detail

template <typename G>
NANO_CONCEPT UniformRandomBitGenerator =
    Invocable<G&>&& UnsignedIntegral<detail::checked_invoke_result_t<G&>>&&
        detail::requires_<detail::UniformRandomBitGenerator_req, G>;

NANO_END_NAMESPACE

#endif



// nanorange/utility.hpp
//
// Copyright (c) 2018 Tristan Brindle (tcbrindle at gmail dot com)
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef NANORANGE_UTILITY_HPP_INCLUDED
#define NANORANGE_UTILITY_HPP_INCLUDED



// TODO: Add tagged tuple machinery here once we've written it

#endif


#endif // NANORANGE_HPP_INCLUDED
