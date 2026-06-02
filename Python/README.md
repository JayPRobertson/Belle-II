# Python Data Analysis

Data output by the Garfield++ and Geant4 programs is collected in the `csv` directory:
- `Garfield++/sh_files/run_mdt.sh` -> `csv/gas`
- `Garfield++/sh_files/run_rantrack.sh` -> `csv/rantrack`
- `Garfield++/sh_files/run_sag.sh` -> `csv/sag`
- `Geant4/b2b/build/run_exampleb2b.sh` -> `csv/hits`

Aditional plots and data analysis on the raw data can be completed using Jupyter Notebook:
- Garfield++ -> `BelleII_Gas_Analysis.ipynb`
- Geant4 -> `geant4_data_analysis.ipynb`