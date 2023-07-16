# install required dependances (i don't ktnow which exacly xd)

`sudo apt install libx11-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev`
`sudo apt install libxrandr-dev libxext-dev libxcursor-dev libxinerama-dev libxi-dev`

`sudo apt install libglew-dev libglfw3-dev libglm-dev`

# other

`sudo apt install freeglut3 freeglut3-dev libglew-dev`
`sudo apt install mesa-utils mesa-common-dev libglu1-mesa-dev`
`sudo apt install libao-dev libmpg123-dev`

# compile
 
`g++ -Wall -pedantic -o main.o main.cpp -lglut -lGL`

# run

`./main.o`