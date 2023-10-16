g++ -c NCG/*.cpp
g++ -c NCG/*.h
g++ -c NCG/*.hpp

g++ *.o -o bin/ncg -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

rm NCG/*.gch
rm *.o

cd bin

./ncg

cd ..