#!/bin/bash
op=$(hostnamectl | grep "Operating System" | cut -d ' ' -f5-)
ks=$(hostnamectl | grep "Kernel:" | cut -d ' ' -f14-)
echo -e "Architecture\t\t$op$ks" > monitoring.txt
echo -e "Physical Processors:\t"`nproc --all` >> monitoring.txt
echo -e "Virtual Processors:\t"`grep 'processor' /proc/cpuinfo | wc -l`>> monitoring.txt
free -m | awk 'NR==2{printf "Memory Usage:\t\t%s/%sMB (%.2f%%)\n", $3,$2,$3*100/$2}' >> monitoring.txt
df -h | awk '$NF=="/"{printf "Disk Usage:\t\t%d/%dGB (%s)\n", $3, $2, $5}' >> monitoring.txt
top -bn 1 | grep load | awk '{printf "CPU-Usage:\t\t%.2f%%\n", $11}' >> monitoring.txt
who -b | awk '{printf "Last Reboot:\t\t%s %s\n", $3, $4}' >> monitoring.txt
printf "LVM-use:\t\t" >> monitoring.txt
lvm=$(lsblk | grep "lvm" |wc -l)
if [ $lvm -eq 0 ]; then printf "no\n" >> monitoring.txt; else printf "yes\n" >> monitoring.txt; fi
echo -e "Active Connections:\t"`netstat -an | grep ESTABLISHED | wc -l` >> monitoring.txt
echo -e "Active Users:\t\t"`who | wc -l` >> monitoring.txt
ip=$(hostname -I)
printf "IPv4 + MAC:\t\t%s ", $ip >> monitoring.txt
ip a | grep "link/ether" | awk '{print $2}' >> monitoring.txt
echo -e "Sudo:\t\t\t"`cat /var/log/auth.log | wc -l` >>  monitoring.txt
wall -n monitoring.txt