# Geant4 Drift Chamber

Files for a basic drift chamber geometry built using a modified example in [v11.4.1 of Geant4](https://github.com/Geant4/geant4/tree/v11.4.1). It is based off of the [2010 Belle II Technical Design Report](https://docs.belle2.org/files/4270/BELLE2-REPORT-2016-001/1/BELLE2-REPORT-2016-001.pdf) (pp. 205–208).

## Running Files
This geometry was built using the [B2b example](https://github.com/Geant4/geant4/tree/v11.4.1/examples/basic/B2/B2b) provided by Geant4 as a framework. Rather than adjusting the makefiles and namespace, it runs off of the b2b files with adjusted src, .mac, and exampleB2b.cc files. As such, this modified geometry can be easily run if the `geant4/examples/basic/B2/b2b` directory is replaced with the contents of the provided b2b file.

One the directory is replaced, run using the Geant4 visualization UI:

```
cd geant4/examples/basic/B2/b2b/build
cmake ../
chmod +x run_exampleb2b.sh
./run_exampleb2b.sh
```

Make sure to adjust the filepath in `run_exampleb2b.sh` before running.

## Output

Outputs three csv files of collected data. Filepath of output is set as `Python/csv/hits/`and can be modified in `run_exampleb2b.sh`.

- `entry_exit_data.csv` - the actual and expected point of entry and exit from the gas volume; for calculating multiple scattering
- `event_action_data.csv` - hit energy and hit positions
- `init_step_data.csv` - initial energy and position, and dEdx over volume

## Supplementary Material
- [Analysis of collected data](https://github.com/JayPRobertson/Belle-II/blob/main/Python/geant4_data_analysis.ipynb)
