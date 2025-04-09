#!/bin/bash

PROGRAM="./RPN"
LOGFILE="test.log"

# Test cases: ("input" "expected_output")
tests=(
    # --- Invalid Inputs ---
    "(1 + 1)"                        "Error"
    "a b +"                          "Error"
    "10 2 +"                         "Error"
    "42"                             "Error"

    # --- Syntax Errors / Stack Issues ---
    "1 +"                            "Error"
    "1 2"                            "Error"
    ""                               "Error"

    # --- Division by Zero ---
    "5 0 /"                          "Error"

    # --- Valid Short Calculations ---
    "1 1 +"                          "2"
    "4 2 +"                          "6"
    "9 3 /"                          "3"
    "8"                              "8"

    # --- Valid Medium Calculations ---
    "2 3 + 5 *"                      "25"
    "3 4 + 2 5 * -"                  "-3"
    "9 3 / 2 * 3 +"                  "9"
    "6 2 * 3 /"                      "4"
    "2 3 4 + *"                      "14"
    "1 2 * 2 / 2 * 2 4 - +"          "0"
    "3 3 * 2 2 * +"                  "13"

    # --- More Valid Medium/Complex ---
    "5 1 2 + 4 * + 3 -"              "14"
    "7 7 * 7 -"                      "42"
    "8 9 * 9 - 9 - 9 - 4 - 1 +"      "42"

    # --- Long Calculations with High Results ---
    "9 9 * 8 8 * + 7 7 * + 6 6 * +"  "230"
    "9 9 9 * * 8 8 * + 7 +"          "800"
    "9 9 + 8 + 7 + 6 + 5 + 4 + 3 +"  "51"

	 # --- Valid Large Calculations ---
    "9 9 * 9 * 9 * 9 * 9 *"             "531441"
    "7 7 * 7 * 7 * 7 * 7 * 7 *"         "823543"

    # --- INT32 Overflow / Underflow ---
    "8 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 2 *"         "Error"
    "8 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 *"         "Error"
    "1 2 - 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 *" "Error"
)

# Start log
echo "RPN Program Test Log" > "$LOGFILE"
echo "====================" >> "$LOGFILE"
echo "" >> "$LOGFILE"

pass=0
total=$((${#tests[@]} / 2))

for ((i = 0; i < ${#tests[@]}; i+=2)); do
    input="${tests[i]}"
    expected_output="${tests[i+1]}"

    actual_output=$($PROGRAM "$input" 2>&1)
    actual_output=$(echo "$actual_output" | tr -d '\r')

    if [ "$actual_output" == "$expected_output" ]; then
        result="✅ PASS"
        ((pass++))
    else
        result="❌ FAIL"
    fi

    # Terminal output
    echo "Test $((i / 2 + 1)): $result"

    # Log file output
    {
        echo "Test $((i / 2 + 1)):"
        echo "Input:            \"$input\""
        echo "Expected Output:  \"$expected_output\""
        echo "Actual Output:    \"$actual_output\""
        echo "Result:           $result"
        echo "----------------------------"
    } >> "$LOGFILE"
done

{
    echo ""
    echo "Test Summary:"
    echo "Passed: $pass / $total"
} >> "$LOGFILE"

echo ""
echo "🎯 Test Summary: $pass / $total passed."
echo "📄 Full results saved to $LOGFILE."
