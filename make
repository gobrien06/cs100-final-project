echo "Compiling...";

g++ -c source/*.cpp main.cpp -I SFML-2.5.1/include;

sleep 2;

echo "Linking...";

g++ *.o -o main -L SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lwinmm -lgdi32;

