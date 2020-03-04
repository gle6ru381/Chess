.PHONY: clean
bin/chess: $(patsubst src/%.c,build/%.o,$(wildcard src/*.c))
	gcc $^ -o $@ 

build/%.o: src/%.c
	gcc -o $@ -c -MD $<

clean:
	rm build/*.o
	rm build/*.d

include $(wildcard build/*.d)