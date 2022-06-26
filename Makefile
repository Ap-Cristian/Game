#fix: Make only the modified files

CXX=clang++
LIBPATH="./lib/"
CFLAGS=-I "./include/SFML/" -I "./include/game/" -I "./include/objects/" -I "./include/objects/sprites/" -I "./include/scenes/" -Wall
DEPS= Game.hpp Object.hpp Objects.hpp Scene.hpp Start_scene.hpp RC_sprite.hpp
LIBS= -lsfml-graphics -lsfml-window -lsfml-system
OUTFILE="../out/build.out"

.SILENT: make out/main.o out/game.o out/object.o out/scene.o out/rc_sprite.o out/objects.o out/start_scene.o clean


make: out/main.o
	cd out && \
	$(CXX) $(CFLAGS) $(LIBS)  main.o game.o scene.o rc_sprite.o objects.o object.o start_scene.o -o $(OUTFILE)
	echo make: Project built succesfully! 

out/main.o:out/object.o out/rc_sprite.o out/scene.o out/objects.o out/game.o out/start_scene.o
	cd src && \
	$(CXX) $(CFLAGS) -c main.cpp -o ../out/main.o
	echo make: Main compiled!
	
out/game.o: src/game.cpp
	cd src && \
	mkdir -p ../out && \
	$(CXX) $(CFLAGS) -c game.cpp -o ../out/game.o
	echo make: Game compiled!

out/object.o: src/object.cpp
	cd src && \
	$(CXX) $(CFLAGS) -c object.cpp -o ../out/object.o
	echo make: Object compiled!

out/scene.o: src/scene.cpp
	cd src && \
	$(CXX) $(CFLAGS) -c scene.cpp -o ../out/scene.o
	echo make: Scene compiled!

out/start_scene.o: src/start_scene.cpp
	cd src && \
	$(CXX) $(CFLAGS) -c start_scene.cpp -o ../out/start_scene.o
	echo make: Start_scene compiled!

out/rc_sprite.o: src/rc_sprite.cpp
	cd src && \
	$(CXX) $(CFLAGS) -c rc_sprite.cpp -o ../out/rc_sprite.o
	echo make: Rc_sprite compiled!

out/objects.o: src/objects.cpp
	cd src && \
	$(CXX) $(CFLAGS) -c objects.cpp -o ../out/objects.o
	echo make: Objects compiled!
	
clean:
	cd out && \
	rm -rf *.o && \
	rm -rf build.out
	echo make: Project cleared!
