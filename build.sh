#!/bin/bash
gcc $( pkg-config --cflags gtk+-3.0 webkit2gtk-4.1 ) -o ./virgil ./src/virgil.c $( pkg-config --libs gtk+-3.0 webkit2gtk-4.1 )
