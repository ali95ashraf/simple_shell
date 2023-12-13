#!/bin/bash

# Directory containing C files
directory="."

# Log file for Betty output
log_file="betty_log.txt"

# Empty the log file if it already exists
> "$log_file"

# Iterate over all .c files in the directory
for file in "$directory"/*.c; do
    # Check if file exists
    if [ -f "$file" ]; then
        echo "Running Betty on $file" >> "$log_file"
        betty "$file" >> "$log_file"
        echo "----------------------------------------------------" >> "$log_file"
    fi
done

echo "Betty checks completed. Results are in $log_file."
