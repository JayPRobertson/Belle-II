#!/bin/bash

FILEPATH="$HOME/Desktop/Belle II/Geant4/b2b"

cp "$FILEPATH"/*.cc ../src/
cp "$FILEPATH"/*.hh ../include/

cp "$FILEPATH"/*.sh .