#!/bin/bash

# Assumes you are in /garfieldpp/Examples/DriftTube/build

# Delete all previous files
rm ~/Desktop/"Belle II"/Python/csv/gas/*.csv
make 

# Collect Ar+CO2 (93/7) Data
./mdt ar_93_co2_7_3bar.gas IonMobility_Ar+_Ar.txt 0
mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/ar_93_co2_7_3bar.csv
./mdt ar_93_co2_7_3bar.gas IonMobility_Ar+_Ar.txt 1
mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/ar_93_co2_7_3bar_B.csv

# Collect Ar+CO2 (80/20) Data
./mdt ar_80_co2_20_0T.gas IonMobility_Ar+_Ar.txt 0
mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/ar_80_co2_20_0T.csv
./mdt ar_80_co2_20_0T.gas IonMobility_Ar+_Ar.txt 1
mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/ar_80_co2_20_0T_B.csv

# Collect Ne+CO2+N2 (90/10/5) Data
./mdt Ne_90_CO2_10_N2_5_with_mg.gas IonMobility_Ne+_Ne.txt 0
mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/Ne_90_CO2_10_N2_5_with_mg.csv
./mdt Ne_90_CO2_10_N2_5_with_mg.gas IonMobility_Ne+_Ne.txt 1
mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/Ne_90_CO2_10_N2_5_with_mg_B.csv

# Collect He+C2H6 (90/10) Data
./mdt he_90_c2h6_10.gas IonMobility_He+_He.txt 0
mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/he_90_c2h6_10.csv
./mdt he_90_c2h6_10.gas IonMobility_He+_He.txt 1
mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/he_90_c2h6_10_B.csv

# Collect He+C3H8 (93.8/6.2) Data
./mdt he_94_c3h8_6.gas IonMobility_He+_He.txt 0
mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/he_94_c3h8_6.csv
./mdt he_94_c3h8_6.gas IonMobility_He+_He.txt 1
mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/he_94_c3h8_6_B.csv

# Collect He+C2H6 (50/50) Data
./mdt he_50_c2h6_50.gas IonMobility_He+_He.txt 0
mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/he_50_c2h6_50.csv
./mdt he_50_c2h6_50.gas IonMobility_He+_He.txt 1
mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/he_50_c2h6_50_B.csv

# Collect He+CO2+C4H10  (78/15/7) Data
./mdt he_78_co2_15_c4h10_7.gas IonMobility_He+_He.txt 0
mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/he_78_co2_15_c4h10_7.csv
./mdt he_78_co2_15_c4h10_7.gas IonMobility_He+_He.txt 1
mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/he_78_co2_15_c4h10_7_B.csv

# Collect Ar+CH4 (90/10) Data
./mdt ar_90_ch4_10.gas IonMobility_Ar+_Ar.txt 0
mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/ar_90_ch4_10.csv
./mdt ar_90_ch4_10.gas IonMobility_Ar+_Ar.txt 1
mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/ar_90_ch4_10_B.csv

# Collect He+C2H6O  (70/30) Data
#./mdt he_70_c2h6O_30.gas IonMobility_He+_He.txt 0
#mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/he_70_c2h6O_30.csv
#./mdt he_70_c2h6O_30.gas IonMobility_He+_He.txt 1
#mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/he_70_c2h6O_30_B.csv

# Collect He+C4H10 (90/10) Data
#./mdt he_90_c4h10_10.gas IonMobility_He+_He.txt 0
#mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/he_90_c4h10_10.csv
#./mdt he_90_c4h10_10.gas IonMobility_He+_He.txt 1
#mv drift_data_file.csv ~/Desktop/"Belle II"/Python/csv/gas/he_90_c4h10_10_B.csv

# Does not eliminate glitch type drift lines so you must
# check number of drift lines is reasonable before accepting data