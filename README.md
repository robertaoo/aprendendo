Estou com um problema local que não consigo rodar o programa pelo WSL na minha maquina Windows. Não tive tempo de arrumar ainda, mas muito provavelmente a solução está aqui: https://stackoverflow.com/questions/61860208/running-graphical-linux-desktop-applications-from-wsl-2-error-e233-cannot-op

ou

https://en.sfml-dev.org/forums/index.php?topic=28293.0

Estamos usando SFML para o jogo. Próximo commit iremos organizar o README.md

Atualmente temos:
Personagem que se move para direita ou esquerda. Velocidade (deltaTime) pode ser modificado. Escala para as imagens. 

Como rodar:

1. Instale SFML pelo WSL sudo apt-get install libsfml-dev
2. Rodar ./sfml-app

ou

Compilar:
g++ -c main.cpp

Linkar:
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

Rodar:
./sfml-app
