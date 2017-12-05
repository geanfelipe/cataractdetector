all:
	@echo "compilando................."
	gcc -w src/imagem.c src/catarata.c src/filtros.c -o catarata

clean:
	@echo "removendo compilados..........."
	rm catarata
