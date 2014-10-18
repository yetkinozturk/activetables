CC      = g++
CFLAGS  = -I ./
LDFLAGS = -lpqxx -lpq -laprutil-1 -lexpat -lapr-1
all: example.app manage.app

example.app: main.o\
             basefield.o\
             field.o\
             model.o\
             person.o
	@echo ""
	@echo "==============="
	@echo "Linking Objects"
	@echo "==============="
	@echo ""
	$(CC) --std=gnu++11 -Wall -O3 -o $@ $^ $(LDFLAGS)

main.o: config/configure.cpp\
        backends/basebackend.cpp backends/postgresql.cpp\
        models/fields/basefield.cpp models/fields/field.cpp models/model.cpp\
        examples/person.cpp examples/main.cpp
	@echo ""
	@echo "================="
	@echo "Compiling Sources"
	@echo "================="
	@echo ""
	$(CC) --std=gnu++11 -Wall -O3 -c $(CFLAGS) $^ 

manage.app: manage.o
	@echo ""
	@echo "=================="
	@echo "Linking manage.app"
	@echo "=================="
	$(CC) --std=gnu++11 -Wall -O3 -o $@ $^ $(LDFLAGS) -lgflags

manage.o: manage/manage.cpp
	@echo ""
	@echo "===================="
	@echo "Compiling manage.app"
	@echo "===================="
	$(CC) --std=gnu++11 -Wall -O3 -c $(CFLAGS) $^

.PHONY: clean

clean:
	@echo ""
	@echo "==========="
	@echo "Cleaning Up"
	@echo "==========="
	@echo ""
	rm *.o
	rm example.app manage.app
