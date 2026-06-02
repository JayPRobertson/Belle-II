#!/bin/bash

# Assumes you are /garfieldpp/Examples/DriftTube/build
rm ~/Desktop/"Belle II"/Python/csv/sag/*.csv
make 

# Single drift cell
./mdt 0 0
mv sag_wires_data.csv ~/Desktop/"Belle II"/Python/csv/sag/
./mdt 0 1
mv sag_wires_data.csv ~/Desktop/"Belle II"/Python/csv/sag/sag_wires_data_ef.csv

# 3x3 drift cell grid
./mdt 1 0
mv sag_wires_data.csv ~/Desktop/"Belle II"/Python/csv/sag/multicell_sag_wires_data.csv
./mdt 1 1
mv sag_wires_data.csv ~/Desktop/"Belle II"/Python/csv/sag/multicell_sag_wires_data_ef.csv

# Circular drift cell grid
./mdt 2 0
mv sag_wires_data.csv ~/Desktop/"Belle II"/Python/csv/sag/circles_sag_data.csv
./mdt 2 1
mv sag_wires_data.csv ~/Desktop/"Belle II"/Python/csv/sag/circles_sag_data_ef.csv