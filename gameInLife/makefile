all: main
main: main.o game.o ge.o
	g++ -O2 main.o game.o graphicsEngine.o -o gameInLife -L../linux/lib -lopencv_core -lopencv_highgui

main.o: main.cpp
	g++ -O2 -c main.cpp -I ../linux/

game.o: game.cpp
	g++ -O2 -c game.cpp -I ../linux/

ge.o: graphicsEngine.cpp
	g++ -O2 -c graphicsEngine.cpp -I ../linux/ 

clean:
	rm -rf *.o main