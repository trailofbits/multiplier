
// This tests the __API_AVAILABLE macro on MacOS.


#if defined(__has_feature) && defined(__has_attribute)
 #if __has_attribute(availability)


    #define __API_AVAILABLE_PLATFORM_macos(x) macos,introduced=x
    #define __API_AVAILABLE_PLATFORM_macosx(x) macosx,introduced=x
    #define __API_AVAILABLE_PLATFORM_ios(x) ios,introduced=x
    #define __API_AVAILABLE_PLATFORM_watchos(x) watchos,introduced=x
    #define __API_AVAILABLE_PLATFORM_tvos(x) tvos,introduced=x

    #define __API_AVAILABLE_PLATFORM_macCatalyst(x) macCatalyst,introduced=x
    #define __API_AVAILABLE_PLATFORM_macCatalyst(x) macCatalyst,introduced=x
    #ifndef __API_AVAILABLE_PLATFORM_uikitformac
     #define __API_AVAILABLE_PLATFORM_uikitformac(x) uikitformac,introduced=x
    #endif
    #define __API_AVAILABLE_PLATFORM_driverkit(x) driverkit,introduced=x


    #if defined(__has_attribute)
      #if __has_attribute(availability)
        #define __API_A(x) __attribute__((availability(__API_AVAILABLE_PLATFORM_##x)))
      #else
        #define __API_A(x)
      #endif
    #else
        #define __API_A(x)
    #endif

    #define __API_AVAILABLE1(x) __API_A(x)
    #define __API_AVAILABLE2(x,y) __API_A(x) __API_A(y)
    #define __API_AVAILABLE3(x,y,z)  __API_A(x) __API_A(y) __API_A(z)
    #define __API_AVAILABLE4(x,y,z,t) __API_A(x) __API_A(y) __API_A(z) __API_A(t)
    #define __API_AVAILABLE5(x,y,z,t,b) __API_A(x) __API_A(y) __API_A(z) __API_A(t) __API_A(b)
    #define __API_AVAILABLE6(x,y,z,t,b,m) __API_A(x) __API_A(y) __API_A(z) __API_A(t) __API_A(b) __API_A(m)
    #define __API_AVAILABLE7(x,y,z,t,b,m,d) __API_A(x) __API_A(y) __API_A(z) __API_A(t) __API_A(b) __API_A(m) __API_A(d)
    #define __API_AVAILABLE8(x,y,z,t,b,m,d,l) __API_A(x) __API_A(y) __API_A(z) __API_A(t) __API_A(b) __API_A(m) __API_A(d) __API_A(l)
    #define __API_AVAILABLE_GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME

    #define __API_APPLY_TO any(record, enum, enum_constant, function, objc_method, objc_category, objc_protocol, objc_interface, objc_property, type_alias, variable, field)
    #define __API_RANGE_STRINGIFY(x) __API_RANGE_STRINGIFY2(x)
    #define __API_RANGE_STRINGIFY2(x) #x

    #define __API_A_BEGIN(x) _Pragma(__API_RANGE_STRINGIFY (clang attribute (__attribute__((availability(__API_AVAILABLE_PLATFORM_##x))), apply_to = __API_APPLY_TO)))

    #define __API_AVAILABLE_BEGIN1(a) __API_A_BEGIN(a)
    #define __API_AVAILABLE_BEGIN2(a,b) __API_A_BEGIN(a) __API_A_BEGIN(b)
    #define __API_AVAILABLE_BEGIN3(a,b,c) __API_A_BEGIN(a) __API_A_BEGIN(b) __API_A_BEGIN(c)
    #define __API_AVAILABLE_BEGIN4(a,b,c,d) __API_A_BEGIN(a) __API_A_BEGIN(b) __API_A_BEGIN(c) __API_A_BEGIN(d)
    #define __API_AVAILABLE_BEGIN5(a,b,c,d,e) __API_A_BEGIN(a) __API_A_BEGIN(b) __API_A_BEGIN(c) __API_A_BEGIN(d) __API_A_BEGIN(e)
    #define __API_AVAILABLE_BEGIN6(a,b,c,d,e,f) __API_A_BEGIN(a) __API_A_BEGIN(b) __API_A_BEGIN(c) __API_A_BEGIN(d) __API_A_BEGIN(e) __API_A_BEGIN(f)
    #define __API_AVAILABLE_BEGIN7(a,b,c,d,e,f,g) __API_A_BEGIN(a) __API_A_BEGIN(b) __API_A_BEGIN(c) __API_A_BEGIN(d) __API_A_BEGIN(e) __API_A_BEGIN(f) __API_A_BEGIN(g)
    #define __API_AVAILABLE_BEGIN8(a,b,c,d,e,f,g,h) __API_A_BEGIN(a) __API_A_BEGIN(b) __API_A_BEGIN(c) __API_A_BEGIN(d) __API_A_BEGIN(e) __API_A_BEGIN(f) __API_A_BEGIN(g) __API_A_BEGIN(h)
    #define __API_AVAILABLE_BEGIN_GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME


    #define __API_DEPRECATED_PLATFORM_macos(x,y) macos,introduced=x,deprecated=y
    #define __API_DEPRECATED_PLATFORM_macosx(x,y) macosx,introduced=x,deprecated=y
    #define __API_DEPRECATED_PLATFORM_ios(x,y) ios,introduced=x,deprecated=y
    #define __API_DEPRECATED_PLATFORM_watchos(x,y) watchos,introduced=x,deprecated=y
    #define __API_DEPRECATED_PLATFORM_tvos(x,y) tvos,introduced=x,deprecated=y

    #define __API_DEPRECATED_PLATFORM_macCatalyst(x,y) macCatalyst,introduced=x,deprecated=y
    #define __API_DEPRECATED_PLATFORM_macCatalyst(x,y) macCatalyst,introduced=x,deprecated=y
    #ifndef __API_DEPRECATED_PLATFORM_uikitformac
     #define __API_DEPRECATED_PLATFORM_uikitformac(x) uikitformac,introduced=x,deprecated=y
    #endif
    #define __API_DEPRECATED_PLATFORM_driverkit(x,y) driverkit,introduced=x,deprecated=y


    #if defined(__has_attribute)
      #if __has_attribute(availability)
        #define __API_D(msg,x) __attribute__((availability(__API_DEPRECATED_PLATFORM_##x,message=msg)))
      #else
        #define __API_D(msg,x)
      #endif
    #else
        #define __API_D(msg,x)
    #endif

    #define __API_DEPRECATED_MSG2(msg,x) __API_D(msg,x)
    #define __API_DEPRECATED_MSG3(msg,x,y) __API_D(msg,x) __API_D(msg,y)
    #define __API_DEPRECATED_MSG4(msg,x,y,z) __API_DEPRECATED_MSG3(msg,x,y) __API_D(msg,z)
    #define __API_DEPRECATED_MSG5(msg,x,y,z,t) __API_DEPRECATED_MSG4(msg,x,y,z) __API_D(msg,t)
    #define __API_DEPRECATED_MSG6(msg,x,y,z,t,b) __API_DEPRECATED_MSG5(msg,x,y,z,t) __API_D(msg,b)
    #define __API_DEPRECATED_MSG7(msg,x,y,z,t,b,m) __API_DEPRECATED_MSG6(msg,x,y,z,t,b) __API_D(msg,m)
    #define __API_DEPRECATED_MSG8(msg,x,y,z,t,b,m,d) __API_DEPRECATED_MSG7(msg,x,y,z,t,b,m) __API_D(msg,d)
    #define __API_DEPRECATED_MSG9(msg,x,y,z,t,b,m,d,l) __API_DEPRECATED_MSG8(msg,x,y,z,t,b,m,d) __API_D(msg,l)
    #define __API_DEPRECATED_MSG_GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,NAME,...) NAME

    #define __API_D_BEGIN(msg, x) _Pragma(__API_RANGE_STRINGIFY (clang attribute (__attribute__((availability(__API_DEPRECATED_PLATFORM_##x,message=msg))), apply_to = __API_APPLY_TO)))

    #define __API_DEPRECATED_BEGIN_MSG2(msg,a) __API_D_BEGIN(msg,a)
    #define __API_DEPRECATED_BEGIN_MSG3(msg,a,b) __API_D_BEGIN(msg,a) __API_D_BEGIN(msg,b)
    #define __API_DEPRECATED_BEGIN_MSG4(msg,a,b,c) __API_D_BEGIN(msg,a) __API_D_BEGIN(msg,b) __API_D_BEGIN(msg,c)
    #define __API_DEPRECATED_BEGIN_MSG5(msg,a,b,c,d) __API_D_BEGIN(msg,a) __API_D_BEGIN(msg,b) __API_D_BEGIN(msg,c) __API_D_BEGIN(msg,d)
    #define __API_DEPRECATED_BEGIN_MSG6(msg,a,b,c,d,e) __API_D_BEGIN(msg,a) __API_D_BEGIN(msg,b) __API_D_BEGIN(msg,c) __API_D_BEGIN(msg,d) __API_D_BEGIN(msg,e)
    #define __API_DEPRECATED_BEGIN_MSG7(msg,a,b,c,d,e,f) __API_D_BEGIN(msg,a) __API_D_BEGIN(msg,b) __API_D_BEGIN(msg,c) __API_D_BEGIN(msg,d) __API_D_BEGIN(msg,e) __API_D_BEGIN(msg,f)
    #define __API_DEPRECATED_BEGIN_MSG8(msg,a,b,c,d,e,f,g) __API_D_BEGIN(msg,a) __API_D_BEGIN(msg,b) __API_D_BEGIN(msg,c) __API_D_BEGIN(msg,d) __API_D_BEGIN(msg,e) __API_D_BEGIN(msg,f) __API_D_BEGIN(msg,g)
    #define __API_DEPRECATED_BEGIN_MSG9(msg,a,b,c,d,e,f,g,h) __API_D_BEGIN(msg,a) __API_D_BEGIN(msg,b) __API_D_BEGIN(msg,c) __API_D_BEGIN(msg,d) __API_D_BEGIN(msg,e) __API_D_BEGIN(msg,f) __API_D_BEGIN(msg,g) __API_D_BEGIN(msg,h)
    #define __API_DEPRECATED_BEGIN_MSG_GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,NAME,...) NAME

    #if __has_feature(attribute_availability_with_replacement)
        #define __API_R(rep,x) __attribute__((availability(__API_DEPRECATED_PLATFORM_##x,replacement=rep)))
    #else
        #define __API_R(rep,x) __attribute__((availability(__API_DEPRECATED_PLATFORM_##x)))
    #endif

    #define __API_DEPRECATED_REP2(rep,x) __API_R(rep,x)
    #define __API_DEPRECATED_REP3(rep,x,y) __API_R(rep,x) __API_R(rep,y)
    #define __API_DEPRECATED_REP4(rep,x,y,z)  __API_DEPRECATED_REP3(rep,x,y) __API_R(rep,z)
    #define __API_DEPRECATED_REP5(rep,x,y,z,t) __API_DEPRECATED_REP4(rep,x,y,z) __API_R(rep,t)
    #define __API_DEPRECATED_REP6(rep,x,y,z,t,b) __API_DEPRECATED_REP5(rep,x,y,z,t) __API_R(rep,b)
    #define __API_DEPRECATED_REP7(rep,x,y,z,t,b,m) __API_DEPRECATED_REP6(rep,x,y,z,t,b) __API_R(rep,m)
    #define __API_DEPRECATED_REP8(rep,x,y,z,t,b,m,d) __API_DEPRECATED_REP7(rep,x,y,z,t,b,m) __API_R(rep,d)
    #define __API_DEPRECATED_REP9(rep,x,y,z,t,b,m,d,l) __API_DEPRECATED_REP8(rep,x,y,z,t,b,m,d) __API_R(rep,l)
    #define __API_DEPRECATED_REP_GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,NAME,...) NAME

    #if __has_feature(attribute_availability_with_replacement)
        #define __API_R_BEGIN(rep,x) _Pragma(__API_RANGE_STRINGIFY (clang attribute (__attribute__((availability(__API_DEPRECATED_PLATFORM_##x,replacement=rep))), apply_to = __API_APPLY_TO)))
    #else
        #define __API_R_BEGIN(rep,x) _Pragma(__API_RANGE_STRINGIFY (clang attribute (__attribute__((availability(__API_DEPRECATED_PLATFORM_##x))), apply_to = __API_APPLY_TO)))
    #endif

    #define __API_DEPRECATED_BEGIN_REP2(rep,a) __API_R_BEGIN(rep,a)
    #define __API_DEPRECATED_BEGIN_REP3(rep,a,b) __API_R_BEGIN(rep,a) __API_R_BEGIN(rep,b)
    #define __API_DEPRECATED_BEGIN_REP4(rep,a,b,c) __API_R_BEGIN(rep,a) __API_R_BEGIN(rep,b) __API_R_BEGIN(rep,c)
    #define __API_DEPRECATED_BEGIN_REP5(rep,a,b,c,d) __API_R_BEGIN(rep,a) __API_R_BEGIN(rep,b) __API_R_BEGIN(rep,c) __API_R_BEGIN(rep,d)
    #define __API_DEPRECATED_BEGIN_REP6(rep,a,b,c,d,e) __API_R_BEGIN(rep,a) __API_R_BEGIN(rep,b) __API_R_BEGIN(rep,c) __API_R_BEGIN(rep,d) __API_R_BEGIN(rep,e)
    #define __API_DEPRECATED_BEGIN_REP7(rep,a,b,c,d,e,f) __API_R_BEGIN(rep,a) __API_R_BEGIN(rep,b) __API_R_BEGIN(rep,c) __API_R_BEGIN(rep,d) __API_R_BEGIN(rep,e) __API_R_BEGIN(rep,f)
    #define __API_DEPRECATED_BEGIN_REP8(rep,a,b,c,d,e,f,g) __API_R_BEGIN(rep,a) __API_R_BEGIN(rep,b) __API_R_BEGIN(rep,c) __API_R_BEGIN(rep,d) __API_R_BEGIN(rep,e) __API_R_BEGIN(rep,f) __API_R_BEGIN(rep,g)
    #define __API_DEPRECATED_BEGIN_REP9(rep,a,b,c,d,e,f,g,h) __API_R_BEGIN(rep,a) __API_R_BEGIN(rep,b) __API_R_BEGIN(rep,c) __API_R_BEGIN(rep,d) __API_R_BEGIN(rep,e) __API_R_BEGIN(rep,f) __API_R_BEGIN(rep,g) __API_R_BEGIN(rep,h)

    #define __API_DEPRECATED_BEGIN_REP_GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,NAME,...) NAME

    /*
     * API Unavailability
     * Use to specify that an API is unavailable for a particular platform.
     *
     * Example:
     *    __API_UNAVAILABLE(macos)
     *    __API_UNAVAILABLE(watchos, tvos)
     */
    #define __API_UNAVAILABLE_PLATFORM_macos macos,unavailable
    #define __API_UNAVAILABLE_PLATFORM_macosx macosx,unavailable
    #define __API_UNAVAILABLE_PLATFORM_ios ios,unavailable
    #define __API_UNAVAILABLE_PLATFORM_watchos watchos,unavailable
    #define __API_UNAVAILABLE_PLATFORM_tvos tvos,unavailable

    #define __API_UNAVAILABLE_PLATFORM_macCatalyst macCatalyst,unavailable
    #define __API_UNAVAILABLE_PLATFORM_macCatalyst macCatalyst,unavailable
    #ifndef __API_UNAVAILABLE_PLATFORM_uikitformac
     #define __API_UNAVAILABLE_PLATFORM_uikitformac(x) uikitformac,unavailable
    #endif
    #define __API_UNAVAILABLE_PLATFORM_driverkit driverkit,unavailable


    #if defined(__has_attribute)
      #if __has_attribute(availability)
        #define __API_U(x) __attribute__((availability(__API_UNAVAILABLE_PLATFORM_##x)))
      #else
        #define __API_U(x)
      #endif
    #else
        #define __API_U(x)
    #endif

    #define __API_UNAVAILABLE1(x) __API_U(x)
    #define __API_UNAVAILABLE2(x,y) __API_U(x) __API_U(y)
    #define __API_UNAVAILABLE3(x,y,z) __API_UNAVAILABLE2(x,y) __API_U(z)
    #define __API_UNAVAILABLE4(x,y,z,t) __API_UNAVAILABLE3(x,y,z) __API_U(t)
    #define __API_UNAVAILABLE5(x,y,z,t,b) __API_UNAVAILABLE4(x,y,z,t) __API_U(b)
    #define __API_UNAVAILABLE6(x,y,z,t,b,m) __API_UNAVAILABLE5(x,y,z,t,b) __API_U(m)
    #define __API_UNAVAILABLE7(x,y,z,t,b,m,d) __API_UNAVAILABLE6(x,y,z,t,b,m) __API_U(d)
    #define __API_UNAVAILABLE8(x,y,z,t,b,m,d,l) __API_UNAVAILABLE7(x,y,z,t,b,m,d) __API_U(l)
    #define __API_UNAVAILABLE_GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME

    #define __API_U_BEGIN(x) _Pragma(__API_RANGE_STRINGIFY (clang attribute (__attribute__((availability(__API_UNAVAILABLE_PLATFORM_##x))), apply_to = __API_APPLY_TO)))

    #define __API_UNAVAILABLE_BEGIN1(a) __API_U_BEGIN(a)
    #define __API_UNAVAILABLE_BEGIN2(a,b) __API_U_BEGIN(a) __API_U_BEGIN(b)
    #define __API_UNAVAILABLE_BEGIN3(a,b,c) __API_U_BEGIN(a) __API_U_BEGIN(b) __API_U_BEGIN(c)
    #define __API_UNAVAILABLE_BEGIN4(a,b,c,d) __API_U_BEGIN(a) __API_U_BEGIN(b) __API_U_BEGIN(c) __API_U_BEGIN(d)
    #define __API_UNAVAILABLE_BEGIN5(a,b,c,d,e) __API_U_BEGIN(a) __API_U_BEGIN(b) __API_U_BEGIN(c) __API_U_BEGIN(d) __API_U_BEGIN(e)
    #define __API_UNAVAILABLE_BEGIN6(a,b,c,d,e,f) __API_U_BEGIN(a) __API_U_BEGIN(b) __API_U_BEGIN(c) __API_U_BEGIN(d) __API_U_BEGIN(e) __API_U_BEGIN(f)
    #define __API_UNAVAILABLE_BEGIN7(a,b,c,d,e,f,g) __API_U_BEGIN(a) __API_U_BEGIN(b) __API_U_BEGIN(c) __API_U_BEGIN(d) __API_U_BEGIN(e) __API_U_BEGIN(f) __API_U_BEGIN(g)
    #define __API_UNAVAILABLE_BEGIN8(a,b,c,d,e,f,g,h) __API_U_BEGIN(a) __API_U_BEGIN(b) __API_U_BEGIN(c) __API_U_BEGIN(d) __API_U_BEGIN(e) __API_U_BEGIN(f) __API_U_BEGIN(g) __API_U_BEGIN(h)
    #define __API_UNAVAILABLE_BEGIN_GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
 #else

 /*
  * Evaluate to nothing for compilers that don't support availability.
  */

  #define __API_AVAILABLE_GET_MACRO(...)
  #define __API_AVAILABLE_BEGIN_GET_MACRO(...)
  #define __API_DEPRECATED_MSG_GET_MACRO(...)
  #define __API_DEPRECATED_REP_GET_MACRO(...)
  #define __API_DEPRECATED_BEGIN_MSG_GET_MACRO(...)
  #define __API_DEPRECATED_BEGIN_REP_GET_MACRO
  #define __API_UNAVAILABLE_GET_MACRO(...)
  #define __API_UNAVAILABLE_BEGIN_GET_MACRO(...)
 #endif /* __has_attribute(availability) */
