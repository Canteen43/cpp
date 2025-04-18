#!/bin/bash

# Extract lines following "Last line of output:" and collect unique values
awk '/Last line of output:/ { getline; print }' pmerge_run.log | sort -n | uniq > numbers.log
