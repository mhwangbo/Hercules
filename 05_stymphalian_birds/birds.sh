#!/bin/bash

clear
echo "If you need help, please write -h  instead of project name when operating a shell file"
if [ "$1" = "-h" ] || [ "$2" = "-h" ]
then
	echo "					Welcome! 👋"
	echo "	This script is made to help you when you start a new project."
	echo "	Script creates the folder stucture, makefile (basic flags: "
	echo "	-Wall -Wextra -Werror), author file, and libft."
	echo "	sh birds.sh PROJECT_NAME will create a new folder with your project"
	echo ""
	exit
fi

echo "Is this a C Project? (y \\ n): "
read C_project
clear

if [ $C_project = "n" ]
then
	echo "What language do you use?"
	read lang
	echo "Sorry, $lang is not supported. YET."

elif [ $C_project = "y" ]
then
	echo "YAY! Now we will make Makefile 😃"
	sh ./makefile.sh $1
	echo "Makefile CREATED"
	echo "Do you need a author file? (y \\ n): "
	read author

	if [ $author = "y" ]
	then
		echo "$USER"	> author
	
	elif [ "$author" != "y" ] && [ "$author" != "n" ]
	then
		echo "I will assume you mean NO."
	
	fi
	
	echo "Do you need a .gitignore file? (y \\ n)"
	read giti
	if [ $giti = "y" ]
	then
		sh ./gitignore.sh $1
	elif [ "$giti" != "y" ] && [ "$giti" != "n" ]
	then
		echo "I will assume you mean NO."
	fi

else
	echo "Wrong, please answer y or n."

fi
exit 0
