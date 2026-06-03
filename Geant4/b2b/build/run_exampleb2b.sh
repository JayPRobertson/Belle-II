#!/bin/bash

FILEPATH="$HOME/Desktop/Belle II"

rm -f event_action_data.csv init_step_data.csv

echo "event_id,num_trajectory,num_hits,energies,hitx,hity,hitz" > event_action_data.csv
echo "energies,initx,inity,initz" > init_step_data.csv

make
./exampleB2b

cp event_action_data.csv "$FILEPATH/Python/csv/hits/"
cp init_step_data.csv "$FILEPATH/Python/csv/hits/"
