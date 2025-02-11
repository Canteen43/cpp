#!/bin/bash

# Log file
LOG_FILE="tester.log"
> "$LOG_FILE"  # Clear log file before starting

# Test cases: ("input text" "string to replace" "replacement" "expected output")
tests=(
    "hello world" "world" "everyone" "hello everyone"
    "aaa bbb ccc" "bbb" "ddd" "aaa ddd ccc"
    "replace this word" "word" "sentence" "replace this sentence"
    "nothing to change" "xyz" "abc" "nothing to change"
    "123 456 123" "123" "789" "789 456 789"
    "a a a a" "a" "b" "b b b b"
    "case sensitive" "Case" "test" "case sensitive"
    "one two three two one" "two" "four" "one four three four one"
    "remove all a" "a" "" "remove ll "
    "123abc456" "abc" "XYZ" "123XYZ456"
    "Hello, Bob!" "Bob" "Alice" "Hello, Alice!"
    "Repeat repeat repeat" "repeat" "once" "Repeat once once"
    "Mix numbers 987 654" "987" "000" "Mix numbers 000 654"
    "A B C D E F" "C D" "X Y" "A B X Y E F"
    "Escape characters: $HOME" "$HOME" "[HOME]" "Escape characters: [HOME]"
    "Special chars !@#$%^&*()" "!@#" "XYZ" "Special chars XYZ$%^&*()"
    "foo foo foo" "foo" "bar" "bar bar bar"
    "Trailing spaces  " "spaces" "lines" "Trailing lines  "
    "double double" "double" "single" "single single"
)

# Run tests
for ((i = 0; i < ${#tests[@]}; i+=4)); do
    input_text="${tests[i]}"
    search="${tests[i+1]}"
    replacement="${tests[i+2]}"
    expected_output="${tests[i+3]}"

    # Create infile.txt with test string
    echo -e "$input_text" > infile.txt

    # Run the program
    ./winner_sed infile.txt "$search" "$replacement"
    
    # Read output file
    if [[ -f "infile.txt.replace" ]]; then
        output=$(cat infile.txt.replace)
    else
        output="[MISSING OUTPUT FILE]"
    fi
    
    # Log the result
    echo "Test $((i/4+1)): Replacing '$search' with '$replacement' in '$input_text'" >> "$LOG_FILE"
    echo "Expected: '$expected_output'" >> "$LOG_FILE"
    echo "Got:      '$output'" >> "$LOG_FILE"
    
    if [[ "$output" == "$expected_output" ]]; then
        echo "✅ Test passed" >> "$LOG_FILE"
    else
        echo "❌ Test failed" >> "$LOG_FILE"
    fi
    echo "-------------------------" >> "$LOG_FILE"
    
    # Cleanup output file
    rm -f infile.txt.replace

done

# Cleanup
rm -f infile.txt

echo "Tests complete. Check log.txt for results."