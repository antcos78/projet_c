CFLAGS = -g -lm -Wall
LDFLAGS = -lm


all : test

test :  src/test_classe_dot.o src/Dot.o src/Items.o src/Porte.o src/Porte_1.o src/Porte_2.o src/Not.o src/And2.o src/Or2.o
	g++ -o $@ $^ $(LDFLAGS)



%.o:%.cpp
	g++ $(CFLAGS) -c $^


clean:
	rm -f *.o src/*.o *~ test