#else

    /*
     * Evaluate to nothing for compilers that don't support clang language extensions.
     */

    #define __API_AVAILABLE_GET_MACRO(...)
    #define __API_AVAILABLE_BEGIN_GET_MACRO(...)
    #define __API_DEPRECATED_MSG_GET_MACRO(...)
    #define __API_DEPRECATED_REP_GET_MACRO(...)
    #define __API_DEPRECATED_BEGIN_MSG_GET_MACRO(...)
    #define __API_DEPRECATED_BEGIN_REP_GET_MACRO
    #define __API_UNAVAILABLE_GET_MACRO(...)
    #define __API_UNAVAILABLE_BEGIN_GET_MACRO(...)
#endif /* #if defined(__has_feature) && defined(__has_attribute) */

#if defined(__has_feature) && defined(__has_attribute)
 #if __has_attribute(availability)

    /*
     * API Introductions
     *
     * Use to specify the release that a particular API became available.
     *
     * Platform names:
     *   macos, ios, tvos, watchos
     *
     * Examples:
     *    __API_AVAILABLE(macos(10.10))
     *    __API_AVAILABLE(macos(10.9), ios(10.0))
     *    __API_AVAILABLE(macos(10.4), ios(8.0), watchos(2.0), tvos(10.0))
     *    __API_AVAILABLE(driverkit(19.0))
     */
    #define __API_AVAILABLE(...) __API_AVAILABLE_GET_MACRO(__VA_ARGS__,__API_AVAILABLE8, __API_AVAILABLE7, __API_AVAILABLE6, __API_AVAILABLE5, __API_AVAILABLE4, __API_AVAILABLE3, __API_AVAILABLE2, __API_AVAILABLE1, 0)(__VA_ARGS__)

    #define __API_AVAILABLE_BEGIN(...) _Pragma("clang attribute push") __API_AVAILABLE_BEGIN_GET_MACRO(__VA_ARGS__,__API_AVAILABLE_BEGIN8, __API_AVAILABLE_BEGIN7, __API_AVAILABLE_BEGIN6, __API_AVAILABLE_BEGIN5, __API_AVAILABLE_BEGIN4, __API_AVAILABLE_BEGIN3, __API_AVAILABLE_BEGIN2, __API_AVAILABLE_BEGIN1, 0)(__VA_ARGS__)
    #define __API_AVAILABLE_END _Pragma("clang attribute pop")

    /*
     * API Deprecations
     *
     * Use to specify the release that a particular API became unavailable.
     *
     * Platform names:
     *   macos, ios, tvos, watchos
     *
     * Examples:
     *
     *    __API_DEPRECATED("No longer supported", macos(10.4, 10.8))
     *    __API_DEPRECATED("No longer supported", macos(10.4, 10.8), ios(2.0, 3.0), watchos(2.0, 3.0), tvos(9.0, 10.0))
     *
     *    __API_DEPRECATED_WITH_REPLACEMENT("-setName:", tvos(10.0, 10.4), ios(9.0, 10.0))
     *    __API_DEPRECATED_WITH_REPLACEMENT("SomeClassName", macos(10.4, 10.6), watchos(2.0, 3.0))
     */
    #define __API_DEPRECATED(...) __API_DEPRECATED_MSG_GET_MACRO(__VA_ARGS__,__API_DEPRECATED_MSG9, __API_DEPRECATED_MSG8,__API_DEPRECATED_MSG7,__API_DEPRECATED_MSG6,__API_DEPRECATED_MSG5,__API_DEPRECATED_MSG4,__API_DEPRECATED_MSG3,__API_DEPRECATED_MSG2,__API_DEPRECATED_MSG1, 0)(__VA_ARGS__)
    #define __API_DEPRECATED_WITH_REPLACEMENT(...) __API_DEPRECATED_REP_GET_MACRO(__VA_ARGS__,__API_DEPRECATED_REP9,__API_DEPRECATED_REP8,__API_DEPRECATED_REP7,__API_DEPRECATED_REP6,__API_DEPRECATED_REP5,__API_DEPRECATED_REP4,__API_DEPRECATED_REP3,__API_DEPRECATED_REP2,__API_DEPRECATED_REP1, 0)(__VA_ARGS__)

    #define __API_DEPRECATED_BEGIN(...) _Pragma("clang attribute push") __API_DEPRECATED_BEGIN_MSG_GET_MACRO(__VA_ARGS__,__API_DEPRECATED_BEGIN_MSG9, __API_DEPRECATED_BEGIN_MSG8,__API_DEPRECATED_BEGIN_MSG7, __API_DEPRECATED_BEGIN_MSG6, __API_DEPRECATED_BEGIN_MSG5, __API_DEPRECATED_BEGIN_MSG4, __API_DEPRECATED_BEGIN_MSG3, __API_DEPRECATED_BEGIN_MSG2, __API_DEPRECATED_BEGIN_MSG1, 0)(__VA_ARGS__)
    #define __API_DEPRECATED_END _Pragma("clang attribute pop")

    #define __API_DEPRECATED_WITH_REPLACEMENT_BEGIN(...) _Pragma("clang attribute push") __API_DEPRECATED_BEGIN_REP_GET_MACRO(__VA_ARGS__,__API_DEPRECATED_BEGIN_REP9, __API_DEPRECATED_BEGIN_REP8,__API_DEPRECATED_BEGIN_REP7, __API_DEPRECATED_BEGIN_REP6, __API_DEPRECATED_BEGIN_REP5, __API_DEPRECATED_BEGIN_REP4, __API_DEPRECATED_BEGIN_REP3, __API_DEPRECATED_BEGIN_REP2, __API_DEPRECATED_BEGIN_REP1, 0)(__VA_ARGS__)
    #define __API_DEPRECATED_WITH_REPLACEMENT_END _Pragma("clang attribute pop")

    /*
     * API Unavailability
     * Use to specify that an API is unavailable for a particular platform.
     *
     * Example:
     *    __API_UNAVAILABLE(macos)
     *    __API_UNAVAILABLE(watchos, tvos)
     */
    #define __API_UNAVAILABLE(...) __API_UNAVAILABLE_GET_MACRO(__VA_ARGS__,__API_UNAVAILABLE8,__API_UNAVAILABLE7,__API_UNAVAILABLE6,__API_UNAVAILABLE5,__API_UNAVAILABLE4,__API_UNAVAILABLE3,__API_UNAVAILABLE2,__API_UNAVAILABLE1, 0)(__VA_ARGS__)

    #define __API_UNAVAILABLE_BEGIN(...) _Pragma("clang attribute push") __API_UNAVAILABLE_BEGIN_GET_MACRO(__VA_ARGS__,__API_UNAVAILABLE_BEGIN8,__API_UNAVAILABLE_BEGIN7,__API_UNAVAILABLE_BEGIN6, __API_UNAVAILABLE_BEGIN5, __API_UNAVAILABLE_BEGIN4, __API_UNAVAILABLE_BEGIN3, __API_UNAVAILABLE_BEGIN2, __API_UNAVAILABLE_BEGIN1, 0)(__VA_ARGS__)
    #define __API_UNAVAILABLE_END _Pragma("clang attribute pop")
 #else

    /*
     * Evaluate to nothing for compilers that don't support availability.
     */

    #define __API_AVAILABLE(...)
    #define __API_AVAILABLE_BEGIN(...)
    #define __API_AVAILABLE_END
    #define __API_DEPRECATED(...)
    #define __API_DEPRECATED_WITH_REPLACEMENT(...)
    #define __API_DEPRECATED_BEGIN(...)
    #define __API_DEPRECATED_END
    #define __API_DEPRECATED_WITH_REPLACEMENT_BEGIN(...)
    #define __API_DEPRECATED_WITH_REPLACEMENT_END
    #define __API_UNAVAILABLE(...)
    #define __API_UNAVAILABLE_BEGIN(...)
    #define __API_UNAVAILABLE_END
 #endif /* __has_attribute(availability) */
#else

    /*
     * Evaluate to nothing for compilers that don't support clang language extensions.
     */

    #define __API_AVAILABLE(...)
    #define __API_AVAILABLE_BEGIN(...)
    #define __API_AVAILABLE_END
    #define __API_DEPRECATED(...)
    #define __API_DEPRECATED_WITH_REPLACEMENT(...)
    #define __API_DEPRECATED_BEGIN(...)
    #define __API_DEPRECATED_END
    #define __API_DEPRECATED_WITH_REPLACEMENT_BEGIN(...)
    #define __API_DEPRECATED_WITH_REPLACEMENT_END
    #define __API_UNAVAILABLE(...)
    #define __API_UNAVAILABLE_BEGIN(...)
    #define __API_UNAVAILABLE_END
#endif /*  #if defined(__has_feature) && defined(__has_attribute) */

extern int APIAvailable(void)
  __API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0), watchos(7.0));
