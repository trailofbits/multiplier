
void ConditionalPragmaMark() {
#if 1
#pragma mark "hrmm 1"
#endif

#if 0
#else
#pragma mark "hrmm 2"
#endif
}
