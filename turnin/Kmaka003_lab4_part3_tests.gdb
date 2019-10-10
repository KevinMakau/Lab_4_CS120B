# Test file for Lab_3_


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
#test "PINA: 0x00, PINB: 0x00 => PORTC: 0"
# Set inputs
#setPINA 0x00
#setPINB 0x00
# Continue for several ticks
#continue 2
# Set expect values
#expectPORTC 0
# Check pass/fail
#checkResult

# Add tests below

test "PINA: 0x00 => PINB = 0x00"
setPINA 0x00
continue 2
expectPORTB 0x00
expectPORTC 2
checkResult

#inside / outside
#-------------------------------------------------------------
test "PINA: 0x80 => PINB = 0x00"
setPINA 0x80
continue 2
expectPORTB 0x00
expectPORTC 6
checkResult

test "PINA: 0x00 => PINB = 0x00"
setPINA 0x00
continue 2
expectPORTB 0x00
expectPORTC 2
checkResult
#--------------------------------------------------------------


#door unlocks from outside
#--------------------------------------------------------------
test "PINA: 0x04 => PINB = 0x00"
setPINA 0x04
continue 5
expectPORTB 0x00
expectPORTC 3
checkResult

test "PINA: 0x00 => PINB = 0x00"
setPINA 0x00
continue 5
expectPORTB 0x00
expectPORTC 4
checkResult


test "PINA: 0x02 => PINB = 0x01"
setPINA 0x02
continue 5
expectPORTB 0x01
expectPORTC 5
checkResult

test "PINA: 0x00 => PINB = 0x01"
setPINA 0x00
continue 5
expectPORTB 0x01
expectPORTC 2
checkResult
#-------------------------------------------------------------------


#door locks from inside
#--------------------------------------------------------------------


test "PINA: 0x80 => PINB = 0x01"
setPINA 0x80
continue 2
expectPORTB 0x01
expectPORTC 6
checkResult


test "PINA: 0x81 => PINB = 0x00"
setPINA 0x81
continue 5
expectPORTB 0x00
expectPORTC 7
checkResult


test "PINA: 0x80 => PINB = 0x00"
setPINA 0x80
continue 5
expectPORTB 0x00
expectPORTC 6
checkResult
#--------------------------------------------------------------------


#door unlocks from inside
#---------------------------------------------------------------------
test "PINA: 0x84 => PINB = 0x00"
setPINA 0x84
continue 5
expectPORTB 0x00
expectPORTC 9
checkResult


test "PINA: 0x86 => PINB = 0x00"
setPINA 0x84
continue 5
expectPORTB 0x00
expectPORTC 9
checkResult

test "PINA: 0x80 => PINB = 0x00"
setPINA 0x80
continue 5
expectPORTB 0x00
expectPORTC 4
checkResult

test "PINA: 0x82 => PINB = 0x00"
setPINA 0x82
continue 5
expectPORTB 0x01
expectPORTC 5
checkResult

test "PINA: 0x80 => PINB = 0x01"
setPINA 0x80
continue 5
expectPORTB 0x01
expectPORTC 6
checkResult
#------------------------------------------------------------------------


#hitting x while wainting for Y sends to init
#-------------------------------------------------------------------------
test "PINA: 0x84 => PINB = 0x00"
setPINA 0x84
continue 5
expectPORTB 0x00
expectPORTC 9
checkResult


test "PINA: 0x86 => PINB = 0x00"
setPINA 0x84
continue 5
expectPORTB 0x00
expectPORTC 9
checkResult

test "PINA: 0x80 => PINB = 0x00"
setPINA 0x80
continue 5
expectPORTB 0x00
expectPORTC 4
checkResult

test "PINA: 0x81 => PINB = 0x00"
setPINA 0x81
continue 5
expectPORTB 0x00
expectPORTC 7
checkResult


test "PINA: 0x80 => PINB = 0x00"
setPINA 0x80
continue 5
expectPORTB 0x00
expectPORTC 6
checkResult





# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
