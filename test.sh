make re
./std > makefile_test/std_output.txt
./ft > makefile_test/ft_output.txt
diff -a makefile_test/std_output.txt makefile_test/ft_output.txt
