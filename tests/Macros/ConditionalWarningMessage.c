
void ConditionalWarningMessage() {
#if 1
#warning "oh nooo"
#endif

#if 0
#else
#warning "oh nooo again"
#endif
}
