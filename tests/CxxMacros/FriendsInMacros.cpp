namespace FriendsInMacros {

class A;
class B;

class ClassWithFriends {

#define MAKE_FRIEND(c) \
    friend class c

#define MAKE_ALL(m) \
    m(A); \
    m(b)

  MAKE_ALL(MAKE_FRIEND);
};

}