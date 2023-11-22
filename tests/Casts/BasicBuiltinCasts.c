void TestImplicitIntCharConversion() {
    int intValue = 65;
    char charValue = intValue;
}

void TestImplicitIntFloatConversion() {
    int intValue = 7;
    float floatValue = intValue;
}

void TestExplicitIntCharCast() {
    int intValue = 65;
    char charValue = (char)intValue;
}

void TestExplicitIntFloatCast() {
    int intValue = 7;
    float floatValue = (float)intValue;
}

void TestExplicitFloatIntCast() {
    float floatValue = 7.99;
    int intValue = (int)floatValue;
}