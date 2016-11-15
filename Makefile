INC := -IUnity/extras/fixture/src/ \
	-IUnity/src/ \
	-Itest/ \
	-Ispi/ \
	
SRC := 	spi/spi.c \
	test/testspi.c \
	Unity/extras/fixture/src/unity_fixture.c \
	Unity/src/unity.c 
	
OPTIONS := -DTESTING	

TESTAPP := test.run

compile-tests:
	$(eval INC += -Itest/hal)
	$(eval SRC += test/hal/hal.c)
	gcc $(INC) $(SRC) test/main.c -o $(TESTAPP)
	
run-tests:	compile-tests
	./$(TESTAPP)

