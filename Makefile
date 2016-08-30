all:
	gcc -g -lm -I./ main.c matrix.c -o main
	
clean:
	rm main