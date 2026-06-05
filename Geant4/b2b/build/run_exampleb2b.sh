#!/bin/bash

FILEPATH="$HOME/Desktop/Belle II"

rm -f event_action_data.csv init_step_data.csv

echo "event_id,num_trajectory,num_hits,energies,hitx,hity,hitz" > event_action_data.csv

echo "actx_ent,acty_ent,actz_ent,actx_exit,acty_exit,actz_exit,predx_ent,predy_ent,predz_ent,predx_exit,predy_exit,predz_exit" > entry_exit_data.csv

echo "energies,initx,inity,initz,tot_dist" > init_step_data.csv

make
./exampleB2b

cp event_action_data.csv "$FILEPATH/Python/csv/hits/"
cp init_step_data.csv "$FILEPATH/Python/csv/hits/"
cp entry_exit_data.csv "$FILEPATH/Python/csv/hits/"