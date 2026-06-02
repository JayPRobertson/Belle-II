#!/bin/bash

# Assumes you are /garfieldpp/Examples/DriftTube/build

rm ~/Desktop/"Belle II"/Python/csv/*rantrack.csv

./mdt ar_93_co2_7_3bar.gas IonMobility_Ar+_Ar.txt 0
mv multitrack_data_file.csv ~/Desktop/"Belle II"/Python/csv/rantrack/ar_co2_93l7_rantrack.csv

./mdt he_50_c2h6_50.gas IonMobility_He+_He.txt 0
mv multitrack_data_file.csv ~/Desktop/"Belle II"/Python/csv/rantrack/he_c2h6_50l50_rantrack.csv
