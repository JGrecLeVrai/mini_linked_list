##
## EPITECH PROJECT, 2023
## tailq
## File description:
## Makefile
##

CC 					:= 	gcc

CFLAGS 				:= 	-Wall -Wextra -I include

SOURCE 				:= 	src/init_list.c				\
						src/free_list.c 			\
						src/get_list_length.c 		\
						src/is_element_present.c	\
						src/list_gestion.c 			\
						src/print_list.c			\
						src/reverse_list.c			\
						src/nb_elements.c

SOURCES_UNIT	 	:=	$(SOURCE)
SOURCES_UNIT		+=	tests/basics.c
SOURCES_UNIT		+=	tests/test_failing_memory_allocation.c
SOURCES_UNIT		+=	tests/malloc_wrapper.c

OBJECTS_UNIT 		:= 	$(SOURCES_UNIT:.c=.o)

OBJECTS 			:= 	$(SOURCE:.c=.o)

UNIT				:=	unit_tests

NAME				:=	liblist.a

MY_COVER			:= 	--coverage -lcriterion

LCOV 				:= 	-fprofile-arcs -ftest-coverage

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS_UNIT)
	@find . -name "*.gcno" -delete
	@find . -name "*.gcda" -delete

fclean: clean
	@rm -f $(UNIT)
	@rm -f $(NAME)

re: fclean all

.PHNONY: clean fclean re

$(UNIT): CFLAGS	+= $(MY_COVER)
$(UNIT): CFLAGS	+= -Wl,--wrap=malloc
$(UNIT): $(OBJECTS_UNIT)
	$(CC) $(LCOV) -o $(UNIT) $(OBJECTS_UNIT) $(CFLAGS)

tests_run: fclean $(UNIT)
	@ ./$(UNIT) --always-succeed
	@ gcovr --exclude tests

.PHONY: tests_run
