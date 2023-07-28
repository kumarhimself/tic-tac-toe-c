CC = gcc
OUT = build/main.out

default:
	@clear
	@echo Building project...
	@$(CC) src/*.c src/app/*.c -o $(OUT)
	@echo Project executable is now ready! 

run:
	@clear
	@$(OUT)

clean:
	@clear
	@echo Cleaning build directory...
	@rm -f $(OUT)
	@echo Build directory is empty
