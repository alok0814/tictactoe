main : tictactoe++.o func1.o func2.o setup.o
	g++ -o tictactoe++.exe tictactoe++.o func1.o func2.o setup.o -lncurses
clean:
	rm tictactoe++.exe func1.exe func2.exe setup.exe tictactoe++.o func1.o select.o func2.o setup.o
func1.o : func1.cpp
	g++ -c func1.cpp
func2.o : func2.cpp
	g++ -c func2.cpp
setup.o : setup.cpp
	g++ -c setup.cpp

