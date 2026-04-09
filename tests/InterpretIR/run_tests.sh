#!/bin/bash
# Run all IR interpreter tests against an indexed database.
# Usage: ./run_tests.sh /path/to/tests.db [/path/to/mx-interpret-ir]

DB="${1:?Usage: $0 <db_path> [mx-interpret-ir_path]}"
INTERP="${2:-mx-interpret-ir}"

PASS=0
FAIL=0
SKIP=0
ERRORS=""

# All test_* functions return 0 on success, nonzero (error code) on failure.
TEST_FUNCS=(
  test_arithmetic
  test_bitfields
  test_casts
  test_compound_assign
  test_control_flow
  test_function_calls
  test_globals
  test_goto
  test_init_lists
  test_memory_ops
  test_pointers
  test_scopes
  test_sizeof_alignof
  test_switch
  test_array_decay
  test_struct_assign
  test_string_literals
  test_variadics
  test_dynamic_alloca
  test_byvalue
  test_evil_goto
  test_conditional_exec
  test_unsigned
)

for func in "${TEST_FUNCS[@]}"; do
  output=$("$INTERP" --db "$DB" --entity_name "$func" 2>&1)
  exit_code=$?

  # Look for the return value in the output.
  ret_val=$(echo "$output" | grep -oP 'Return value: \K[-0-9]+' | tail -1)

  if [ $exit_code -ne 0 ]; then
    echo "CRASH  $func (exit code $exit_code)"
    ERRORS="$ERRORS\n  $func: crashed (exit $exit_code)"
    FAIL=$((FAIL + 1))
  elif [ -z "$ret_val" ]; then
    echo "SKIP   $func (no return value found)"
    SKIP=$((SKIP + 1))
  elif [ "$ret_val" = "0" ]; then
    echo "PASS   $func"
    PASS=$((PASS + 1))
  else
    echo "FAIL   $func (returned $ret_val)"
    ERRORS="$ERRORS\n  $func: returned $ret_val"
    FAIL=$((FAIL + 1))
  fi
done

echo ""
echo "Results: $PASS passed, $FAIL failed, $SKIP skipped"
if [ -n "$ERRORS" ]; then
  echo -e "Failures:$ERRORS"
fi

exit $FAIL
