#!/bin/bash
scp ./arm_start_work/start_work root@192.168.100.$1:/opt/spc-arm/plugin/ 
scp ./arm_createtab/Qrcode root@192.168.100.$1:/opt/spc-arm/ 
scp ./arm_program2/program2 root@192.168.100.$1:/opt/spc-arm/plugin/ 
scp ./build-createtab-Desktop_Qt_5_6_3_GCC_64bit-Release/data/batch.txt  root@192.168.100.$1:/opt/spc-arm/data/ 
