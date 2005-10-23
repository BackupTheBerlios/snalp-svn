
libsnalpsqlite.a: sqlite.o
	ar rs $@ $<
sqlite.o: src/bti.o
	cp src/bti.o $@
.PHONY: src/bti.o
src/bti.o:
	@(cd src;$(MAKE);)

clean:
	@echo Cleaning up ...
	@(cd src;$(MAKE) clean;)
	@rm *.o *.a||true
