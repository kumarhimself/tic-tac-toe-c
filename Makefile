CC = gcc
OUT = build/main.out

default:
	@echo Building project...
	@$(CC) src/*.c src/app/*.c -o $(OUT)
	@echo Project executable is now ready! 

run:
	@$(OUT)

clean:
	@echo Cleaning build directory...
	@rm -f $(OUT)
	@echo Build directory is empty
