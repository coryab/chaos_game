# Chaos Game

Mail: [cory@balaton.dev](mailto:cory@balaton.dev)

## Libraries

- [Matplot++](https://alandefreitas.github.io/matplotplusplus/)

Read about the chaos game [here](https://en.wikipedia.org/wiki/Chaos_game).

Read about the sierpinski triangle [here](https://en.wikipedia.org/wiki/Sierpiński_triangle).

## Compiling

The steps below should for most Linux systems. I have tested it using Fedora.

Matplot++ uses gnuplot, so make sure that you have it installed on your system. On Fedora, you can install it like this:

	sudo dnf install gnuplot

For MacOS and Windows, other steps are most likely necessary.

### One time step

I would recommend creating a new directory within the project called **build** and then open a terminal inside that directory.
Then you can run this command to generate a **MakeFile**:

    cmake ..


Whenever you want to compile the code, just run this command inside the build directory:

    make

## Executing code

After compiling the code, there should be a file called **main** inside the build directory. To execute it, just run:

    ./main

You should then see a sierpinski triangle, and when the program is done, it will save the image.
