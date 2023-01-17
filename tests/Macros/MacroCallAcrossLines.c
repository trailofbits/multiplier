
void MacroCallAcrossLines() {
#define FUNC_MACRO(a1, a2, a3)
FUNC_MACRO( \
           __LINE__ \
           ,
           __COUNTER__ \
           /*
            * / * / *** , )
            */ \
            ,
            __FILE__ /*

            */      )
}
