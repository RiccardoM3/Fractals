# Fractals
Fractal Maker in C++

## Dependencies
`sudo apt-get install libsfml-dev`

## If Running on WSL
- Ensure you are running on WSL2
- Download and start [VcXsrv Windows X Server](https://sourceforge.net/projects/vcxsrv/) to allow the SFML package to render to a window and register input events in windows
- When starting the X server:
    - untick "Native opengl" setting
    - tick the "Disable Access Control" setting

- Run the following command, or add it to your .bashrc
    - `export DISPLAY=<windows-ip>:0`
    - e.g. `export DISPLAY=192.168.0.159:0`

## Building
`./build.sh`

## Running
`./build/bin/product/fractal_app`