# release the horses!
./download/manger &

sleep  5

# kill horses!
pkill -4 podargos
pkill -4 yes
pkill -5 lampon
pkill -10 xanthos
pkill -11 deinos

kill -s KILL $(top -l 1 | grep manger | awk '{print $1}')

rm -rf *.poo

gcc -o crazy my_manger.c
sleep 1
chmod 777 crazy
sleep 1
clear
echo "WARNING!!! CRZAY HORSES COMING!\n"
say "warning! warning! warning! warning!"
clear
say "one"
echo "one"
sleep 1
clear
say "two"
echo "two"
sleep 1
clear
say "three"
echo "three"
sleep 1
clear
say "four"
echo "four"
sleep 1
clear
say "five"
echo "five"
sleep 1
clear
say "go!"

./crazy &

sleep 5

pkill crazy

rm -rf *.poo
