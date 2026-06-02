#!/bin/bash

# Assumes you are in /garfieldpp/Examples/DriftTube/build

# Change this path to the location you want the csv files
FILEPATH="$HOME/Desktop/Belle II/Python/csv/rantrack"

rm "$FILEPATH"/*.csv

./mdt ar_93_co2_7_3bar.gas IonMobility_Ar+_Ar.txt 0
mv multitrack_data_file.csv "$FILEPATH/ar_co2_93l7_rantrack.csv"

./mdt he_50_c2h6_50.gas IonMobility_He+_He.txt 0
mv multitrack_data_file.csv "$FILEPATH/he_c2h6_50l50_rantrack.csv"
