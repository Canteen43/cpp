#!/bin/bash

LOGFILE="pmerge_run.log"
> "$LOGFILE"  # Clear the logfile

args=()
for i in {31..0}; do
    args+=("$i")
    echo "Running: ./PmergeMe ${args[*]}" >> "$LOGFILE"
    
    # Log number of arguments
    echo "Argument count: ${#args[@]}" >> "$LOGFILE"

    output=$(./PmergeMe "${args[@]}" 2>&1)
    status=$?

    if [ $status -ne 0 ]; then  # Segmentation fault
        
        echo "❌ Exit status: $status" >> "$LOGFILE"
    else
        echo "✅ Exit status: $status" >> "$LOGFILE"
    fi

    echo "-----------------------------" >> "$LOGFILE"
done
