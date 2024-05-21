namespace ArgumentPack {

namespace std {
    template<typename T>
    struct declval {};

    template<typename T>
    struct remove_reference {
        using type = T;
    };

    template<typename T>
    struct remove_reference<T&> {
        using type = T;
    };

    template<typename T>
    struct remove_reference<T&&> {
        using type = T;
    };

    template<typename T>
    constexpr T&& forward(typename std::remove_reference<T>::type& t) noexcept {
        return static_cast<T&&>(t);
    }

    template<typename T>
    constexpr T&& forward(typename std::remove_reference<T>::type&& t) noexcept {
        return static_cast<T&&>(t);
    }

    struct random_access_iterator_tag {};

    template<typename T1, typename T2>
    struct is_base_of_v {};

    template<typename T1>
    struct iterator_traits {
        using iterator_category = T1;
    };

    template<typename T>
    using remove_reference_t = typename remove_reference<T>::type;

    template <bool B, typename T = void>
    struct enable_if {
        using type = T;
    };

    template <typename T>
    struct enable_if<true, T> {
        using type = T;
    };

   template<typename T1, typename T2>
    struct is_convertible_v {
        static constexpr bool value = true;
    };

    template<typename T1, typename T2>
    struct convertible_to {
        static constexpr bool value = is_convertible_v<T1, T2>::value;
    };

    template<typename T>
    constexpr typename std::remove_reference<T>::type&& move(T&& t) noexcept {
        return static_cast<typename std::remove_reference<T>::type&&>(t);
    }

    struct nullopt_t {
        explicit constexpr nullopt_t(int) noexcept {}
    };

    constexpr nullopt_t nullopt{0};
}

template< typename result_type, typename bind_type >
struct compose_state_t {
    compose_state_t(bind_type &&binder) : binder(std::forward< bind_type >(binder)) {}

    template< typename arg_t >
    static constexpr bool valid(const arg_t &arg) {
        if constexpr (std::convertible_to< arg_t , bool >::value) {
            return static_cast< bool >(arg);
        } else {
            // initialized non-boolean arg is always valid
            return true;
        }
    }

    template< typename ...args_t >
    static constexpr bool valid(const args_t &...args) { return (valid(args) && ...); }

    template< typename... Args >
    constexpr inline auto bind(Args &&...args) && {
        auto binded = [... args = std::forward< Args >(args), binder = std::move(binder)] (auto &&...rest) {
            if (!valid(args...)) {
                return result_type{};
            }
            return binder(args..., std::forward< decltype(rest) >(rest)...);
        };
        return compose_state_t< result_type, decltype(binded) >(std::move(binded));
    }

    template< typename arg_t >
    constexpr inline auto bind_if(bool cond, arg_t &&arg) && {
        auto binded = [cond, arg = std::forward< arg_t >(arg), binder = std::move(binder)] (auto &&...args) {
            if (cond) {
                if (!valid(arg)) {
                    return result_type{};
                }

                return binder(arg, std::forward< decltype(args) >(args)...);
            }

            return binder(std::forward< decltype(args) >(args)...);
        };
        return compose_state_t< result_type, decltype(binded) >(std::move(binded));
    }

    template< typename arg_t >
    constexpr inline auto bind_region_if(bool cond, arg_t &&arg) && {
        auto binded = [cond, arg = std::forward< arg_t >(arg), binder = std::move(binder)] (auto &&...args) {
            if (cond) {
                if (!valid(arg)) {
                    return result_type{};
                }
                return binder(arg, std::forward< decltype(args) >(args)...);
            }
            return binder(std::nullopt, std::forward< decltype(args) >(args)...);
        };
        return compose_state_t< result_type, decltype(binded) >(std::move(binded));
    }

    auto freeze() { return binder(); }

    bind_type binder;
};


}
