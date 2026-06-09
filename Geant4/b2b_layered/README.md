# Layered Gas Volume Drift Chamber

One way to measure energy deposition through a volume is to divide up the volume into layers and detect when a particle enters and exits that layer. 

This code is a supplemental to the main body of code in `b2b`. Replace select files in `b2b` directory with those in `b2b_layered` and run as normal.

Outputs two files:

- `event_action_data_layered.csv` - hit energy and hit positions
- `layered_edep_data.csv` - energy deposition within layers