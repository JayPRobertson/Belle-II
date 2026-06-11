#!/bin/bash

FILEPATH="$HOME/Desktop/Belle II/Geant4/b2b_layered"
cp "$FILEPATH"/*.cc ../src/
cp "$FILEPATH"/*.hh ../include/

cp "$FILEPATH"/*.sh .