#!/bin/bash

FILEPATH="$HOME/Desktop/Belle II"

rm -f event_action_data.csv layered_edep_data.csv layer_radius.csv

echo "event_id,num_trajectory,num_hits,energies,hitx,hity,hitz" > event_action_data_layered.csv

echo "index,entry_x,entry_y,entry_z,exit_x,exit_y,exit_z,edep" > layered_edep_data.csv

echo "r1,r2" > layer_radius.csv

make
./exampleB2b

cp event_action_data_layered.csv "$FILEPATH/Python/csv/hits/"
cp layered_edep_data.csv "$FILEPATH/Python/csv/hits/"
cp layer_radius.csv "$FILEPATH/Python/csv/hits/"
