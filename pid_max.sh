#!/bin/bash

# Lire la valeur depuis /proc/sys/kernel/pid_max
pid_max=$(cat /proc/sys/kernel/pid_max)

# Afficher la valeur maximale de PID
echo "Valeur maximale de PID : $pid_max"
