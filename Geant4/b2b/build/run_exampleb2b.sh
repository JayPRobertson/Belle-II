#!/bin/bash

FILEPATH = "$HOME/\"Belle II\"/Python/csv/hits"

rm event_action_data.csv
echo "event_id,num_trajectory,num_hits,energies,hitx,hity,hitz" > "event_action_data.csv"

make
./exampleB2b

cp event_action_data.csv "$FILEPATH"
