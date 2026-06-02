#!/bin/bash

# Assumes you are /garfieldpp/Examples/DriftTube/build

# Change this path to the location you want the csv files
FILEPATH="$HOME/Desktop/\"Belle II\"/Python/csv/sag"

rm "$FILEPATH"/*.csv
make 

# Single drift cell
./mdt 0 0
mv sag_wires_data.csv "$FILEPATH/"
./mdt 0 1
mv sag_wires_data.csv "$FILEPATH/sag_wires_data_ef.csv"

# 3x3 drift cell grid
./mdt 1 0
mv sag_wires_data.csv "$FILEPATH/multicell_sag_wires_data.csv"
./mdt 1 1
mv sag_wires_data.csv "$FILEPATH/multicell_sag_wires_data_ef.csv"

# Circular drift cell grid
./mdt 2 0
mv sag_wires_data.csv "$FILEPATH/circles_sag_data.csv"
./mdt 2 1
mv sag_wires_data.csv "$FILEPATH/circles_sag_data_ef.csv"