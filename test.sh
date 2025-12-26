#!/bin/bash

# Compile the shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

echo "--- Starting Tests ---"

touch out_hsh.txt out_sh.txt

# Test 1: Simple command
echo "Test 1: /bin/ls"
echo "/bin/ls" | ./hsh > out_hsh.txt
echo "/bin/ls" | /bin/sh > out_sh.txt
diff out_hsh.txt out_sh.txt && echo -e "${GREEN}PASS${NC}" || echo -e "${RED}FAIL${NC}"

# Test 2: Command with arguments
echo "Test 2: /bin/ls -l /tmp"
echo "/bin/ls -l /tmp" | ./hsh > out_hsh.txt
echo "/bin/ls -l /tmp" | /bin/sh > out_sh.txt
diff out_hsh.txt out_hsh.txt && echo -e "${GREEN}PASS${NC}" || echo -e "${RED}FAIL${NC}"

# Clean up
rm out_hsh.txt out_sh.txt
