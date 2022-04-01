COMPILER=g++
NAME=main

main:$(NAME).cpp
	$(COMPILER) -o $(NAME) $(NAME).cpp
