CFLAGS = -g -lm -Wall
LDFLAGS = -lm


all : test3

test1 :  ../src/test_classe_dot.o ../src/Dot.o ../src/Items.o ../src/Porte.o  ../src/Not.o ../src/And2.o ../src/Or2.o ../src/Dot.o ../src/Schema.o ../src/Simulateur.o ../src/Input.o ../src/Output.o ../src/Stimuli.o ../src/Xor2.o ../src/Xnor2.o ../src/Nor2.o ../src/Nand2.o
	g++ -o $@ $^ $(LDFLAGS)

test2 :  ../src/test_classe_stimuli.o ../src/Stimuli.o ../src/Items.o ../src/Porte.o ../src/Not.o ../src/And2.o ../src/Or2.o ../src/Input.o ../src/Output.o
	g++ -o $@ $^ $(LDFLAGS)

test3 : ../src/test_classe_simulateur.o ../src/Dot.o ../src/Items.o ../src/Porte.o  ../src/Not.o ../src/And2.o ../src/Or2.o ../src/Dot.o ../src/Schema.o ../src/Simulateur.o ../src/Input.o ../src/Output.o ../src/Stimuli.o ../src/Xor2.o ../src/Xnor2.o ../src/Nor2.o ../src/Nand2.o
		g++ -o $@ $^ $(LDFLAGS)

%.o:%.cpp
	g++ $(CFLAGS) -c $^


clean:
	rm -f *.o ../src/*.o *~ test
