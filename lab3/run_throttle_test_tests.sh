echo "==========================================="
echo "Running Test-Test 1: error in default constructor"
echo "-------------------------------------------"
g++ ../throttle_test_tests/test1.o throttle_test.cpp -o testrun
./testrun
echo

echo "==========================================="
echo "Running Test-Test 2: error in default constructor"
echo "-------------------------------------------"
g++ ../throttle_test_tests/test2.o throttle_test.cpp -o testrun
./testrun
echo

echo "==========================================="
echo "Running Test-Test 3: error in 1-param constructor"
echo "-------------------------------------------"
g++ ../throttle_test_tests/test3.o throttle_test.cpp -o testrun
./testrun
echo

echo "==========================================="
echo "Running Test-Test 4: error in 1-param constructor"
echo "-------------------------------------------"
g++ ../throttle_test_tests/test4.o throttle_test.cpp -o testrun
./testrun
echo

echo "==========================================="
echo "Running Test-Test 5: error in flow function"
echo "-------------------------------------------"
g++ ../throttle_test_tests/test5.o throttle_test.cpp -o testrun
./testrun
echo

echo "==========================================="
echo "Running Test-Test 6: error in is_on function"
echo "-------------------------------------------"
g++ ../throttle_test_tests/test6.o throttle_test.cpp -o testrun
./testrun
echo

echo "==========================================="
echo "Running Test-Test 7: error in shift function"
echo "-------------------------------------------"
g++ ../throttle_test_tests/test7.o throttle_test.cpp -o testrun
./testrun
echo

echo "==========================================="
echo "Running Test-Test 8: error in shift function"
echo "-------------------------------------------"
g++ ../throttle_test_tests/test8.o throttle_test.cpp -o testrun
./testrun
echo

echo "==========================================="
echo "Running Test-Test 9: error in shut_off function"
echo "-------------------------------------------"
g++ ../throttle_test_tests/test9.o throttle_test.cpp -o testrun
./testrun
echo
