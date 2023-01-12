##
## EPITECH PROJECT, 2023
## tailq
## File description:
## Makefile
##

CC 					= 	gcc

CFLAGS 				= 	-g -Wall -Wextra -I include

SOURCES_UNIT	 	= 	src/init_list.c				\
						src/free_list.c 			\
						src/get_list_length.c 		\
						src/is_element_present.c	\
						src/list_gestion.c 			\
						src/print_list.c			\
						tests/basics.c

SOURCE 				= 	src/init_list.c				\
						src/free_list.c 			\
						src/get_list_length.c 		\
						src/is_element_present.c	\
						src/list_gestion.c 			\
						src/print_list.c

OBJECTS_UNIT 		= 	$(SOURCES_UNIT:.c=.o)

OBJECTS 			= 	$(SOURCE:.c=.o)

TARGET				=	unit_tests

NAME				=	liblist.a

MY_COVER			= 	--coverage -lcriterion

LCOV 				= 	-fprofile-arcs -ftest-coverage

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	@rm -f $(OBJECTS_UNIT)
	@find . -name "*.gcno" -delete
	@find . -name "*.gcda" -delete

fclean: clean
	@rm -f $(TARGET)
	@rm -f $(NAME)

unit_tests: CFLAGS	+=	$(MY_COVER)
unit_tests: fclean $(OBJECTS_UNIT)
	$(CC) $(LCOV) -o $(TARGET) $(OBJECTS_UNIT) $(MY_COVER)

gcovr:
	@./unit_tests
	@gcovr --exclude tests/
