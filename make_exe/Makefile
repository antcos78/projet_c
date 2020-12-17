CFLAGS = -g -lm -Wall -std=c++11
LDFLAGS = -lm


all : test6

test :   ../src/Items.o ../src/Porte.o ../src/Not.o ../src/And2.o ../src/Stimuli.cc ../src/Or2.o ../src/test_classe_items.o ../src/Input.o ../src/Output.o ../src/Xor2.o ../src/Xnor2.o ../src/Nor2.o ../src/Nand2.o
	g++ -o $@ $^ $(LDFLAGS)

test2 :../src/test_classe_dot.o ../src/Dot.o ../src/Items.o ../src/Porte.o ../src/Not.o ../src/And2.o ../src/Or2.o ../src/Porte.o ../src/Not.o ../src/Input.o ../src/Output.o  ../src/Stimuli.o
	g++ -o $@ $^ $(LDFLAGS)

test3 : ../src/Dot.o ../src/Stimuli.o ../src/Items.o ../src/Porte.o  ../src/Not.o  ../src/And2.o ../src/Or2.o ../src/Schema.o ../src/Input.o ../src/Output.o ../src/Dot.o ../src/test_classe_schema.o
	g++ -o $@ $^ $(LDFLAGS)


test4 : ../src/Dot.o ../src/Stimuli.o ../src/Simulateur.o ../src/Items.o ../src/Porte.o  ../src/Not.o  ../src/And2.o ../src/Or2.o ../src/Schema.o ../src/Input.o ../src/Output.o ../src/Dot.o ../src/test_classe_schema.o
	g++ -o $@ $^ $(LDFLAGS)

test5 : ../src/test_classe_simulateur.o ../src/Dot.o ../src/Items.o ../src/Porte.o  ../src/Not.o ../src/And2.o ../src/Or2.o ../src/Dot.o ../src/Schema.o ../src/Simulateur.o ../src/Input.o ../src/Output.o ../src/Stimuli.o ../src/Xor2.o ../src/Xnor2.o ../src/Nor2.o ../src/Nand2.o
	g++ -o $@ $^ $(LDFLAGS)

test6 : ../src/test_classe_wavedrom.o ../src/Dot.o ../src/Items.o ../src/Porte.o  ../src/Not.o ../src/And2.o ../src/Or2.o ../src/Dot.o ../src/Schema.o ../src/Simulateur.o ../src/Input.o ../src/Output.o ../src/Stimuli.o ../src/Xor2.o ../src/Xnor2.o ../src/Nor2.o ../src/Nand2.o ../src/Wavedrom.o ../src/Mux.o ../src/Bascule.o 
		g++ -o $@ $^ $(LDFLAGS)

%.o:%.cpp
	g++ $(CFLAGS) -c $^


clean:
	rm -f *.o ../src/*.o *~ test4
