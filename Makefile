CFLAGS=-g

all : test_schema

test_items :  src/test_classe_items.o src/Items.o src/Porte.o src/Porte_1.o src/Porte_2.o src/Not.o src/And2.o src/Or2.o
	g++ -o $@ $^ $(LDFLAGS)

test_schema : src/test_classe_schema.o src/Items.o src/Porte.o src/Porte_1.o src/Porte_2.o src/Not.o src/And2.o src/Or2.o src/Schema.o
	g++ -o $@ $^ $(LDFLAGS)

%.o:%.cpp
	g++ $(CFLAGS) -c $^


clean:
	rm -f *.o *~  src/test_classe_items.o src/Items.o src/Porte.o src/Porte_1.o src/Porte_2.o src/Not.o src/And2.o src/Or2.o src/Schema.o
