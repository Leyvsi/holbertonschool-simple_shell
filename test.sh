#!/bin/bash

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh || exit 1

echo "Starting tests"

touch out_hsh.txt out_sh.txt

#Test 1 : simple command
echo "/bin/ls" | ./hsh > out_hsh.txt
echo "/bin/ls" | /bin/sh > out_sh.txt
diff out_hsh.txt out_sh.txt && echo "Test 1 PASS" || echo "Test 1 FAIL"

#Test 2 : command w arg
echo "/bin/ls -l /tmp" | ./hsh > out_hsh.txt
echo "/bin/ls -l /tmp" | /bin/sh > out_sh.txt
diff out_hsh.txt out_sh.txt && echo "Test 2 PASS" || echo "Test 2 FAIL"

#For clean up
rm out_hsh.txt out_sh.txt

