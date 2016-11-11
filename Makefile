INC := -IUnity/extras/fixture/src/ \
	-IUnity/src/ \
	-Itest/ \
	-Ispi/ \
	-Ihal/
	
SRC := 	spi/spi.c \
	test/testspi.c \
	hal/hal.c \
	Unity/extras/fixture/src/unity_fixture.c \
	Unity/src/unity.c 

TESTAPP := test.run

compile-tests:
	gcc $(INC) $(SRC) test/main.c -o $(TESTAPP)
	
run-tests:	compile-tests
	./$(TESTAPP)

