#!/bin/bash

FILEPATH="$HOME/Desktop/Belle II"

rm -f event_action_data.csv layered_edep_data.csv

echo "event_id,num_trajectory,num_hits,energies,hitx,hity,hitz" > event_action_data_layered.csv

echo "entry_x,entry_y,entry_z,exit_x,exit_y,exit_z,edep" > layered_edep_data.csv

make
./exampleB2b

cp event_action_data_layered.csv "$FILEPATH/Python/csv/hits/"
cp layered_edep_data.csv "$FILEPATH/Python/csv/hits/"
