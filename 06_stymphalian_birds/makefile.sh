echo "What is your directory to your project?
(in ./ format)"
read dir
clear
mkdir $1
mkdir $1/srcs
cp $dir/*.c $1/srcs
mkdir $1/includes
cp $dir/*.h $1/includes
cd $1
echo "NAME = $1

SRC = *.c

OBJ = \$(SRC:.c=.o)

SRC_PATH = srcs/

SRC_POS = \$(addprefix \$(SRC_PATH),\$(SRC))

INC = -I includes" > Makefile
echo "Need libft? (y \\ n)"
read libft_y
if [ $libft_y = "y" ]
then
	echo "Where is you libft? 
(in ./libft format or write GIT)"
	read libft_dir
	if [ $libft_dir = "GIT" ]
	then
		echo "Please write cloning address"
		read address
		git clone $address lib/libft
		rm -rf lib/libft/.git
	else
		mkdir lib
		cp -r ../$libft_dir lib/
	fi
	echo "
LIBFT =	lib/libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: \$(NAME)

\$(NAME): \$(LIBFT) \$(OBJ)
	\$(CC) \$(FLAGS) \$(OBJ) -o \$(NAME) \$(LIBFT)

\$(OBJ): \$(LIBFT)
	\$(CC) \$(FLAGS) \$(INC) -c \$(SRC_POS)

\$(LIBFT):
	make -C ./lib/libft/

clean:
	rm -f \$(OBJ)
	make clean -C ./lib/libft/

fclean: clean
	rm -f \$(NAME)
	make fclean -C ./lib/libft/

re: fclean all

.PHONY : all, re, clean, flcean" >> Makefile
else
	echo "
CC = gcc

FLAGS = -Wall -Wextra -Werror

all: \$(NAME)

\$(NAME): \$(OBJ)
	\$(CC) \$(FLAGS) -o \$(NAME) \$(OBJ)

\$(OBJ):
	\$(CC) \$(FLAGS) \$(INC) -c \$(SRC_POS)

clean:
	rm -f \$(OBJ)

fclean: clean
	rm -f \$(NAME)

re: fclean all

.PHONY : all, re, clean, fclean" >> Makefile
fi
clear
echo "Makefile CREATED"
clear
