#!/bin/bash

data_root=../../data
sub_folder=real
data_name=so

time_file=$data_root/$sub_folder/$data_name/time.txt
event_file=$data_root/$sub_folder/$data_name/event.txt
percent=0.2

python split_train_test.py -t $time_file -e $event_file -p $percent -n 128 -s 1
