CFLAGS = -g -lm -Wall
LDFLAGS = -lm


all : test4

test :   ../src/Dot.o ../src/Items.o ../src/Porte.o ../src/Porte_1.o ../src/Porte_2.o ../src/Not.o ../src/And2.o ../src/Or2.o ../src/test_classe_items.o
	g++ -o $@ $^ $(LDFLAGS)

test2 :../src/test_classe_schema.o ../src/Dot.o ../src/Items.o ../src/Porte.o ../src/Porte_1.o ../src/Porte_2.o ../src/Not.o ../src/And2.o ../src/Or2.o ../src/Schema.o
	g++ -o $@ $^ $(LDFLAGS)

test3 :../src/test_classe_dot.o ../src/Dot.o ../src/Items.o ../src/Porte.o ../src/Porte_1.o ../src/Porte_2.o ../src/Not.o ../src/And2.o ../src/Or2.o ../src/Schema.o ../src/dot.o
	g++ -o $@ $^ $(LDFLAGS)

test4 : ../src/test_classe_dot.o ../src/Dot.o ../src/Items.o ../src/Porte.o ../src/Porte_1.o ../src/Porte_2.o ../src/Not.o ../src/And2.o ../src/Or2.o ../src/Dot.o ../src/Schema.o ../src/Simulateur.o
	g++ -o $@ $^ $(LDFLAGS)


%.o:%.cpp
	g++ $(CFLAGS) -c $^


clean:
	rm -f *.o ../src/*.o *~ test4
