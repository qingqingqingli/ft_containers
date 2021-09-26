PROGRAM_STD		= 	std
PROGRAM_FT		= 	ft

SOURCE			= 	makefile_test/makefile_test.cpp
OBJECT			=	$(SOURCE:.cpp=.o)
OUTPUT_FILES    =   makefile_test/ft_output.txt makefile_test/std_output.txt

COMPILE			= 	clang++

FLAGS_STD		= 	-Wall -Wextra -Werror -std=c++98 -D STD_OPTION=1
FLAGS_FT		= 	-Wall -Wextra -Werror -std=c++98 -D STD_OPTION=0

RESET			= 	\033[0m
GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m
RED 			= 	\033[38;5;160m

all: $(PROGRAM_STD) $(PROGRAM_FT)

$(PROGRAM_STD): $(OBJECT)
	@echo "$(GREEN)----------------------------------------------------"
	@$(COMPILE) $(FLAGS_STD) $(SOURCE) -o $(PROGRAM_STD)
	@echo "STD Executable				./$(PROGRAM_STD) $(RESET)"

$(PROGRAM_FT): $(OBJECT)
	@echo "$(GREEN)----------------------------------------------------"
	@$(COMPILE) $(FLAGS_FT) $(SOURCE) -o $(PROGRAM_FT)
	@echo "FT Executable				./$(PROGRAM_FT) $(RESET)"

clean:
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(OBJECT)
	@echo "$(GRAY)REMOVED O-FILES $(RESET)"

fclean: clean
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(PROGRAM_STD) $(PROGRAM_FT) $(OUTPUT_FILES)
	@echo "$(GRAY)REMOVED EXECUTABLE FILE & OUTPUT FILES $(RESET)"

re: fclean all

.PHONY: all clean fclean re