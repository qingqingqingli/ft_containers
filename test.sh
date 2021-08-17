make re
./std > TESTS/std_output.txt
./ft > TESTS/ft_output.txt
diff TESTS/std_output.txt TESTS/ft_output.txt