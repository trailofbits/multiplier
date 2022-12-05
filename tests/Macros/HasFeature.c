
// This test checks that we properly handle `__has_feature`.

void HasFeature(void) {
#if __has_feature(attribute_availability_with_message)
#endif
}
