#!/bin/bash

LOGFILE="pmerge_run.log"
> "$LOGFILE"  # Clear the logfile

args=()
for i in {0..100}; do
    args+=("$i")
    echo "Running: ./PmergeMe ${args[*]}" >> "$LOGFILE"
    
    # Log number of arguments
    echo "Argument count: ${#args[@]}" >> "$LOGFILE"

    output=$(./PmergeMe "${args[@]}" 2>&1)
    status=$?

    if [ $status -eq 139 ]; then  # Segmentation fault
        size_line=$(echo "$output" | grep '^Size' | tail -n 1)
        iter_line=$(echo "$output" | grep '^Iteration' | tail -n 1)
        
        echo "❌ Segfault (exit 139)" >> "$LOGFILE"
        [ -n "$size_line" ] && echo "$size_line" >> "$LOGFILE"
        [ -n "$iter_line" ] && echo "$iter_line" >> "$LOGFILE"
    else
        echo "✅ Exit status: $status" >> "$LOGFILE"
    fi

    echo "-----------------------------" >> "$LOGFILE"
done
