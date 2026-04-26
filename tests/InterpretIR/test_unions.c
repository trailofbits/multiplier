// Tests: union access, type punning, nested unions, anonymous unions,
// anonymous nested structs, struct-with-array fields, struct-with-pointer
// fields, struct-with-float fields.
//
// These types exist primarily to be indexed so that the MemoryView Python
// class can be tested against real multiplier types.

// --- Unions ---

union IntFloat {
    int i;
    float f;
};

union Multi {
    char c;
    short s;
    int i;
    long long ll;
};

// --- Anonymous nested struct/union ---

struct HasAnonymousUnion {
    int tag;
    union {
        int as_int;
        float as_float;
        char as_bytes[4];
    };
};

struct HasAnonymousStruct {
    int header;
    struct {
        int a;
        int b;
    };
    int footer;
};

struct DoubleAnonymous {
    union {
        int x;
        float fx;
    };
    union {
        int y;
        float fy;
    };
};

// --- Structs with array fields ---

struct WithArray {
    int tag;
    int data[4];
    int checksum;
};

struct Matrix2x2 {
    int m[2][2];
};

// --- Structs with pointer fields ---

struct LinkedNode {
    int value;
    struct LinkedNode *next;
};

struct TwoPointers {
    int *a;
    int *b;
};

// --- Structs with float fields ---

struct Vec3f {
    float x;
    float y;
    float z;
};

struct MixedTypes {
    int id;
    float score;
    double precise;
    char label;
};

// --- Helpers for interpreter tests ---

int read_union_int(union IntFloat u) { return u.i; }
float read_union_float(union IntFloat u) { return u.f; }

int sum_anon_union_int(struct HasAnonymousUnion h) {
    return h.tag + h.as_int;
}

int sum_anon_struct(struct HasAnonymousStruct h) {
    return h.header + h.a + h.b + h.footer;
}

int sum_with_array(struct WithArray w) {
    int s = w.tag + w.checksum;
    for (int i = 0; i < 4; i++) s += w.data[i];
    return s;
}

float dot3f(struct Vec3f a, struct Vec3f b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

int test_unions(void) {
    // 1. Basic union write/read
    union IntFloat uf;
    uf.i = 42;
    if (uf.i != 42) return 1;

    // 2. Multi-size union
    union Multi m;
    m.i = 0x12345678;
    // Reading smaller member gives low bytes (little-endian)
    if (m.c != 0x78) return 2;
    if (m.s != 0x5678) return 3;

    // 3. Anonymous union in struct
    struct HasAnonymousUnion h;
    h.tag = 1;
    h.as_int = 100;
    if (h.tag != 1) return 4;
    if (h.as_int != 100) return 5;

    // 4. Anonymous struct in struct
    struct HasAnonymousStruct hs;
    hs.header = 10;
    hs.a = 20;
    hs.b = 30;
    hs.footer = 40;
    if (hs.header != 10) return 6;
    if (hs.a != 20) return 7;
    if (hs.b != 30) return 8;
    if (hs.footer != 40) return 9;
    if (sum_anon_struct(hs) != 100) return 10;

    // 5. Double anonymous union
    struct DoubleAnonymous da;
    da.x = 1;
    da.y = 2;
    if (da.x != 1) return 11;
    if (da.y != 2) return 12;

    // 6. Struct with array field
    struct WithArray wa;
    wa.tag = 1;
    wa.data[0] = 10;
    wa.data[1] = 20;
    wa.data[2] = 30;
    wa.data[3] = 40;
    wa.checksum = 99;
    if (wa.data[2] != 30) return 13;
    if (sum_with_array(wa) != 200) return 14;

    // 7. Float struct
    struct Vec3f v;
    v.x = 1.0f;
    v.y = 2.0f;
    v.z = 3.0f;
    if (v.x != 1.0f) return 15;
    if (v.y != 2.0f) return 16;

    // 8. Mixed types struct
    struct MixedTypes mt;
    mt.id = 42;
    mt.score = 3.14f;
    mt.label = 'A';
    if (mt.id != 42) return 17;
    if (mt.label != 'A') return 18;

    return 0;
}
