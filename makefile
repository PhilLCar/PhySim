comp:
	@gcc -lX11 physim.c -o physim

run: comp
	@./physim
