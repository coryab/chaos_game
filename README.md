# Chaos Game

Mail: [cory@balaton.dev](mailto:cory@balaton.dev)

## Compiling

The steps described here work for Linux systems. The same steps may work on MacOS, but I haven't tested that. For Windows, other steps may be necessary.

### One time only step

I would recommend creating a new directory within the project called **build** and then open a terminal inside that directory.
Then you can run this command to generate a **MakeFile**:

    cmake ..


Whenever you want to compile the code, just run this command inside the build directory:

    make

## Executing code

After compiling the code, there should be a file called **main** inside the build directory. To execute it, just run:

    ./main