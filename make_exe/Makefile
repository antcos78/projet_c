CFLAGS = -g -lm -Wall -std=c++11
LDFLAGS = -lm


all : main

main : ../src/main.o ../src/Dot.o ../src/Items.o ../src/Porte.o  ../src/Not.o ../src/And2.o ../src/Or2.o ../src/Dot.o ../src/Schema.o ../src/Simulateur.o ../src/Input.o ../src/Output.o ../src/Stimuli.o ../src/Xor2.o ../src/Xnor2.o ../src/Nor2.o ../src/Nand2.o ../src/Wavedrom.o ../src/Mux.o ../src/Bascule.o
		g++ -o $@ $^ $(LDFLAGS)

%.o:%.cpp
	g++ $(CFLAGS) -c $^


clean:
	rm -f *.o ../src/*.o *~ main
